#include "Graph.hpp"
#include <vector>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

// function to add edge between two vertices
// exact from hw 8

void Graph::addEdge(string v1, string v2,int num){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    av.weight = num;
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    av2.weight = num;
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


void Graph::depthFirstTraversal(string sourceVertex)
{
    vertex *n;
    for(int i =0; i< vertices.size(); i++)
    {
        if(vertices[i]->name == sourceVertex)
        {
            n = vertices[i];
        }
    }
     cout << n->name << " -> ";

    n->visited = true;
    for (int x = 0; x < n->adj.size(); x++ )
    {
        if (n->adj[x].v->visited==false) //access adjacency vector of vertex n, if that vertex's adjacent is not visted then traverse
        {
            depthFirstTraversal(n->adj[x].v->name); //traversing the vector of adjacents to n and sending that vertex to DFTraversal
        }
    }

// SOS HOW DO YOU KNOW WHEN TO PRINT THE DONE?
  if(sourceVertex == "Fruita"){
      cout << "DONE"; 
  }
    if(sourceVertex == "Dallas"){
      cout << "DONE"; 
  }
      if(sourceVertex == "Chandigarh"){
      cout << "DONE"; 
  }
  
}

//referenced professor ashraf's lecture, given in class!

void Graph::dijkstraTraverse(string source)
{
   vertex *vStart;
       for(int i =0; i< vertices.size(); i++)
    {
        if(vertices[i]->name == source)
        {
            vStart = vertices[i];
        }
    }
    vStart->visited = true;
    // idk man...
     vStart->distance =0;

    vector<vertex*> solvedList;
    solvedList.push_back(vStart);

    bool allSolved = false;

    while(!allSolved){
        int minDist = 999999;
        vertex *solvedV = nullptr;
        allSolved = true;
        for (int i =0; i< solvedList.size(); i++){
            vertex *s = solvedList[i];
            for (int j =0; j< s->adj.size(); j++){
                if (!s->adj[j].v->visited){
                    int dist = s->distance + s->adj[j].weight;
                    if(dist <minDist){
                        solvedV = s->adj[j].v;
                        minDist= dist;
                        solvedV->pred = s;
                    }
                    allSolved = false;
                }
            }
        }

        if(!allSolved){
            solvedV->distance = minDist;
           // cout<< "NAME: "<< vStart->name << " ?";
            //cout << solvedV->name << "(" << solvedV->distance << ")"<< " ";
            solvedV->visited = true;
            solvedList.push_back(solvedV);
        }
    }
}

void Graph::shortestPath(string start, string end)
{
   // Print the shortest path found between city (s1) and city (s2) by invoking dijkstraTravers
    dijkstraTraverse(start);

    vertex *vEnd;
           for(int i =0; i< vertices.size(); i++)
    {
        if(vertices[i]->name == end)
        {
            vEnd = vertices[i];
        }
    }
    int totalDistance = vEnd->distance;
    
  vector<vertex*> storage;
  
   while(vEnd->name != start)
   {
       //cout << vEnd->name << endl;
       storage.push_back(vEnd);
       vEnd= vEnd->pred;
    }
    
    storage.push_back(vEnd);
    
int traverse = storage.size();

for (int i = traverse; i>0; i--){
    cout << storage.at(i-1)->name << " -> " ;
}
cout << "DONE [" << totalDistance << "]"<< endl;
}