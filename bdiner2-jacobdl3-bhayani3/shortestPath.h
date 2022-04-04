#include <queue>
#include <iostream>
#include "graph.h"
/*
input: starting and ending airport
output: Airport path

implemented using priotiy queue 

*/

class shortestPath{
public:
    shortestPath(Graph::Vertex ,Graph::Vertex);
    queue<pair<double, Graph::Vertex>> dijkstra(Graph, Graph::Vertex);
     Graph::Vertex source;
    Graph::Vertex dest;
    void printPath(queue<pair<double, Graph::Vertex>>);
    
};
//comparison class for priority queue
//sorts by distance
class comparison_by_dist{
    public:
        bool operator() (const pair<double, Graph::Vertex> a, const pair<double, Graph::Vertex>b) {
           
            if(a.first > b.first)
                return true;
            else
                return false;
        }
};


   
