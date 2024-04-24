#include<stdio.h>
 
int graph[10][10],visited[10],vertices ;

void DFS(int i)
{
    int j;
    printf("%d\t",i);
    visited[i]=1;
    for(j=0;j<vertices;j++)
    {
        if(!visited[j]&&graph[i][j]==1)
        {
             DFS(j);
        }
    }
}

void main()
{
    int edges , u , v  , w , i , j , k ;
    printf("Enter number of vertices and edges:");
    scanf("%d%d", &vertices, &edges);
 
	for(i=0 ; i<vertices ; i++)
	{
		for(j=0 ; j<vertices;j++)
		{
			graph[i][j]=0;
		}
	}
 
	printf("Enter the source and destination: \n");
 
	for(j=0 ; j<edges ;j++)
	{
		scanf("%d%d",&u,&v);
		graph[u][v]=1;
		graph[v][u]=1;
	}

   for(i=0;i<vertices;i++)
   {
        visited[i]=0;
   }

    printf("\nEnter the starting vertes: ");
	scanf("%d",&k);
    printf("The Nodes which are reachable are: \n");

    DFS(k);
}
