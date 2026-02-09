#include <iostream>
#include <SDL.h>

void dibujarCirculo(SDL_Renderer* renderer, int centroX, int centroY, int radio);

void dibujarCirculoRelleno(SDL_Renderer* renderer, int centroX, int centroY, int radio, bool c1, bool c2, bool c3, bool c4);

class button{
	private:
		SDL_Rect rectangle;
		SDL_Rect rectangle_h;
		SDL_Rect rectangle_w;
		SDL_Color color;
		int rradio;

	public:
		button(int x, int y, int width, int height, SDL_Color c, int radio){
			rectangle_h = {((x-(width/2))+radio), (y-(height/2)), (width-(radio*2)), height};
			rectangle_w = {(x-(width/2)), ((y-(height/2))+radio), width, (height-(radio*2))};
			color = c;
			rectangle = {x, y, width, height};
			rradio = radio;
		}


		void draw_button(SDL_Renderer* prenderer){

			SDL_SetRenderDrawColor(prenderer, color.r, color.g, color.b, color.a);
			SDL_RenderFillRect(prenderer, &rectangle_h);
			SDL_RenderFillRect(prenderer, &rectangle_w);
		
			dibujarCirculoRelleno(prenderer, (rectangle.x+(rectangle_h.w/2)), (rectangle.y-(rectangle_w.h/2))-1, rradio, true, false, false, false);
			dibujarCirculoRelleno(prenderer, 300, 300, rradio, false, true, false, false);
			dibujarCirculoRelleno(prenderer, 300, 300, rradio, false, false, true, false);
			dibujarCirculoRelleno(prenderer, 300, 300, rradio, false, false, false, true);
		}

	};

int main(){

	SDL_Window* pwindow = SDL_CreateWindow("calculadora", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 600, 0);
	
	if(!pwindow){
		std::cout << "no jala" << std::endl;
	}

		
	SDL_Renderer* prenderer = SDL_CreateRenderer(pwindow, -1, SDL_RENDERER_ACCELERATED);
	
	SDL_Surface* psurface = SDL_GetWindowSurface(pwindow);
	SDL_FillRect(psurface, NULL, 0xFF00FF);
	
	SDL_Event evento;
	bool corriendo = true;

	int x = 0;		
	
	//aqui se dibuja el entorno, esto es lo que se repite constantemente.
	while(corriendo == true){
		while(SDL_PollEvent(&evento)){
			if(evento.type == SDL_QUIT){
				corriendo = false;	
			}
		}

		SDL_SetRenderDrawColor(prenderer, 0, 0, 0, 255);
		SDL_RenderClear(prenderer);
	
		SDL_Rect rectangle = {100, 100, 50, 50}; 
		SDL_SetRenderDrawColor(prenderer, 255, 0, 0, 255);
		SDL_RenderFillRect(prenderer, &rectangle);

		dibujarCirculo(prenderer, 400, 50, 30);

		dibujarCirculoRelleno(prenderer, 300, 300, 20, true, false, true, false);
		
		button button_1 = button(x, 200, 50, 50, {0, 0, 255, 255}, 10);
		button_1.draw_button(prenderer);
	

		button button_2 = button(100, 200, 50, 50, {100, 0, 100, 255}, 5);
		button_2.draw_button(prenderer);
		
		SDL_RenderPresent(prenderer);


		x += 1;

		if(x >= 1100){
			x = 0;
		}
	
	}
	
	SDL_DestroyRenderer(prenderer);
        SDL_DestroyWindow(pwindow); 
     	SDL_Quit();
			
}

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



