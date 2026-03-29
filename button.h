#include </System/Volumes/Data/opt/homebrew/Cellar/sdl2/2.32.10/include/SDL2/SDL.h>
#include "draw_func.h"

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
			dibujarCirculoRelleno(prenderer, (rectangle.x-(rectangle_h.w/2))-1, (rectangle.y-(rectangle_w.h/2))-1, rradio, false, true, false, false);
			dibujarCirculoRelleno(prenderer, (rectangle.x-(rectangle_h.w/2))-1, (rectangle.y+(rectangle_w.h/2)), rradio, false, false, true, false);
			dibujarCirculoRelleno(prenderer, (rectangle.x+(rectangle_h.w/2)), (rectangle.y+(rectangle_w.h/2)), rradio, false, false, false, true);
		}

		void isClicked(SDL_Event event){
        	if (event.type == SDL_MOUSEBUTTONDOWN) {
            
				int width_max = rectangle.x + (rectangle.w/2);
				int width_min = rectangle.x - (rectangle.w/2);
				int height_max = rectangle.y + (rectangle.h/2);
				int height_min = rectangle.y - (rectangle.h/2);

				// Revisar qué botón se presionó
				if (event.button.button == SDL_BUTTON_LEFT) {
					if((event.button.x >= width_min && event.button.x <= width_max) && (event.button.y >= height_min && event.button.y <= height_max)){
					std::cout << "Clic izquierdo en: " 
							<< event.button.x << ", " 
							<< event.button.y << std::endl;
					}
				} 
				else if (event.button.button == SDL_BUTTON_RIGHT) {
					std::cout << "Clic derecho detectado." << std::endl;
				}
			}

		}
		
};