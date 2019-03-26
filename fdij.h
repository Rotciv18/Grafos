#ifndef FDIJ_H_INCLUDED
#define FDIJ_H_INCLUDED
void dijkstra(int G[V][V],int n,int startnode)
{

	int cost[V][V],distance[V],pred[V];
	int visited[V],count,mindistance,nextnode,i,j;

	//pred[] guarda o antecessor de cada nó
	//count dá o numero de nós examinados
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INT_MAX;
			else
				cost[i][j]=G[i][j];

	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

	while(count<n-1)
	{
		mindistance=INT_MAX;

		//nextnode dá o nó de menor distância
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}

			//check if a better path exists through nextnode
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}

	//printa caminho para cada nó
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistancia de vertice %d: %d",i,distance[i]);
			printf("\nCaminho --- %d",i);

			j=i;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
	}
}


#endif // FDIJ_H_INCLUDED
