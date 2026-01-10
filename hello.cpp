#include <iostream>
#include <SDL.h>


class button{
	private:
		SDL_Rect rectangle;
		SDL_Color color;

	public:
		button(int x, int y, int width, int height, SDL_Color c){
			rectangle = {x, y, width, height};
			color = c;
		}


		void draw_button(SDL_Renderer* prenderer){

			SDL_SetRenderDrawColor(prenderer, color.r, color.g, color.b, color.a);
			SDL_RenderFillRect(prenderer, &rectangle);
		}

		void move(int x){
			rectangle.x += x;
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

		button button_1 = button(x, 200, 50, 50, {0, 0, 255, 255});
		button_1.draw_button(prenderer);
	

		button button_2 = button(100, 200, 50, 50, {100, 0, 100, 255});
		button_2.draw_button(prenderer);
		
		SDL_RenderPresent(prenderer);

		x += 1;

		if(x >= 550){
			x = 0;
		}
	
	}



	
	SDL_DestroyRenderer(prenderer);
        SDL_DestroyWindow(pwindow); 
     	SDL_Quit();
			
}
