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
    characterStats player;
    player.texture = LoadTexture("../resources/player.png");
    player.characterWidth = 10;
    player.characterHeight = 20;
    player.CordinatesX = GetScreenWidth() / 2 - float(player.characterWidth / 2);
    player.CordinatesY = GetScreenHeight() / 2 - float(player.characterWidth / 2);
    player.characterPosition = { player.CordinatesX, player.CordinatesY };
    player.character = { player.CordinatesX, player.CordinatesY, player.characterWidth , player.characterHeight };

    bool movement = true;

    // Declare Camera2D for player
    Camera2D playerCamera;
    playerCamera.offset = { float(screenWidth) / 2 - float(player.characterWidth / 2), float(screenHeight) / 2 - float(player.characterHeight / 2) };
    playerCamera.target = { player.CordinatesX, player.CordinatesY };
    playerCamera.zoom = 4;
    playerCamera.rotation = 0;

    //Declaer player inventory
    Vector2 inventoryPos = {0,0};

    
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

    // Declares the character camera


    //Main game loop
    while (!WindowShouldClose())
    {
        mousePointer = GetScreenToWorld2D(GetMousePosition(), playerCamera);
        inventoryPos = GetScreenToWorld2D(Vector2{ 0,0 }, playerCamera);
        getObjectCords(currentMapForm, mapWidth, mapHeight, mapBlockSize, objectStorage, objectHitbox, objectCounter, objectType);

        // Creates the movement for the character
           
        if (IsKeyDown(KEY_A))
        {
            player.CordinatesX -= 2;
            inventoryPos = GetScreenToWorld2D(Vector2{ -8,0 }, playerCamera);
        }        
        if (IsKeyDown(KEY_D))
        {
            player.CordinatesX += 2;
            inventoryPos = GetScreenToWorld2D(Vector2{ 8,0 }, playerCamera);
        }
        if (IsKeyDown(KEY_W))
        {
            player.CordinatesY -= 2;
            inventoryPos = GetScreenToWorld2D(Vector2{ 0,-8 }, playerCamera);
        }
        if (IsKeyDown(KEY_S))
        {
            player.CordinatesY += 2;
            inventoryPos = GetScreenToWorld2D(Vector2{ 0,8 }, playerCamera);
        }

        if (IsKeyDown(KEY_A) && IsKeyDown(KEY_W))
        {
            inventoryPos = GetScreenToWorld2D(Vector2{ -8,-8 }, playerCamera);
        }
        if (IsKeyDown(KEY_A) && IsKeyDown(KEY_S))
        {
            inventoryPos = GetScreenToWorld2D(Vector2{ -8,8 }, playerCamera);
        }
        if (IsKeyDown(KEY_D) && IsKeyDown(KEY_W))
        {
            inventoryPos = GetScreenToWorld2D(Vector2{ 8,-8 }, playerCamera);
        }
        if (IsKeyDown(KEY_D) && IsKeyDown(KEY_S))
        {
            inventoryPos = GetScreenToWorld2D(Vector2{ 8,8 }, playerCamera);
        }


        // Make playerCamera follow player
        playerCamera.target.x = player.CordinatesX;
        playerCamera.target.y = player.CordinatesY;
        
        // Begin Render
        BeginDrawing();

        // Set background color to waterBlue
        ClearBackground(waterBlue);

        BeginMode2D(playerCamera);

        ClearBackground(waterBlue);

        // Draw map
        drawMap(currentMapForm, mapWidth, mapHeight, mapBlockSize, grass, water);

        DrawTextureEx(player.texture, Vector2{ player.CordinatesX, player.CordinatesY }, 0, 0.15, RAYWHITE);
        /*DrawRectangle(mainCharacter.characterCordinatesX, mainCharacter.characterCordinatesY, mainCharacter.texture.width * 0.15, mainCharacter.texture.height * 0.15, GOLD);*/

        drawObjects(currentMapForm, mapWidth, mapHeight, mapBlockSize, rock, tree1, objectStorage, objectHitbox, objectCounter, objectType);

        for (int i = 0; i < 100; i++)
        {
            if (CheckCollisionPointRec(mousePointer, objectHitbox[i]))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    DrawRectangleRec(objectHitbox[i], RED);
                }
            }
        }

        // Draw inventory blocks
        /*DrawRectangleGradientV(inventoryPos.x,inventoryPos.y, 30, 30, BLACK, BLANK);*/

        EndMode2D;
        //spawnCreatures(zombiesCounter, zombies);

        EndDrawing();
    }

    CloseWindow();

    // Delete the build arrays which are no longer needed
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