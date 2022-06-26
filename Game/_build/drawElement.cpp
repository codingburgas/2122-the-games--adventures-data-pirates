#include "raylib.h"
#include "drawElement.h"
#include "buildMapLayouts.h"
#include "manageElements.h"

void storeTexturePosition(mapData mapForm[27][43], int mapX, int mapY, Vector2 mapBlockSize, int objects[50], int objectCounter, int objectType[100], Vector2 textureStorage[100])
{
    for (int i = 0; i < mapY; i++)
    {
        for (int j = 0; j < mapX; j++)
        {
            // Check if a block will be drawn
            if (mapForm[i][j].drawKey == true)
            {
                // Check if items can spawn on block
                if (mapForm[i][j].spKey == true)
                {
                    // Check if block on top has no object drown
                    if (mapForm[i - 1][j].spKey != true)
                    {
                        if (mapForm[i][j - 1].spKey != true && mapForm[i][j + 1].spKey != true)
                        {
                            if (objects[i] == 0)
                            {

                                // Make hitbox for object rock
                                textureStorage[objectCounter] = { mapBlockSize.x * j + 27, mapBlockSize.y * i + 5 };
                            }
                            else if (objects[i] == 1)
                            {
                                // Make hitbox for object tree1
                                textureStorage[objectCounter] = { mapBlockSize.x * j + 11, mapBlockSize.y * i - 23 };
                            }

                            // Add one position to counter
                            objectCounter++;
                        }
                    }
                }
            }
        }
    }
}


void applyObjectHitBox(mapData mapForm[27][43], int mapX, int mapY, Vector2 mapBlockSize, int objects[50], Rectangle objectHitbox[100], int objectCounter, int objectType[100])
{
    for (int i = 0; i < mapY; i++)
    {
        for (int j = 0; j < mapX; j++)
        {
            // Check if a block will be drawn
            if (mapForm[i][j].drawKey == true)
            {
                // Check if items can spawn on block
                if (mapForm[i][j].spKey == true)
                {
                    // Check if block on top has no object drown
                    if (mapForm[i - 1][j].spKey != true)
                    {
                        if (mapForm[i][j - 1].spKey != true && mapForm[i][j + 1].spKey != true)
                        {
                            if (objects[i] == 0)
                            {

                                // Make hitbox for object rock
                                objectHitbox[objectCounter] = { mapBlockSize.x * j + 24, mapBlockSize.y * i + 2, 25, 25 };

                                objectType[objectCounter] = 1;
                            }
                            else if (objects[i] == 1)
                            {
                                // Make hitbox for object tree1
                                objectHitbox[objectCounter] = { mapBlockSize.x * j + 23, mapBlockSize.y * i - float(20.5), 28, 47 };

                                objectType[objectCounter] = 2;
                            }

                            // Add one position to counter
                            objectCounter++;
                        }
                    }
                }
            }
        }
    }
}


