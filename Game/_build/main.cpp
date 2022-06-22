#include "raylib.h"
#include "game.h"
#include "drawElement.h"

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

    mapData mapForm[27][43]; // temporary map form
    int mapHeight = 27;
    int mapWidth = 43;

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

    // Temporary Randomisation of the map 
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            chance = GetRandomValue(0, 2);
            if (chance == 0)
            {
                mapForm[i][j].drawKey = false;
            }
        }
    }

    // Temporary additionals placement
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            if (mapForm[i][j].drawKey == true)
            {
                chance = GetRandomValue(0, 6);
                if (chance == 0)
                {
                    mapForm[i][j].spKey = true;
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
        drawMap(mapForm, mapWidth, mapHeight, mapBlockSize, chance, grass, water, rock, tree1, objectStorage, objectHitbox, objectCounter, objectType);

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
    return 0;
}