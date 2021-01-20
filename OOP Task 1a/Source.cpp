#include "raylib.h"
#include "Game.h"
#include "Source.h"

int main()
{
    Image icon = LoadImage("./assets/yodaIcon.png");
    InitWindow(940, 640, "BABA YADA");
    SetWindowIcon(icon);
    SetTargetFPS(60);
    Font titleFont = LoadFontEx("./assets/mainMenu1.ttf", 32, 0, 250);
    Font subtitleFont = LoadFontEx("./assets/mainMenu2.ttf", 32, 0, 250);
    Image babaYadaImg = LoadImage("./assets/yodaSplash.png");
    ImageResize(&babaYadaImg, 300, 230);
    Texture2D babaYada = LoadTextureFromImage(babaYadaImg);
    //NICKY HIGHSCORE 338

    //lots of textures consider a diferent way to load? or something not sure if it's possible other than a sprite sheet.
    Texture2D floorTile = LoadTexture("./assets/floor.png");
    Texture2D wallTile = LoadTexture("./assets/wall.png");
    Texture2D waterTile = LoadTexture("./assets/water.png");
    Texture2D keyTile = LoadTexture("./assets/key2.png");
    Texture2D coinTile = LoadTexture("./assets/nonCopyrightSpaceMetal.png");
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
    int currentCol = 0;
    vector<pair<string, int>> HighScores = move(game.highScoreList.GetHighScoreList());
    game.Setup();
    InitAudioDevice();              // Initialize audio device

    Music menuMusic = LoadMusicStream("./assets/gamemusic.mp3");
    Music gameOverMusic = LoadMusicStream("./assets/gameoverMusic.mp3");
    Music levelMusic = LoadMusicStream("./assets/levelMusic.mp3");
    Sound deathSound = LoadSound("./assets/DeathNoise.mp3");
    Sound gameOverSound = LoadSound("./assets/gameoversound.mp3");

    Sound footstepSound = LoadSound("./assets/footstep01.ogg");
    Sound footstepAltSound = LoadSound("./assets/footstep08.ogg");
    Sound keyPickUpSound = LoadSound("./assets/keypickup.ogg");

    bool pause = false;
    PlayMusicStream(menuMusic);
    while (!WindowShouldClose())
    {
        auto currentLevel = game.PrepareGrid(game.CurrentLevelMap());
        while (!game.IsRunning() && !WindowShouldClose())
        {
            UpdateMusicStream(menuMusic);
            ClearBackground(BROWN);
            DrawTexture(babaYada, 550, 340, WHITE);
            DrawRectangle(50, 180, 520, 115, GRAY);
            DrawTextEx(titleFont, "Baba Yada's\n Adventure", { 5.0f, 25.0f }, 60, 2, GREEN);
            DrawTextEx(subtitleFont, "for\n non-descript\n  space metal", { 60.0f, 200.0f }, 20, 2, BLACK);
            DrawText("Grab the key!\nDodge the spikes!\nEscape the level!", 160, 400, 30, GOLD);
            DrawText("Press Space to Begin!", 80, 550, 40, ORANGE); 
            if (IsKeyPressed(KEY_SPACE))
            {
                StopMusicStream(menuMusic);
                game.StartGame();
            }
            EndDrawing();
        }
        if (game.IsRunning() && !WindowShouldClose())
        {
            ClearBackground(SKYBLUE);
            UpdateMusicStream(levelMusic);
            PlayMusicStream(levelMusic);

            if (IsKeyPressed(KEY_RIGHT)) { PlaySound(keyPickUpSound); game.ProcessInput(KEY_RIGHT, currentLevel); }
            if (IsKeyPressed(KEY_LEFT)) { PlaySound(footstepSound); game.ProcessInput(KEY_LEFT, currentLevel);}
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
            game.LevelRemoveCoin(); //COMBINE THESE FUNCTIONS.

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
                    case FLOOR:  
                        DrawRectangle(xPosition, yPosition, cellSize, cellSize, DARKGREEN);
                        DrawTextureRec(floorTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;
                    case WALL:   
                        DrawRectangle(xPosition, yPosition, cellSize, cellSize, LIGHTGRAY);
                        DrawTextureRec(wallTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;
                    case OCEAN:   
                        DrawRectangle(xPosition, yPosition, cellSize, cellSize, LIGHTGRAY);
                        DrawTextureRec(waterTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;
                    case PLAYER: 
                        DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);
                        if (game.GetPlayerDirection() == 1) { DrawTextureRec(playerFront, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); }
                        else if (game.GetPlayerDirection() == 2) { DrawTextureRec(playerRight, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); }
                        else if (game.GetPlayerDirection() == 3) { DrawTextureRec(playerBack, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); }
                        else { DrawTextureRec(playerLeft, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); } break;
                    case HOLE:   
                        DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK);
                        DrawTextureRec(holeTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;
                    case KEY:
                        DrawRectangle(xPosition, yPosition, cellSize, cellSize, GOLD);
                        DrawTextureRec(keyTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;                    
                    case COIN:
                            DrawRectangle(xPosition, yPosition, cellSize, cellSize, GOLD);
                            DrawTextureRec(coinTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;
                    case DOOR:   
                        DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);
                        if (game.player.GetKeys() != game.GetCurrentLevel()) { DrawTextureRec(doorClosedTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); }
                        else { DrawTextureRec(doorOpenTile, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); } break; //this is a temp fix, i think it can be done better.
                    case SPIKE:  
                        DrawRectangle(xPosition, yPosition, cellSize, cellSize, RED);
                        DrawTextureRec(spikeUp, Rectangle{ 0 ,0 , cellSize, cellSize }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;
                    case SPIKEDOWN:  
                        DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLUE);                                     
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
            DrawText(FormatText("HighScores:"), 650, 170, 40, BLACK);
            int i = 0;
            for (auto &Scores : HighScores)
            {
                i++;
                char a = 65;
                int listPosition = 170 + (30 * (i + 1));
                DrawText(FormatText(": %s, %i", Scores.first.c_str(), Scores.second), 650, listPosition, 30, BLACK);
            }
            DrawText("Press P\nto pause/unpause\nmusic ", 650, 400, 30, BLACK);
        }
        EndDrawing();
        while (!game.IsRunning() && game.player.GetLives() == 0 && !WindowShouldClose())
        {
            
            
            UpdateMusicStream(gameOverMusic);
            PlayMusicStream(gameOverMusic);
            ClearBackground(BLACK);
            DrawText("GAME OVER", 130, 250, 120, RED);
            DrawText("Press F to close", 130, 360, 20, RED);
            EndDrawing();
            if (IsKeyPressed(KEY_F))
            {
                StopMusicStream(gameOverMusic);
                EndDrawing();
                CloseWindow();
            }
        }
        while (!game.IsRunning() && game.player.GetLives() > 0 && !WindowShouldClose())
        {
            ClearBackground(BLUE);
            StopMusicStream(gameOverMusic);
            DrawText("YOU WIN", 260, 200, 120, GOLD);
            DrawText("ENTER NAME", 300, 300, 30, BLACK);

            char col [3];

            for (auto c : col)
            {
                c = 65;
            }


            if (IsKeyPressed(KEY_DOWN))
            {
                col[currentCol]--;
                if (col[currentCol] < 65)
                {
                    col[currentCol] = 90;
                }
            }
            else if (IsKeyPressed(KEY_UP))
            {
                col[currentCol]++;
                if (col[currentCol] > 90)
                {
                    col[currentCol] = 65;
                }

            }
            else if (IsKeyPressed(KEY_LEFT))
            {
                currentCol--;
                if (currentCol < 0)
                {
                    currentCol = 3;
                }

            }
            else if (IsKeyPressed(KEY_RIGHT))
            {
                currentCol++;
                if (currentCol > 3)
                {
                    currentCol = 0;
                }

            }


            if (currentCol == 0)
            {
                DrawText("_", 300, 335, 40, WHITE);
            }
            if (currentCol == 1)
            {
                DrawText("_", 340, 335, 40, WHITE);
            }
            if (currentCol == 2)
            {
                DrawText("_", 380, 335, 40, WHITE);
            }
            if (currentCol == 3)
            {
                DrawText("_", 420, 335, 40, WHITE);
            }

            DrawText(FormatText("%c,%c,%c,%c", col[0], col[1], col[2], col[3]), 300, 330, 40, BLACK);
            DrawText(FormatText("Press F to Submit Score:  %i", game.GetScore()), 300, 370, 40, BLACK);

            if (IsKeyPressed(KEY_F))
            {
                game.highScoreList.AddToHighScoreList(string{ col[0], col[1], col[2], col[3] }, game.GetScore());
                EndDrawing();

            }

            EndDrawing();

        }
    }

    CloseWindow();
    return 0;
}
