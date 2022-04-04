#### bdiner2-jacobdl3-bhayani3

# Note: This upload is done by Jacob Lee and is of a final group project conducted in the spring semester of 2021 in CS225 between Brian Diner, Rushabh Bhayani, and Jacob Lee. Its purpose is to merely demonstrate previous academic work and is not to be copied or referenced by students per academic policy. 
The work on all files reflects collaborative efforts except for shortestPath, leastFlights, and mostPopular. This work is published by Jacob Lee to demonstrate performance of the mostPopular algorithm, which reflects his contribution of the PageRank algorithm to the project's data. 



# Final Project
Dataset: Open Flights
Major amount of the code resides in the leastFlights.cpp, shortestPath.cpp and mostPopular.cpp files containing the BFS, Dijkstra’s and PageRank Algorithm respectively. With the graph.cpp and BFSGraph  containing the graph class and graph related functions. 

The BFS algorithm allows the user to traverse through the dataset and find a path from one source airport (Vertex) to another destination airport with the least number of flights taken (least number of edges). 

Whereas the Dijkstra's gives the user a path with the shortest distance in Km between the airports and doesn't care for the number of flights taken, just the distance travelled.

In the case of PageRank Algorithm, which tells the relavance of the website by the number of clicks to it, we replaced the website part of it with airports (vertices) and the number of clicks with flights (the number of edges for each vertex), which told us the relavance of each airport, relevance in this case accounts for the amount of traffic, the number of flights to and from and the edges to the number of different airports. 

# Final Presentation
//post link here

## How to run the project
*To run the project, the following commands must be used :*

`module load llvm/6.0.1`

`make && ./final`

`make test && ./test`

After which, the on-screen instructions on the console should guide you to each algorithm by inputting a charachter which represents the algorithm

### Shortest Path (Djiktra), 'D'
upon entering the following, it will lead you to Djiktra 

`D`

From here you can select between any two airports in the world using their airport ID's which can be ofund in data/airportscleaned.txt and data/routescleaned.txt

The result should be the route that covers the least distance and the total distance traveled.

*Sample output*

`Enter an airport ID as a starting location: 1`

`Enter an airport ID as a destination location: 4`

`path found`

`Shortest Path: Goroka Airport -> Distance Traveled: 0`

### Fewest Stops (BFS), 
upon entering the following, it will lead you to BFS

`B`

In BFS, you will first be asked to input a source Airport ID from "Data/airportscleaned.txt" and then a destination airport ID from the same file. Upon doing this, it should display a flight path on the screen where it will show you the least number of flights that need to be taken to reach destination airport from the source one. 

*Sample output*

`Please enter a Numerical airport ID from 'Data/Airports.txt' to set as Source ID: 2997`

`You have selected Chhatrapati Shivaji International Airport as your source airport`

`Please enter a Numerical airport ID from 'Data/Airports.txt' to set as Destination ID: 3830`

`You have selected Chicago O'Hare International Airport as your destination airport`

Results: 

`path1: Chhatrapati Shivaji International Airport -> Queen Alia International Airport, the distance for the flight is 3942.6 KM`

`path2: Queen Alia International Airport -> Chicago O'Hare International Airport, the distance for the flight is 10049.9 KM`

### Most visited (PageRank)
upon entering the following, it will lead you to PageRank

`P`

In PageRank you will be asked to input a ID for an airport that you want the relevance for. 

*Sample Output*

`Please enter a Numerical airport ID from 'Data/airports.txt' to set as Source ID for Pagerank: 3830`

`Airport's Relevance: 133163`
