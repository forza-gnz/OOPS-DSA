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
    
}

// void GraphAdjList::PRint(){
//   for(int i =0;i<indegree.size();i++){
//       cout<<indegree[i]<<" "; 
//   }
//   cout<<endl;
// }


// int GraphAdjList::getN(){
//   return getnodecount();
// }

void GraphAdjList::printgraph(){
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

set<int> GraphAdjList::vcover_expon(){ 

  int n = getnodecount();
  queue<int> subset;
  for(int k = 1; k <= n ; k++){
        for(int i=0; i<k; i++){
          subset.push(i);
        }
        if(check(subset)){
          return set_to_queue(subset);
        }

        for(int i=k ; i<n; i++){
          subset.pop();
          subset.push(i);
          if(check(subset)){
            return queue_to_set(subset);
          }
        }
}
}

bool GraphAdjList::check(queue<int> S){
  
  bool check1 = true;
   
  for(int i=0;i<S.size();i++){
    for (auto ptr = AdjList[i].begin();ptr != AdjList[i].end();ptr++){
      for(int j=0;j<S.size();j++){
        if(ptr->first == j || ptr->second == j){
            check1 = true;
        }
        else{
            return false;
        }
      }
    }
  }

  return true;

}

set<int> GraphAdjList::vcover_greedy(){
  
}