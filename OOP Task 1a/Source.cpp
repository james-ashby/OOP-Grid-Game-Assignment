#include "raylib.h"
#include "Game.h"
#include "Source.h"

int main()
{
    InitWindow(900, 600, "OOP Assignment 1");
    SetTargetFPS(60);

    Texture2D maptiles = LoadTexture("./assets/mapTiles.png");

    float frameWidth = (float)(maptiles.width / 16);
    float frameHeight = (float)(maptiles.width / 16);

    Game game;
    game.Setup();
    InitAudioDevice();              // Initialize audio device

    Music music = LoadMusicStream("./assets/gamemusic.mp3");
    bool pause = false;
    PlayMusicStream(music);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(SKYBLUE);
        auto currentLevel = game.PrepareGrid(game.CurrentLevelMap()); // TODO: maybe look into const currentLevel
        UpdateMusicStream(music);

        if (game.IsRunning())
        {
            if (IsKeyPressed(KEY_RIGHT))  game.ProcessInput(KEY_RIGHT, currentLevel);
            if (IsKeyPressed(KEY_LEFT))   game.ProcessInput(KEY_LEFT, currentLevel);
            if (IsKeyPressed(KEY_UP))     game.ProcessInput(KEY_UP, currentLevel);
            if (IsKeyPressed(KEY_DOWN))   game.ProcessInput(KEY_DOWN, currentLevel);
            if (IsKeyPressed(KEY_P))
            {
                pause = !pause;

                if (pause) PauseMusicStream(music);
                else ResumeMusicStream(music);
            }
            currentLevel = game.PrepareGrid(game.CurrentLevelMap());
            game.LevelRemoveKey();

            if (game.LevelComplete())
            {
                game.ChangeLevel();
                currentLevel = game.PrepareGrid(game.CurrentLevelMap());
            }
        }
        else
        {
            DrawText("OUT OF LIVES\n GAME OVER", 610, 100, 35, RED);
        }
        const int cellSize = (int)((float)GetScreenHeight() / (float)(SIZE));


        for (int x = 0; x < SIZE; x++)
        {
            for (int y = 0; y < SIZE; y++)
            {
                int xPosition = x * cellSize;
                int yPosition = y * cellSize;

                switch (currentLevel[y][x])
                {
                    case FLOOR:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, DARKGREEN);
                                 DrawTextureRec(maptiles, Rectangle{ 0,0,frameWidth, frameHeight }, Vector2{ (float)xPosition, (float)yPosition }, RAYWHITE); break;
                    case WALL:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, LIGHTGRAY); break;
                    case PLAYER: DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);     break;
                    case HOLE:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK);     break;
                    case KEY:    DrawRectangle(xPosition, yPosition, cellSize, cellSize, GOLD);      break;
                    case DOOR:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, BROWN);      break;
                    default:     assert(false);  // if this hits you probably forgot to add your new tile type :)
                }

                // draw lines around each tile, remove this if you don't like it!
               DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY);
            }
        }
        DrawText(FormatText("Lives = %i", game.player.GetLives()), 610, 50, 40, RED);
        DrawText(FormatText("Score = %i", game.GetScore()),610, 10, 40, GOLD);
        DrawText(FormatText("Level = %i", game.GetCurrentLevel()), 610, 90, 40, GREEN);
        DrawText(FormatText("Keys = %i", game.player.GetKeys()), 610, 130, 40, BLUE);
        DrawText("Press P\nto pause/unpause\nmusic ", 610, 400, 30, BLACK);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}