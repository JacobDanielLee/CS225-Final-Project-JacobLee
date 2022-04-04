# Team Proposal (bdiner2-jacobdl3-garyhl2-bhayani3) 

## Leading Question
We want to use the Openflights dataset to find the shortest flight path between a given starting location and destination. We want to be able to search the list of airports/nodes on the map and be able to sort by longest/shortest paths.
From the data set, we will be learning the shortest path between two nodes (airports) between the world given a directed graph of flight paths. We are hoping to help people pick out the shortest flight plan for when they book their airline tickets. The team agreed on the ideas for what the project will look like. 

## Dataset Acquisition and Processing

We’ll be using the Openflights dataset available here: https://openflights.org/data.html
We will turn each airport into a node that has its unique characteristics like location/ID/country and then also use the routes dataset to sort distances and shortest path.
The two datasets are downloadable in .dat form and we’ll begin by checking the data for errors in excel. If there's missing/broken entries we’ll fix them if it’s possible or delete them if the data is corrupted or not reasonably fixable. 
Graph Algorithms 
 
### Dikjstra’s Algorithm
Purpose:  To find the shortest path between the starting and destination
inputs:  Starting point and Ending point as nodes
outputs: shortest route, route length, 
Efficiency: O(ElogV), where E is the number edges (Flight paths) and V is the number of Vertices (Destination points)

### PageRank Algorithm
Purpose:  To identify the most visited airports around the world using the amount of flights to the airports as the criteria for it being “famous”
inputs:  It will take frequency of flights going in and out of various airports
outputs: output the top n number of airports visited
Effiiency: O(V+E) where v is the number of vertices(the airports) and E is the edges(the flights)
BFS traversal algorithm
	Purpose: It will be our graph traversal algorithm to search the airports from the database given to us, we will be using this algorithm to assist the other algorithms

## Timeline 
submit the proposal and contracts by 9th April
Obtain and setup the database by 14th April
Complete BFS by 21st April
Complete Dikjstra’s Algorithm by 28th April
Complete PageRank by the 5th May
Complete optimizations and final touches by 10th May
