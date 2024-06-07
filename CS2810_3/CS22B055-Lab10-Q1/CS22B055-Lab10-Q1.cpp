#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
#include<iterator>
#include<cassert>
#include <stdlib.h>
#include <getopt.h>
#include "GraphAdjList.h"
using namespace std;

int main(int argc, char *argv[])
{
  ifstream ifile;
  ofstream ofile;
  int N;
  string alg;

  static struct option long_options[] =
  {
    {"in",  required_argument, 0, 'i'},
    {"out",  required_argument, 0, 'o'},
    {"alg", required_argument, 0, 'a'},
    {0, 0, 0, 0}
  };
  
  while (1)
  {
    /* getopt_long stores the option index here. */
    int option_index = 0;
    int id;

    id = getopt_long (argc, argv, "i:o:a:", long_options, &option_index);

    /* Detect the end of the options. */
    if (id == -1)
      break;

    switch (id)
    {
    case 'i':
      ifile.open(optarg, ios::in);
      break;

    case 'o':
      ofile.open(optarg, ios::out);
      break;

    case 'a':
      alg = string(optarg);
      break;

    default:
      abort ();
    }
  }

  ifile >> N;
  GraphAdjList G(N);
  
  int src, dest, weight;
  
  while (ifile >> src >> dest >> weight)
  {
    G.addedge(src, dest, weight);
    G.addedge(dest, src, weight);
    // Make sure that bidirectional edges are added.
  }

  set<int> S;

  if (alg == "grd")
  {
    S.clear();
    S = G.vcover_greedy(G);
    for (auto ptr = S.begin(); ptr != S.end(); ptr++)
      ofile << *ptr << " ";
    ofile << endl;

  }
  
  if (alg == "exp")
  {
    S.clear();
    S = G.vcover_expon();
    for (auto ptr = S.begin(); ptr != S.end(); ptr++)
      ofile << *ptr << " ";
    ofile << endl;
  }
}
