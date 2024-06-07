// Roll Number: CS22B055
// Name: Neeraj Bandhey
// CS2810 Lab Number: 6
// Date: 12th of March , 2024, 2pm
// Question No. 1 (2, etc. as appropriate)
// This submission is based entirely on my efforts. I realize that
// any form of academic dishonesty with respect to the Lab assignment
// will result in
// corrective action imposed by the IIT Madras Senate.
#include "GraphAdjList.h"

GraphAdjList::GraphAdjList(int nc, int ec): Graph(nc,ec)

{
  // Hint: resize() method of vector() can be invoked to create a vector
  // of required size. This will help avoid seg. faults

  AdjList.resize(nc);
  indegree.resize(nc,0);
}

void GraphAdjList::addedge(int src, int dest, int weight){
        //  if(AdjList[src].find(dest)!=AdjList[src].end()){
        AdjList[src].insert(make_pair(dest,weight));
        indegree[dest]++;
        // cout<<"inc " <<src <<" "<<dest<<endl;
        //  } 
        // cout<<"ans<"<<endl;
}  

void GraphAdjList::deledge(int src, int dest){
    indegree[dest]--;
    for(auto it = AdjList[src].begin();it!=AdjList[src].end();it++){
      if(it->first==dest){
        AdjList[src].erase(dest);
      }
    }
    // edges--;
}

// void GraphAdjList::PRint(){
//   for(int i =0;i<indegree.size();i++){
//       cout<<indegree[i]<<" "; 
//   }
//   cout<<endl;
// }

vector<int> GraphAdjList::toposort(){
    vector<int> ans;
    queue<int> Q;
    int n = getnodecount();
    // cout<<"count "<< n <<endl;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            Q.push(i);
            indegree[i] =-1;
        }
    }

    while(!Q.empty() ){
        int x = Q.front();
        Q.pop();
        ans.push_back(x);

        for(auto it = AdjList[x].begin();it!=AdjList[x].end();it++){
            indegree[it->first]--; //updating indegree
            if(indegree[it->first]==0)Q.push(it->first);
        }
        // indegree[x] = -1; 
    }
        // for(int i=0;i<n ;i++){
        //     if(indegree[i]==0){
        //         Q.push(i);
        //         indegree[i] = -1;

        //     }
        // }
    

    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" "<<endl;
    // }
    

    return ans;
}




void GraphAdjList::printgraph()
{
  int N = getnodecount();
  int E = getedgecount();

  cout << N << " " << E << endl;
  for (int node = 0; node < N; node++)
    {
      for (auto ptr = AdjList[node].begin();
	   ptr != AdjList[node].end();
	   ptr++)
	{
	  cout << node << " " << ptr->first << " " << ptr->second << endl;
	}
    }
}

// Please verify if this code is correct, before proceeding.
// This validates if a given TS output is valid (meeting the edge
// constraints of the graph).  
bool GraphAdjList::validateTS(vector<int> TS)
{
  int nid1, nid2;
  
  for (int i = 0; i < TS.size(); i++)
    {
      nid1 = TS[i];

      for (int j = i; j < TS.size(); j++)
	{
	  nid2 = TS[j];
	  if (AdjList[nid2].find(nid1) != AdjList[nid2].end())
	    return false;
	}
    }

  return true;
  
}
