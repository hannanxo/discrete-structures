#include <iostream>
#include <string>

using namespace std;

#define numOfVertices 9

int *dijkstra(int graph[numOfVertices][numOfVertices], int dist[numOfVertices])
{
    bool setN[numOfVertices] = {};

    // initially, all vertices in set N
    for (int i = 0; i < numOfVertices; i++)
    {
        setN[i] = true;
    }

    // initialize source to 0 and others to infinity
    dist[0] = 0;
    for (int i = 1; i < numOfVertices; i++)
    {
        dist[i] = 100;
    }

    // iterations
    for (int i = 0; i < numOfVertices; i++)
    {
        // choose minimum vertex from N
        int min = 100;
        int minIndex = -1;
        for (int j = 0; j < numOfVertices; j++)
        {
            if (setN[j] && dist[j] < min)
            {
                min = dist[j];
                minIndex = j;
            }
        }

        // remove minimum vertex from N
        if (minIndex != -1)
        {
            setN[minIndex] = false;
        }

        // update neighbours of minimum vertex
        if (minIndex != -1)
        {
            for (int k = 0; k < numOfVertices; k++)
            {
                if (graph[minIndex][k] != 0 && setN[k])
                {
                    if (dist[minIndex] + graph[minIndex][k] < dist[k])
                    {
                        dist[k] = dist[minIndex] + graph[minIndex][k];
                    }
                }
            }
        }
    }

    return dist;
}

int main()
{
    int dist[numOfVertices] = {};

    int graph[numOfVertices][numOfVertices] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                                               {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                               {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                               {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                               {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                               {0, 0, 4, 0, 10, 0, 2, 0, 0},
                                               {0, 0, 0, 14, 0, 2, 0, 1, 6},
                                               {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                               {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, dist);

    for (int i = 0; i < numOfVertices; i++)
    {
        cout << dist[i] << endl;
    }

    return 0;
}