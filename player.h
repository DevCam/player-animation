//
// Created by Josean Camarena on 04/05/23.
//

#ifndef PLAYER_ANIMATION_PLAYER_H
#define PLAYER_ANIMATION_PLAYER_H

#include "raylib.h"
#include "sprite.h"

typedef enum player_state
{
  IDLE,
  MOVING,
  JUMPING
} PlayerState;

typedef struct player_struct
{
  Vector2 position;
  Vector2 speed;
  PlayerState state;
  Sprite sprites[3];
} Player;

// Load player with default sprites
Player LoadPlayer();

// Update player
Player UpdatePlayer(Player p, int input[]);

// Draw player
void DrawPlayer(Player p);

#endif //PLAYER_ANIMATION_PLAYER_H
