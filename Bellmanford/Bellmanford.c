#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

typedef struct AdjListNode  AdjListNode ;

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

 AdjListNode* A[100] ;
 int n ;


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

void BellManFord(int src)
{
    int sp[n] ;
    sp[0]=0 ;
    bool flag=false ;

    for(int i=1;i<n;i++)
    	sp[i]=INT_MAX ;

    for(int i=0;i<n-1;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		 AdjListNode* P=A[j] ;
    		 while(P!=NULL)
    		 {
    		 	sp[P->vertex]=min(sp[P->vertex],sp[j]+(P->weight)) ;
    		 	P=P->Next ;
    		 }
    	}
    }

    for(int j=0;j<n;j++)
    	{
    		 AdjListNode* P=A[j] ;
    		 while(P!=NULL)
    		 {
    		 	if(sp[P->vertex]>sp[j]+(P->weight))
    		 	{
    		 		printf("THERE ARE NEGATIVE EDGE CYCLES") ;
    		 		flag=true ;
    		 		goto L76 ;
    		 	}
    		 	P=P->Next ;
    		 }
    	}
    	L76: ;

     if(flag==false)
     {
     	for(int i=0;i<n;i++)
     		printf("%d ",sp[i]) ;
     }

}


int main(void)
{
	printf("Enter number of vertices in graph") ;
	scanf("%d",&n) ;
	printf("Enter the number of queries") ;
	int q ;
	scanf("%d",&q) ;
	int x,y,z ;

 for(int i=0;i<100;i++)
 	A[i]=NULL ;

	for(int i=0;i<q;i++)
	{
       scanf("%d",&x) ;
       scanf("%d",&y) ;
       scanf("%d",&z) ;
       A[x]=insert(x,y,z) ;
	}
	BellManFord(0) ;
}


