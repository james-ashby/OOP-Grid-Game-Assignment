#pragma once

#include "raylib.h"
#include "Game.h"
#include "Source.h"
class Source {
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
};
