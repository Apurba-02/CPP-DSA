#include<stdio.h>
 
int vertices , edges ,graph[9][9] , visited[9],queue[9], front =-1 , rear = -1, u , v ,i ,j;
 
void bfs(int v)
{
	for(i=0;i<vertices ;i++)
	{
		if(graph[v][i] && !visited[i])
		{
			queue[++rear] =i;
		}
	}
	if(front<=rear)
	{
		visited[queue[front]] = 1;
		bfs(queue[front++]);
	}
}
 
int main()
{
	printf("Enter number of vertices and edges:");
	scanf("%d%d", &vertices, &edges);
 
	for(i=0;i<vertices;i++)
	{
		queue[i] = 0;
		visited[i] = 0; 
	}
 
	int k;
 
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
 
 
	printf("\nEnter the starting vertes: ");
	scanf("%d",&k);
	bfs(k);
	printf("The nodes which are reachable are: \n");
 
	for(i=0;i<vertices;i++)
	{
		if(visited[i])
		{
			printf("%d\t",i);
		}
		else
		{
			printf("BFS is not possible!!");
		}
	}
	return 0;		
}
