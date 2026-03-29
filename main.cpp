#include <iostream>
#include </System/Volumes/Data/opt/homebrew/Cellar/sdl2/2.32.10/include/SDL2/SDL.h>
#include "button.h"



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
	
		
	button boton1 = button (200, 150, 60, 60, {200, 130, 130, 100}, 10);

	button boton2 = button(300, 150, 60, 60, {200, 200, 130, 100}, 10);

	button boton3 = button (400, 150, 60, 60, {200, 130, 130, 100}, 10);

	button boton4 = button(200, 250, 60, 60, {200, 200, 130, 100}, 10);
	
	button boton5 = button (300, 250, 60, 60, {200, 130, 130, 100}, 10);

	button boton6 = button(400, 250, 60, 60, {200, 200, 130, 100}, 10);
	
	button boton7 = button (200, 350, 60, 60, {200, 130, 130, 100}, 10);

	button boton8 = button(300, 350, 60, 60, {200, 200, 130, 100}, 10);

	button boton9 = button (400, 350, 60, 60, {200, 130, 130, 100}, 10);

	button boton0 = button(300, 450, 60, 60, {200, 130, 130, 100}, 10);

	//aqui se dibuja el entorno, esto es lo que se repite constantemente.
	while(corriendo == true){

		while(SDL_PollEvent(&evento)){
			if(evento.type == SDL_QUIT){
				corriendo = false;	
			}
			boton0.isClicked(evento);

		}

		SDL_SetRenderDrawColor(prenderer, 0, 0, 0, 255);
		SDL_RenderClear(prenderer);


        boton1.draw_button(prenderer);
		boton2.draw_button(prenderer);
        boton3.draw_button(prenderer);
        boton4.draw_button(prenderer);
        boton5.draw_button(prenderer);
        boton6.draw_button(prenderer);
        boton7.draw_button(prenderer);
        boton8.draw_button(prenderer);
        boton9.draw_button(prenderer);
        boton0.draw_button(prenderer);

		SDL_RenderPresent(prenderer);
	
	}
	
	SDL_DestroyRenderer(prenderer);
        SDL_DestroyWindow(pwindow); 
     	SDL_Quit();
			
}



