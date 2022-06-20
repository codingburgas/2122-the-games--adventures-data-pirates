#include "raylib.h"
#include "drawElement.h"

void drawMap(mapData mapForm[27][43], int mapX, int mapY, Vector2 mapBlockSize, bool change, Texture2D grass, Texture2D water, Texture2D rock, Texture2D tree1, int objects[50], Rectangle objectHitbox[100], int objectCounter)
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
                }
            }
            else if (i != 0) // Accout first row
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
        }
    }


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
                                DrawTextureEx(rock, Vector2{ mapBlockSize.x * j + 12, mapBlockSize.y * i - 5 }, 0, 0.17, RAYWHITE);

                                // Make hitbox for object rock
                                objectHitbox[objectCounter] = { mapBlockSize.x * j + 17, mapBlockSize.y * i + 2, 32, 26 };
                            }
                            else if (objects[i] == 1)
                            {
                                // Draw tree type 1 on the map
                                DrawTextureEx(tree1, Vector2{ mapBlockSize.x * j + 11, mapBlockSize.y * i - 23 }, 0, 0.40, RAYWHITE);

                                // Make hitbox for object tree1
                                objectHitbox[objectCounter] = { mapBlockSize.x * j + 23, mapBlockSize.y * i - float(18.5), 28, 42 };

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