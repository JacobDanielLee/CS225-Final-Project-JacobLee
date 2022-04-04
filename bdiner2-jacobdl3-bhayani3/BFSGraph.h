#pragma once

#include "BFSEdge.h"
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;



class BFSGraph{
public:
    //constructor to initialise the function
    BFSGraph(const string& Routes, const string& Airports);
    //gets adjacent vertices in the grpah to the current vertex
    vector<BFSVertex> getNearby(BFSVertex source) const;
    //get the edge between two vertices 
    BFSEdge getEdge(BFSVertex source, BFSVertex destination) const;
    //returns the vertices in the graph
    vector<BFSVertex> getVertices() const;
    //to store the graph in
    mutable unordered_map<BFSVertex, unordered_map<BFSVertex, BFSEdge, hashingFunc>, hashingFunc> adjacent;
    map <int, BFSVertex> m;

private:
    //to insert vertex into the graph
    void vertexIns(BFSVertex v);
    // converts file line to string
    string file_to_string(const std::string & filename);
    //to convert a string into a vector
    vector<string> vectorise(string s);
    //convert a string containing multiple lines into multiple strings
    vector<string> doLines(string sentence);
    //returns a vector of edges in the grpah
    vector<BFSEdge> getEdges() const;
    //to set the value of an edge
    BFSEdge setEdge(BFSVertex source, BFSVertex destination, long double weight);
    //inserts an edge between the two passed vertices
    void edgeIns(BFSVertex source, BFSVertex destination, string airline);
    //calculate the distance in Kmm between two airport vertices
    long double distanceCalculate(BFSVertex source, BFSVertex destination);
    

};