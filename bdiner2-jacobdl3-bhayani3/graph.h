#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <unordered_map>
#include "readFromFile.hpp"
#include <list>
#include <climits>
#include <fstream>
#include <iomanip>
#include <set>
#include <vector>
#include <map>


using std::cerr;
using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::string;
using std::to_string;
using std::vector;
using std::pair;
using std::make_pair;
using std::unordered_map;

using namespace std;

class Graph
{
public:
    class Vertex{
            public:    
            //constructor
            Vertex();
            Vertex(int,string, string, string, string, double, double);  

            //operator overloading
            bool operator == (const Graph::Vertex& other) const;  
            bool operator!=(Vertex& other) const;

            //member variables
            int airportID_;
            double longitude_;
            double lattitude_;
            double distance;
            string iata_;
            string airportName_;
            string country_;
            string city_;
        };
               
    class Edge{
            public:
            //constrcutors            
            Edge();
            Edge(string, string, string);            
            Edge(Vertex s, Vertex d, string arli);
            Edge(Vertex ,Vertex);

            //operator
            bool operator==(const Graph::Edge& other) const; //function to compare two edges
        
            //accessor            
            double getLength();

            //member variables
            string airlineID_;
            string sourceID_;
            string destID_;
            int srcId_;
            int destId_;
            Vertex src_;
            Vertex dest_;
            

    };
    //constructor
    Graph(string, string);

    //acccessor
    double getLength(Vertex a, Vertex b);
    Vertex getVertex(int);
    Edge getEdge(Vertex source, Vertex destination) const;

    //constructor helpers
    void parseEdges(vector<string>);
    void parseVerticies(vector<string>);
    void connectVertex();
    vector<string> parseLines(string);

    //members
    vector<Edge> edges_;
    vector<Vertex> vertices_;
};
