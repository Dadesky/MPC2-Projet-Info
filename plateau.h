void soldat( SDL_Renderer* pinceau, int x , int y,int cR,int cB,int nc);
void ligne(SDL_Renderer* pinceau);
void selection(SDL_Renderer*pinceau, SDL_Event event);
void Accueil(SDL_Renderer* pinceau);
void pos_case(int i, int j, int*x,int*y);
int v_deplacement(int x1,int y1,int x2,int y2,int joueur);
typedef struct
{int joueur;int officier;int prise}pion;
