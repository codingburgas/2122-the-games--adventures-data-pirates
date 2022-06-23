#include "raylib.h"
#include "game.h"
#include "drawElement.h"
#include "buildMapLayouts.h"

// Define custom colors for the water effect
#define waterBlue CLITERAL(Color){ 34, 146, 248, 255 } // background color
#define waveEffectBlue CLITERAL(Color){ 113, 200, 244, 255 } // wave effect color

int main()
{
    int screenWidth = 1920;
    int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Game");
    SetTargetFPS(60);

    Vector2 mousePointer = { 0.0f, 0.0f };
    

    // Declare the parameters for main character
    characterStats mainCharacter;
    mainCharacter.characterWidth = 10;
    mainCharacter.characterHeight = 20;
    mainCharacter.characterCordinatesX = GetScreenWidth() / 2 - float(mainCharacter.characterWidth / 2);
    mainCharacter.characterCordinatesY = GetScreenHeight() / 2 - float(mainCharacter.characterWidth / 2);
    mainCharacter.characterPosition = { mainCharacter.characterCordinatesX, mainCharacter.characterCordinatesY };
    mainCharacter.character = { mainCharacter.characterCordinatesX, mainCharacter.characterCordinatesY, mainCharacter.characterWidth , mainCharacter.characterHeight };
    mainCharacter.health = 100;
    mainCharacter.healthBar = { 10, 10, mainCharacter.health * 2, mainCharacter.health / 2 };
    Rectangle negativeHealthBar = { 10, 10, 100 * 2, 100 / 2 };

    bool movement = true;

    // Declare Camera2D for player
    Camera2D playerCamera;
    playerCamera.offset = { float(screenWidth) / 2 - float(mainCharacter.characterWidth / 2), float(screenHeight) / 2 - float(mainCharacter.characterHeight / 2) };
    playerCamera.target = { mainCharacter.characterCordinatesX, mainCharacter.characterCordinatesY };
    playerCamera.zoom = 4;
    playerCamera.rotation = 0;

    // Declare the parametres for the creatures
    const int zombiesCounter = 10;

    characterStats zombies[zombiesCounter];

    for (int i = 0; i < zombiesCounter; i++)
    {
        zombies[i].characterCordinatesX = GetRandomValue(100, screenWidth - 100);
        zombies[i].characterCordinatesY = GetRandomValue(100, screenHeight - 100);
        zombies[i].characterWidth = 10;
        zombies[i].characterHeight = 20;
        zombies[i].character = { zombies[i].characterCordinatesX,  zombies[i].characterCordinatesY, zombies[i].characterWidth, zombies[i].characterHeight };
    }

    
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

    Vector2 mapBlockSize = { 44, 39 };
    bool chance = true; // chance to chip away from the full map
    Texture2D grass = LoadTexture("../resources/grassBlock.png"); // Load texture for the grass blocks
    Texture2D water = LoadTexture("../resources/waterEffect.png"); // Load texture for the water effect
    Texture2D rock = LoadTexture("../resources/rock.png"); // Load texture for the rock
    Texture2D tree1 = LoadTexture("../resources/tree1.png"); // Load texture for the spruce tree
    int objectStorage[50];
    int objectCounter = 0;
    Rectangle objectHitbox[100];
    int objectType[100];

    int whatToDraw = 0;

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

    // Declares the character camera


    //Main game loop
    while (!WindowShouldClose())
    {
        mousePointer = GetScreenToWorld2D(GetMousePosition(), playerCamera);

        
        if (movement == true)
        {

            // Creates the movement for the character
            if (IsKeyDown(KEY_A))
            {
                mainCharacter.characterCordinatesX -= 2;
            }
            if (IsKeyDown(KEY_D))
            {
                mainCharacter.characterCordinatesX += 2;
            }
            if (IsKeyDown(KEY_W))
            {
                mainCharacter.characterCordinatesY -= 2;
            }
            if (IsKeyDown(KEY_S))
            {
                mainCharacter.characterCordinatesY += 2;
            }

        }

        // Make playerCamera follow playerdddd
        playerCamera.target.x = mainCharacter.characterCordinatesX;
        playerCamera.target.y = mainCharacter.characterCordinatesY;
        
        // Begin Render
        BeginDrawing();

        // Set background color to waterBlue
        ClearBackground(waterBlue);

        BeginMode2D(playerCamera);

        ClearBackground(waterBlue);

        // Draw map
        drawMap(currentMapForm, mapWidth, mapHeight, mapBlockSize, chance, grass, water, rock, tree1, objectStorage, objectHitbox, objectCounter, objectType);

        DrawRectangle(mainCharacter.characterCordinatesX, mainCharacter.characterCordinatesY, mainCharacter.characterWidth, mainCharacter.characterHeight, RED);

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