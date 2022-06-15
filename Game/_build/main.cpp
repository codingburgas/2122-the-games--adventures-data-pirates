#include "raylib.h"
#include "movement.h"


int main()
{
    int screenWidth = 1920;
    int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Game");
    SetTargetFPS(FLAG_VSYNC_HINT);

    // Declares the parameters fo the main character
    characterStats mainCharacter;
    mainCharacter.characterWidth = 10;
    mainCharacter.characterHeight = 20;
    mainCharacter.characterCordinatesX = GetScreenWidth() / 2 - float(mainCharacter.characterWidth / 2);
    mainCharacter.characterCordinatesY = GetScreenHeight() / 2 - float(mainCharacter.characterWidth / 2);
    mainCharacter.characterPosition = { 0, 0 };
    mainCharacter.character = { mainCharacter.characterCordinatesX, mainCharacter.characterCordinatesY, mainCharacter.characterWidth , mainCharacter.characterHeight };
    mainCharacter.health = 100;
    mainCharacter.healthBar = { 10, 10, mainCharacter.health * 2, mainCharacter.health / 2 };
    Rectangle negativeHealthBar = { 10, 10, 100 * 2, 100 / 2 };



    // Declares the parametres for the creatures
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

    mapData mapForm[10][6]; // temporary map form
    bool chance = true; // chance to chip away from the full map

    // Temporary Randomisation of the map 
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            // Apply chance to outer rows
            if (i == 0 || i == 9)
            {
                chance = GetRandomValue(0, 2);
                if (chance == 0)
                {
                    mapForm[i][j].drawKey = false;
                }
            }
            else
            {
                // Apply chance to outer columns
                if (j == 0 || j == 5)
                {
                    chance = GetRandomValue(0, 2);
                    if (chance == 0)
                    {
                        mapForm[i][j].drawKey = false;
                    }
                }
            }
        }
    }

    // Check for single corner blocks --------------------------------------
        // top left corner
        if(mapForm[1][1].drawKey == false && mapForm[0][1].drawKey == false)
        {
            mapForm[0][0].drawKey = false;
        }

        // top right corner
        if(mapForm[1][5].drawKey == false && mapForm[0][4].drawKey == false)
        {
            mapForm[0][5].drawKey = false;
        }

        // bottom right corner
        if(mapForm[8][0].drawKey == false && mapForm[9][1].drawKey == false)
        {
            mapForm[9][0].drawKey = false;
        }

        // bottom left corner
        if (mapForm[8][5].drawKey == false && mapForm[9][4].drawKey == false)
        {
            mapForm[9][5].drawKey = false;
        }
    //-----------------------------------------------------------------------

    // Temporary additionals placement
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 6; j++)
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
        // Creates the movement for the character
        if (IsKeyDown(KEY_A))
        {
            mainCharacter.characterCordinatesX -= 300.0f * GetFrameTime();
        }
        if (IsKeyDown(KEY_D))
        {
            mainCharacter.characterCordinatesX += 300.0f * GetFrameTime();
        }
        if (IsKeyDown(KEY_W))
        {
            mainCharacter.characterCordinatesY -= 300.0f * GetFrameTime();
        }
        if (IsKeyDown(KEY_S))
        {
            mainCharacter.characterCordinatesY += 300.0f * GetFrameTime();
        }

        // Creates the visuals of the game
        BeginDrawing();

        ClearBackground(WHITE);

        // Draw map blocks
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (mapForm[i][j].drawKey == true)
                {
                    if (mapForm[i][j].spKey == true)
                    {
                        DrawRectangle(51 * j + 450, 51 * i + 70, 50, 50, GREEN);
                    }
                    else
                    {
                        DrawRectangle(51 * j + 450, 51 * i + 70, 50, 50, BLUE);
                    }
                }
            }
        }

        DrawRectangle(mainCharacter.characterCordinatesX, mainCharacter.characterCordinatesY, mainCharacter.characterWidth, mainCharacter.characterHeight, RED);
        DrawRectangleRec(negativeHealthBar, RED);
        DrawRectangleRec(mainCharacter.healthBar, GREEN);

        /*spawnCreatures(zombiesCounter, zombies);*/


        EndDrawing();
    }

    CloseWindow();
    return 0;
}