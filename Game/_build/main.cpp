#include "raylib.h"
#include "game.h"
#include "drawElement.h"
#include "buildMapLayouts.h"
#include "collision.h"

int main()
{
    int screenWidth = 1920;
    int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Game");
    SetTargetFPS(60);

    Vector2 mousePointer = { 0.0f, 0.0f };

    // Declare the parameters for main character
    characterStats mainCharacter;
    mainCharacter.texture = LoadTexture("../resources/player.png");
    mainCharacter.characterWidth = 10;
    mainCharacter.characterHeight = 20;
    mainCharacter.CordinatesX = GetScreenWidth() / 2 - float(mainCharacter.characterWidth / 2);
    mainCharacter.CordinatesY = GetScreenHeight() / 2 - float(mainCharacter.characterWidth / 2);
    mainCharacter.characterPosition = { mainCharacter.CordinatesX, mainCharacter.CordinatesY };
    mainCharacter.character = { mainCharacter.CordinatesX, mainCharacter.CordinatesY, mainCharacter.characterWidth , mainCharacter.characterHeight };

    bool movement = true;

    // Declare Camera2D for player
    Camera2D playerCamera;
    playerCamera.offset = { float(screenWidth) / 2 - float(mainCharacter.characterWidth / 2), float(screenHeight) / 2 - float(mainCharacter.characterHeight / 2) };
    playerCamera.target = { mainCharacter.CordinatesX, mainCharacter.CordinatesY };
    playerCamera.zoom = 4;
    playerCamera.rotation = 0;

    // Declare inventory
    Vector2 inventoryPos = { float(GetScreenWidth()) - 30, float(GetScreenHeight()) - 30 };
    bool drawInventory = false;
    int itemsCounter[2] = {0, 0};
    Texture2D woodItem = LoadTexture("../resources/spruceWood.png");
    Texture2D stoneItem = LoadTexture("../resources/miniRock.png");

    // map layouts
    mapData mapLayout1[27][43];
    mapData mapLayout2[27][43];
    mapData mapLayout3[27][43];
    mapData currentMapForm[27][43];
    int mapHeight = 27;
    int mapWidth = 43;
    int currentMapLayout = GetRandomValue(1, 3); // temporary map layout randomisation

    // build arrays
    bool** buildArray1 = buildMapLayout1(mapHeight, mapWidth);
    bool** buildArray2 = buildMapLayout2(mapHeight, mapWidth);
    bool** buildArray3 = buildMapLayout3(mapHeight, mapWidth);

    Texture2D chMoveXTextureRight = LoadTexture("../resources/1stCharacterMovementX.png");
    Texture2D chMoveXTextureLeft = LoadTexture("../resources/1stCharacterMovementXleft.png");

    Rectangle frameRecRight = { mainCharacter.CordinatesX, mainCharacter.CordinatesY, (float)chMoveXTextureRight.width, (float)chMoveXTextureRight.height };
    Rectangle frameRecLeft = {0, 0, (float)chMoveXTextureLeft.width / 8, (float)chMoveXTextureLeft.height };
    int currentFrame = 0;
    int framesCounter = 0;
    int framesSpeed = 8;

    // Save 1-st map layout
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            mapLayout1[i][j].drawKey = buildArray1[i][j];
        }
    }

    // Save 2-nd map layout
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            mapLayout2[i][j].drawKey = buildArray2[i][j];
        }
    }

    // Save 3-rd map layout
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            mapLayout3[i][j].drawKey = buildArray3[i][j];
        }
    }

    // Update the currect form of the map, based on the currentMapLayout variable
    switch (currentMapLayout)
    {
    case 1:
        // Update the form of the map to the 1-st layout
        for (int i = 0; i < mapHeight; i++)
        {
            for (int j = 0; j < mapWidth; j++)
            {
                currentMapForm[i][j].drawKey = mapLayout1[i][j].drawKey;
            }
        }
        break;
    case 2:
        // Update the form of the map to the 2-nd layout
        for (int i = 0; i < mapHeight; i++)
        {
            for (int j = 0; j < mapWidth; j++)
            {
                currentMapForm[i][j].drawKey = mapLayout2[i][j].drawKey;
            }
        }
        break;
    case 3:
        // Update the form of the map to the 3-rd layout
        for (int i = 0; i < mapHeight; i++)
        {
            for (int j = 0; j < mapWidth; j++)
            {
                currentMapForm[i][j].drawKey = mapLayout3[i][j].drawKey;
            }
        }
        break;
    }

    Texture2D grass = LoadTexture("../resources/grassBlock.png"); // Load texture for the grass blocks
    Texture2D water = LoadTexture("../resources/waterEffect.png"); // Load texture for the water effect
    Texture2D rock = LoadTexture("../resources/rock.png"); // Load texture for the rock
    Texture2D tree1 = LoadTexture("../resources/tree1.png"); // Load texture for the spruce tree

    Vector2 mapBlockSize = { 44, 39 };
    bool chance = true;

    int objectStorage[50];
    int objectCounter = 0;
    Rectangle objectHitbox[100];
    int objectType[100];
    Vector2 textureStorage[100];
    int requiredItems[2][1];

    requiredItems[0][0] = 0;
    requiredItems[1][0] = 0;

    // Temporary additionals placement
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            if (currentMapForm[i][j].drawKey == true)
            {
                chance = GetRandomValue(0, 6);
                if (chance == 0)
                {
                    currentMapForm[i][j].spKey = true;
                }
            }
        }
    }

    // Randomize different types of objects
    for (int i = 0; i < 50; i++)
    {
        int num = GetRandomValue(0, 1);
        if (num == 0)
        {
            objectStorage[i] = 0;

        }
        else if (num == 1)
        {
            objectStorage[i] = 1;
        }
    }

    storeTexturePosition(currentMapForm, mapWidth, mapHeight, mapBlockSize, objectStorage, objectCounter, objectType, textureStorage);

    // Create hitboxes for objects on map
    applyObjectHitBox(currentMapForm, mapWidth, mapHeight, mapBlockSize, objectStorage, objectHitbox, objectCounter, objectType);



    //Main game loop
    while (!WindowShouldClose())
    {
        mousePointer = GetScreenToWorld2D(GetMousePosition(), playerCamera);
        inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 110, float(screenHeight) - 110}, playerCamera);
        // Creates the movement for the character

        if (IsKeyDown(KEY_A))
        {
            mainCharacter.CordinatesX -= 1;
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 115, float(screenHeight) - 110 }, playerCamera);

            /*if (framesCounter >= (60 / framesSpeed))
            {
                framesCounter = 0;
                currentFrame++;

                if (currentFrame > 8)
                {
                    currentFrame = 0;
                }

                frameRecLeft.x = (float)currentFrame * (float)chMoveXTextureLeft.width / 8 ;
                
            }*/

            
        }
        if (IsKeyDown(KEY_D))
        {   
            mainCharacter.CordinatesX += 1;
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 109, float(screenHeight) - 110 }, playerCamera);
        }
        if (IsKeyDown(KEY_W))
        {
            mainCharacter.CordinatesY -= 1;
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 110, float(screenHeight) - 112 }, playerCamera);
        }
        if (IsKeyDown(KEY_S))
        {
            mainCharacter.CordinatesY += 1;
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 110, float(screenHeight) - 105 }, playerCamera);
        }

        // Ensure that that the inventory blocks stick to the bottom right corner
        if (IsKeyDown(KEY_A) && IsKeyDown(KEY_W))
        {
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 115, float(screenHeight) - 112 }, playerCamera);
        }
        if (IsKeyDown(KEY_A) && IsKeyDown(KEY_S))
        {
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 115, float(screenHeight) - 105 }, playerCamera);
        }
        if (IsKeyDown(KEY_D) && IsKeyDown(KEY_W))
        {
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 109, float(screenHeight) - 112 }, playerCamera);
        }
        if (IsKeyDown(KEY_D) && IsKeyDown(KEY_S))
        {
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 109, float(screenHeight) - 105 }, playerCamera);
        }


        // Make playerCamera follow player
        playerCamera.target.x = mainCharacter.CordinatesX;
        playerCamera.target.y = mainCharacter.CordinatesY;

        for (int i = 0; i < 100; i++)
        {
            if (CheckCollisionPointRec(mousePointer, objectHitbox[i]))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    if (objectType[i] == 1)
                    {
                        objectHitbox[i] = { -2000, -2000 };
                        textureStorage[i] = { -2000, -2000 };
                    }
                    else if (objectType[i] == 2)
                    {
                        objectHitbox[i] = { -2000, -2000 };
                        textureStorage[i] = { -2000, -2000 };
                    }
                }
            }
        }


        // Begin Render
        BeginDrawing();

        // Set background color to waterBlue
        ClearBackground(waterBlue);

        BeginMode2D(playerCamera);

        ClearBackground(waterBlue);

        // Draw map
        drawMap(currentMapForm, mapWidth, mapHeight, mapBlockSize, grass, water, rock, tree1, objectStorage, objectHitbox, objectCounter, objectType, textureStorage);

        DrawTextureEx(mainCharacter.texture, Vector2{ mainCharacter.CordinatesX, mainCharacter.CordinatesY }, 0, 0.15, RAYWHITE);

        /*DrawTexture(chMoveXTextureRight, GetScreenWidth() / 2, GetScreenHeight() / 2, RAYWHITE);*/
        
        //if (IsKeyDown(KEY_A))
        //{
        //    /*DrawTextureRec(chMoveXTextureLeft, frameRecLeft, Vector2{ 0, 0 }, WHITE);*/
        //}

        //if (IsKeyDown(KEY_D))
        //{
        //    
        //}
        //if (IsKeyDown(KEY_W))
        //{
        //    
        //}
        //if (IsKeyDown(KEY_S))
        //{
        //    
        //}

        // Draw inventory
        if (!drawInventory)
        {
            if (IsKeyPressed(KEY_E))
            {
                drawInventory = true;
            }
        }
        else
        {
            if (IsKeyPressed(KEY_E))
            {
                drawInventory = false;
            }
        }

        if (drawInventory == true)
        {
            DrawRectangle(inventoryPos.x, inventoryPos.y, 25, 25, DARKGRAY);
            DrawTextureEx(woodItem, Vector2{inventoryPos.x, inventoryPos.y }, 0, 0.2, RAYWHITE);
            /*DrawText(TextFormat("Score: %i", itemsCounter[0]), inventoryPos.x + float(2.5), inventoryPos.y + float(3), 0, WHITE);*/

            DrawRectangle(inventoryPos.x, inventoryPos.y - 28, 25, 25, DARKGRAY);
            DrawTextureEx(stoneItem, Vector2{ inventoryPos.x + float(2.5), inventoryPos.y - 24 }, 0, 0.15, RAYWHITE);
            /*DrawTextureEx();
            DrawText();*/
        }


        EndMode2D;
        //spawnCreatures(zombiesCounter, zombies);

        EndDrawing();
    }

    CloseWindow();

    // Delete the build arrays which no longer needed
    // Delete buildArra1
    for (int i = 0; i < mapHeight; i++)
    {
        delete[] buildArray1[i];
    }
    delete[] buildArray1;
    buildArray1 = 0;

    // Delete buildArra2
    for (int i = 0; i < mapHeight; i++)
    {
        delete[] buildArray2[i];
    }
    delete[] buildArray2;
    buildArray2 = 0;

    // Delete buildArra3
    for (int i = 0; i < mapHeight; i++)
    {
        delete[] buildArray3[i];
    }
    delete[] buildArray3;
    buildArray3 = 0;

    return 0;
}