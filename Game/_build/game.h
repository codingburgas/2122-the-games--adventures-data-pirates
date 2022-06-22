#pragma once

#include "raylib.h"

struct characterStats {
    float characterWidth;
    float characterHeight;
    float characterCordinatesX;
    float characterCordinatesY;
    float health;
    Vector2 characterPosition;
    Rectangle character;
    Rectangle healthBar;
};

void spawnCreatures(const int creatureCounter, characterStats creature[100]);
