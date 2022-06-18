#include "raylib.h"
#include "drawElement.h"

void drawMap(mapData mapForm[27][43], int mapX, int mapY, Vector2 mapBlockSize, bool change, Texture2D grass, Texture2D water)
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
                    DrawTextureEx(water, Vector2{ mapBlockSize.x * j + 15, mapBlockSize.y * i + 15 }, 0, 0.35, RAYWHITE);

                    // Draw wave effect
                    DrawLineEx(Vector2{ mapBlockSize.x * j + 15, mapBlockSize.y * i + 15 }, Vector2{ (mapBlockSize.x * j + 15) + mapBlockSize.x, mapBlockSize.y * i + 15 }, 3, waveEffectBlue);
                }
            }
        }
    }
}