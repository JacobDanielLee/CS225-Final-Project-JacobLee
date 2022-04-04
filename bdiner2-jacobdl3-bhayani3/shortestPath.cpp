#include "shortestPath.h"
#include <limits.h>
#include <float.h>
using namespace std;

//this pair will hold a vertex and it's distance from the source
typedef pair<double, Graph::Vertex> qp;//(distance, vertex)

/*Description
Implementing the shortest path from a starting node to a dest node using Djikstra's shortest path algorithm with a minheap
Alogrithm based on https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
*/

//Shortest path constructor to set class source and dest airports
shortestPath::shortestPath(Graph::Vertex src, Graph::Vertex dest){
    source = src;
    //dest = dest;
}

//Implements Dijkstra's algorithm on a group given a starting point
//returns a queue of pairs of vertices
queue<qp> shortestPath::dijkstra(Graph g, Graph::Vertex source) { 
	queue<qp> path;
    priority_queue< qp, vector<qp>, comparison_by_dist> minheap;
    
	for (unsigned i=0; i < g.edges_.size(); i++) {
        Graph::Vertex v = g.edges_[i].src_;
        if (v != source) 
            v.distance = INFINITY;       
		else
			v.distance = 0.0;
	
        minheap.push(make_pair(v.distance , v));
    }

    while (!minheap.empty()) {
        Graph::Vertex u = minheap.top().second;
       	if(u == dest) break;
        minheap.pop();

        for (unsigned i=0; i < g.edges_.size(); i++) {
            double alt = 0.0;
			Graph::Edge e = g.edges_[i];
			
			//e.dest is neighbor of u aka connected to u on the graph          
			if (e.src_ == u) {
				Graph::Vertex n = e.dest_;//n is neighbor of u

                alt = u.distance + g.getLength(u, n);
		        if (alt < n.distance) {
		            n.distance = alt;
		            minheap.push(make_pair(alt, n));
		        }
			}
        }
    }

	//popout all qp's in minheap
	while(!minheap.empty()){
		path.push(minheap.top());
		if(minheap.top().second == dest){
			cout<<"path found"<<endl;
			return path;
		}
		else{
			minheap.pop();	
		}
	}
	cout<<"path not found "<<endl;
    return path;
}

//print the shortest path to terminal given a path queue
void shortestPath::printPath(queue<pair<double, Graph::Vertex>> p){
	double dist = 0.0;	
	cout<<"Shortest Path: ";	
	for(unsigned i=0; i<p.size(); i++){
		dist += p.front().first;		
		cout<<p.front().second.airportName_ <<" -> ";
		p.pop();
}
	cout<< "Distance Traveled: " << dist << endl;
}

