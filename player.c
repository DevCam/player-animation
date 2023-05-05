//
// Created by Josean Camarena on 04/05/23.
//

#include "player.h"
#include "math.h"

Player LoadPlayer()
{
  Player p;

  p.sprites[IDLE] = CreateSprite("../Assets/idle.png", 10);
  p.sprites[MOVING] = CreateSprite("../Assets/run.png", 8);
  p.sprites[JUMPING] = CreateSprite("../Assets/jump.png", 3);

  p.state = IDLE;
  p.position = (Vector2) {250, 250};
  p.speed = (Vector2) {0,0};

  return p;
}

Player update_sprite_state(Player p); // funcion privada para actualizar los sprites

Player UpdatePlayer(Player p, int input[])
{
  switch (p.state) {
    case IDLE:
      if(input[0] == true || input[1] == true)
        p.state = MOVING;
      if(input[2] == true)
        p.state = JUMPING;
      break;

    case MOVING:
        if(input [0] == false && input[1] == false)
          p.state = IDLE;
        if(input[2] == true)
          p.state = JUMPING;
      break;
    case JUMPING:
      break;
  }

  if(input[0] == true) {
    p.speed.x = 3;
  }
  else if(input[1] == true) {
    p.speed.x = -3;

  }
  else
    p.speed.x = 0;

  p.position.x += p.speed.x;
  p.position.y += p.speed.y;

  p = update_sprite_state(p);

  return p;
}

Player update_sprite_state(Player p)
{
  if (p.speed.x < 0) {
    // player was/is moving left!
    for(int i = 0; i < 3; i++)
      p.sprites[i].mask.width = -1 * fabsf(p.sprites[i].mask.width); // tenemos que actualizar TODAS las mascaras
      // quizá sería mas facil tener UNA sola mascara :(
  }

  if (p.speed.x > 0) {
    for(int i = 0; i < 3; i++)
      p.sprites[i].mask.width = fabsf(p.sprites[i].mask.width); // tenemos que actualizar TODAS las mascaras
    // player was/is moving right!
  }

  // TODO : si ven , cuando el usuario BRINCA todo se rompe, eso les tocará a ustedes :)

  p.sprites[p.state] = UpdateSprite(p.sprites[p.state]);
  return p;
}

void DrawPlayer(Player p)
{
  RenderSprite(p.sprites[p.state], p.position);
}
