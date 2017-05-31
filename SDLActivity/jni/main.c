#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <android/log.h>
#include <android/native_activity.h>

#define MY_LOG_LEVEL_VERBOSE 1
#define MY_LOG_LEVEL_DEBUG 2
#define MY_LOG_LEVEL_INFO 3
#define MY_LOG_LEVEL_WARNING 4
#define MY_LOG_LEVEL_ERROR 5
#define MY_LOG_LEVEL_FATAL 6
#define MY_LOG_LEVEL_SILENT 7

#include "SDL.h"


int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;
	
	SDL_Rect *rectangle;
	int w, h;

    if(SDL_CreateWindowAndRenderer(0, 0, 0, &window, &renderer) < 0)
        exit(2);

	SDL_GetWindowSize(window, &w, &h);
    /* Main render loop */
    Uint8 done = 0;
    SDL_Event event;

	int rectX = w /2;
	int rectY = h / 2;
	int rectWidth = 160;
    while(!done)
		{
        /* Check for events */
        while(SDL_PollEvent(&event))
		{
            if(event.type == SDL_FINGERMOTION || event.type == SDL_FINGERDOWN)
			{	
				rectX = event.tfinger.x * w - 80;
				rectY = event.tfinger.y * h - 80;
				__android_log_print(2, "EVENT", "pos : %f - %f",  event.tfinger.x * w, event.tfinger.y * h );
				__android_log_print(2, "EVENT", "pos : %d - %d",  w , h);
            }
        }

		/* Draw background */

		SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
		SDL_RenderClear(renderer);

		/*create rectangle*/
		SDL_Rect rectangle = (SDL_Rect){rectX, rectY, rectWidth, rectWidth};
		rectangle.x = rectX;
		rectangle.y = rectY;

		/*render rectangle*/
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderFillRect(renderer, &rectangle);

		/* Update the screen! */
		SDL_RenderPresent(renderer);

		// SDL_Delay(10);
    }

    exit(0);
}
