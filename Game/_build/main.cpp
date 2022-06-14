#include "raylib.h"
#include "movement.h"

int main()
{
    int screenWidth = 1280;
    int screenHeight = 720;
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

    // Declares the character camera

    //Main game loop
    while (!WindowShouldClose())
    {
        // Creates the movement for the character
        if ((mainCharacter.characterPosition.x >= 0 && mainCharacter.characterPosition.x <= 1280-mainCharacter.characterWidth) &&
            (mainCharacter.characterPosition.y >= 0 && mainCharacter.characterPosition.y <= screenHeight-mainCharacter.characterHeight))
        {
            if (IsKeyDown(KEY_A))
            {

                mainCharacter.characterCordinatesX -= 300.0f * GetFrameTime();
            }
            if (IsKeyDown(KEY_D))
            {
                // if(mainCharacter.characterPosition.x <= (GetScreenWidth() - mainCharacter.characterWidth))

                mainCharacter.characterCordinatesX += 300.0f * GetFrameTime();
            }
            if (IsKeyDown(KEY_W))
            {
                // if(mainCharacter.characterPosition.y >= 0)
                mainCharacter.characterCordinatesY -= 300.0f * GetFrameTime();
            }
            if (IsKeyDown(KEY_S))
            {
                // if(mainCharacter.characterPosition.y <= (GetScreenHeight() - mainCharacter.characterHeight))
                mainCharacter.characterCordinatesX += 300.0f * GetFrameTime();
            }
        }

        // Creates the visuals of the game
        BeginDrawing();

        ClearBackground(WHITE);

        DrawRectangle(mainCharacter.characterCordinatesX, mainCharacter.characterCordinatesY, mainCharacter.characterWidth, mainCharacter.characterHeight, BLUE);
        DrawRectangleRec(negativeHealthBar, RED);
        DrawRectangleRec(mainCharacter.healthBar, GREEN);


        spawnCreatures(zombiesCounter, zombies);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}