#pragma once
#include "graph.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <map>

class Popular {
    public:
    std::map<string, double> popular(Graph g);
    std::map<string, double> deliverable;
    class Airport {
        public:
        Graph::Vertex port;
        int outdegrees = 0;
        int index = 0;

        Airport() {};
        Airport(Graph::Vertex p) : port(p) {}
    };

   
};
