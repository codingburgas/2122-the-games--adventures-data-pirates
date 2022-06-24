#include "raylib.h"
#include "buildMapLayouts.h"

// get object hitboxes
void getObjectCords(mapData mapForm[27][43], int mapX, int mapY, Vector2 mapBlockSize, int objects[50], Rectangle objectHitbox[100], int objectCounter, int objectType[100])
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
                                objectHitbox[objectCounter] = { mapBlockSize.x * j + 22, mapBlockSize.y * i + 2, 25, 25 };

                                objectType[objectCounter] = 1;
                            }
                            else if (objects[i] == 1)
                            {

                                // Make hitbox for object tree1
                                objectHitbox[objectCounter] = { mapBlockSize.x * j + 23, mapBlockSize.y * i - float(18.5), 28, 42 };

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

// Still under development. Currently doesn't work!
bool objectCollision(Rectangle objectHitbox[100], Texture2D texture ,float playerX, float playerY, int direction)
{
    for (int i = 0; i < 100; i++)
    {
        // Manage object collision base on movement direction
        switch (direction)
        {
        case 1:
            // obeject collision for left movement
            if (CheckCollisionPointRec(Vector2{ playerX, playerY }, objectHitbox[i]) == true || 
                CheckCollisionPointRec(Vector2{ playerX, playerY + texture.height * float(0.15)}, objectHitbox[i]) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 2:
            // obeject collision for rigth movement
            if (CheckCollisionPointRec(Vector2{ playerX + texture.width * float(0.15), playerY }, objectHitbox[i]) == true ||
                CheckCollisionPointRec(Vector2{ playerX + texture.width * float(0.15), playerY + texture.height * float(0.15) }, objectHitbox[i]) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 3:
            // obeject collision for upwards movement
            if (CheckCollisionPointRec(Vector2{ playerX, playerY }, objectHitbox[i]) == true ||
                CheckCollisionPointRec(Vector2{ playerX + texture.width * float(0.15), playerY}, objectHitbox[i]) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 4:
            // obeject collision for downwards movement
            if (CheckCollisionPointRec(Vector2{ playerX, playerY + texture.height * float(0.15) }, objectHitbox[i]) == true ||
                CheckCollisionPointRec(Vector2{ playerX + texture.width * float(0.15), playerY + texture.height * float(0.15) }, objectHitbox[i]) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        }
        
    }
}