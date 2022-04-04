#include <string>
#include <vector>
#include <map>

#include "../leastFlights.h"
#include "../BFSGraph.h"
#include "../cs225/catch/catch.hpp"
#include "../readFromFile.hpp"
#include "../graph.h"
#include "../mostPopular.h"

/*
TEST_CASE("Verify that file_to_string works on a small example") {
	std::string res = file_to_string("tests/smallSample.txt");
	// always check "expected" == "actual" --> be consistent
	REQUIRE("hello\ngroupmates\nof\ncs\n225\n!!!\n" == res);
}

TEST_CASE("Verify that file_to_vector works on a small example") {
	std::vector<std::string> res = file_to_vector("tests/smallSample.txt");
	std::string expected[] = {"hello", "groupmates", "of", "cs", "225", "!!!"};
	
	REQUIRE(6 == res.size());

	for (int i = 0; i < res.size(); i++) {
		REQUIRE(expected[i] == res[i]);
	}
}

TEST_CASE("Verify Edge length is correct within 1km"){
    Edge e = Edge(111, Vertex(12, "airport", 20, 10), Vertex(13, "airport2", 10, 20));
    double trueDist = 1544;

    REQUIRE(trueDist - e.getLength() < 1);
}
*/

TEST_CASE("Verify that PageRank demonstrates convergence"){
	Graph g("Data/PageRankRoutesTest.txt","Data/PageRankAirportsTest.txt");
	std::map<string,double> result;
	result["Goroka Airport"] = 0.0;
	result["Madang Airport"] = 0.4;
	result["Mount Hagen Kagamuga Airport"] = 0.2;
	result["Nadzab Airport"] = 0.2;
	result["Port Moresby Jacksons International Airport"] = 0.0;

	Popular t;
	t.popular(g);

	std::map<string, double>:: iterator it;

	for ( it = t.deliverable.begin(); it != t.deliverable.end(); it++) {
		it->second = round(it->second * 10.0) / 10.0;
	}

	std::map<string, double>:: iterator j;

	bool tester = true;
	for ( it = t.deliverable.begin(); it != t.deliverable.end(); it++) {
		for (j = result.begin(); j != result.end(); j++) {
			if ((it->second - j->second) >= 0.5) {
				tester = false;
			}
		}
	}

	REQUIRE(tester == true);
}


TEST_CASE("bfs test") {
    // BFSGraph small = BFSGraph("tests/BFStestRoutes.txt", "tests/BFStestAirports.txt");
    BFSGraph g("Data/routescleaned.txt", "Data/airportscleaned.txt");
    BFSVertex BOM = g.m[2997];/*BFSVertex(2997, 19.08869934,72.86789703, "Chhatrapati Shivaji International Airport");*/
    BFSVertex AMM = g.m[2170];/*BFSVertex(2170,31.72260094,35.99319839, "Queen Alia International Airport");*/
    BFSVertex ORD =g.m[3830]; /*BFSVertex(3830,41.9786,-87.9048, "Chicago O'Hare International Airport");*/
    BFSEdge route1 = BFSEdge(BOM, AMM, "RJ");
    BFSEdge route2 = BFSEdge(AMM, ORD, "AA");

    leastFlights direct(BOM, ORD);
    std::vector<BFSEdge> directPath = direct.BFS(g);
    REQUIRE(directPath.size() == 2);
    REQUIRE(directPath[0] == route1);
}
