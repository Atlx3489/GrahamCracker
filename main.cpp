#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>

/*std::istream& lets me reference an input
example: std::istream& = std::cin;*/

int main() {
//test  test test
    int screen_width = 750, screen_height = 750;

    bool isRunning = true;
/* //Code to Allow the User to Manually Alter the window resolution
    std::cout << "Input a Screen Width as an Integer: \n" << std::endl;

    if(!(std::cin >> screen_width)) {
        return -1;
    }

    std::cout << "Input a Screen Height as an Integer: \n" << std::endl;

    if(!(std::cin >> screen_height)){
        return -1;
    } */

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "SDL_INIT_EVERYTHING could not initialize" << std::endl;
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("GrahamCracker", 100, 100, screen_width, screen_height, SDL_WINDOW_SHOWN);

    if (!window) {
        std::cout << "SDL_CreateWindow could not create window" << std::endl;
        return -1;
    }

    SDL_Surface *windowsurface = SDL_GetWindowSurface(window);

    SDL_Event keyboardHandler;


    //don't define declared variables inside a loop unless you intend for it to stay at the set value OR you intend to set it to static(?)
    int rectX = 50, rectY = 50;
    //int prevRectX = NULL, prevRectY = NULL; /*Potential Use Later*/




    while (isRunning) {
        while (SDL_PollEvent(&keyboardHandler)) {
            switch (keyboardHandler.type /*Potentially add a && to try new methods for this mess*/) {
                case SDL_KEYDOWN:
                    switch (keyboardHandler.key.keysym.sym) {
                        case SDLK_UP:
                            //prevRectY = rectY; /*Potential Use Later*/
                            rectY -= 50;
                            printf("UP Pressed\n");
                        break;
                        case SDLK_DOWN:
                            //prevRectY = rectY; /*Potential Use Later*/
                            rectY += 50;
                            printf("DOWN Pressed\n");
                        break;
                        case SDLK_LEFT:
                            //prevRectX = rectX; /*Potential Use Later*/
                            rectX -= 50;
                            printf("LEFT Pressed\n");
                        break;
                        case SDLK_RIGHT:
                            //prevRectX = rectX; /*Potential Use Later*/
                            rectX += 50;
                            printf("RIGHT Pressed\n");
                        break;
                        case SDLK_ESCAPE:
                            isRunning = false;
                        break;
                    }
                break;
                case SDL_KEYUP:
                    switch (keyboardHandler.key.keysym.sym) {
                        case SDLK_UP:
                            printf("UP Depressed\n");
                        break;
                        case SDLK_DOWN:
                            printf("DOWN Depressed\n");
                        break;
                        case SDLK_LEFT:
                            printf("LEFT Depressed\n");
                        break;
                        case SDLK_RIGHT:
                            printf("RIGHT Depressed\n");
                        break;
                    }
                break;
            }
        }

        SDL_Rect rect(rectX ,rectY, 100, 100);

        SDL_FillRect(windowsurface, NULL, SDL_MapRGB(windowsurface->format, 0, 0, 0));

        SDL_FillRect(windowsurface, &rect, SDL_MapRGB(windowsurface->format, 255, 90, 120));

        SDL_UpdateWindowSurface(window);
    }
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.