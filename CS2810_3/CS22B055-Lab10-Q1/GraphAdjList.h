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
  vector<int> degree; // degree of each vertex
  
 public:
  GraphAdjList(int nc = 0, int ec = 0);

  // Create a copy of original graph.
  GraphAdjList(const GraphAdjList& G1): Graph(0, 0)
  {
    *this = G1;
  }

  void addedge(int src, int dest, int weight);
  void deledge(int src, int dest);

  void DeleteNodeEdges(int m); // Implement, if needed.

  bool checkedge(GraphAdjList &G1);

  set<int> vcover_expon();
  set<int> vcover_greedy(GraphAdjList &G1);

  void printgraph(); // Implement, if needed.

  // verify the vertex cover output of your function
  bool verifyVC(set<int> S);

  set<int> queue_to_set(queue<int> Q){
    set<int> s;
    int i;

    while(!Q.empty()){
      i = Q.front();
      Q.pop();
  
      s.insert(i);
    }
    return s;
  }

  bool check(vector<int> S);
  
};
