#include <SDL2/SDL.h>
#include <stdio.h>
#include<stdbool.h>
#include "plateau.h"
#include "SDL2_gfxPrimitives.h"

#define H 650
#define L 800
#define margew 120
#define margeh 45
#define taille_case (L - 2*margew) / 7;
extern sel_i;sel_j;
void ligne(SDL_Renderer*);
 pion A[7][7];
int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_VIDEO)!=0) return 1;
    int i,j;
    for(i=0; i<=6;i++)
    { for (j=0; j<=6; j++)
      {  A[i][j].officier=1;
         A[i][j].prise=0;
          if ((i+j)%2!=0) A[i][j].joueur=-1;
         else
         {if (i<=2) A[i][j].joueur=1;
         else
            if( i>=4) A[i][j].joueur=2;
             else A[i][j].joueur=0;
         }

      }

    }
    SDL_Window* window = SDL_CreateWindow("EESAIE",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,L, H,SDL_WINDOW_SHOWN);

    SDL_Renderer* pain = SDL_CreateRenderer(
        window, -1, SDL_RENDERER_ACCELERATED);
// Bouton JOUER
    SDL_Rect btn_jouer = {200, 200, 200, 60};
    // Bouton HELP
    SDL_Rect btn_help = {200, 300, 200, 60};
    // Bouton QUITTER
   SDL_Rect btn_quit = {0, 0, 60, 60};
    int etat = 0;
    Accueil(pain);
    SDL_Event event;
   bool run=true;
    while(run)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
        {case SDL_QUIT: run = false; break;
         case SDL_MOUSEBUTTONDOWN:
            {   int px = event.button.x;
                int py = event.button.y;
                if(etat == 0)
                {
                    // Clic JOUER
                    if(px>=btn_jouer.x && px<=btn_jouer.x+btn_jouer.w &&
                       py>=btn_jouer.y && py<=btn_jouer.y+btn_jouer.h)
                        { // initialisation de selection
                            sel_i=-1; sel_j=-1;etat = 1;}

                    // Clic HELP
                    if(px>=btn_help.x && px<=btn_help.x+btn_help.w &&
                       py>=btn_help.y && py<=btn_help.y+btn_help.h)
                        etat = 2;

                }else
                if (etat==1)
                { //Clic QUITTER
                    if(px>=btn_quit.x && px<=btn_quit.x+btn_quit.w &&
                       py>=btn_quit.y && py<=btn_quit.y+btn_quit.h)
                        etat = 0;
                        else
                        selection(pain,event);
                }
              } break;
              case SDL_KEYDOWN:
            { // Retour au menu avec ECHAP
                if(event.key.keysym.sym == SDLK_SPACE)
                    etat = 0; break;
             break;
        }
      }


        if(etat == 0)
        Accueil(pain);
        else
        if(etat == 1)
        {   SDL_SetRenderDrawColor(pain, 0, 0, 0, 255);SDL_RenderClear(pain);
            ligne(pain);
        }

        if(etat == 2)
        {SDL_SetRenderDrawColor(pain, 20, 255, 200, 255);SDL_RenderClear(pain);}
        }
        SDL_RenderPresent(pain);

    }

    SDL_DestroyRenderer(pain);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
    }
