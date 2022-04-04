//Page rank
#include "graph.h"
#include "graph.cpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include "mostPopular.h"

using namespace std;



std::map<string,double> Popular::popular(Graph ge) {
/*PageRank Algorithm 
1. Store number of airports
2. Set Number of Iterations
3. Set a damping factor
4. Create adjacency matrix
5. Fill Adjacency Matrix with Data
6. Create a eigenvector of size n with sum of values of 1
7. By using 20 iterations derive vector v_k by taking the matrix to the kth power and multiplying by the initial eigenvector (step 6)
8. Put values of v_k into a dictionary with respective airport in key slots
9. Return Dictionary of Popular::Airport and Priority Values
*/

    //Sets working graph to input
    Graph g = ge;

    //If input does not exist, set default
    if (ge.vertices_.empty() && ge.edges_.empty()) {
        Graph temp("Data/routescleaned.txt","Data/airportscleaned.txt");
        g = temp;
    }

//Variable to store size of airport universe
    int airportSize = g.vertices_.size();
    //Standard default iterations to produce ranked result
    int iterations = 20;

    //Map of airports that contain respective position in vector and object
    map<int, Popular::Airport> ref;

// Fills map with data including port and index
    for (int i = 0; i < airportSize; i++) {
        Popular::Airport port(g.vertices_[i]);
        ref[g.vertices_[i].airportID_] = port;
        ref[g.vertices_[i].airportID_].index = i;
    }


// Map of Airports gets outdegree data filled in
    for (unsigned i = 0; i < g.edges_.size(); i++) {
        Graph::Edge it = g.edges_[i];
        ref[it.srcId_].outdegrees++;
    }
    

//Creates 2-D adjacency matrix
    vector<vector<double> > a(airportSize, vector<double>(airportSize, 0.0));
    //For every existing airplane route, affirm connection between airports
    for (unsigned i = 0; i < g.edges_.size(); i++) {
        int temp1 = 0;
        int temp2 = 0;
        Graph::Edge it = g.edges_[i];
        temp1 = ref[it.srcId_].index;
        temp2 = ref[it.destId_].index;
        //Sets initial probability value
        double value = 1.0 / (double)ref[it.srcId_].outdegrees;
        a[temp2][temp1] = value;
    }

    //Initialize eigenvector to multiply and transform matrix
    vector<double> eigenvector((double)airportSize, 1.0 / (double)airportSize);

//Runs through iterations to rearrange values
    for (int iter = 0; iter < iterations; iter++) {
        vector<double> temp;
//Matrix multiplication of NxN matrix and Nx1 Eigenvector
        for (int i = 0; i < airportSize; i++) {
            double newVal = 0.0;
            for (int j = 0; j < airportSize; j++) {
                newVal += a[i][j] * eigenvector[j];
            }
            temp.push_back(newVal);
        }
        //Eigenvector set with new redistributed probabilities
        eigenvector = temp;
    }
    
//Initializes return map
    map<string, double> pagerank;
    //Creates map iterator for future loading
    map<string, double>:: iterator it;

//Loads pagerank with final results of eigenvector
    for (unsigned i = 0; i < eigenvector.size(); i++) {
        pagerank[g.vertices_[i].airportName_] = eigenvector[i];
    }       

//Set access map to pagerank return result;
    deliverable = pagerank;
    //Return Pagerank
    return pagerank;
}
