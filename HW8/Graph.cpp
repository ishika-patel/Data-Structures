#include "Graph.hpp"
#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

// function to add edge between two vertices
void Graph::addEdge(string v1, string v2){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}


// function to add a vertex to the graph
void Graph::addVertex(string n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == n){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->name = n;
        vertices.push_back(v);
    }
}

// function to visualize the graph
void Graph::displayEdges(){

    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<" --> ";
        for(int j = 0; j < vertices[i]->adj.size(); j++){
            cout << vertices[i]->adj[j].v->name << " ";
        }
        cout<<endl;
    }
}

void Graph::breadthFirstTraverse(string sourceVertex)
{
    vertex *vStart;

    for(int i =0; i< vertices.size(); i++)
    {
        if(vertices[i]->name == sourceVertex)
        {
            vStart = vertices[i];
        }
    }

    cout << "Starting vertex (root): " << vStart->name << "-> ";

    vStart->visited = true;

    queue<vertex*> q;

    q.push(vStart);

    vertex *n;

    while(!q.empty())
    {
        n = q.front();
        q.pop();

        for(int j = 0; j <n->adj.size(); j++)
        {
            if(!n->adj[j].v->visited)
            {
                n->adj[j].v->distance = n->distance + 1;
                n->adj[j].v->visited = true;
                q.push(n->adj[j].v);
                cout << n->adj[j].v->name << "(" << n->adj[j].v->distance << ") ";
            }
        }
    }

}


void DFTraversal(vertex *n)
{
    n->visited = true;
    for (int x = 0; x < n->adj.size(); x++ )
    {
        if (n->adj[x].v->visited==false) //access adjacency vector of vertex n, if that vertex's adjacent is not visted then traverse
        {
            DFTraversal(n->adj[x].v); //traversing the vector of adjacents to n and sending that vertex to DFTraversal
        }
    }
}

int Graph::getConnectedComponents()
{
// set all vertices unvisited
    for(int i=0; i< vertices.size(); i++) {
      vertices[i]->visited = false;
  }

  // num. of connected componenets in the graph before removing the edge
  int initial_components = 0;

  // TODO Step1: Get initial_components. Complete and use the DFTraversal function.
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i]->visited == false)
        {
            DFTraversal(vertices[i]);
            initial_components++;
        }
    }
    
  return initial_components;
}