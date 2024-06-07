#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<algorithm>
#include<iterator>
#include<cassert>
#include<getopt.h>

#include "GraphAdjList.h"
using namespace std;

// You MUST add the long options code from the earlier example.

int main(int argc, char *argv[])
{
  // These are placeholders; replace with longopt.
  string ifile_1,ofile_1;
  


      int option_read;
       

int alg = 0, s = 0, t = 0;

  static struct option long_options[] =
    {
     
      
      {"in",     required_argument,       0, 'i'},
      {"out",  required_argument,       0, 'o'},
      {"alg",  required_argument, 0, 'a'},
      {"src", required_argument, 0 , 's'},
      {"dest", required_argument, 0 ,'t'},
      
    };

   while (1)
    {
      /* getopt_long stores the option index here. */
      int option_index = 0;

      option_read = getopt_long (argc, argv, "a:b:c:d:e",
                       long_options, &option_index);

      /* Detect the end of the options. */
      if (option_read == -1)
        break;

      string s;
      switch (option_read)
        {
        case 'a':
          ifile_1 = optarg;
          break;

        case 'b':
          ofile_1 = optarg;
          break;

        case 'c':
          s = optarg;
          alg = s == "dij";
          break;
        
        case 'd':
          s = stoi(optarg);
          break;
          
        case 'e':
          t = stoi(optarg);
          break;

        default:
          abort ();
        }
    }



  ifstream ifile(argv[1]);
  ofstream ofile(argv[2], ios::out);
  int N;

  //cout << argv[1] << " " << N << endl;

  ifile >> N;
  GraphAdjList G(N);
  
  int src, dest, weight;
  
  while (ifile >> src >> dest >> weight)
    {
      G.addedge(src, dest, weight);
      G.addedge(dest, src, weight);
      // Make sure that bidirectional edges are added.
    }

  
  // These are placeholders; replace with longopt.
  // Only one algorithm will be invoked in a given run of the executable.
  // s = stoi(argv[3]);
  // t = stoi(argv[4]);

  assert( (s >= 0 && s < N) && (t >= 0 && t < N));

  if(alg)
  {
    auto [SPath, tcost] = G.dijkstra(s, t);

    while (!SPath.empty())
      {
        int n;
        n = SPath.top();
        ofile << n << " ";
        SPath.pop();
      }

    ofile << "; " << tcost << endl;
  } 
  else
  {
    auto [SPath1, tcost1] = G.flowarsh(s, t);

    while (!SPath1.empty())
      {
        int n;
        n = SPath1.top();
        ofile << n << " ";
        SPath1.pop();
      }

    ofile << "; " << tcost1 << endl;
  }


}

