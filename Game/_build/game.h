#pragma once
#include "raylib.h"

struct characterStats {
    float characterWidth;
    float characterHeight;
    float CordinatesX;
    float CordinatesY;
    Vector2 characterPosition;
    Rectangle character;
    Texture2D textureFront;
    Texture2D textureLeft;
    Texture2D textureRight;
    Texture2D textureBack;
    int direction;
};