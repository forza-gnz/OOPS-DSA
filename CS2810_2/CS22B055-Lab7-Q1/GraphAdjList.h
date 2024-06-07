#include<ostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include <algorithm>
#include <iterator>
#include "Graph.h"
using namespace std;

#pragma once

class GraphAdjList: public Graph
{
 private:
  vector< map<int, int, less <int> > > AdjList;
  vector<int> indegree;	// Initialized to zero
  
 public:
  GraphAdjList(int nc = 0, int ec = 0);

  void addedge(int src, int dest, int weight);
  void deledge(int src, int dest);

  // First int -> weight of edge
  // Second int -> first node of edge
  // Third int -> second node of edge
  // Used in storing a priority_queue, sorted by edge weights.

  void kruskal(ofstream &ofile);

  void prim(ofstream &ofile);
  
  void printgraph();

};
