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
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "GraphAdjList.h"
using namespace std;

// You must add the long options code from the earlier example.
//static int verbose_flag;

int main(int argc, char *argv[])
{

 
  //    int option_read;

  // static struct option long_options[] =
  //   {
     
      
  //     {"in",     required_argument,       0, 'i'},
  //     {"out",  required_argument,       0, 'o'},
  //     {"alg",  required_argument, 0, 'a'},
  //     {0, 0, 0, 0}
  //   };
  //   string algo = "";
    ifstream ifile(argv[2]);
    ofstream ofile(argv[4],ios::out);


  // while (1)
  //   {
  //     /* getopt_long stores the option index here. */
  //     int option_index = 0;

  //     option_read = getopt_long (argc, argv, "i:o:a:",long_options, &option_index);

  //     /* Detect the end of the options. */
  //     if (option_read == -1)
  //       break;

  //     switch (option_read)
  //       {
  //       case 'i':
  //       ifile.open(optarg, ios::in);
  //         break;

  //       case 'o':
  //          ofile.open(optarg,ios:: out);
  //         break;

  //       case 'a':
  //         if(optarg=="prim"){
  //           algo = 1;
  //         }
  //         break;

  //       default:
  //         abort ();
  //       }
  //   }

     int N;

  //cout << argv[1] << " " << N << endl;

  ifile >> N;
  GraphAdjList G(N);
  
  int src, dest, weight;

  while (ifile >> src >> dest >> weight)
    {
      G.addedge(src, dest, weight);  // Make sure that bidirectional edges are added.
    }


  string algo(argv[6]);
  // Change this to long option
  if (algo == "kruskal")
    G.kruskal(ofile);
  if (algo=="prim")
    G.prim(ofile);

}

