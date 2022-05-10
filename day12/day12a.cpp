#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <map>
using namespace std;

// A directed graph using
// adjacency list representation
class Graph
{
    int V;          // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists

    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int, int, bool[], int[], int &, int &);

public:
    Graph(int V); // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d, int &counter);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u’s list.
    adj[v].push_back(u);
}

// Prints all paths from 's' to 'd'
void Graph::printAllPaths(int s, int d, int &counter)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];

    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty

    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to print all paths
    printAllPathsUtil(s, d, visited, path, path_index, counter);
}

// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeps track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, int d, bool visited[], int path[], int &path_index, int &counter)
{
    // Mark the current node and store it in path[]
    if (u == 0 || u == 1 || u == 5 || u == 6 || u == 7 || u == 8 || u == 9 || u == 10)
        visited[u] = true;
    path[path_index] = u;
    path_index++;

    // If current vertex is same as destination, then print
    // current path[]
    if (u == d)
    {
        for (int i = 0; i < path_index; i++)
        {
            cout << path[i] << " ";
        }
        counter++;
        cout << endl;
    }
    else // If current vertex is not destination
    {
        // Recur for all the vertices adjacent to current vertex
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index, counter);
    }

    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}

// Driver program
int main()
{
    // Create a graph given in the above diagram
    Graph g(11);

    map<string, int> input;
    map<string, bool> node;
    string input1, input2;
    char garbage;
    int result = 0;

    input["start"] = 0;
    input["zi"] = 1;
    input["GC"] = 2;
    input["FU"] = 3;
    input["QQ"] = 4;
    input["zv"] = 5;
    input["ky"] = 6;
    input["lk"] = 7;
    input["ca"] = 8;
    input["iv"] = 9;
    input["end"] = 10;

    ifstream file_name("input_day12.txt");
    while (!file_name.eof())
    {
        file_name >> input1;
        file_name >> garbage;
        file_name >> input2;
        cout << input1 << " " << input2 << endl;
        g.addEdge(input[input1], input[input2]);
        node[input1] = true;
        node[input2] = true;
    }

    int s = 0, d = 10;
    cout << "Following are all different paths from " << s << " to " << d << endl;
    g.printAllPaths(s, d, result);
    cout << result << endl;
}