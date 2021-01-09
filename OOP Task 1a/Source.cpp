#include "raylib.h"
#include "Game.h"

int main()
{
    InitWindow(900, 600, "OOP Assignment 1");
    SetTargetFPS(60);

    Game game;
    game.Setup();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);
        const auto grid = game.PrepareGrid(); // Can change this to currentLevel i.e current grid based on level
                                              // ^ for this we would need to make the game class include a vector/array of 2d vectors, one for each level (vector<level> levels[0]) 
                                              // Could do it using what we have, vector<vector<char>>[] / vector<vector<vector<char>>> or create a level class and use vector<level> or level[]

        if (game.IsRunning())
        {
            if (IsKeyPressed(KEY_RIGHT))  game.ProcessInput(KEY_RIGHT, grid);
            if (IsKeyPressed(KEY_LEFT))   game.ProcessInput(KEY_LEFT, grid);
            if (IsKeyPressed(KEY_UP))     game.ProcessInput(KEY_UP, grid);
            if (IsKeyPressed(KEY_DOWN))   game.ProcessInput(KEY_DOWN, grid);
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

                switch (grid[y][x])
                {
                    case FLOOR:  DrawRectangle(xPosition, yPosition, cellSize, cellSize, DARKGREEN); break;
                    case WALL:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, LIGHTGRAY); break;
                    case PLAYER: DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);     break;
                    case HOLE:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK);     break;
                    case KEY:    DrawRectangle(xPosition, yPosition, cellSize, cellSize, GOLD);      break;
                    case DOOR:    DrawRectangle(xPosition, yPosition, cellSize, cellSize, BROWN);      break;
                    default:     assert(false);  // if this hits you probably forgot to add your new tile type :)
                }

                // draw lines around each tile, remove this if you don't like it!
               DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY);
            }
        }
        DrawText(FormatText("Lives = %i", game.player.GetLives()), 610, 50, 40, LIGHTGRAY);
        DrawText(FormatText("Score = %i", game.getScore()),610, 10, 40, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}