#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include <queue>
#include<iostream>

struct vertex;

struct adjVertex{
    vertex *v;
};

struct vertex{
    int key;
    //bool visited = false;
    bool visited;
    int distance;
    vertex *pred; // predecessor
    std::vector<adjVertex> adj;
};

class Graph
{
    public:
        void addEdge(int v1, int v2);
        void addVertex(int v);
        int findShortestPath(int sourceVertex, int destinationVertex);
        void printPath(int sourceVertex, int destinationVertex);

    private:
        std::vector<vertex*> vertices;

};

#endif
