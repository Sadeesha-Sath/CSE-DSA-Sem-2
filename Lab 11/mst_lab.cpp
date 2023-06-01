#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Structure to represent a node in the adjacency list
struct Node
{
    int value, weight;
};

class Graph
{
    int numVertices;
    vector<vector<Node>> adjacencyList;

public:
    Graph(int V)
    {
        numVertices = V;
        adjacencyList.resize(V);
    }

    void addEdge(int src, int dest, int weight)
    {
        Node node;
        node.value = dest;
        node.weight = weight;
        adjacencyList[src].push_back(node);

        node.value = src;
        node.weight = weight;
        adjacencyList[dest].push_back(node);
    }

    void primMST(int startNode)
    {
        // Priority queue to store vertices along with their key values
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Vector to store keys (minimum edge weight) to all vertices
        vector<int> key(numVertices, INT_MAX);

        // Vector to store parent of each vertex in the MST
        vector<int> parent(numVertices, -1);

        // Vector to track if a vertex is included in the MST
        vector<bool> inMST(numVertices, false);

        // Insert the start node into the priority queue
        pq.push(make_pair(0, startNode));
        key[startNode] = 0;

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            // Iterate through all adjacent vertices of u
            for (Node &neighbor : adjacencyList[u])
            {
                int v = neighbor.value;
                int weight = neighbor.weight;

                // If v is not yet included in MST and weight of (u,v) is smaller than current key of v
                if (inMST[v] == false && weight < key[v])
                {
                    // Update the key value of v
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        // Print the MST edges
        cout << "Minimum Spanning Tree Edges:" << endl;
        for (int i = 1; i < numVertices; ++i)
        {
            int weight;
            for (Node &node : adjacencyList[i])
            {
                if (node.value == parent[i])
                {
                    weight = node.weight;
                }
            }
            cout << parent[i] << " - " << i << " (" << weight << ") " << endl;
        }
    }
};

int main()
{
    int numVertices = 6;

    Graph graph(numVertices);

    graph.addEdge(0, 1, 3);
    graph.addEdge(0, 5, 1);
    graph.addEdge(1, 2, 2);
    graph.addEdge(1, 3, 1);
    graph.addEdge(1, 4, 10);
    graph.addEdge(2, 3, 3);
    graph.addEdge(2, 5, 5);
    graph.addEdge(3, 4, 5);
    graph.addEdge(4, 5, 4);

    // Pass the start node here
    graph.primMST(0);

    return 0;
}