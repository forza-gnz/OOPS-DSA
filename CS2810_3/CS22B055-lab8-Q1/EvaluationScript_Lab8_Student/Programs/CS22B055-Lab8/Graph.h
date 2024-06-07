#include<iostream>
#include<vector>
#include<stack> 
using namespace std;
// Node indices go from 0 to nodes-1
// Edge indices go from 0 to edges-1
// Edge weights are integer values

#pragma once
class Graph
{
 private:
  int nodes;
  int edges;

 public:

  Graph(int nc = 0, int ec = 0)
    {
      nodes = nc;
      edges = ec;
    }

  void setnodecount(int nodecount);
  int getnodecount();

  void setedgecount(int edgecount);
  int getedgecount();

  virtual void addedge(int src, int dest, int weight) = 0;
  virtual void deledge(int src, int dest) = 0;
  virtual void printgraph() = 0;

  virtual std::tuple< stack<int>, int>
  dijkstra(int src, int dest) = 0;

  virtual std::tuple< stack<int>, int>
  flowarsh (int src, int dest) = 0;

};
