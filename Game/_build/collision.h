#pragma once
#include "raylib.h"
#include "buildMapLayouts.h"

// get object hitboxes
void getObjectCords(mapData mapForm[27][43], int mapX, int mapY, Vector2 mapBlockSize, int objects[50], Rectangle objectHitbox[100], int objectCounter, int objectType[100]);


bool objectCollision(Rectangle objectHitbox[100], Texture2D texture, float playerX, float playerY, int direction);