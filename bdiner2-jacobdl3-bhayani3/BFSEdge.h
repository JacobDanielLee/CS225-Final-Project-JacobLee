#pragma once

#include "BFSVertex.h"

using std::string;

using namespace std;

class BFSEdge
{
  public:
    BFSVertex source_; //The source vertice in the edge
    BFSVertex destination_; //The destination vertice in the edge
    bool isVisited; //checks if the edge edge object was visited after its creation
    long double weight; //distance between two airports
    string airline; //name of the airline


    //paramerter constructor for weighted graph
    BFSEdge(BFSVertex s, BFSVertex d, long double w, string arli)
        : source_(s), destination_(d) ,isVisited(false), weight(w), airline(arli)
    {    }

    //default constructor
    BFSEdge() : source_(BFSVertex()), destination_(BFSVertex()), isVisited(false),weight(-1), airline(""){ 
    }

    //constructor for unweighted graph
    BFSEdge(BFSVertex s, BFSVertex d, string arli) : source_(s), destination_(d), isVisited(false), weight(-1) ,airline(arli) {  }
    bool operator<(const BFSEdge& other) const {
        return weight < other.weight;
    }

    //check if the edges are same
    bool operator==(const BFSEdge& other) const{
        if (this->source_.portID_ == other.source_.portID_ 
            && this->destination_.portID_ == other.destination_.portID_)
            return true;
        return false;
    }
};