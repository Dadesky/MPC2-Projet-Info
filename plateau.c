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
//int z1=-1;int z2=-1;
int tour=1;
int temoin=0;
extern pion A[7][7];
// fonction pour un pion
void soldat( SDL_Renderer* pinceau, int x , int y,int cR,int cB,int x1,int y1)
{ int a,b,k; a=30; b=15;
  int off=A[x1][y1].officier;
  int nc= A[x1][y1].prise;
  int cb=cB; int cr=cR;

if (off==0) // pas encore officier
   {
     if (nc==0) //pas de prise
   {filledEllipseRGBA(pinceau,x,y,a,b,cR,0,cB,255);// ellipse base
    aaellipseRGBA(pinceau,x,y,a,b,0,0,0,255);// contour ellipse base
    filledEllipseRGBA(pinceau,x,y-10,a,b,cR,0,cB,255);// second ellipse
    aaellipseRGBA(pinceau,x,y-10,a,b,0,0,0,255);// contour second ellipse
    SDL_SetRenderDrawColor(pinceau,0,0,0,255);// choix couleur ligne
    SDL_RenderDrawLine(pinceau,x-a,y-10,x-a,y);// ligne a gauche
    SDL_RenderDrawLine(pinceau,x+a,y-10,x+a,y);}//ligne a droite
   else
   {for(k=0;k<=nc;k++)
     {  if (k<nc)
       { if (A[x1][y1].pile[k].joueur!=A[x1][y1].joueur)
       {filledEllipseRGBA(pinceau,x,y-k*10,a,b,cb,0,cr,255);// ellipse base couleur inverse
        aaellipseRGBA(pinceau,x,y-k*10,a,b,0,0,0,255);}// contour ellipse base
        else {filledEllipseRGBA(pinceau,x,y-k*10,a,b,cr,0,cb,255);// ellipse base couleur inverse
        aaellipseRGBA(pinceau,x,y-k*10,a,b,0,0,0,255);}// contour ellipse base}
      }


     else
    {filledEllipseRGBA(pinceau,x,y-nc*10,a,b,cr,0,cb,255);// ellipse base couleur joueur
     aaellipseRGBA(pinceau,x,y-nc*10,a,b,0,0,0,255);// contour ellipse base
     filledEllipseRGBA(pinceau,x,y-nc*10-10,a,b,cr,0,cb,255);// second ellipse
     aaellipseRGBA(pinceau,x,y-nc*10-10,a,b,0,0,0,255);// contour second ellipse
     SDL_SetRenderDrawColor(pinceau,0,0,0,255);// choix couleur ligne
     SDL_RenderDrawLine(pinceau,x-a,y-nc*10,x-a,y);// ligne a gauche
     SDL_RenderDrawLine(pinceau,x+a,y-nc*10-10,x+a,y);}//ligne a droite*/
    }
   }
 }
  else
  {if (nc==0) //pas de prise
   {filledEllipseRGBA(pinceau,x,y,a,b,cR,0,cB,255);// ellipse base
    aaellipseRGBA(pinceau,x,y,a,b,0,0,0,255);// contour ellipse base
    filledEllipseRGBA(pinceau,x,y-10,a,b,cR,0,cB,255);// second ellipse
    aaellipseRGBA(pinceau,x,y-10,a,b,0,0,0,255);// contour second ellipse
    filledEllipseRGBA(pinceau,x,y-10,10,5,255,215,0,255);// ellipse or
    aaellipseRGBA(pinceau,x,y-10,10,5,255,215,0,255);// ellipse or
    SDL_SetRenderDrawColor(pinceau,0,0,0,255);// choix couleur ligne
    SDL_RenderDrawLine(pinceau,x-a,y-10,x-a,y);// ligne a gauche
    SDL_RenderDrawLine(pinceau,x+a,y-10,x+a,y);}//ligne a droite
   else
   {for(k=0;k<=nc;k++)
     {  if (k<nc)
       { if (A[x1][y1].pile[k].joueur!=A[x1][y1].joueur)
       {filledEllipseRGBA(pinceau,x,y-k*10,a,b,cb,0,cr,255);// ellipse base couleur inverse
        aaellipseRGBA(pinceau,x,y-k*10,a,b,0,0,0,255);}// contour ellipse base
        else {filledEllipseRGBA(pinceau,x,y-k*10,a,b,cr,0,cb,255);// ellipse base couleur inverse
        aaellipseRGBA(pinceau,x,y-k*10,a,b,0,0,0,255);}// contour ellipse base}
      }


     else
    {filledEllipseRGBA(pinceau,x,y-nc*10,a,b,cr,0,cb,255);// ellipse base couleur joueur
     aaellipseRGBA(pinceau,x,y-nc*10,a,b,0,0,0,255);// contour ellipse base
     filledEllipseRGBA(pinceau,x,y-nc*10-10,a,b,cr,0,cb,255);// second ellipse
     aaellipseRGBA(pinceau,x,y-nc*10-10,a,b,0,0,0,255);// contour second ellipse
     filledEllipseRGBA(pinceau,x,y-nc*10-10,10,5,255,215,0,255);// ellipse or
     aaellipseRGBA(pinceau,x,y-nc*10-10,10,5,255,215,0,255);// ellipse or
     SDL_SetRenderDrawColor(pinceau,0,0,0,255);// choix couleur ligne
     SDL_RenderDrawLine(pinceau,x-a,y-nc*10,x-a,y);// ligne a gauche
     SDL_RenderDrawLine(pinceau,x+a,y-nc*10-10,x+a,y);}//ligne a droite*/
    }
   }

  }
}



