#include <stdio.h>
#include "raylib.h"
#include "player.h"

void GetUserInput(int[]);
void DrawStateInformation(Player p, int input[]);

int main()
{
  InitWindow(500, 500, "TestGame");

  SetTargetFPS(16);

  Player p = LoadPlayer();
  int user_input[3] = {0};

  while (!WindowShouldClose())
  {
    // Get User input
    GetUserInput(user_input);

    p = UpdatePlayer(p, user_input);

    BeginDrawing();
      ClearBackground(BLACK);
      DrawStateInformation(p, user_input);
      DrawPlayer(p);

    EndDrawing();
  }
}

void GetUserInput(int result[])
{
    result[0] = IsKeyDown(KEY_RIGHT);
    result[1] = IsKeyDown(KEY_LEFT);
    result[2] = IsKeyDown(KEY_SPACE);
}

// Esta funcion no se molesten en hacerla bonita, esta hardcodeado para que dibujen la info que quieran!
// la informacion que puse aqui es solo de ejemplo

void DrawStateInformation(Player p, int input[])
{
  DrawRectangleLines(0, 0, 340,80, PURPLE);
  DrawText(TextFormat("Player <X, Y>: <%f, %f>", p.position.x, p.position.y), 10, 10, 10, WHITE);
  switch (p.state) {
    case IDLE:
      DrawText("IDLE", 10, 25, 10, WHITE);
      break;
    case MOVING:
      DrawText("MOVING", 10, 25, 10, WHITE);
      break;
    case JUMPING:
      DrawText("JUMPING", 10, 25, 10, WHITE);
      break;
  }

  if(input[0])
    DrawText("R", 10, 40, 15, RED); // RIGHT!
  if(input[1])
    DrawText("L", 20, 40, 15, RED); // LEFT!
  if(input[2])
    DrawText("S", 30, 40, 15, RED); // SPACE!

  DrawText(TextFormat("Mask Info <X, Y> [WIDTH] <%f, %f> [%f]",
                      p.sprites[p.state].mask.x,
                      p.sprites[p.state].mask.y,
                      p.sprites[p.state].mask.width
                      ), 10, 55, 10, WHITE);
}
