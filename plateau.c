#include <SDL2/SDL.h>
#include "plateau.h"
#include "SDL2_gfxPrimitives.h"
#define H 650
#define L 800
#define margew 120
#define margeh 45
#include <math.h>
int taille_case=(L - 2*margew)/7;
int sel_i;
int sel_j;
int tour=1;
extern pion A[7][7];
// fonction pour un pion
void soldat( SDL_Renderer* pinceau, int x , int y,int cR,int cB,int nc)
{ int a,b,k,i,j; a=30; b=15;
  if (nc==0)// si pas encore de prises
    A[i][j].officier=1;
      filledEllipseRGBA(pinceau,x,y,a,b,cR,0,cB,255);// ellipse base
aaellipseRGBA(pinceau,x,y,a,b,0,0,0,255);// contour ellipse base
filledEllipseRGBA(pinceau,x,y-10,a,b,cR,0,cB,255);// second ellipse
aaellipseRGBA(pinceau,x,y-10,a,b,0,0,0,255);// contour second ellipse
SDL_SetRenderDrawColor(pinceau,0,0,0,255);// choix couleur ligne
SDL_RenderDrawLine(pinceau,x-a,y-10,x-a,y);// ligne a gauche
SDL_RenderDrawLine(pinceau,x+a,y-10,x+a,y);}//ligne a droite
else
 {for(k=0;k<=nc;k++)
 {  if (k!=nc){filledEllipseRGBA(pinceau,x,y-k*10,a,b,cB,0,cR,255);// ellipse base couleur inverse
aaellipseRGBA(pinceau,x,y-k*10,a,b,0,0,0,255);// contour ellipse base
filledEllipseRGBA(pinceau,x,y-k*10-10,a,b,cB,0,cR,255);// second ellipse
aaellipseRGBA(pinceau,x,y-k*10-10,a,b,0,0,0,255);// contour second ellipse
SDL_SetRenderDrawColor(pinceau,0,0,0,255);// choix couleur ligne
SDL_RenderDrawLine(pinceau,x-a,y-k*10,x-a,y);// ligne a gauche
SDL_RenderDrawLine(pinceau,x+a,y-k*10-10,x+a,y);}//ligne a droite
else
{filledEllipseRGBA(pinceau,x,y-nc*10,a,b,cR,0,cB,255);// ellipse base couleur joueur
aaellipseRGBA(pinceau,x,y-nc*10,a,b,0,0,0,255);// contour ellipse base
filledEllipseRGBA(pinceau,x,y-nc*10-10,a,b,cR,0,cB,255);// second ellipse
aaellipseRGBA(pinceau,x,y-nc*10-10,a,b,0,0,0,255);// contour second ellipse
SDL_SetRenderDrawColor(pinceau,0,0,0,255);// choix couleur ligne
SDL_RenderDrawLine(pinceau,x-a,y-nc*10,x-a,y);// ligne a gauche
SDL_RenderDrawLine(pinceau,x+a,y-nc*10-10,x+a,y);}//ligne a droite*/
 }



 }
 }



