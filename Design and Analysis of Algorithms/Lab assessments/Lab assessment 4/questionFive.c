#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define maximumNumberOfVertices 100 // maximum number of vertices in the graph



int graph[maximumNumberOfVertices][maximumNumberOfVertices]; // adjacency matrix of the graph
int parent[maximumNumberOfVertices]; // array to store the parent of each vertex in the augmenting path
int visited[maximumNumberOfVertices]; // array to keep track of visited vertices during DFS
int numberOfVertices; // number of vertices in the graph



int min(int firstNumber, int secondNumber)
{
    return (firstNumber < secondNumber) ? firstNumber : secondNumber;
}



// find an augmenting path from the source to the sink in the residual graph
int depthFirstSearch(int source, int sink, int minimumFlow)
{
    int index;
    visited[source] = 1;

    if (source == sink) return minimumFlow;

    for (index = 0; index < numberOfVertices; index++)
    {
        if (!visited[index] && graph[source][index] > 0)
        {
            parent[index] = source;
            int flow = depthFirstSearch(index, sink, min(minimumFlow, graph[source][index]));
            if (flow > 0)
            {
                graph[source][index] -= flow;
                graph[index][source] += flow;
                return flow;
            }
        }
    }
    return 0;
}

// compute the maximum flow from the source to the sink in the given graph
int maximumFlow(int source, int sink)
{
    int index, secondaryIndex, maximumFlow = 0;
    while (1)
    {
        memset(visited, 0, sizeof(visited));
        int flow = depthFirstSearch(source, sink, INT_MAX);
        if (flow == 0) break;
        maximumFlow += flow;
    }
    return maximumFlow;
}



int main()
{
    printf("Name: Afraaz Hussain\nAdmission number: 20BDS0374\n\n\n");

    int numberOfEdges, index, secondaryIndex, u, v, w, source, sink;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &numberOfVertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &numberOfEdges);

    // initialize the adjacency matrix with all entries set to 0
    memset(graph, 0, sizeof(graph));
    // read the edges and their weights
    printf("Enter the edges and their weights (u v w):\n");
    for (index = 0; index < numberOfEdges; index++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] += w;
    }
    printf("Enter the source and sink vertices: ");
    scanf("%d %d", &source, &sink);

    // compute the maximum flow from the source to the sink
    int maximumFlowValue = maximumFlow(source, sink);

    // print the maximum flow
    printf("The maximum flow from vertex %d to vertex %d is: %d\n", source, sink, maximumFlowValue);
    return 0;
}

/*
Enter the number of vertices in the graph: 4
Enter the number of edges in the graph: 5
Enter the edges and their weights (u v w):
0 1 3
0 2 2
1 2 1
1 3 2
2 3 3
Enter the source and sink vertices: 0 3

The maximum flow from vertex 0 to vertex 3 is: 4

*/