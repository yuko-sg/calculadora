#pragma once
#include </System/Volumes/Data/opt/homebrew/Cellar/sdl2/2.32.10/include/SDL2/SDL.h>

void dibujarCirculo(SDL_Renderer* renderer, int centroX, int centroY, int radio);
void dibujarCirculoRelleno(SDL_Renderer* renderer, int centroX, int centroY, int radio, bool c1, bool c2, bool c3, bool c4);