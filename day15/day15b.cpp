// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// iPair ==>  Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V; // No. of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list<pair<int, int>> *adj;

public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v, int w);

    // prints shortest path from s
    void shortestPath(int s);
};

// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}

// Prints shortest paths from src to all other vertices
void Graph::shortestPath(int src)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // https://www.geeksforgeeks.org/implement-min-heap-using-stl/
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);

    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;

    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();

        // 'i' is used to get all adjacent vertices of a vertex
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // Print shortest distances stored in dist[]
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int V = 250000;
    Graph g(V);

    ifstream file_name1("input_day15b.txt");
    ifstream file_name2("input_day15b.txt");
    char input1, input2, input_down;
    int counter = 0;

    for (int i = 0; i < 500; i++)
        file_name2 >> input_down;

    file_name1 >> input1;

    while (!file_name1.eof())
    {
        for (int i = 0; i < 500; i++)
        {
            file_name1 >> input2;
            if (!file_name2.eof())
                file_name2 >> input_down;
            if (i == 0)
            {
                g.addEdge(counter, counter + 1, input2 - '0');
                g.addEdge(counter + 1, counter, input1 - '0');
            }
            if (i % 499 != 0 && i != 0)
            {
                g.addEdge(counter, counter + 1, input2 - '0');
                g.addEdge(counter + 1, counter, input1 - '0');
            }
            if (!file_name2.eof())
            {
                g.addEdge(counter, counter + 500, input_down - '0');
                g.addEdge(counter + 500, counter, input1 - '0');
            }
            counter++;
            input1 = input2;
        }
    }

    g.shortestPath(0);

    return 0;
}