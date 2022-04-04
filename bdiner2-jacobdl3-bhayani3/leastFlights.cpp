//BFS
//Graph Traversal algorithm
 
#include "leastFlights.h"
#include "BFSGraph.h"
#include "BFSEdge.h"
#include <iostream>
#include <string>
#include <vector>

leastFlights::leastFlights(BFSVertex _source, BFSVertex _destination) {
    source = _source;
    destination = _destination;
}
leastFlights::leastFlights() {

}

void leastFlights::callout(string routes, string destination) {
    BFSGraph g(routes, destination);
    int src;
    cout << "Please enter a Numerical airport ID from 'Data/Airports.txt' to set as Source ID: ";
    cin >> src;
    while (g.m.find(src) == g.m.end()) {
         cout << "Please enter a valid airport ID: ";
         cin >> src;
    }
    cout << "You have selected " << g.m[src].nameOfAirport <<" as your source airport" << endl;
    int dest;
    cout << "Please enter a Numerical airport ID from 'Data/Airports.txt' to set as Destination ID: ";
    cin >> dest;
    while (g.m.find(dest) == g.m.end() || src == dest) {
         cout << "Please enter a valid airport ID that is not your source airport ID: ";
         cin >> dest;
    }
    cout << "You have selected " << g.m[dest].nameOfAirport <<" as your destination airport"<< endl;
    std::cout <<std::endl;
    leastFlights lf(g.m[src], g.m[dest]);
    vector<BFSEdge> paths = lf.BFS(g);

}
std::vector<BFSEdge> leastFlights::BFS(BFSGraph g) {
    // vector containing all the pathes (Edges) in the minimun flights distance
    std::vector<BFSEdge> minimumPaths;

    std::queue<int> q;
    
    for (BFSVertex V : g.getVertices()) {
        if (source.portID_ == V.portID_)
            finalMap[V.portID_] = {0, BFSVertex(), false};
        else
            finalMap[V.portID_] = {DBL_MAX, BFSVertex(), false};
    }

    q.push(source.portID_);
//start of BFS
    while (!q.empty()) {
        int currportID_ = q.front();
        BFSVertex currentV = g.m[currportID_];
        q.pop();

        if (currentV == destination) {
            BFSVertex pre = get<1>(finalMap[currentV.portID_]);
            BFSEdge path = g.getEdge(pre, currentV);
            minimumPaths.push_back(path);
            while (pre != source) {
                BFSVertex curr = pre;
                pre = get<1>(finalMap[pre.portID_]);
                path = g.getEdge(pre, curr);
                minimumPaths.push_back(path);
            }

            std::cout << "Results: " << std::endl;
            for (int i = minimumPaths.size() - 1; i >= 0; i--)
                std::cout<< "path" << minimumPaths.size() - i << ": " << minimumPaths[i].source_.nameOfAirport << " -> " 
                    << minimumPaths[i].destination_.nameOfAirport << ", the distance for the flight is " << minimumPaths[i].weight << " KM" << std::endl;
            // reverse the minimum paths array to make the first item the source path and the last item the destination path
            std::reverse(minimumPaths.begin(), minimumPaths.end());
            finalMap.clear();
            return minimumPaths;
        }

        // search adjacent Vertices if current Vertex is not the destination
        for (BFSVertex W : g.getNearby(currentV)) {
           if (!get<2>(finalMap[W.portID_])) {
               get<2>(finalMap[W.portID_]) = true;
               get<1>(finalMap[W.portID_]) = currentV;
               q.push(W.portID_);
           } else if (!g.getEdge(get<1>(finalMap[currportID_]), get<1>(finalMap[W.portID_])).isVisited) {
               g.adjacent[currentV][g.m[W.portID_]].isVisited = true;
           }
        }
    }

    // for invalid destination and source paths
    std::cout<< "No logical path between " << source.nameOfAirport << " and " << destination.nameOfAirport << std::endl;
    minimumPaths.push_back(BFSEdge());
    finalMap.clear();
    return minimumPaths;
}

