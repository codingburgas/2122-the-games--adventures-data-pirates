#include "raylib.h"
#include "movement.h"

void spawnCreatures(const int creatureCounter, characterStats creature[100])
{
    for (int i = 0; i < creatureCounter; i++)
    {
        DrawRectangleRec(creature[i].character, GREEN);
    }
}