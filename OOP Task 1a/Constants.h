#pragma once

// the size of the grid
#define SIZE      20

// symbols used for storing where things are
#define PLAYER    'P'
#define HOLE      'H'
#define WALL      'W'
#define FLOOR     'F'
#define KEY       'K'

// the command letters to move the mouse on the maze
#define KEY_RIGHT 262
#define KEY_LEFT  263
#define KEY_DOWN  264
#define KEY_UP    265

//10x10 map
#define MAP1 {\
{\
    { 'F','F','F','F','W','F','F','F','F','F' },\
    { 'F','F','F','F','F','F','F','F','F','F' },\
    { 'F','F','F','W','W','W','F','F','F','H' },\
    { 'F','F','F','W','F','W','F','F','F','H' },\
    { 'W','F','F','W','F','W','W','F','F','F' },\
    { 'F','F','F','W','F','F','F','F','F','F' },\
    { 'F','F','F','W','W','W','W','F','F','F' },\
    { 'F','F','F','F','F','F','F','F','F','F' },\
    { 'F','F','P','F','F','F','F','F','F','F' },\
    { 'F','F','F','F','F','W','F','F','F','F' }\
}\
              }

//20x20 map
#define MAP2 {\
{\
    { 'F','F','F','F','W','F','F','F','F','F','F','F','F','F','W','F','F','F','F','F' },\
    { 'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F' },\
    { 'F','F','F','W','W','W','F','F','F','H','F','F','F','F','F','F','F','F','F','W' },\
    { 'F','F','F','W','F','W','F','F','F','H','F','F','F','F','F','F','F','F','F','F' },\
    { 'W','F','F','W','F','W','W','F','F','F','W','F','F','F','F','F','F','F','F','F' },\
    { 'F','F','F','W','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F' },\
    { 'F','F','F','W','W','W','W','F','F','F','F','F','F','F','F','F','F','F','F','F' },\
    { 'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F' },\
    { 'F','F','P','F','F','F','F','F','F','F','F','F','P','F','F','F','F','F','F','F' },\
    { 'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','W','F','F','F','W' },\
    { 'F','F','F','F','F','F','F','F','F','F','F','F','F','F','W','F','F','F','F','F' },\
    { 'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F' },\
    { 'F','F','F','F','F','F','F','F','F','H','F','F','F','W','W','W','F','F','F','F' },\
    { 'F','F','F','F','F','F','F','F','F','H','F','F','F','W','F','W','F','F','F','F' },\
    { 'W','F','F','F','F','F','F','F','F','F','W','F','F','W','F','W','W','F','F','F' },\
    { 'F','F','F','F','F','F','F','F','F','F','F','F','F','W','F','F','F','F','F','F' },\
    { 'F','F','F','F','F','F','F','F','F','F','F','F','F','W','W','W','W','F','F','F' },\
    { 'F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','F','W' },\
    { 'F','F','F','F','F','F','F','F','F','F','F','F','P','F','F','F','F','F','F','F' },\
    { 'F','F','F','F','F','W','F','F','F','F','F','F','F','F','F','W','F','F','F','F' }\
}\
              }
