//
// Created by Josean Camarena on 04/05/23.
//

#include "sprite.h"

Sprite CreateSprite(char *texture_path, int steps)
{
  Sprite new_sprite;

  new_sprite.texture = LoadTexture(texture_path);
  new_sprite.animation_steps = steps;
  Rectangle mask = {0,0,new_sprite.texture.width/steps,new_sprite.texture.height};
  new_sprite.mask = mask;

  return new_sprite;
}

void RenderSprite(Sprite s, Vector2 position)
{
  DrawTextureRec(s.texture, s.mask,  position, WHITE);
}

Sprite UpdateSprite(Sprite s)
{
  s.mask.x += s.texture.width / s.animation_steps;
  s.mask.x = (int)s.mask.x % s.texture.width;
  return s;
}
