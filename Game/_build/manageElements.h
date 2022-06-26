#pragma once
#include "raylib.h"

// player struct
struct playerStats {
    float width;
    float height;
    float CordinatesX;
    float CordinatesY;
    Vector2 playerPosition;
    Texture2D textureFront;
    Texture2D textureLeft;
    Texture2D textureRight;
    Texture2D textureBack;
    int direction;
};

// Manage player movement direction based on keyboard input
int managePlayerDierction();