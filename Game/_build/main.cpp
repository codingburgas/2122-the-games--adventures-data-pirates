#include "raylib.h"
#include "manageElements.h"
#include "drawElement.h"
#include "buildMapLayouts.h"
#include "collision.h"

int main()
{
    int screenWidth = 1920;
    int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Game");
    SetTargetFPS(60);

    Vector2 mousePointer = { 0.0f, 0.0f };

    // Declare the parameters for main character
    playerStats player;
    player.textureFront = LoadTexture("../resources/playerFront.png");
    player.textureLeft = LoadTexture("../resources/playerLeft.png");
    player.textureRight = LoadTexture("../resources/playerRight.png");
    player.textureBack = LoadTexture("../resources/playerBack.png");
    player.width = 10;
    player.height = 20;
    player.CordinatesX = GetScreenWidth() / 2 - float(player.width / 2);
    player.CordinatesY = GetScreenHeight() / 2 - float(player.width / 2);
    player.playerPosition = { player.CordinatesX, player.CordinatesY };
    player.direction = 4;
    float playerSpeed = 1;

    // Declare Camera2D for player
    Camera2D playerCamera;
    playerCamera.offset = { float(screenWidth) / 2 - float(player.width / 2), float(screenHeight) / 2 - float(player.height / 2) };
    playerCamera.target = { player.CordinatesX, player.CordinatesY };
    playerCamera.zoom = 4;
    playerCamera.rotation = 0;

    // Declare inventory
    Vector2 inventoryPos = { float(GetScreenWidth()) - 30, float(GetScreenHeight()) - 30 };
    Vector2 taskPos = { float(GetScreenWidth()) - 60,  float(GetScreenHeight()) - 60};
    bool drawInventory = false;
    bool drawTask = false;
    int requiredItems[2] = { 0,0 };
    int itemRock = 1;
    int itemWood = 1;
    Texture2D woodItem = LoadTexture("../resources/spruceWood.png");
    Texture2D stoneItem = LoadTexture("../resources/miniRock.png");
    Texture2D itemBorder = LoadTexture("../resources/itemBorder.png");
    Texture2D taskBorder = LoadTexture("../resources/taskBorder.png");
    Texture2D pickaxe = LoadTexture("../resources/pickaxe.png");
    Texture2D axe = LoadTexture("../resources/axe.png");
    Rectangle axeEquipButton = {};
    bool isAxeEquipped = false;
    Rectangle pickAxeEquipButton = {};
    bool isPickaxeEquipped = false;
    
    // map layouts
    mapData mapLayout1[27][43];
    mapData mapLayout2[27][43];
    mapData mapLayout3[27][43];
    mapData currentMapForm[27][43];
    int mapHeight = 27;
    int mapWidth = 43;
    int currentMapLayout = 1; // temporary map layout randomisation
    
    // Load animation textures
    Texture2D chMoveXTextureRight = LoadTexture("../resources/1stCharacterMovementX.png");
    Texture2D chMoveXTextureLeft = LoadTexture("../resources/1stCharacterMovementXleft.png");
    Rectangle frameRecRight = { player.CordinatesX, player.CordinatesY, (float)chMoveXTextureRight.width, (float)chMoveXTextureRight.height };
    Rectangle frameRecLeft = {0, 0, (float)chMoveXTextureLeft.width / 8, (float)chMoveXTextureLeft.height };
    int currentFrame = 0;
    int framesCounter = 0;
    int framesSpeed = 8;

    // Declare task variables
    int cTask = 1;
    const char* currentTask;
    const char* taskCraft1 = "Task: Craft a pickaxe";
    const char* taskCraft2 = "Task: Craft a axe";
    const char* taskCollect1 = "Task: Collect sticks";
    const char* taskCollect2 = "Task: Collect wood";
    const char* taskCollect3 = "Task: Collect stones";
    const char* taskMine = "Task: Mine iron";


    // Declare map variables
    Texture2D grass = LoadTexture("../resources/grassBlock.png"); // Load texture for the grass blocks
    Texture2D grassTexture = LoadTexture("../resources/grassTexture.png"); // Load texture for the grass blocks
    Texture2D water = LoadTexture("../resources/waterEffect.png"); // Load texture for the water effect
    Texture2D rock = LoadTexture("../resources/rock.png"); // Load texture for the rock
    Texture2D tree1 = LoadTexture("../resources/tree1.png"); // Load texture for the spruce tree
    Vector2 mapBlockSize = { 44, 39 };
    int chance;

    int objectStorage[50];
    int objectCounter = 0;
    Rectangle objectHitbox[100];
    int objectType[100];
    Vector2 textureStorage[100];

    // build arrays
    bool** buildArray1 = buildMapLayout1(mapHeight, mapWidth);
    bool** buildArray2 = buildMapLayout2(mapHeight, mapWidth);
    bool** buildArray3 = buildMapLayout3(mapHeight, mapWidth);

    // Save 1-st map layout
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            mapLayout1[i][j].drawKey = buildArray1[i][j];
        }
    }

    // Delete buildArra1
    for (int i = 0; i < mapHeight; i++)
    {
        delete[] buildArray1[i];
    }
    delete[] buildArray1;


    // Save 2-nd map layout
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            mapLayout2[i][j].drawKey = buildArray2[i][j];
        }
    }

    // Delete buildArra2
    for (int i = 0; i < mapHeight; i++)
    {
        delete[] buildArray2[i];
    }
    delete[] buildArray2;

    // Save 3-rd map layout
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            mapLayout3[i][j].drawKey = buildArray3[i][j];
        }
    }

    // Delete buildArra3
    for (int i = 0; i < mapHeight; i++)
    {
        delete[] buildArray3[i];
    }
    delete[] buildArray3;

    // Update the currect form of the map, based on the currentMapLayout variable
    switch (currentMapLayout)
    {
    case 1:
        // Update the form of the map to the 1-st layout
        for (int i = 0; i < mapHeight; i++)
        {
            for (int j = 0; j < mapWidth; j++)
            {
                currentMapForm[i][j].drawKey = mapLayout1[i][j].drawKey;
            }
        }

        break;
    case 2:
        // Update the form of the map to the 2-nd layout
        for (int i = 0; i < mapHeight; i++)
        {
            for (int j = 0; j < mapWidth; j++)
            {
                currentMapForm[i][j].drawKey = mapLayout2[i][j].drawKey;
            }
        }
        break;
    case 3:
        // Update the form of the map to the 3-rd layout
        for (int i = 0; i < mapHeight; i++)
        {
            for (int j = 0; j < mapWidth; j++)
            {
                currentMapForm[i][j].drawKey = mapLayout3[i][j].drawKey;
            }
        }
        break;
    }

    // Temporary additionals placement
    for (int i = 0; i < mapHeight; i++)
    {
        for (int j = 0; j < mapWidth; j++)
        {
            if (currentMapForm[i][j].drawKey == true)
            {
                chance = GetRandomValue(0, 6);
                if (chance == 0)
                {
                    currentMapForm[i][j].spKey = true;
                }
                else if (chance == 4)
                {
                    currentMapForm[i][j].grassKey = true;
                }

            }
        }
    }

    // Randomize different types of objects
    for (int i = 0; i < 50; i++)
    {
        int num = GetRandomValue(0, 1);
        if (num == 0)
        {
            objectStorage[i] = 0;

        }
        else if (num == 1)
        {
            objectStorage[i] = 1;
        }
    }

    storeTexturePosition(currentMapForm, mapWidth, mapHeight, mapBlockSize, objectStorage, objectCounter, objectType, textureStorage);

    // Create hitboxes for objects on map
    applyObjectHitBox(currentMapForm, mapWidth, mapHeight, mapBlockSize, objectStorage, objectHitbox, objectCounter, objectType);

    //Main game loop
    while (!WindowShouldClose())
    {
        mousePointer = GetScreenToWorld2D(GetMousePosition(), playerCamera);
        inventoryPos = GetScreenToWorld2D(Vector2{ float(GetScreenWidth()) - 110, float(GetScreenHeight()) - 110}, playerCamera);
        taskPos = GetScreenToWorld2D(Vector2{ float(GetScreenWidth()) - 590, float(GetScreenHeight()) - 120 }, playerCamera);
        
        // Create movement for player and position inventory and task blocks
        if (IsKeyDown(KEY_A))
        {
            player.CordinatesX -= playerSpeed;
            // Handle inventory and task left offset
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 114, float(screenHeight) - 110 }, playerCamera);
            taskPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 594, float(screenHeight) - 120 }, playerCamera);
           
        }
        if (IsKeyDown(KEY_D))
        {   
            player.CordinatesX += playerSpeed;
            // Handle inventory and task right offset
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 106, float(screenHeight) - 110 }, playerCamera);
            taskPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 586, float(screenHeight) - 120 }, playerCamera);
        }
        if (IsKeyDown(KEY_W))
        {

            player.CordinatesY -= playerSpeed;
            // Handle inventory and task forwards offset
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 110, float(screenHeight) - 114 }, playerCamera);
            taskPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 590, float(screenHeight) - 124 }, playerCamera);
        }
        if (IsKeyDown(KEY_S))
        {
            player.CordinatesY += playerSpeed;
            // Handle inventory and task backwards offset
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 110, float(screenHeight) - 106 }, playerCamera);
            taskPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 590, float(screenHeight) - 116 }, playerCamera);
        }

        // Ensure that that the inventory blocks and the task block stick to the bottom right corner
        if (IsKeyDown(KEY_A) && IsKeyDown(KEY_W))
        {
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 114, float(screenHeight) - 114 }, playerCamera);
            taskPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 594, float(screenHeight) - 124 }, playerCamera);
        }
        if (IsKeyDown(KEY_A) && IsKeyDown(KEY_S))
        {
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 114, float(screenHeight) - 106 }, playerCamera);
            taskPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 594, float(screenHeight) - 116 }, playerCamera);
        }
        if (IsKeyDown(KEY_D) && IsKeyDown(KEY_W))
        {
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 106, float(screenHeight) - 114 }, playerCamera);
            taskPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 586, float(screenHeight) - 124 }, playerCamera);
        }
        if (IsKeyDown(KEY_D) && IsKeyDown(KEY_S))
        {
            inventoryPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 106, float(screenHeight) - 106 }, playerCamera);
            taskPos = GetScreenToWorld2D(Vector2{ float(screenWidth) - 586, float(screenHeight) - 116 }, playerCamera);
        }

        // check what direction the playerr moves
        if (IsKeyPressed(KEY_A))
        {
            player.direction = 1;
        }
        else if (IsKeyPressed(KEY_D))
        {
            player.direction = 2;
        }
        else if (IsKeyPressed(KEY_W))
        {
            player.direction = 3;
        }
        else if (IsKeyPressed(KEY_S))
        {
            player.direction = 4;
        }

        // Make playerCamera follow player
        playerCamera.target.x = player.CordinatesX;
        playerCamera.target.y = player.CordinatesY;

        for (int i = 0; i < 100; i++)
        {
            if (CheckCollisionPointRec(mousePointer, objectHitbox[i]))
            {
                if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
                {
                    if (objectType[i] == 1)
                    {
                        objectHitbox[i] = { -2000, -2000 };
                        textureStorage[i] = { -2000, -2000 };
                        requiredItems[0] += itemRock;
                    }
                    else if (objectType[i] == 2)
                    {
                        objectHitbox[i] = { -2000, -2000 };
                        textureStorage[i] = { -2000, -2000 };
                        requiredItems[1] += itemWood;
                    }
                }
            }
        }

        if (cTask == 1)
        {
            currentTask = taskCollect1;
        }
        else if (cTask == 2)
        {
            currentTask = taskCollect2;
        }
        else if (cTask == 3)
        {
            currentTask = taskCollect3;
        }
        else if (cTask == 4)
        {
            currentTask = taskCraft1;
        }
        else if (cTask == 5)
        {
            currentTask = taskCraft1;
        }
        else if (cTask == 6)
        {
            currentTask = taskMine;
        }

        // Begin Render
        BeginDrawing();

        BeginMode2D(playerCamera);

        // Set background color
        ClearBackground(waterBlue);

        // Draw map
        drawMap(currentMapForm, mapWidth, mapHeight, mapBlockSize, grass, water, rock, tree1, grassTexture, objectStorage, objectHitbox, objectCounter, objectType, textureStorage);

        drawPlayer(player);
        
        // Check for keyboard input for drawing the inventory
        if (!drawInventory)
        { 
            if (IsKeyPressed(KEY_E))
            {
                drawInventory = true;
            }
        }
        else
        {
            if (IsKeyPressed(KEY_E))
            {
                drawInventory = false;
            }
        }

        if (drawInventory == true)
        {
            // Draw inventory blocks
            for (int i = 0; i < 6; i++)
            {
                DrawTextureEx(itemBorder, Vector2{ inventoryPos.x, inventoryPos.y - float(28 * i) }, 0, float(0.25), RAYWHITE);
            }

            // Draw axe tool
            DrawTextureEx(axe, Vector2{ inventoryPos.x + 3, inventoryPos.y + 2}, 0, 0.1, RAYWHITE);
            DrawRectangle(inventoryPos.x + 1, inventoryPos.y - float(28), pickaxe.width * 0.135, pickaxe.height * 0.135, BLANK);

            // Draw pickaxe tool
            DrawTextureEx(pickaxe, Vector2{inventoryPos.x + 3, inventoryPos.y - float(25)}, 0, 0.1, RAYWHITE);
            DrawRectangle(inventoryPos.x+1, inventoryPos.y, pickaxe.width * 0.135, pickaxe.height * 0.135, BLANK); 

            // Draw wood item
            DrawTextureEx(woodItem, Vector2{ inventoryPos.x, inventoryPos.y - 56}, 0, float(0.2), RAYWHITE);
            DrawText(TextFormat("%i", requiredItems[1]), inventoryPos.x + float(18), inventoryPos.y - float(41), 4, WHITE);

            /*DrawTextureEx();
            DrawText();  stick */

            // Draw stone item
            DrawTextureEx(stoneItem, Vector2{ inventoryPos.x + float(2.5), inventoryPos.y - float(109) }, 0, float(0.15), RAYWHITE);
            DrawText(TextFormat("%i", requiredItems[0]), inventoryPos.x + float(18), inventoryPos.y - float(97), 4, WHITE);

            /*DrawTextureEx();
            DrawText();  iron */ 
        }

        // Check for keyboard input for equipping the axe
        if (!isAxeEquipped)
        {
            if (IsKeyPressed(KEY_ONE))
            {
                isAxeEquipped = true;
            }
        }
        else
        {
            if (IsKeyPressed(KEY_ONE))
            {
                isAxeEquipped = false;
            }
        }

        // Check for keyboard input for equipping the pickaxe
        if (!isPickaxeEquipped)
        {
            if (IsKeyPressed(KEY_TWO))
            {
                isPickaxeEquipped = true;
            }
        }
        else
        {
            if (IsKeyPressed(KEY_TWO))
            {
                isPickaxeEquipped = false;
            }
        }

        // Draw equipped item indicator
        drawEquippedItem(itemBorder, pickaxe, axe, inventoryPos, isPickaxeEquipped, isAxeEquipped);

        // Check for keyboard input for drawing the current task
        if (!drawTask)
        {
            if (IsKeyPressed(KEY_Q))
            {
                drawTask = true;
            }
        }
        else
        {
            if (IsKeyPressed(KEY_Q))
            {
                drawTask = false;
            }
        }

        if (drawTask == true)
        {
            DrawTextureEx(taskBorder, Vector2{ taskPos.x, taskPos.y }, 0, float(0.14), RAYWHITE);
            DrawText(currentTask, taskPos.x + float(3), taskPos.y + float(10), 2, BLACK);
        }


        EndMode2D();
        //spawnCreatures(zombiesCounter, zombies);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}