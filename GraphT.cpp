
#include "GraphT.h"

template<class T>
GraphT<T>::GraphT() {

}

template<class T>
void GraphT<T>::AddVertex(string vertex) {
    vertices.insert(vertex);
}

template<class T>
void GraphT<T>::AddEdge(string vertexA, string vertexB, T weight) {
    if (vertices.count(vertexA) == 0 || vertices.count(vertexB) == 0) {
        throw VertexNotFound();
    }
//    
    pair<string, T> edgeWeightPair;
    edgeWeightPair.first = vertexB;
    edgeWeightPair.second = weight;
    graph[vertexA].insert(edgeWeightPair);
}

template<class T>
T* GraphT<T>::GetWeight(string vertexA, string vertexB) {
    if (vertices.count(vertexA) == 0 || vertices.count(vertexB) == 0) {
        throw VertexNotFound();
    }
    
    if (graph[vertexA].count(vertexB) == 0) {
        return nullptr;
    }
    
    return new T(graph[vertexA][vertexB]);
}

template<class T>
queue<string> GraphT<T>::GetToVertices(string vertex) {
    queue<string> adjacentVerticies;

    for (auto it = graph[vertex].begin(); it != graph[vertex].end(); ++it) {
        adjacentVerticies.push(it->first);
    }
    
    return adjacentVerticies;
}