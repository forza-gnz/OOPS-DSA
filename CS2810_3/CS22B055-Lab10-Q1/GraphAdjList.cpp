#include "GraphAdjList.h"

GraphAdjList::GraphAdjList(int nc, int ec): Graph(nc,ec)

{
  // Hint: resize() method of vector() can be invoked to create a vector
  // of required size. This will help avoid seg. faults

  AdjList.resize(nc);
  degree.resize(nc,0);
}

void GraphAdjList::addedge(int src, int dest, int weight){
        //  if(AdjList[src].find(dest)!=AdjList[src].end()){
        AdjList[src].insert(make_pair(dest,weight));
        degree[dest]++;
        // cout<<"inc " <<src <<" "<<dest<<endl;
        //  } 
        // cout<<"ans<"<<endl;
}  

void GraphAdjList::deledge(int src, int dest){
    degree[dest]--;
    for(auto it = AdjList[src].begin();it!=AdjList[src].end();it++){
      if(it->first==dest){
        AdjList[src].erase(dest);
      }
    }
    // edges--;
}

void printset(set<int> &S)
{
  cout << "*** \t Printing set with size k: " << S.size() << endl;
  for (auto ptr = S.begin(); ptr != S.end(); ptr++)
    cout << *ptr << " ";
  cout << "\n***\n" << endl;
}

void GraphAdjList::printgraph()
{
  int N = getnodecount();
  int E = getedgecount();

  cout << "\n** Printing graph **\n";

  cout << N << " " << E << endl;
  for (int node = 0; node < N; node++)
  {
    cout << "Degree of " << node << " is: " << degree[node] << endl;
    for (auto ptr = AdjList[node].begin(); ptr != AdjList[node].end(); ptr++)
    {
      cout << node << " " << ptr->first << " " << ptr->second << endl;
    }
  }

  cout << "\n** Printed graph **\n";
}

bool GraphAdjList::check(vector<int> S){
  
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

void calcSubset(vector<int>& A, vector<vector<int> >& res,vector<int>& subset, int index){

    
    res.push_back(subset);
    
    for (int i = index; i < A.size(); i++) {
        
        subset.push_back(A[i]);
        calcSubset(A, res, subset, i + 1);
        subset.pop_back();
    }
}

vector<vector<int> > subsets(vector<int>& A){

    vector<int> subset;
    vector<vector<int> > res;
    int index = 0;
    calcSubset(A, res, subset, index);
    return res;
}

// Create all subsets
// Go through each subset and cover all edges of nodes in this subset in the graph.
// if edgecount goes to the number of edges in the graph, then check if it is minimum sized
// return the minimum set

set<int> GraphAdjList::vcover_expon(){ 
  set<int> st;
  int n = getnodecount();
  vector<int> vc;

    vector<int> arr;
    for(int i=0;i<n;i++){
      arr.push_back(i);
    }
    vector<vector<int> > res = subsets(arr);


  // Print the generated subsets
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++){
            vc.push_back(res[i][j]);
            if(check(vc)){
              for(int i = 0;i<vc.size();i++){
                st.insert(vc[i]);
              }
              return st;
            }
        }
        vc.clear();
    }

  return st;
}

bool GraphAdjList:: checkedge(GraphAdjList &G1){
  bool flag =1;
  int n = getnodecount();
  for(int i=0;i<n;i++){
    if(G1.AdjList[i].size()==0){
        flag =1;
    }
    else{
      flag = false;
      
      return false;
    }
  }

  return true;
}

set<int> GraphAdjList::vcover_greedy(GraphAdjList &G1){
  set<int> vc;
  int n = getnodecount();
  
  GraphAdjList Gnew(G1);
  int k =-1;
  while(!checkedge(Gnew)){
    for(int i=0;i<n;i++){
      if(Gnew.AdjList[i].size()!=0){
        k = i;
    }
    }

    auto it = Gnew.AdjList[k].begin();
    vc.insert(it->first);
    vc.insert(it->first);
    int  u = it->first;
    int  v = it->second;


   
    for (auto ptr = Gnew.AdjList[u].begin(); ptr != Gnew.AdjList[u].end(); ptr++)
    {
      deledge(u,ptr->first);
    }
     for (auto ptr = Gnew.AdjList[v].begin(); ptr != Gnew.AdjList[v].end(); ptr++)
    {
      deledge(v,ptr->first);
    }
  }
    
  return vc;




}