void drawMap(mapData mapForm[27][43], int mapX, int mapY, Vector2 mapBlockSize, Texture2D grass, Texture2D water, Texture2D rock, Texture2D tree1, Texture2D grassTexture, int objects[50], Rectangle objectHitbox[100], int objectCounter, int objectType[100], Vector2 textureStorage[100])
{
    // Draw map
    for (int i = 0; i < mapY; i++)
    {
        for (int j = 0; j < mapX; j++)
        {
            // Check if a block will be drawn
            if (mapForm[i][j].drawKey == true)
            {
                // Check if items can spawn on block
                if (mapForm[i][j].spKey == true)
                {
                    DrawTextureEx(grass, Vector2{ mapBlockSize.x * j + 15,mapBlockSize.y * i }, 0, 0.35, RAYWHITE);
                }
                else
                {
                    DrawTextureEx(grass, Vector2{ mapBlockSize.x * j + 15,mapBlockSize.y * i }, 0, 0.35, RAYWHITE);
   
                    if (mapForm[i][j].grassKey == true)
                    {
                        DrawTextureEx(grassTexture, Vector2{ mapBlockSize.x * j + 21,mapBlockSize.y * i + 3}, 0, 0.50, RAYWHITE);
                    }
                }
            }
            else  
            {
                if (i != 0) // Accout for first row
                {
                    // Check where to draw water effect
                    if (mapForm[i - 1][j].drawKey == true)
                    {
                        // Draw slightly transparent water block
                        DrawTextureEx(water, Vector2{ mapBlockSize.x * j + float(15.5), mapBlockSize.y * i + 15 }, 0, 0.11, RAYWHITE);

                        // Draw wave effect
                        DrawLineEx(Vector2{ mapBlockSize.x * j + float(15.4), mapBlockSize.y * i + 15 }, Vector2{ (mapBlockSize.x * j + 16) + mapBlockSize.x, mapBlockSize.y * i + 15 }, 3, waveEffectBlue);
                    }
                }

                DrawRectangleRec(Rectangle{ mapBlockSize.x * j + 15, mapBlockSize.y * i, grass.width * float(0.35), grass.height * float(0.35) }, BLANK);

            }
        }
    }

    // Draw rocks and trees on the map
    for (int i = 0; i < mapY; i++)
    {
        for (int j = 0; j < mapX; j++)
        {
            // Check if a block will be drawn
            if (mapForm[i][j].drawKey == true)
            {
                // Check if items can spawn on block
                if (mapForm[i][j].spKey == true)
                {
                    // Check if block on top has no object drown
                    if (mapForm[i - 1][j].spKey != true)
                    {
                        if (mapForm[i][j - 1].spKey != true && mapForm[i][j + 1].spKey != true)
                        {
                            if (objects[i] == 0)
                            {
                                // Draw rock on the map
                                DrawTextureEx(rock, textureStorage[objectCounter], 0, 0.08, RAYWHITE);

                                /*DrawRectangleRec(objectHitbox[objectCounter], RED);*/

                                objectType[objectCounter] = 1;
                            }
                            else if (objects[i] == 1)
                            {
                                // Draw tree type 1 on the map
                                DrawTextureEx(tree1, textureStorage[objectCounter], 0, 0.40, RAYWHITE);

                                /*DrawRectangleRec(objectHitbox[objectCounter], RED);*/

                                objectType[objectCounter] = 2;
                            }
                            // Add one position to counter
                            objectCounter++;
                        }
                    }
                }
            }
        }
    }
}

// Draw the player
void drawPlayer(playerStats player)
{
    switch (player.direction)
    {
    case 1:
        // Draw player's left prespective
        DrawTextureEx(player.textureLeft, Vector2{ player.CordinatesX, player.CordinatesY }, 0, float(0.15), WHITE);
        break;

    case 2:
        // Draw player's right prespective
        DrawTextureEx(player.textureRight, Vector2{ player.CordinatesX, player.CordinatesY }, 0, float(0.15), WHITE);
        break;

    case 3:
        // Draw player's backrwards prespective
        DrawTextureEx(player.textureBack, Vector2{ player.CordinatesX, player.CordinatesY }, 0, float(0.15), WHITE);
        break;

    case 4:
        // Draw player's forwards prespective
        DrawTextureEx(player.textureFront, Vector2{ player.CordinatesX, player.CordinatesY }, 0, float(0.15), WHITE);
        break;
    }
}

// Draw equipped item
void drawEquippedItem(Texture2D itemborder, Texture pickaxe, Texture axe, Vector2 inventoryPos, bool isPickEquipped, bool isAxeEquipped)
{
    // Check if axe is equipped 
    if (isAxeEquipped == true)
    {
        // Draw indicator that the axe is equipped
        DrawTextureEx(itemborder, Vector2{ inventoryPos.x - 211, inventoryPos.y - 121 }, 0, float(0.1), RAYWHITE);
        DrawTextureEx(axe, Vector2{ inventoryPos.x - 210, inventoryPos.y - float(120.5) }, 0, float(0.04), WHITE);
    }
    else if(isPickEquipped == true) // Check if pickaxe is equipped 
    {
        // Draw indicator that the pickaxe is equipped
        DrawTextureEx(itemborder, Vector2{ inventoryPos.x - 211, inventoryPos.y - 121 }, 0, float(0.1), RAYWHITE);
        DrawTextureEx(pickaxe, Vector2{ inventoryPos.x - 210, inventoryPos.y - 120 }, 0, float(0.04), WHITE);
    }
}