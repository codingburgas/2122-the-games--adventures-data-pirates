#pragma once
#include "raylib.h"
#include "buildMapLayouts.h"
#include "manageElements.h"

// Define custom colors for the water effect
#define waterBlue CLITERAL(Color){ 34, 146, 248, 255 } // background color
#define waveEffectBlue CLITERAL(Color){ 113, 200, 244, 255 } // wave effect color

// Save object hitboxes
void applyObjectHitBox(mapData mapForm[27][43], int mapX, int mapY, Vector2 mapBlockSize, int objects[50], Rectangle objectHitbox[100], int objectCounter, int objectType[100]);

// Save texture positions
void storeTexturePosition(mapData mapForm[27][43], int mapX, int mapY, Vector2 mapBlockSize, int objects[50], int objectCounter, int objectType[100], Vector2 textureStorage[100]);

// Draw map
void drawMap(mapData mapForm[27][43], int mapX, int mapY, Vector2 mapBlockSize, Texture2D grass, Texture2D water, Texture2D rock, Texture2D tree1, Texture2D grassTexture, int objects[50], Rectangle objectHitbox[100], int objectCounter, int objectType[100], Vector2 textureStorage[100]);

// Draw the player
void drawPlayer(playerStats player);

// Draw equipped item
void drawEquippedItem(Texture2D itemborder, Texture pickaxe, Texture axe, Vector2 inventoryPos, bool isPickEquipped, bool isAxeEquipped);