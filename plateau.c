#include <SDL2/SDL.h>
#include "plateau.h"
#include "SDL2_gfxPrimitives.h"
#define H 650
#define L 800
#define margew 120
#define margeh 45
int taille_case=(L - 2*margew)/7;

// fonction pour un pion
void soldat( SDL_Renderer* pinceau, int x , int y,int cR,int cB)
{ int a,b; a=30; b=15;

filledEllipseRGBA(pinceau,x,y,a,b,cR,0,cB,255);// ellipse base
aaellipseRGBA(pinceau,x,y,a,b,0,0,0,255);// contour ellipse base
filledEllipseRGBA(pinceau,x,y-10,a,b,cR,0,cB,255);// second ellipse
aaellipseRGBA(pinceau,x,y-10,a,b,0,0,0,255);// contour second ellipse
SDL_SetRenderDrawColor(pinceau,0,0,0,255);// choix couleur ligne
SDL_RenderDrawLine(pinceau,x-a,y-10,x-a,y);// ligne a gauche

SDL_RenderDrawLine(pinceau,x+a,y-10,x+a,y);

}


void ligne(SDL_Renderer* pinceau)
{
    int i, j;
    // fond gris dans la page plateau
SDL_SetRenderDrawColor(pinceau,128,128,128,255);SDL_RenderClear(pinceau);

     int posx,posy;
     // boucle qui dessine les tous les pions
for (i=0;i<=6;i++)
{for (j=0;j<=6;j++)
     {posx=margew+(j*taille_case)+(taille_case/2); posy=margeh+(i*taille_case)+(taille_case/2);
       if (i==3 && ((i+j)%2==0)){filledEllipseRGBA(pinceau,posx,posy,60,40,255,255,255,255);aaellipseRGBA(pinceau,posx,posy,60,40,255,255,255,255);}
     if ((i<=2) && (i+j)%2==0){filledEllipseRGBA(pinceau,posx,posy,60,40,255,255,255,255);aaellipseRGBA(pinceau,posx,posy,60,40,255,255,255,255); soldat(pinceau,posx,posy,0,255);}
     else
     if((i>=4) && (i+j)%2==0){filledEllipseRGBA(pinceau,posx,posy,60,40,255,255,255,255);aaellipseRGBA(pinceau,posx,posy,60,40,255,255,255,255);soldat(pinceau,posx,posy,255,0);}
     }
  }

}
