#include "../includes/wolf.h"

static void  init_sideDist(t_raycast *rc)
{
      if(rc->rayDirX < 0)
      {
        rc->stepX = -1;
        rc->sideDistX = (rc->posX - rc->mapX) * rc->deltaDistX;
      }
      else
      {
        rc->stepX = 1;
        rc->sideDistX = (rc->mapX + 1.0 - rc->posX) * rc->deltaDistX;
      }
      if(rc->rayDirY < 0)
      {
        rc->stepY = -1;
        rc->sideDistY = (rc->posY - rc->mapY) * rc->deltaDistY;
      }
      else
      {
        rc->stepY = 1;
        rc->sideDistY = (rc->mapY + 1.0 - rc->posY) * rc->deltaDistY;
      }
}

static void  perform_DDA(t_raycast *rc, int **map)
{
      while (rc->hit == 0)
      {
        if(rc->sideDistX < rc->sideDistY)
        {
            rc->sideDistX += rc->deltaDistX;
            rc->mapX += rc->stepX;
            rc->side = 0;
        }
        else
        {
            rc->sideDistY += rc->deltaDistY;
            rc->mapY += rc->stepY;
            rc->side = 1;
        }
        if (map[rc->mapX][rc->mapY] > 0)
            rc->hit = 1;
      }
}

static void  kinit_rc(t_env *e, t_raycast *rc)
{
      rc->cameraX = 2 * rc->x / (double)WIDTH - 1;
      rc->rayPosX = rc->posX;
	rc->rayPosY = rc->posY;
      rc->rayDirX = rc->dirX + rc->planeX * rc->cameraX;
      rc->rayDirY = rc->dirY + rc->planeY * rc->cameraX;
      rc->mapX = (int)(rc->posX);
      rc->mapY = (int)(rc->posY);
      rc->deltaDistX = sqrt(1 + (rc->rayDirY * rc->rayDirY)
			/ (rc->rayDirX * rc->rayDirX));
	rc->deltaDistY = sqrt(1 + (rc->rayDirX * rc->rayDirX)
			/ (rc->rayDirY * rc->rayDirY));
      rc->hit = 0;
      init_sideDist(rc);
      perform_DDA(rc, e->map);
      if(rc->side == 0)
            rc->perpWallDist = (rc->mapX - rc->posX + (1 - rc->stepX) / 2)
                  / rc->rayDirX;
      else
            rc->perpWallDist = (rc->mapY - rc->posY + (1 - rc->stepY) / 2)
                  / rc->rayDirY;
}

void ray_cast(t_env *e, t_raycast *rc)
{
      rc->x = -1;
      while(++rc->x < WIDTH)
      {
            kinit_rc(e, rc);
            rc->lineHeight = (int)(HEIGHT / rc->perpWallDist);
            rc->drawStart = -rc->lineHeight / 2 + HEIGHT / 2;
            if(rc->drawStart < 0)
                  rc->drawStart = 0;
            rc->drawEnd = rc->lineHeight / 2 + HEIGHT / 2;
            if(rc->drawEnd >= HEIGHT)
                  rc->drawEnd = HEIGHT - 1;
            if (rc->side == 1)
      		rc->color = 0xdd8800;
      	else
      		rc->color = 0x00FF00;
            draw_wall(rc, rc->drawStart - 1, rc->drawEnd, e);
      }
/*
    //timing for input and FPS counter
    rc->oltime = rc->time;
    rc->time = getTicks();
    frameTime = (rc->time - rc->oltime) / 1000.0; //frameTime is the rc->time this frame has taken, in seconds
    print(1.0 / rc->frameTime); //FPS counter
    redraw();
    cls();

    //speed modifiers
    double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

    readKeys();
    //move forward if no wall in front of you
    if(keyDown(SDLK_UP))
    {
      if(worldMap[int(posX + rc->dirX * moveSpeed)][int(posY)] == false) rc->posX += rc->dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY + rc->dirY * moveSpeed)] == false) rc->posY += rc->dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if(keyDown(SDLK_DOWN))
    {
      if(worldMap[int(posX - rc->dirX * moveSpeed)][int(posY)] == false) rc->posX -= rc->dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY - rc->dirY * moveSpeed)] == false) rc->posY -= rc->dirY * moveSpeed;
    }
    //rotate to the right
    if(keyDown(SDLK_RIGHT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = rc->dirX;
      rc->dirX = rc->dirX * cos(-rotSpeed) - rc->dirY * sin(-rotSpeed);
      rc->dirY = oldDirX * sin(-rotSpeed) + rc->dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - rc->planeY * sin(-rotSpeed);
      rc->planeY = oldPlaneX * sin(-rotSpeed) + rc->planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if(keyDown(SDLK_LEFT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = rc->dirX;
      rc->dirX = rc->dirX * cos(rotSpeed) - rc->dirY * sin(rotSpeed);
      rc->dirY = oldDirX * sin(rotSpeed) + rc->dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - rc->planeY * sin(rotSpeed);
      rc->planeY = oldPlaneX * sin(rotSpeed) + rc->planeY * cos(rotSpeed);
}*/
}
