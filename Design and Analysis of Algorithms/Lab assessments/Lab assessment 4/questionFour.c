#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define maximumNumberOfVertices 100 // maximum number of vertices in the graph



int graph[maximumNumberOfVertices][maximumNumberOfVertices]; // adjacency matrix of the graph
int distance[maximumNumberOfVertices][maximumNumberOfVertices]; // matrix to store the shortest distanceances between pairs of vertices



void floydWarshall(int numberOfVertices)
{
    int index, secondaryIndex, tertiaryIndex;
    for (index = 0; index < numberOfVertices; index++) for (secondaryIndex = 0; secondaryIndex < numberOfVertices; secondaryIndex++) distance[index][secondaryIndex] = graph[index][secondaryIndex];
    for (tertiaryIndex = 0; tertiaryIndex < numberOfVertices; tertiaryIndex++)
    {
        for (index = 0; index < numberOfVertices; index++)
        {
            for (secondaryIndex = 0; secondaryIndex < numberOfVertices; secondaryIndex++)
            {
                if (distance[index][tertiaryIndex] != INT_MAX && distance[tertiaryIndex][secondaryIndex] != INT_MAX && distance[index][tertiaryIndex] + distance[tertiaryIndex][secondaryIndex] < distance[index][secondaryIndex])
                {
                    distance[index][secondaryIndex] = distance[index][tertiaryIndex] + distance[tertiaryIndex][secondaryIndex];
                }
            }
        }
    }
}



int main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    int numberOfVertices, numberOfEdges, index, secondaryIndex, u, v, w;
    
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numberOfVertices);
    
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numberOfEdges);

    // initialize the adjacency matrix with all entries set to infinity
    for (index = 0; index < numberOfVertices; index++) for (secondaryIndex = 0; secondaryIndex < numberOfVertices; secondaryIndex++) graph[index][secondaryIndex] = INT_MAX;

    // read the edges and their weights
    printf("Enter the edges and their weights (u v w):\n");
    for (index = 0; index < numberOfEdges; index++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    // run the Floyd-Warshall algorithm
    floydWarshall(numberOfVertices);

    // print the shortest distanceances between all pairs of vertices
    printf("Shortest distanceances between all pairs of vertices:\n\n");
    for (index = 0; index < numberOfVertices; index++)
    {
        for (secondaryIndex = 0; secondaryIndex < numberOfVertices; secondaryIndex++)
        {
            if (distance[index][secondaryIndex] == INT_MAX) printf("INF\t");
            else printf("%d\t", distance[index][secondaryIndex]);
        }
        printf("\n");
    }
    return 0;
}




/*
Enter the number of vertices in the graph: 4
Enter the number of edges in the graph: 5
Enter the edges and their weights (u v w):
0 1 2
0 2 4
1 2 1
1 3 7
2 3 3

*/