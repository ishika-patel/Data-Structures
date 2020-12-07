#include <iostream>
#include <vector>
#include "Graph.hpp"

using namespace std;


int main()
{
    Graph g; // undirected and unweighted (can be connected or disconnected)
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 6);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << g.fun() << endl;

    Graph g1; // undirected and unweighted (can be connected or disconnected)
    g1.addVertex(0);
    g1.addVertex(1);
    g1.addVertex(2);
    g1.addVertex(3);
    g1.addVertex(4);


    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 4);

    cout << g1.fun() << endl;


    Graph g2; // undirected and unweighted (can be connected or disconnected)
    g2.addVertex(0);
    g2.addVertex(1);
    g2.addVertex(2);
    g2.addVertex(3);
    g2.addVertex(4);


    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(0, 3);
    g2.addEdge(1, 2);
    g2.addEdge(1, 3);

    cout << g2.fun() << endl;

}