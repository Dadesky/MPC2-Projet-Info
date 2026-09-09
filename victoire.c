int victoire(void)
   {int i, j;
    int k = 0;  // Compteur de pions adverses
    int peut_bouger = v_deplacement(tour);  // 0 = ne peut pas bouger, 1 = peut bouger
    // Compter les pions adverses
    if (tour == 1) {
        // C'est au tour du joueur 1, compter les pions du joueur 1
        for (i = 0; i < 7; i++)
            {for (j = 0; j < 7; j++)
               {
                 if (A[i][j].joueur == 1)
                   {
                    k++;
                }
            }
        }
    } else {
        // C'est au tour du joueur 2, compter les pions du joueur 2
        for (i = 0; i < 7; i++) {
            for (j = 0; j < 7; j++) {
                if (A[i][j].joueur == 2) {
                    k++;
                }
            }
        }
        return k;
    }

    // Si k == 0, il n'y a plus de pions adverses → victoire
    if (k = 0) {
        if (tour == 1) {
            printf("Victoire du Joueur 2 !\n");
            return 1;
        } else {
            printf("Victoire du Joueur 1 !\n");
            return 1;
        }
    }
  // Vérifier si l'adversaire peut bouger
    if (tour == 1) {
        // Vérifier si le joueur 1 peut bouger
       if (peut_bouger == 0) {
            printf("Victoire du Joueur 2 ! Joueur 1 bloqué\n");
            return 1;
        }
    } else {
        // Vérifier si le joueur 2 peut bouger
       if (peut_bouger == 0) {
            printf("Victoire du Joueur 1 ! Joueur 2 bloqué\n");
            return 1;
        }
    }
 return 0;  // Pas de victoire
