#include <iostream>
#include "GraphT.h"
using namespace std;

int main() {

    GraphT<int> graph;

    for (char c = 'a'; c <= 'i'; c++) {
        string node = " ";
        node[0] = c;
        graph.AddVertex(node);
    }

    graph.AddEdge("a", "b", 1);
    graph.AddEdge("a", "f", 1);
    graph.AddEdge("a", "i", 1);
    graph.AddEdge("b", "c", 1);
    graph.AddEdge("b", "e", 1);
    graph.AddEdge("c", "d", 1);
    graph.AddEdge("c", "e", 1);
    graph.AddEdge("d", "g", 1);
    graph.AddEdge("d", "h", 1);
    graph.AddEdge("g", "f", 1);
    graph.AddEdge("g", "e", 1);

    cout << "DFS Test" << endl;
    cout << "--------" << endl;
    queue<string> visited = graph.DFS("a");
    while (!visited.empty())
    {
        cout << visited.front() << endl;
        visited.pop();
    }
    cout << endl;

    cout << "BFS Test" << endl;
    cout << "--------" << endl;
    visited = graph.BFS("a");
    while (!visited.empty())
    {
        cout << visited.front() << endl;
        visited.pop();
    }
    cout << endl;

    cout << "Dijkstra Test" << endl;
    cout << endl;
    unordered_map<string, int> distTable = graph.Dijkstra("a");
    unordered_set<string> vertices = graph.GetVertices();

    cout << "Node\tDist" << endl;
    cout << "-----------------------" << endl;
    for (auto vert = vertices.begin(); vert != vertices.end(); ++vert)
    {
        cout << *vert << "\t" << distTable[*vert] << endl;
    }

    return 0;
}
