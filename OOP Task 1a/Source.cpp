#include "raylib.h"
#include "Game.h"
#include "Source.h"

int main()
{
    Image icon = LoadImage("./assets/yodaIcon.png");
    InitWindow(940, 640, "[GAME NAME]");
    SetWindowIcon(icon);
    SetTargetFPS(60);

    //lots of textures consider a diferent way to load? or something not sure if it's possible other than a sprite sheet.
    Texture2D floorTile = LoadTexture("./assets/floor.png");
    Texture2D wallTile = LoadTexture("./assets/wall.png");
    Texture2D waterTile = LoadTexture("./assets/water.png");
    Texture2D keyTile = LoadTexture("./assets/key2.png");
    Texture2D spikeUp = LoadTexture("./assets/spikeUp.png");
    Texture2D spikeDown = LoadTexture("./assets/spikeDown.png");
    Texture2D holeTile = LoadTexture("./assets/hole.png"); //yes i did use the hole emoji
    Texture2D doorClosedTile = LoadTexture("./assets/doorClosed.png");
    Texture2D doorOpenTile = LoadTexture("./assets/doorOpen.png");
    Texture2D playerFront = LoadTexture("./assets/YodaBack.png");
    Texture2D playerRight = LoadTexture("./assets/YodaRight.png");
    Texture2D playerBack = LoadTexture("./assets/YodaFront.png"); //remind me to change the names
    Texture2D playerLeft = LoadTexture("./assets/YodaLeft.png");
    

    Game game;
    int lives = game.player.GetLives();
    game.Setup();
    InitAudioDevice();              // Initialize audio device

    Music menuMusic = LoadMusicStream("./assets/gamemusic.mp3");
    Music levelMusic = LoadMusicStream("./assets/levelMusic.mp3");
    Sound deathSound = LoadSound("./assets/DeathNoise.mp3");
    Sound footstepSound = LoadSound("./assets/footstep01.ogg");
    Sound footstepAltSound = LoadSound("./assets/footstep08.ogg");
    Sound keyPickUpSound = LoadSound("./assets/keypickup.ogg");

    bool pause = false;
    PlayMusicStream(menuMusic);
    while (!WindowShouldClose())
    {
        auto currentLevel = game.PrepareGrid(game.CurrentLevelMap());
        while (!game.IsRunning())
        {
            UpdateMusicStream(menuMusic);
            ClearBackground(SKYBLUE);
            DrawText("Press Spacebar to Begin!", 80, 350, 60, ORANGE); 
            EndDrawing();
            if (IsKeyPressed(KEY_SPACE))
            {
                StopMusicStream(menuMusic);

                game.StartGame();
            }
        }
        if (game.IsRunning())
        {
            ClearBackground(SKYBLUE);
            UpdateMusicStream(levelMusic);
            PlayMusicStream(levelMusic);

            if (IsKeyPressed(KEY_RIGHT)) { PlaySound(keyPickUpSound); game.ProcessInput(KEY_RIGHT, currentLevel); }
            if (IsKeyPressed(KEY_LEFT)) { PlaySound(footstepSound); game.ProcessInput(KEY_LEFT, currentLevel);
        }
            if (IsKeyPressed(KEY_UP)) { PlaySound(footstepAltSound); game.ProcessInput(KEY_UP, currentLevel); }
            if (IsKeyPressed(KEY_DOWN)) { PlaySound(footstepSound); game.ProcessInput(KEY_DOWN, currentLevel); }
            if (IsKeyPressed(KEY_P))
            {
                pause = !pause;

                if (pause) PauseMusicStream(levelMusic);
                else ResumeMusicStream(levelMusic);
            }
            if (game.player.GetLives() < lives)
            {
                lives--;
                PlaySound(deathSound);
            }
            currentLevel = game.PrepareGrid(game.CurrentLevelMap());
            game.LevelRemoveKey();

            if (game.LevelComplete())
            {
                game.ChangeLevel();
                currentLevel = game.PrepareGrid(game.CurrentLevelMap());
            }
            //const int cellSize = (int)((float)GetScreenHeight() / (float)(SIZE));
            //set size to 32 as it fits the sprites better.
            const int cellSize = 32;


            for (int x = 0; x < SIZE; x++)
            {
                for (int y = 0; y < SIZE; y++)
                {
                    int xPosition = x * cellSize;
                    int yPosition = y * cellSize;

                    switch (currentLevel[y][x])
                    {
                    case FLOOR:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, DARKGREEN);
                        DrawTextureRec(floorTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;
                    case WALL:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, LIGHTGRAY);
                                 DrawTextureRec(wallTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;
                    case OCEAN:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, LIGHTGRAY);
                                  DrawTextureRec(waterTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;
                    case PLAYER: DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);
                        if (game.GetPlayerDirection() == 1) { DrawTextureRec(playerFront, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); }
                        else if (game.GetPlayerDirection() == 2) { DrawTextureRec(playerRight, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); }
                        else if (game.GetPlayerDirection() == 3) { DrawTextureRec(playerBack, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); }
                        else { DrawTextureRec(playerLeft, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); }
                        break;
                    case HOLE:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK);
                        DrawTextureRec(holeTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;
                    case KEY:    DrawRectangle(xPosition, yPosition, cellSize, cellSize, GOLD);
                        DrawTextureRec(keyTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;
                    case DOOR:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);
                        //this is a temp fix, i think it can be done better.
                        if (game.player.GetKeys() != game.GetCurrentLevel()) { DrawTextureRec(doorClosedTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); }
                        else { DrawTextureRec(doorOpenTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); }
                        break;
                    case SPIKE:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, RED);
                                 DrawTextureRec(spikeUp, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;
                    case SPIKEDOWN:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLUE); 
                                     DrawTextureRec(spikeDown, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;

                    default:     assert(false);  // if this hits you probably forgot to add your new tile type :)
                    }

                    // draw lines around each tile, remove this if you don't like it!
                   //DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY); Disabled it for now to test how textures will look.
                }
            }
            DrawText(FormatText("Lives = %i", game.player.GetLives()), 650, 50, 40, RED);
            //can add heart sprites here if we want to.
            DrawText(FormatText("Score = %i", game.GetScore()), 650, 10, 40, GOLD);
            DrawText(FormatText("Level = %i", game.GetCurrentLevel()), 650, 90, 40, GREEN);
            DrawText(FormatText("Keys = %i", game.player.GetKeys()), 650, 130, 40, BLUE);
            DrawText("Press P\nto pause/unpause\nmusic ", 650, 400, 30, BLACK);
        }
        else
        {
            if (game.player.GetLives() == 0)
            {
                DrawText("OUT OF LIVES\n GAME OVER", 650, 300, 35, RED);
            }
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}