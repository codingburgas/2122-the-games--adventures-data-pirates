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
    mainCharacter.textureFront = LoadTexture("../resources/playerFront.png");
    mainCharacter.textureLeft = LoadTexture("../resources/playerLeft.png");
    mainCharacter.textureRight = LoadTexture("../resources/playerRight.png");
    mainCharacter.textureBack = LoadTexture("../resources/playerBack.png");
    mainCharacter.characterWidth = 10;
    mainCharacter.characterHeight = 20;
    mainCharacter.CordinatesX = GetScreenWidth() / 2 - float(mainCharacter.characterWidth / 2);
    mainCharacter.CordinatesY = GetScreenHeight() / 2 - float(mainCharacter.characterWidth / 2);
    mainCharacter.characterPosition = { mainCharacter.CordinatesX, mainCharacter.CordinatesY };
    mainCharacter.character = { mainCharacter.CordinatesX, mainCharacter.CordinatesY, mainCharacter.characterWidth , mainCharacter.characterHeight };
    mainCharacter.direction = 4;
    float playerSpeed = 1;

    bool directionLeft = true;
    bool directionRight = true;
    bool directionBack = true;
    bool directionFront = true;

    // Declare Camera2D for player
    Camera2D playerCamera;
    playerCamera.offset = { float(screenWidth) / 2 - float(mainCharacter.characterWidth / 2), float(screenHeight) / 2 - float(mainCharacter.characterHeight / 2) };
    playerCamera.target = { mainCharacter.CordinatesX, mainCharacter.CordinatesY };
    playerCamera.zoom = 4;
    playerCamera.rotation = 0;

    // Declare inventory
    Vector2 inventoryPos = { float(GetScreenWidth()) - 30, float(GetScreenHeight()) - 30 };
    Vector2 taskPos = { float(GetScreenWidth()) - 60,  float(GetScreenHeight()) - 60};
    bool drawInventory = false;
    bool drawTask = false;
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

    Texture2D itemBorder = LoadTexture("../resources/itemBorder.png");
    Texture2D taskBorder = LoadTexture("../resources/taskBorder.png");

    Texture2D chMoveXTextureRight = LoadTexture("../resources/1stCharacterMovementX.png");
    Texture2D chMoveXTextureLeft = LoadTexture("../resources/1stCharacterMovementXleft.png");

    Rectangle frameRecRight = { mainCharacter.CordinatesX, mainCharacter.CordinatesY, (float)chMoveXTextureRight.width, (float)chMoveXTextureRight.height };
    Rectangle frameRecLeft = {0, 0, (float)chMoveXTextureLeft.width / 8, (float)chMoveXTextureLeft.height };
    int currentFrame = 0;
    int framesCounter = 0;
    int framesSpeed = 8;

    int cTask = 1;

    const char* currentTask;
    const char* taskCraft1 = "Task: Craft a pickaxe";
    const char* taskCraft2 = "Task: Craft a axe";
    const char* taskCollect1 = "Task: Collect sticks";
    const char* taskCollect2 = "Task: Collect wood";
    const char* taskCollect3 = "Task: Collect stones";
    const char* taskMine = "Task: Mine iron";

    bool axe = false;
    bool pickaxe = false;

    Texture2D grass = LoadTexture("../resources/grassBlock.png"); // Load texture for the grass blocks
    Texture2D grassTexture = LoadTexture("../resources/grassTexture.png"); // Load texture for the grass blocks
    Texture2D water = LoadTexture("../resources/waterEffect.png"); // Load texture for the water effect
    Texture2D rock = LoadTexture("../resources/rock.png"); // Load texture for the rock
    Texture2D tree1 = LoadTexture("../resources/tree1.png"); // Load texture for the spruce tree

    int itemRock = 1;
    int itemWood = 1;

    Vector2 mapBlockSize = { 44, 39 };
    int chance;

    int objectStorage[50];
    int objectCounter = 0;
    Rectangle objectHitbox[100];
    int objectType[100];
    Vector2 textureStorage[100];
    int requiredItems[2];

    requiredItems[0] = 0;
    requiredItems[1] = 0;

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
                else if (chance == 4)
                {
                    currentMapForm[i][j].grassKey = true;
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
        taskPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 590, float(screenHeight) - 115 }, playerCamera);
        
        // Create movement for player
        if (IsKeyDown(KEY_A))
        {
            if (directionLeft == true)
            {
                mainCharacter.CordinatesX -= playerSpeed;
            }
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 110, float(screenHeight) - 110 }, playerCamera);
           
        }
        if (IsKeyDown(KEY_D))
        {   
            if (directionRight == true)
            {
                mainCharacter.CordinatesX += playerSpeed;
            }
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 110, float(screenHeight) - 110 }, playerCamera);
        }
        if (IsKeyDown(KEY_W))
        {
            if (directionBack == true)
            {
                mainCharacter.CordinatesY -= playerSpeed;
            }
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 110, float(screenHeight) - 110 }, playerCamera);
        }
        if (IsKeyDown(KEY_S))
        {
            if (directionFront == true)
            {
                mainCharacter.CordinatesY += playerSpeed;
            }
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 110, float(screenHeight) - 110 }, playerCamera);
        }


        // check what direction the playerr moves
        if (IsKeyPressed(KEY_A))
        {
            mainCharacter.direction = 1;
        }
        else if (IsKeyPressed(KEY_D))
        {
            mainCharacter.direction = 2;
        }
        else if (IsKeyPressed(KEY_W))
        {
            mainCharacter.direction = 3;
        }
        else if (IsKeyPressed(KEY_S))
        {
            mainCharacter.direction = 4;
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
                        requiredItems[0] += itemRock;
                    }
                    else if (objectType[i] == 2)
                    {
                        objectHitbox[i] = { -2000, -2000 };
                        textureStorage[i] = { -2000, -2000 };
                        requiredItems[1] += itemWood;
                    }
                }
            }
        }

        if (cTask == 1)
        {
            currentTask = taskCollect1;
        }
        else if (cTask == 2)
        {
            currentTask = taskCollect2;
        }
        else if (cTask == 3)
        {
            currentTask = taskCollect3;
        }
        else if (cTask == 4)
        {
            currentTask = taskCraft1;
        }
        else if (cTask == 5)
        {
            currentTask = taskCraft1;
        }
        else if (cTask == 6)
        {
            currentTask = taskMine;
        }


        // Begin Render
        BeginDrawing();

        // Set background color to waterBlue
        ClearBackground(waterBlue);

        BeginMode2D(playerCamera);

        ClearBackground(waterBlue);

        // Draw map
        drawMap(currentMapForm, mapWidth, mapHeight, mapBlockSize, grass, water, rock, tree1, grassTexture, objectStorage, objectHitbox, objectCounter, objectType, textureStorage);

        // 
        switch (mainCharacter.direction)
        {
        case 1:
            DrawTextureEx(mainCharacter.textureLeft, Vector2{ mainCharacter.CordinatesX, mainCharacter.CordinatesY }, 0, 0.15, RAYWHITE);
            break;

        case 2:
            DrawTextureEx(mainCharacter.textureRight, Vector2{ mainCharacter.CordinatesX, mainCharacter.CordinatesY }, 0, 0.15, RAYWHITE);
            break;

        case 3:
            DrawTextureEx(mainCharacter.textureBack, Vector2{ mainCharacter.CordinatesX, mainCharacter.CordinatesY }, 0, 0.15, RAYWHITE);
            break;

        case 4:
            DrawTextureEx(mainCharacter.textureFront, Vector2{ mainCharacter.CordinatesX, mainCharacter.CordinatesY }, 0, 0.15, RAYWHITE);
            break;
        }


        /*DrawTexture(chMoveXTextureRight, GetScreenWidth() / 2, GetScreenHeight() / 2, RAYWHITE);*/
        
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

        if (!drawTask)
        {
            if (IsKeyPressed(KEY_Q))
            {
                drawTask = true;
            }
        }
        else
        {
            if (IsKeyPressed(KEY_Q))
            {
                drawTask = false;
            }
        }

        if (drawTask == true)
        {
            DrawTextureEx(taskBorder, Vector2{ taskPos.x, taskPos.y }, 0, 0.14, RAYWHITE);
            DrawText(currentTask, taskPos.x + 3, taskPos.y + 10, 2, BLACK);
        }

        if (drawInventory == true)
        {
            DrawTextureEx(itemBorder, inventoryPos, 0, 0.25, RAYWHITE);
            DrawTextureEx(woodItem, Vector2{inventoryPos.x, inventoryPos.y }, 0, 0.2, RAYWHITE);
            /*DrawText(TextFormat("Score: %i", itemsCounter[0]), inventoryPos.x + float(2.5), inventoryPos.y + float(3), 0, WHITE);*/
            DrawText(TextFormat("%i", requiredItems[1]), inventoryPos.x + 18, inventoryPos.y + 15, 4, WHITE);
            
            DrawTextureEx(itemBorder, Vector2{ inventoryPos.x, inventoryPos.y - 28 }, 0, 0.25, RAYWHITE);
            DrawTextureEx(stoneItem, Vector2{ inventoryPos.x + float(2.5), inventoryPos.y - 24 }, 0, 0.15, RAYWHITE);
            DrawText(TextFormat("%i", requiredItems[1]), inventoryPos.x + 18, inventoryPos.y + 15 - 28, 4, WHITE);

            DrawTextureEx(itemBorder, Vector2{ inventoryPos.x, inventoryPos.y - 56 }, 0, 0.25, RAYWHITE);
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