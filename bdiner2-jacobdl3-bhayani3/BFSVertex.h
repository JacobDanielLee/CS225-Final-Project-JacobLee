#pragma once
#include <string>
#include <limits.h>
#include <float.h>
using std::string;
using namespace std;

class BFSVertex{
public:
    int portID_; //airport ID
    long double long_; //longitude
    long double lat_; //lattitude
    string nameOfAirport; //name of the airport

    //empty constructor
    BFSVertex() : portID_(0), long_(0.0), lat_(0.0), nameOfAirport("") { }
    //copy constructor
    BFSVertex(int airID, long double longti, long double lati, string airport) : 
        portID_(airID), long_(longti), lat_(lati), nameOfAirport(airport) { }
    //check if this and the other vertices are the same or not
    bool operator==(const BFSVertex& other) const {
        if(this->portID_ != other.portID_){return false;}
        return true;
    }
    bool operator!=(BFSVertex& other) const {
        return this->portID_ != other.portID_;
    }

    /*void operator=(const BFSVertex& other) {
        this->portID_ = other.portID_;
        this->lat_ = other.lat_;
        this->long_ = other.long_;
        this->nameOfAirport = other.nameOfAirport;
    }
    */

    bool operator<(const BFSVertex& other) const {
        return this->portID_ < other.portID_;
    }

};

class hashingFunc { 
public: 
    size_t operator()(const BFSVertex& p) const { 
        return p.portID_;
    } 
};