#include <SDL2/SDL.h>
#include "plateau.h"
#include "SDL2_gfxPrimitives.h"
void Accueil(SDL_Renderer* pinceau)
{
    // Fond bleu
        SDL_SetRenderDrawColor(pinceau, 240, 251, 251, 255);
        SDL_RenderClear(pinceau);
        // Bouton JOUER
    SDL_Rect btn_jouer = {200, 200, 200, 60};
    // Bouton HELP
    SDL_Rect btn_help = {200, 300, 200, 60};
   SDL_SetRenderDrawColor(pinceau, 0, 0, 0, 255);
    SDL_RenderFillRect(pinceau,& btn_jouer);
    SDL_RenderFillRect(pinceau,& btn_help);

}
