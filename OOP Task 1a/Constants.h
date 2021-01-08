#pragma once

// the size of the grid
#define SIZE      10

// symbols used for storing where things are
#define PLAYER    'P'
#define HOLE      'H'
#define WALL      'W'
#define FLOOR     'F'

// the command letters to move the mouse on the maze
#define KEY_RIGHT 262
#define KEY_LEFT  263
#define KEY_DOWN  264
#define KEY_UP    265

#define MAP1 {\
{\
    { 'F','F','F','F','F','F','F','F','F','F' },\
    { 'F','F','F','F','F','F','F','F','F','F' },\
    { 'F','F','F','W','W','W','F','F','F','H' },\
    { 'F','F','F','W','F','W','F','F','F','H' },\
    { 'F','F','F','W','F','W','W','F','F','F' },\
    { 'F','F','F','W','F','F','F','F','F','F' },\
    { 'F','F','F','W','W','W','W','F','F','F' },\
    { 'F','F','F','F','F','F','F','F','F','F' },\
    { 'F','F','P','F','F','F','F','F','F','F' },\
    { 'F','F','F','F','F','F','F','F','F','F' }\
}\
              }