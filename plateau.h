void soldat( SDL_Renderer* pinceau, int x , int y,int cR,int cB,int x1,int y1);
void ligne(SDL_Renderer* pinceau);
void selection(SDL_Renderer*pinceau, SDL_Event event);
void Accueil(SDL_Renderer* pinceau);
void pos_case(int i, int j, int*x,int*y);
int v_deplacement(int x1,int y1,int x2,int y2,int joueur);
int obligation(int joueur);
void gestion(int x1, int y1 , int x2, int y2);
void grade(int x1 , int y1);
int toujou(int x1, int y1, int joueur);
typedef struct
{int officier; int joueur}prison;

typedef struct
{int joueur;int officier;int prise; prison pile[11]}pion;
