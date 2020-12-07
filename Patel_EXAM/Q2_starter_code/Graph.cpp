#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void Graph::addEdge(string source, string target){
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == source){
            for(unsigned int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == target && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                }
            }
        }
    }
}

void Graph::addVertex(string vName){
    bool found = false;
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == vName){
            found = true;
            cout<<vertices[i]->name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->name = vName;
        v->distance = 0;
        vertices.push_back(v);
    }
}

void Graph::displayEdges(){
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<":"<<endl;
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
            cout<<" --> "<< vertices[i]->adj[j].v->name <<endl;
        }
        cout<<endl;
    }
}

//taken from recitation 11!
void DFTraversal(vertex *n)
{
    n->visited = true;
    for (int x = 0; x < n->adj.size(); x++)
    {
        if (!n->adj[x].v->visited) //access adjacency vector of vertex n, if that vertex's adjacent is not visted then traverse
        {
            DFTraversal(n->adj[x].v); //traversing the vector of adjacents to n and sending that vertex to DFTraversal
        }
    }
}

bool Graph::isStronglyConnected()
{
    for(int i= 0; i < vertices.size(); i++) //interate through vertices
    {
        DFTraversal(vertices[i]); // traverse and mark all items visited as true
        
        for(int k = 0; k <vertices.size(); k++) // check to see if something is not visited therefore showing poor connectivity
        {
            if(vertices[k]->visited == false) 
            {
                return false; // if not visited then bad connectivity
            }
            vertices[k]->visited = false;
        }
    }
    return true; // else great connectivity
}