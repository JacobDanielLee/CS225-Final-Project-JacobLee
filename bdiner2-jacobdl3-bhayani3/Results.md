# Introduction
We used the openflights dataset which records the paths flights take around the world. We took two sets from this: ROUTES and AIRPORTS. The routes data was used for the edges of the graph and the airports data was used for the nodes of our graph.
Our purpose was to implement 3 different algorithms, BFS - that gives the least number of flights taken between the two airports, PageRank - which tells us how relevant an airport is, for example is one airport more important than the other airport, and finally Dijkstra’s algorithm, which takes into account the physical distance between the source and the destination airport, and returns the shortest path between the two airports, ignoring the number of flights and going for the total distance it can find via flights from one airport to the other that is closest to the displacement between the source and destination airports

 # Goals met and Implementation of Code
According to our proposal set out from the beginning, the goals that pertained to our project included the Dijkstra’s algorithm, PageRank Algorithm, and BFS Traversal to accompany data acquisitioning and processing from the OpenFlights Dataset. Amongst these goals, PageRank and BFS were completed with full development, while Dijkstra’s was implemented with mild difficulty and flawed implementation. Altogether, Dijkstra’s essentially bears the logic and reasoning to support a functioning algorithm, but more time would be needed to fully debug and complete a full development of the code. Data processing involved the creation of a graph class with Vertices objects for Nodes/Airports and Edges for Routes with a parsing function that successfully takes the data from a .txt file to a useful Graph class to be used across the project.

In regards to the optimization

Dijkstra: We used a min priority heap rather than a simple queue to store vertices to improve run time from O(n^2) to O((E+V)logn)
BFS: Maps and an adjacency list were used to speed up and simplify accessing the edges and vertices in our graph. 
PageRank: By utilizing an adjacency matrix and an eigenvector, simple matrix multiplication with proper probability distributions were used to adequately assess or approximate the converged ranking value of each node according to PageRank’s original implementation.

# Discoveries 
We gained a deeper understanding of how algorithms implemented in real life work and how optimizing an algorithm can be challenging. We also became more familiar with certain c++ coding techniques and functions that we otherwise hadn’t explored much. In regards to Pagerank, the implementation of an adjacency matrix and matrix multiplication proved to be a new concept to be well implemented. Such as the use of priority queue (min heap), maps and further usage of vectors, complexity for Dijkstra, the iterative nature of BFS.

# Challenges
One of the big challenges we had was how to implement storing the graph. Many methods for Djikstra’s algorithm call for an adjacency matrix/list but we tried simply using two vectors of edges and vertices and found out why people recommend that implementation. We ended up failing to complete dijkstra’s algorithm for shortest path because we could not properly traverse the data.

# Results 

For the results, we found that though our BFS algorithm may suggest a flight path that gives the least number of flights, for certain paths, the possibilities of different paths can be higher, for example, we discovered that flight path suggested by the algorithm from BOM airport to ORD was through AMM, but we can also replace AMM with AUH and DEL if we chose different airlines. Pagerank can be a bulky code to run and depending on the airport took about 40 seconds to run on the EWS machines. It would give the rank of an airport compared to other airports in the world in terms of the total flight traffic. 

# Conclusion
Overall, while difficulties were met implementing the Dijkstra’s algorithm for the flights, there was a strong collaborative effort towards tackling the greater tasks of data processing and parsing string information. Strong strides were made in the independence associated with this project and it proved to be very useful toward understanding real-world applications of data structures. 
