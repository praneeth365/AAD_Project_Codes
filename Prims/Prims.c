#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

int matrix[100][100] ;
int n ;
bool set[100]={false} ;
int key[100] ;
int parent[100] ;

int min(void)
{
	int x=INT_MAX ;
	int index=0 ;
	for(int i=0;i<n;i++)
	{
		if(set[i]==false&&x>key[i])
		{
			x=key[i] ;
			index=i ;
		}
	}
	return index ;
}

void prims(void)
{
   key[0]=0 ;
   parent[0]=-1 ;
   for(int i=0;i<n;i++)
   	key[i]=INT_MAX ;
   int x ;
  
  for(int i=1;i<n-1;i++)
  {
     x=min() ;
     set[x]=true ;

     for(int j=0;j<n;j++)
     {
     	if(matrix[x][j]!=0&&key[j]>matrix[x][j]&&set[j]==false)
     	{
     		parent[j]=x ;
     		key[j]=matrix[j][x] ;
     	}
     }
  }

  for(int i=1;i<n;i++)
  	printf("%d %d %d\n",parent[i],i,matrix[i][parent[i]])  ;

}


int main(void)
{
   printf("Enter number of vertices:") ;
   scanf("%d",&n) ;
   printf("Enter the matrix:\n") ;
   for(int i=0;i<n;i++)
   {
   	  for(int j=0;j<n;j++)
   	  	scanf("%d",&matrix[i][j]) ;
   } 
   prims() ;
}
