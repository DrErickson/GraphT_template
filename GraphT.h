
#ifndef GRAPHT_H
#define GRAPHT_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class VertexNotFound
{
public:
    VertexNotFound(string vertex)
    {
        badVertex = vertex;
    }
    string GetBadVertex()
    {
        return badVertex;
    }
private:
    string badVertex;
};

enum GRAPH_TYPE {DIRECTED, UNDIRECTED};

template<class T>
class GraphT {
public:
    GraphT();
    GraphT(GRAPH_TYPE gType);
    
    // Add vertex to graph
    void AddVertex(string vertex);
    
    // Add edge between vertices
    void AddEdge(string vertexA, string vertexB, T weight);
    
    // Returns weight between two vertices
    T* GetWeight(string vertexA, string vertexB);

    // Returns a set of the graph vertices
    unordered_set<string> GetVertices();

    // Returns vector of vertices connected to vertex
    vector<string> GetToVertices(string vertex);

    queue<string> DFS(string startVertex);
    queue<string> BFS(string startVertex);
    unordered_map<string, T> Dijkstra(string startVertex);

private:
    unordered_map<string, unordered_map<string, T>> graph;
    unordered_set<string> vertices;

    priority_queue<pair<string,T>> pqueue;
    GRAPH_TYPE graphType;
};

#include "GraphT.cpp"

#endif // GRAPHT_H
