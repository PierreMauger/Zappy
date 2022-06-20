/*
** EPITECH PROJECT, 2022
** draw.c
** File description:
** draw
*/

#include "zappy_gui.h"

void draw_map(client_t *client)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            for (int i = 0; i < client->size_map.y; i++) {
                for (int j = 0; j < client->size_map.x; j++) {
                }
            }
        EndDrawing();
    }
    CloseWindow();
}