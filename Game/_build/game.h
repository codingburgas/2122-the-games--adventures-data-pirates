#pragma once
#include "raylib.h"

struct characterStats {
    float characterWidth;
    float characterHeight;
    float characterCordinatesX;
    float characterCordinatesY;
    Vector2 characterPosition;
    Rectangle character;
    Texture2D texture;
};