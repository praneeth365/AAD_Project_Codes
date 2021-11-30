#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>


#define rep(i,a,b) for(int i=a;i<b;i++) 
typedef struct AdjListNode AdjListNode ;




AdjListNode* A[101] ;
int sp[101] ;
bool visited[101]={false} ;
int n ;



struct AdjListNode{
	int vertex ;
	int weight ;
	AdjListNode* Next ;
} ;

int min(int x,int y)
{
	if(x>=y)
		return y ;
	else
		return x ;
}

int get_min(void)
{
	int x=INT_MAX ;
	int index=0 ;
	for(int i=1;i<n+1;i++)
	{
		if(visited[i]==false&&x>sp[i])
		{
			x=sp[i] ;
			index=i ;
		}
	}
	return index ;
}

AdjListNode* MakeNode(int x,int y,int z)
{
	AdjListNode* P=(AdjListNode*)malloc(sizeof(AdjListNode)) ;
	P->vertex=y ;
	P->weight=z ;
	P->Next=NULL  ;
	return P ;
}

AdjListNode* insert(int x,int y,int z)
{
	AdjListNode* B=A[x] ;
	AdjListNode* P =MakeNode(x,y,z) ;
	if(B==NULL)
	{
		A[x]=P ;
	}
	else
	{
		P->Next=B->Next ;
		A[x]=P ;
	}
	return A[x] ;
}

void djikstra(int src)
{
    sp[src]=0 ;
    rep(i,1,n+1)
    {
    	 int x=get_min() ;
    	 visited[x]=true ;
         AdjListNode* P=A[x] ;

        while(P!=NULL)
        {
        	if(visited[P->vertex]==false)
        		sp[P->vertex]=min(sp[P->vertex],sp[x]+P->weight) ;
        	P=P->Next ;
        }
    }
}



int main(void)
{
   rep(i,1,101)
   sp[i]=INT_MAX ;
   printf("Enter number of vertices: ") ;
   scanf("%d",&n) ; 

  printf("Enter number of queries: ") ;
  int q ;
  scanf("%d",&q) ;
  int x,y ;
  int z ;
  printf("Enter queries\n") ;
  while(q--)
  {
    scanf("%d",&x) ;
    scanf("%d",&y) ;
    scanf("%d",&z) ;
    A[x]=insert(x,y,z) ;
  }
  djikstra(1) ;
  rep(i,1,n+1)
  printf("%d ",sp[i]) ;

}
