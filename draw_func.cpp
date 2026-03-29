#include "draw_func.h"

void dibujarCirculo(SDL_Renderer* renderer, int centroX, int centroY, int radio) {
    int x = radio - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radio << 1);

    while (x >= y) {
        // Se dibujan los 8 octantes del círculo simultáneamente
        SDL_RenderDrawPoint(renderer, centroX + x, centroY + y);
//        SDL_RenderDrawPoint(renderer, centroX + y, centroY + x);
//        SDL_RenderDrawPoint(renderer, centroX - y, centroY + x);
//        SDL_RenderDrawPoint(renderer, centroX - x, centroY + y);
//        SDL_RenderDrawPoint(renderer, centroX - x, centroY - y);
//        SDL_RenderDrawPoint(renderer, centroX - y, centroY - x);
//        SDL_RenderDrawPoint(renderer, centroX + y, centroY - x);
//        SDL_RenderDrawPoint(renderer, centroX + x, centroY - y);


     //esto normaliza el resultado para que dibuje el contorno del circulo correctamente:
        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        }
        if (err > 0) {
            x--;
            dx += 2;
            err += dx - (radio << 1);
        }
    }
}

void dibujarCirculoRelleno(SDL_Renderer* renderer, int centroX, int centroY, int radio, bool c1, bool c2, bool c3, bool c4) {
    int x = radio - 1;
    int y = 0;
    int dx = 1;
    int dy = 1;
    int err = dx - (radio << 1);

    while (x >= y) {

        // Cuadrante 1: Superior Derecha (X+, Y-)
        if (c1) {
            SDL_RenderDrawLine(renderer, centroX, centroY - y, centroX + x, centroY - y);
            SDL_RenderDrawLine(renderer, centroX, centroY - x, centroX + y, centroY - x);
        }
        // Cuadrante 2: Superior Izquierda (X-, Y-)
        if (c2) {
            SDL_RenderDrawLine(renderer, centroX - x, centroY - y, centroX, centroY - y);
            SDL_RenderDrawLine(renderer, centroX - y, centroY - x, centroX, centroY - x);
        }
        // Cuadrante 3: Inferior Izquierda (X-, Y+)
        if (c3) {
            SDL_RenderDrawLine(renderer, centroX - x, centroY + y, centroX, centroY + y);
            SDL_RenderDrawLine(renderer, centroX - y, centroY + x, centroX, centroY + x);
        }
        // Cuadrante 4: Inferior Derecha (X+, Y+)
        if (c4) {
            SDL_RenderDrawLine(renderer, centroX, centroY + y, centroX + x, centroY + y);
            SDL_RenderDrawLine(renderer, centroX, centroY + x, centroX + y, centroY + x);
        }


        if (err <= 0) {
            y++;
            err += dy;
            dy += 2;
        }
        if (err > 0) {
            x--;
            dx += 2;
            err += dx - (radio << 1);
        }
    }

}

