//
// Created by Josean Camarena on 04/05/23.
//

#ifndef PLAYER_ANIMATION_SPRITE_H
#define PLAYER_ANIMATION_SPRITE_H

#include "raylib.h"

typedef struct sprite
{
  Texture2D texture;
  Rectangle mask;
  int animation_steps;
}Sprite;

Sprite CreateSprite(char *texture_path, int steps);
void RenderSprite(Sprite s, Vector2 position);
Sprite UpdateSprite(Sprite s);

#endif //PLAYER_ANIMATION_SPRITE_H
