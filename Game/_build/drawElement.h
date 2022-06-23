#pragma once
#include "raylib.h"
#include "buildMapLayouts.h"

// Define custom colors for the water effect
#define waterBlue CLITERAL(Color){ 34, 146, 248, 255 } // background color
#define waveEffectBlue CLITERAL(Color){ 113, 200, 244, 255 } // wave effect color

// Draw map
void drawMap(mapData mapForm[27][43], int mapX, int mapY, Vector2 mapBlockSize, Texture2D grass, Texture2D water, Texture2D rock, Texture2D tree1, int objects[50], Rectangle objectHitbox[100], int objectCounter, int objectType[100]);