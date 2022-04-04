#pragma once
#include "BFSVertex.h"
#include "BFSGraph.h"
#include "BFSEdge.h"
#include <iostream>
#include <queue>
#include <map>
#include <tuple>
using namespace std;

class leastFlights {
    public:
        // constructor
        leastFlights(BFSVertex _source, BFSVertex _destination);
        //empty constructor
        leastFlights();
        //call BFS in main
        void callout(string routes, string airports);
        // BFS implementation
        std::vector<BFSEdge> BFS(BFSGraph G);

    private:
        // source and destination Vertices 
        BFSVertex source;
        BFSVertex destination;
        map<int, tuple<long double, BFSVertex, bool>> finalMap;
};