int victoire(void)
{
    int i, j, k = 0;
    int adversaire = (tour == 1) ? 2 : 1;

    // Compter les pions de l'adversaire
    for (i = 0; i < 7; i++)
        for (j = 0; j < 7; j++)
            if (A[i][j].joueur == adversaire) k++;

    // Cas 1 : l'adversaire n'a plus de pions
    // Cas 2 : l'adversaire ne peut pas bouger
    if (k == 0 || !peut_bouger(adversaire))
    {
        gagnant = tour;
        return 1;
    }

    return 0;
}

int peut_bouger(int joueur)
{
    int i, j;
    int adv = (joueur == 1) ? 2 : 1;
    int dir = (joueur == 1) ? 1 : -1;
    int alez = -dir;

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (A[i][j].joueur == joueur)
            {
                // Déplacement simple vers l'avant
                if (i + dir >= 0 && i + dir <= 6)
                {
                    if (j - 1 >= 0 && A[i+dir][j-1].joueur == 0) return 1;
                    if (j + 1 <= 6 && A[i+dir][j+1].joueur == 0) return 1;
                }

                // Prise vers l'avant
                if (i + 2*dir >= 0 && i + 2*dir <= 6)
                {
                    if (j - 2 >= 0 &&
                        A[i+dir][j-1].joueur == adv &&
                        A[i+2*dir][j-2].joueur == 0) return 1;

                    if (j + 2 <= 6 &&
                        A[i+dir][j+1].joueur == adv &&
                        A[i+2*dir][j+2].joueur == 0) return 1;
                }

                // Officier : déplacement arrière
                if (A[i][j].officier == 1)
                {
                    if (i + alez >= 0 && i + alez <= 6)
                    {
                        if (j - 1 >= 0 && A[i+alez][j-1].joueur == 0) return 1;
                        if (j + 1 <= 6 && A[i+alez][j+1].joueur == 0) return 1;
                    }

                    if (i + 2*alez >= 0 && i + 2*alez <= 6)
                    {
                        if (j - 2 >= 0 &&
                            A[i+alez][j-1].joueur == adv &&
                            A[i+2*alez][j-2].joueur == 0) return 1;

                        if (j + 2 <= 6 &&
                            A[i+alez][j+1].joueur == adv &&
                            A[i+2*alez][j+2].joueur == 0) return 1;
                    }
                }
            }
        }
    }
    return 0;
}
