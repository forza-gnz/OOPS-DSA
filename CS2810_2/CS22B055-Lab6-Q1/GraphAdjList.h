#include<ostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
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

  void PRint();

  void addedge(int src, int dest, int weight);
  void deledge(int src, int dest);
  vector<int> toposort();
  void printgraph();
  bool validateTS(vector<int> TS);
};