void ligne(SDL_Renderer* pinceau)
{
    int i, j;
    // fond gris dans la page plateau
SDL_SetRenderDrawColor(pinceau,128,128,128,255);SDL_RenderClear(pinceau);
 // Bouton QUITTER
   SDL_Rect btn_quit = {0, 0, 60, 60}; SDL_Rect btn_j = {350, 0, 60, 20};
   SDL_SetRenderDrawColor(pinceau,0,0,0,255);
   SDL_RenderFillRect(pinceau,&btn_quit);
   if (tour==1){ SDL_SetRenderDrawColor(pinceau,0,0,255,255);  SDL_RenderFillRect(pinceau,&btn_j);}
   else { SDL_SetRenderDrawColor(pinceau,255,0,0,255);SDL_RenderFillRect(pinceau,&btn_j);}


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
                soldat(pinceau,posx,posy,0,255,i,j);}
             else
            if(A[i][j].joueur==2)
                {
                soldat(pinceau,posx,posy,255,0,i,j);}

        }
    }
}

}


void selection(SDL_Renderer*pinceau, SDL_Event event)
{ int i,j,posx,posy,px,py;
    px=event.button.x ;
    py=event.button.y;
for (i=0;i<=6;i++)
 {for (j=0;j<=6;j++)
      {if((i+j)%2==0)
        {pos_case(i,j,&posx,&posy);
     float res=(px-posx)*(px-posx)/(float)3600 + ((py-posy)*(py-posy)/(float)1600);// formule ellipse
     if ( res<=1)// verifier si clic dans ellipse
       { if (A[i][j].joueur==tour)
           {
            if (temoin==1 && (i!=sel_i || j!=sel_j))
            { SDL_Log(" Joueur %d peut encore manger", tour);return;}
             SDL_Log("joueur %d a selectionne", tour);sel_i = i;sel_j = j; return;
           }

       if (A[i][j].joueur==0 && sel_i!=-1 && sel_j!=-1) // si joueur a deja clic et clic dans un espace vide
       {
         int ok= v_deplacement(sel_i,sel_j,i,j,tour);
         int ob= obligation(tour);
           if(ok==1)
           {
            if(ob==1)
             {
              printf("vous devez manger");
              sel_i=-1;sel_j=-1;
              return;
             }

                A[i][j]=A[sel_i][sel_j];grade (i,j);
                A[sel_i][sel_j].officier=0;
                A[sel_i][sel_j].joueur=0 ;
                A[sel_i][sel_j].prise=0;

                tour=(tour==1)?2:1;
                temoin=0;
                sel_i=-1;sel_j=-1; return;

           }
        else if(ok==2)
           {  A[i][j]=A[sel_i][sel_j]; gestion(sel_i,sel_j,i,j);grade (i,j);
             A[sel_i][sel_j].officier=0;
              A[sel_i][sel_j].joueur=0 ;
              A[sel_i][sel_j].prise=0;
              if (toujou(i,j,tour))
                { temoin=1;
                  sel_i=i;sel_j=j;
                  return;
                }
                temoin=0;
              tour=(tour==1)?2:1;

              sel_i=-1;sel_j=-1; return;
           }

       }

     }
    }
  }
}
    sel_i=-1;sel_j=-1; temoin =0;
}

int v_deplacement(int x1,int y1,int x2,int y2,int player)
{  int vrai=0;
   int dl=x2-x1;
   int dc=y2-y1;
   int adv=((player==1)? 2: 1);
   int off=A[x1][y1].officier;
   int mx=(x2+x1)/2;
   int my=(y2 +y1)/2;
   int dir= ((player==1)? 1 : -1);
  // pour un pion Normal
     if (!off)
   {

       if ((dl==dir) && (dc==1 || dc==-1))
      vrai=1;// deplacement simple


    if ((dl==2*dir) && (dc==2 || dc==-2))
      {
        if (A[mx][my].joueur==adv ) {vrai=2;}// on peut manger + deplacement
      }
    }
    // pour les officiers
      else
    {if (abs(dl)==1 && abs(dc)==1)
      vrai=1; // Officier deplace librement

      if (abs(dl)==2 && abs(dc)==2)
      { if (A[mx][my].joueur==adv) vrai=2;// on peut manger + deplacement libre
      }
    }
    return vrai;
    }

