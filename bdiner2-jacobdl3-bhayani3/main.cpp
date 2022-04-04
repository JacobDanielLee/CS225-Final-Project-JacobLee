#include "shortestPath.h"
#include "leastFlights.h"
#include "mostPopular.h"


int main(){
    
//Djikstra running on small data set.
char input = 'N';
bool isValid = false;
cout<<"please select the algorithm you wanna run, 'D' for Dijkstra's, 'B', for BFS and 'P' for Pagerank: ";
cin >> input;
while(isValid != true){
     if(input == 'D') {
          	Graph t("Data/PageRankRoutesTest.txt","Data/PageRankAirportsTest.txt");
			cout<<"Enter an airport ID as a starting location: ";
           	int start_id, dest_id;
            cin>>start_id;
            cout<<"Enter an airport ID as a destination location: ";
            cin>>dest_id;

			shortestPath s(t.getVertex(start_id), t.getVertex(dest_id));
			queue<pair<double, Graph::Vertex>> path = s.dijkstra(t, s.source);

			s.printPath(path);

          //insert code here
          isValid = true;
     } else if (input == 'B') {
          leastFlights lf;
          lf.callout("Data/routescleaned.txt","Data/airportscleaned.txt");
          isValid = true;
     } else if (input == 'P') {
          int src;
          cout << "Please enter a Numerical airport ID from 'Data/airports.txt' to set as Source ID for Pagerank: ";
          cin >> src;
          BFSGraph g("Data/routescleaned.txt", "Data/airportscleaned.txt");
          Popular example;
          Graph t("Data/routescleaned.txt","Data/airportscleaned.txt");
          BFSVertex e = g.m[src];
          example.popular(t);
          cout << "Airport's Relevance: " << example.deliverable.at(e.nameOfAirport) << endl;
          isValid = true;
     } else {
          cout<<"please enter a valid input";
          cin >> input;
     }
}

return 0;
}
