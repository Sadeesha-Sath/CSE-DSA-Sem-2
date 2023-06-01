#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int numVt;
    vector<vector<int>> adjMatrix;

private:
    int minDistance(int distance[], bool visited[])
    {
        int minimum = INT_MAX;
        int index;
        for (int i = 0; i < numVt; i++)
        {
            if (!visited[i] && distance[i] < minimum)
            {
                minimum = distance[i];
                index = i;
            }
        }
        return index;
    }

    void printSSSP(int n, int distance[], int src)
    {
        cout << "Shortest Path from the Source City " << src << "\n\n";
        double sum = 0.0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (i != src)
            {
                sum += distance[i];
                count++;
                cout << i << "\t" << distance[i] << endl;
            }
        }
        cout << "\n";
        cout << "Average Distance to other cities: " << sum / count << endl;
        cout << "\n\n";
    }

public:
    Graph(int V)
    {
        numVt = V;
        adjMatrix.resize(V);
        for (int i = 0; i < V; i++)
        {
            adjMatrix[i].resize(V);
        }
    }

    void addEdge(int u, int v, int w)
    {
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }

    void Dijikstra(int src)
    {
        int distance[numVt];
        bool visited[numVt];

        for (int i = 0; i < numVt; i++)
        {
            distance[i] = INT_MAX;
            visited[i] = false;
        }

        distance[src] = 0;

        for (int i = 0; i < numVt; i++)
        {
            int min = minDistance(distance, visited);
            visited[min] = true;
            for (int j = 0; j < numVt; j++)
            {
                if (!visited[j] && adjMatrix[min][j] && distance[min] != INT_MAX && (distance[min] + adjMatrix[min][j]) < distance[j])
                {
                    distance[j] = distance[min] + adjMatrix[min][j];
                }
            }
        }

        printSSSP(numVt, distance, src);
    }
};

int main()
{
    Graph graph(6);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 4, 15);
    graph.addEdge(0, 5, 5);
    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 3, 30);
    graph.addEdge(2, 3, 12);
    graph.addEdge(2, 4, 5);
    graph.addEdge(3, 5, 20);

    for (int i = 0; i < 6; i++)
    {
        graph.Dijikstra(i);
    }

    return 0;
}
