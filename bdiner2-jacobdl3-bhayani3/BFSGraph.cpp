#include "BFSGraph.h"
#include <set>

using namespace std;

BFSGraph::BFSGraph(const string& routes, const string& airports){
    string a = file_to_string(airports);
    string r = file_to_string(routes);
    vector<vector<string>> airportsFile;
    vector<vector<string>> routesFile;

    vector<string> result = doLines(a);
    size_t ite = 0;
    while ( ite < result.size()) {
        airportsFile.push_back(vectorise(result[ite]));
        ite++;
    }

    vector<string> result2 = doLines(r);
    size_t t = 0;
    while (t < result2.size()) {
        routesFile.push_back(vectorise(result2[t]));
        t++;
    }
    size_t i = 0;
    while (i < airportsFile.size()){
        BFSVertex insert;
        stringstream portID(airportsFile[i][0]);
        stringstream lat_(airportsFile[i][5]);
        stringstream long_(airportsFile[i][6]);
        insert.portID_ = atoi(portID.str().c_str());
        insert.lat_ = atoi(lat_.str().c_str());
        insert.long_ = atoi(long_.str().c_str());
        insert.nameOfAirport = airportsFile[i][1];
        
        vertexIns(insert);
        m[insert.portID_] = insert;
        i++;
    }
    size_t j =0;
    while(j<routesFile.size()){
        stringstream sourceID(routesFile[j][2]);
        stringstream destID(routesFile[j][4]);
        string airline = routesFile[j][1];
        int sourceId = 0;
        int destinationId = 0;
        sourceId = atoi(sourceID.str().c_str());
        destinationId = atoi(destID.str().c_str());
        if (m[sourceId].portID_ != 0 && m[destinationId].portID_ != 0) {
            edgeIns(m[sourceId], m[destinationId], airline);
        }
        BFSEdge sameEdge = setEdge(m[sourceId], m[destinationId], distanceCalculate(m[sourceId], m[destinationId]));
        j++;
    }
}

string BFSGraph::file_to_string(const std::string & filename) {
    ifstream tex(filename);

    stringstream strStream;
    if (tex.is_open()) {
        strStream << tex.rdbuf();
    }

    return strStream.str();
}

vector<string> BFSGraph::vectorise(string s) {
    vector<string> v;
    string str;
    for(size_t i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ','){
            v.push_back(str);
            str.clear();
        } else{
            str +=string(1,s[i]);
        }
    }
    return v;
}

vector<string> BFSGraph::doLines(string sentence) {
    std::stringstream ss(sentence);
    std::string to;
    vector<string> result;
  
    while(std::getline(ss,to,'\n')){
        result.push_back(to);
    }

    return result;
}

void BFSGraph::vertexIns(BFSVertex v){
    adjacent[v] = unordered_map<BFSVertex, BFSEdge, hashingFunc>();
}

vector<BFSVertex> BFSGraph::getVertices() const{
    vector<BFSVertex> toReturn;
    for(auto it = adjacent.begin(); it != adjacent.end(); it++){
        if (it->first.portID_ != 0) {
            toReturn.push_back(it->first);
        }
        
    }

    return toReturn;
}

long double BFSGraph::distanceCalculate(BFSVertex source, BFSVertex destination) {
    source.lat_ = ((source.lat_)*(M_PI/180)); 
    source.long_ = ((source.long_)*(M_PI/180));
    destination.lat_ = ((destination.lat_)*(M_PI/180)); 
    destination.long_ = ((destination.long_)*(M_PI/180)); 
    long double longitude = destination.long_ - source.long_; 
    long double latitude = destination.lat_ - source.lat_; 
  
    long double ans = pow(sin(latitude / 2), 2) +  cos(source.lat_) * cos(destination.lat_) *  pow(sin(longitude / 2), 2); 
  
    ans = 2 * asin(sqrt(ans)) * 6378; 
    return ans; 
}

void BFSGraph::edgeIns(BFSVertex source, BFSVertex destination, string airline) {
    if (source.portID_ == 0 || destination.portID_ == 0) {
        return;
    }
    //checking if the edge exists
    if(adjacent.find(source)!= adjacent.end() 
    && adjacent[source].find(destination)!= adjacent[source].end()){
        return;
    }
    
    if(adjacent.find(source)==adjacent.end()){
        adjacent[source] = unordered_map<BFSVertex, BFSEdge, hashingFunc>();
    }
    adjacent[source][destination] = BFSEdge(source, destination, airline);
}

vector<BFSVertex> BFSGraph::getNearby(BFSVertex source) const {
    auto look = adjacent.find(source);
    if(look == adjacent.end()) {
        return vector<BFSVertex>();
    }
        

    else{
        vector<BFSVertex> vertex_list;
        unordered_map <BFSVertex, BFSEdge, hashingFunc> & map = adjacent[source];
        for (auto it = map.begin(); it != map.end(); it++)
        {
            vertex_list.push_back(it->first);
        }
        return vertex_list;
    }
}

BFSEdge BFSGraph::getEdge(BFSVertex source , BFSVertex destination) const{
    BFSEdge toReturn = adjacent[source][destination];
    return toReturn;
}

BFSEdge BFSGraph::setEdge(BFSVertex source, BFSVertex destination, long double weight){
    BFSEdge e = adjacent[source][destination];
    BFSEdge new_edge(source, destination, weight, e.airline);
    adjacent[source][destination] = new_edge;
    return new_edge;
}

vector<BFSEdge> BFSGraph::getEdges() const{
    if (adjacent.empty())
        return vector<BFSEdge>();

    vector<BFSEdge> toReturn;
    set<pair<BFSVertex, BFSVertex>> checked;

    for (auto it = adjacent.begin(); it != adjacent.end(); it++){
        BFSVertex source = it->first;
        for (auto its = adjacent[source].begin(); its != adjacent[source].end(); its++){
            BFSVertex destination = its->first;
            if(checked.find(make_pair(source, destination)) == checked.end()){
                toReturn.push_back(its->second);
                checked.insert(make_pair(source,destination));
            }
        }
    }

    return toReturn;
}