void ligne(SDL_Renderer* pinceau)
{
    int i, j;
    // fond gris dans la page plateau
SDL_SetRenderDrawColor(pinceau,128,128,128,255);SDL_RenderClear(pinceau);

     int posx,posy;
     // boucle qui dessine les tous les pions
for(i=0;i<7;i++)
{
    for(j=0;j<7;j++)
    {
        pos_case(i,j,&posx,&posy);

        if(A[i][j].joueur != -1)
        { filledEllipseRGBA(pinceau,posx,posy,60,40,255,255,255,255);
        aaellipseRGBA(pinceau,posx,posy,60,40,255,255,255,255);// On dessine une ellipse blanche

            if(A[i][j].joueur==1)
                {
                soldat(pinceau,posx,posy,0,255,A[i][j].prise);}
             else
            if(A[i][j].joueur==2)
                {
                soldat(pinceau,posx,posy,255,0,A[i][j].prise);}

        }
    }
}  // colorie en vert ou rouge
  for(i=0;i<7;i++)
{ for(j=0;j<7;j++)
  {pos_case(i,j,&posx,&posy);;
      if (i== sel_i && j==sel_j)
      {
        switch(tour)
        {
            case 1: {if (A[i+1][j+1].joueur==0 ||A[i+1][j-1].joueur==0 )
            {
                aaellipseRGBA(pinceau,posx,posy,60,40,0,255,0,255);pos_case(i+1,j-1,&posx,&posy);
                aaellipseRGBA(pinceau,posx,posy,60,40,255,255,0,255);pos_case(i+1,j+1,&posx,&posy);
                aaellipseRGBA(pinceau,posx,posy,60,40,255,255,0,255);
            }else aaellipseRGBA(pinceau,posx,posy,60,40,255,0,0,255);}break;
            case 2: {if (A[i-1][j+1].joueur==0 ||A[i-1][j-1].joueur==0 )
            {
                aaellipseRGBA(pinceau,posx,posy,60,40,0,255,0,255);pos_case(i-1,j+1,&posx,&posy);
                aaellipseRGBA(pinceau,posx,posy,60,40,255,255,0,255);pos_case(i-1,j-1,&posx,&posy);
                aaellipseRGBA(pinceau,posx,posy,60,40,255,255,0,255);
            }
            else aaellipseRGBA(pinceau,posx,posy,60,40,255,0,0,255);}break;

        }

      }
  }
}
 // Bouton QUITTER
   SDL_Rect btn_quit = {0, 0, 60, 60};SDL_RenderFillRect(pinceau, &btn_quit);
}


void selection(SDL_Renderer*pinceau, SDL_Event event)
{

    int i,j,posx,posy,px,py;
    px=event.button.x ;py=event.button.y;
    for (i=0;i<=6;i++)
    {for (j=0;j<=6;j++)
      {if((i+j)%2==0)
        {pos_case(i,j,&posx,&posy);
     float res=(px-posx)*(px-posx)/(float)3600 + ((py-posy)*(py-posy)/(float)1600);// formule ellipse
     if ( res<=1)// verifier si clic dans ellipse
       { if (A[i][j].joueur==tour)
            {SDL_Log("joueur %d  a selectione" ,tour);sel_i=i;sel_j=j; return;}


       if (A[i][j].joueur==0 && sel_i!=-1 & sel_j!=-1) // si joueur a deja clic et clic dans un espace vide
       { int ok= v_deplacement(sel_i,sel_j,i,j,tour);
           if(ok==1)
           {   A[i][j]=A[sel_i][sel_j];
               A[sel_i][sel_j].joueur=0 ;A[sel_i][sel_j].prise=0; tour=(tour==1)?2:1;
            sel_i=-1;sel_j=-1; return;
           }
           else if(ok==2)
           {A[sel_i][sel_j].prise++;
               A[i][j]=A[sel_i][sel_j];
               A[sel_i][sel_j].joueur=0; ; tour=(tour==1)?2:1;
            sel_i=-1;sel_j=-1; return;

           }

       }
     }
    }
  }
}
    sel_i=-1;sel_j=-1;
}

int v_deplacement(int x1,int y1,int x2,int y2,int player)
{  int vrai=0;

  int dl=x2-x1;
  int dc=y2-y1;
  if (player==1)
   {if ((dl==1) && (dc==1 || dc==-1))
      vrai=1;// deplacement simple

    if ((dl==2) && (dc==2 || dc==-2))
      { int mx=(x2+x1)/2;
        int my=(y2 +y1)/2;
        if (A[mx][my].joueur==2 ) {vrai=2;}// on peut manger + deplacement
      }
    }

  if (player==2)
    {if ((dl==-1) && (dc==1 || dc==-1))
      vrai=1;
      if ((dl==-2) && (dc==2 || dc==-2))
      { int mx=(x2+x1)/2;
        int my=(y2 +y1)/2;
        if (A[mx][my].joueur==1) vrai=2;// on peut manger + deplacement
      }
    }
    return vrai;
    }

void pos_case(int i, int j, int*x,int*y)
{*x=margew+(j*taille_case)+(taille_case/2);
 *y=margeh+(i*taille_case)+(taille_case/2);

}
