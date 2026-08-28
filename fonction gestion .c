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
     for(int k=0; k<A[mx][my].prise-1;i++)
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