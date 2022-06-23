#pragma once
#include "raylib.h"
#include "buildMapLayouts.h"

void getObjectCords(mapData mapForm[27][43], int mapX, int mapY, Vector2 mapBlockSize, int objects[100], Rectangle objectHitbox[100], int objectCounter, int objectType[100]);

bool objectCollision(Rectangle objectData[100], float playerX, float playerY, float playerHeight, float playerWidth);