void pos_case(int i, int j, int*x,int*y)
{*x=margew+(j*taille_case)+(taille_case/2);
 *y=margeh+(i*taille_case)+(taille_case/2);

}

void gestion(int x1, int y1 , int x2, int y2)
{  // reperage du mafia en Question
     int mx= (x1+x2)/2;
     int my= (y1+y2)/2;

     // creation du Komandan pour capturer le mafia
     prison policier;
     policier.joueur= A[mx][my].joueur;
     policier.officier= A[mx][my].officier;

     // si le mafia avait des complices
     if ( A[mx][my].prise>0)
     { // le chef second devient le nouveau mafia
     A[mx][my].joueur=A[mx][my].pile[0].joueur;
     A[mx][my].officier= A[mx][my].pile[0].officier;
     // il commande ses surbodonées
     for(int k=0; k<A[mx][my].prise-1;k++)
       A[mx][my].pile[k]= A[mx][my].pile[k+1];

       A[mx][my].prise--;
     }
     else
     {     // si ce mafia agissait en solo,  le gang est demantelé
     A[mx][my].joueur=0;
     A[mx][my].officier=0;
     A[mx][my].prise=0;
     }

  // enfin le mafia en Question est mise en garde a vue.
   A[x2][y2].pile[A[x2][y2].prise]= policier;
   A[x2][y2].prise++;
}


void grade(int x1, int y1)
 {
     if (A[x1][y1].joueur==1 && x1==6)
     {
         A[x1][y1].officier=1;
         SDL_Log("le joueur 1 a un officier");return;
     }
     if (A[x1][y1].joueur==2 && x1==0)
     {
         A[x1][y1].officier=1;
         SDL_Log("le joueur 2 a un officier");return;
     }

 }


int obligation(int joueur)
{
	int i,j;
int adv= (joueur==2)?1:2;
int direc=(joueur==1)?1:-1;
int alez=(joueur==1)?-1:1;
for(i=0;i<=6;i++)
{ for(j=0;j<=6;j++)
 {
  if( A[i][j].joueur==joueur )
  {
     if((i+2*direc>=0&&i+2*direc<=6)&&(j+2>=0&&j+2<=6))
     {
  	if((A[i+direc][j+1].joueur==adv)&&(A[i+2*direc][j+2].joueur==0))  return 1;
     }

if((i+2*direc>=0&&i+2*direc<=6)&&(j-2>=0&&j-2<=6))
      {
  	if((A[i+direc][j-1].joueur==adv)&&(A[i+2*direc][j-2].joueur==0)) return 1;
      }
 	       if(A[i][j].officier==1)
 	       {


if((i+2*alez>=0 && i+2*alez<=6)&&(j+2>=0 && j+2<=6))
 	    {
 if((A[i+alez][j+1].joueur==adv)&&(A[i+2*alez][j+2].joueur==0)) return 1;
 	    }
 if((i+2*alez>=0 && i+2*alez<=6)&&(j-2>=0 && j-2<=6))
 	           {
 if((A[i+alez][j-1].joueur==adv)&&(A[i+2*alez][j-2].joueur==0)) return 1;
  	          }
    	    }

  	}
   }
 }
return 0;
}

int toujou(int x1, int y1, int joueur)
{    int adv=((joueur==1)? 2: 1);
     int dir=((joueur==1)? 1:-1);
     int alez=(joueur==1)?-1:1;
      //verifions diagonales gauches et droites
      if (x1+2*dir>=0 && x1+2*dir<=6 && y1-2>=0 && y1-2<= 6 )
          {if (A[x1+dir][y1-1].joueur==adv && A[x1+2*dir][y1-2].joueur==0) return 1;}
          if (x1+2*dir>=0 && x1+2*dir<=6 &&y1+2>=0 && y1+2<= 6 )
            {if (A[x1+dir][y1+1].joueur==adv && A[x1+2*dir][y1+2].joueur==0) return 1;}

      if (A[x1][y1].officier==1)
      {if (x1+2*alez>=0 && x1+2*alez<=6 && y1-2>=0 && y1-2<= 6 )
        {if (A[x1+alez][y1-1].joueur==adv && A[x1+2*alez][y1-2].joueur==0) return 1;}

      if (x1+2*alez>=0 && x1+2*alez<=6 &&y1+2>=0 && y1+2<= 6 )
          {if (A[x1+alez][y1+1].joueur==adv && A[x1+2*alez][y1+2].joueur==0) return 1;}

      }


      return 0;
}

void init()
{  sel_i=-1;
   sel_j=-1;
   tour=1;
    int i,j;
    for(i=0; i<=6;i++)
    { for (j=0; j<=6; j++)
      {  for (int n=0; n<11; n++)
            {A[i][j].pile[n].joueur=0;
             A[i][j].pile[n].officier=0;
            }
          A[i][j].officier=0;
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
}







