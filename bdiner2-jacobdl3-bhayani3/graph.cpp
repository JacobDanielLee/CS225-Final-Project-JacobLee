#include "graph.h"
#include <math.h>
#include "readFromFile.cpp"
#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;

//Graph constructor
//given two files this pares builds up vectors of vertex and edge objects with their own member variables
Graph::Graph(string routesFile, string airportsFile){
    //convert raw files to string 
    string routesStr = file_to_string(routesFile);
    string airportsStr = file_to_string(airportsFile);

    //parse lines to fill up lists of edges and verticies
    vector<string> edge_lines = parseLines(routesStr);
    vector<string> vertex_lines = parseLines(airportsStr);
    parseEdges(edge_lines);
    parseVerticies(vertex_lines);

    //fill in verticies in edges vector (attach airports to routes)
    connectVertex(); 
}

//parses lines of long CSV string and puts each "sentence" into a vector    
vector<string> Graph::parseLines(string rawCSV){
    stringstream ss(rawCSV);
    string line;
    vector<string> lines;
    while(getline(ss, line))
        lines.push_back(line);   
    return lines;
}

//parse lines to fill in verticies_ vector
void Graph::parseVerticies(vector<string> parsedLines){
     while(!parsedLines.empty()){
        string oneLine = parsedLines.back();
        parsedLines.pop_back();
        string word;
        stringstream s(oneLine);
        int numwords = 7;
        Vertex v;
        while(getline(s, word, ',')){
            if(numwords == 7){
                numwords--;   
                v.airportID_ =atof(word.c_str());
                continue;
            }
            if(numwords == 6){
                numwords--;   
                v.airportName_ =word;
                continue;
            }
            if(numwords == 5){
                numwords--;  
                v.city_=word;
                continue;
            }
            if(numwords == 4){
               numwords--;   
                v.country_=word;
                continue;
            }  
            if(numwords == 3){
                v.iata_=word;
                numwords--; 
                continue;
            }  
            if(numwords == 2){
                v.lattitude_=atof(word.c_str());
                numwords--;  
                continue;
            }
            if(numwords == 1){
                v.longitude_= atof(word.c_str());


                vertices_.push_back(v);
                break; 
            } 
        }
       
    }   
}


//parse lines to fill in edges_ vector
void Graph::parseEdges(vector<string> parsedLines){
     while(!parsedLines.empty()){
        string oneLine = parsedLines.back();
        parsedLines.pop_back();
        string word;
        stringstream s(oneLine);
        int numwords = 5;
        int srcId=0;
        int destId=0;
        Edge e;
        while(getline(s, word, ',')){
            if(numwords == 5){
                e.airlineID_=word;
                numwords--; 
                continue;
            }
            if(numwords == 4){
                e.sourceID_=word;
                numwords--; 
                continue;
            }
            if(numwords == 3){
                e.srcId_=atof(word.c_str());
                srcId = e.srcId_;
                numwords--; 
                continue;
            }  
            if(numwords == 2){
                e.destID_=word;
                numwords--;  
                continue;
            }
            if(numwords == 1){
                e.destId_=atof(word.c_str());
                destId = e.destId_;
                edges_.push_back(e);
                break; 
            } 
        }
    }   
}

//overloaded equal operator to compare vertex 
//two vertices are equal if their id's are identical
bool Graph::Vertex::operator==(const Vertex& other) const {
        if(this->airportID_ != other.airportID_){return false;}
        return true;
}

//overloaded equal operator to compare vertex 
//two verticies are not equal if their id's aren't identical
bool Graph::Vertex::operator!=(Vertex& other) const {
        return this->airportID_ != other.airportID_;
}

//fills each edge object with a vertex object
void Graph::connectVertex(){
    for(unsigned i=0; i<edges_.size(); i++){
        for(unsigned j=0; j<vertices_.size();j++){

            if(edges_[i].sourceID_ == vertices_[j].iata_)
                edges_[i].src_ = vertices_[j];
            if(edges_[i].destID_ == vertices_[j].iata_)
                edges_[i].dest_ = vertices_[j];
        }
    }
}

//default Vertex constructor
Graph::Vertex::Vertex(){
    Graph::Vertex::iata_ = "";
    Graph::Vertex::airportName_ = "";
    Graph::Vertex::country_ = "";
    Graph::Vertex::city_ = "";
    Graph::Vertex::longitude_ = 0;
    Graph::Vertex::lattitude_ = 0;
    Graph::Vertex::airportID_ = 0;
}

//full Vertex constructor
Graph::Vertex::Vertex(int ID,string iata, string name, string country, string city, double lon, double lat){
    Graph::Vertex::airportID_ = ID;
    Graph::Vertex::iata_ = iata;
    Graph::Vertex::airportName_ = name;
    Graph::Vertex::country_ = country;
    Graph::Vertex::city_ = city;
    Graph::Vertex::longitude_ = lon;
    Graph::Vertex::lattitude_ = lat;
}
  
//default edge constructor
Graph::Edge::Edge(){
    Graph::Edge::airlineID_ = "";
    Graph::Edge::sourceID_ = "";
    Graph::Edge::destID_ = "";
}

//construct edge from two vertices
Graph::Edge::Edge(Vertex a, Vertex b){
    src_ = a;
    dest_ = b;
}

//distance calculator
//dist = central angle in radians * radius
//central angle = arccos(sin(lat1)sin(lat2) + cos(lat1)cos(lat2)cos(lon2-lon1))
//radius of earth = 6378km
double Graph::Edge::getLength(){
    const double radiusEarth = 6378;    
    double lat1 = src_.lattitude_* M_PI /180;               ;
    double lat2 = dest_.lattitude_* M_PI /180;
    double lon1 = src_.longitude_* M_PI /180;
    double lon2 = dest_.longitude_* M_PI /180;
    double centralAngle = acos(sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(lon2-lon1));
    return radiusEarth*centralAngle;
}

//function to compare two edges
bool Graph::Edge::operator==(const Graph::Edge& other) const{
                if (this->src_.airportID_ == other.src_.airportID_
                && this->dest_.airportID_ == other.dest_.airportID_)
                return true;

                return false;
}

//finds the length between two vertices
double Graph::getLength(Vertex a, Vertex b){
    Edge e(a, b);    
    return e.getLength();
}

//return a vertex given an airport id
Graph::Vertex Graph::getVertex(int id){
    for(unsigned i=0; i<vertices_.size(); i++){
        if(vertices_[i].airportID_ == id)
            return vertices_[i];
            
    }
    return Graph::Vertex();
}
