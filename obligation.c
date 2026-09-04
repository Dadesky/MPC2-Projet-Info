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
  {int i_case=i+2*direc;
     if((i_case>=0&&i_case<=6)&&(j+2>=0&&j+2<=6))
     {
  	if((A[i+direc][j+1].joueur==adv)&&(A[i+2*direc][j+2].joueur==0))  return 1;
     }
 
if((i_case>=0&&i_case<=6)&&(j-2>=0&&j-2<=6))
      {
  	if((A[i+direc][j-1].joueur==adv)&&(A[i+2*direc][j-2].joueur==0)) return 1;
      }
 	       if(A[i][j].officier==1) 
 	       {
 	        i_case=i+2*alez;
 	
if((i_case>=0 && i_case<=6)&&(j+2>=0 && j+2<=6))	       	
 	    {   	
 if((A[i+alez][j+1].joueur==adv)&&(A[i+2*alez][j+2].joueur==0)) return 1;
 	    }
 if((i_case>=0 && i_case<=6)&&(j-2>=0 && j-2<=6))	    
 	           {
 if((A[i+alez][j-1].joueur==adv)&&(A[i+2*alez][j-2].joueur==0)) return 1;
  	          }
    	    }   
  
  	}
   }
 } 
return 0;
}