// Roll Number: CS22B055
// Name: Neeraj Bandhey
// CS2810 Lab Number: 6
// Date: 12th of March , 2024, 2pm
// Question No. 1 (2, etc. as appropriate)
// This submission is based entirely on my efforts. I realize that
// any form of academic dishonesty with respect to the Lab assignment
// will result in
// corrective action imposed by the IIT Madras Senate.
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<iterator>

#include "GraphAdjList.h"
using namespace std;

int main(int argc, char *argv[])
{
  // ifstream ifile;
  

  ifstream ifile(argv[1]);
  ofstream ofile;
  ofile.open(argv[2]);
  int N;
  // cin>> N;
  ifile>>N;

  GraphAdjList G(N,0);
  int s,d,w;
  while(ifile>>s>>d>>w){
    
    // ifile>>s>>d>>w;
    G.addedge(s,d,w);
  }

  // G.PRint();
  
  vector<int> TS;
  
  TS = G.toposort();

  for(int i=0;i<TS.size();i++){
    // cout<<TS[i]<<" ";
    ofile<<TS[i]<<" ";
    
  }

  // Uncomment this for testing purposes ONLY; Comment it before submission.
  //  bool valid = G.validateTS(TS);
  //  cout << "Topo Sort is Correct? " << valid << endl;
}
