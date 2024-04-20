#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define GRAVITY 0.25
#define FLAP_FORCE -5

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* birdTexture = NULL;
SDL_Rect birdRect;
int birdVelocity = 0;

void init() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Flappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface* surface = IMG_Load("bird.png");
    birdTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    birdRect.x = SCREEN_WIDTH / 4 - 20;
    birdRect.y = SCREEN_HEIGHT / 2 - 20;
    birdRect.w = 40;
    birdRect.h = 40;
}

void cleanup() {
    SDL_DestroyTexture(birdTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            exit(0);
        }
        if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_SPACE) {
                birdVelocity = FLAP_FORCE;
            }
        }
    }
}

void update() {
    birdVelocity += GRAVITY;
    birdRect.y += birdVelocity;
}

void render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, birdTexture, NULL, &birdRect);
    SDL_RenderPresent(renderer);
}

int main(int argc, char* args[]) {
    init();
    while (1) {
        handleEvents();
        update();
        render();
        SDL_Delay(10);
    }
    cleanup();
    return 0;
}
