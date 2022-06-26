#include "raylib.h"
#include "manageElements.h"

// manage player movement direction based on keyboard input
int managePlayerDierction()
{
    if (IsKeyPressed(KEY_A))
    {
        return 1;
    }
    if (IsKeyPressed(KEY_D))
    {
        return 2;
    }
    if (IsKeyPressed(KEY_W))
    {
        return 3;
    }
    if (IsKeyPressed(KEY_S))
    {
        return 4;
    }
}