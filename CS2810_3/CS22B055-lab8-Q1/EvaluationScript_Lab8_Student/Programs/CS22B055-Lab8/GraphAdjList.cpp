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
#include<cstdint>

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

std::tuple<stack<int>, int> GraphAdjList::dijkstra(int src, int dest){
  // set<int> st;
  int N = getnodecount();
  int inf = INT16_MAX;

  priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;

  vector<int> dist(N,inf);
  vector<int> prev;

  dist[src] = 0;
  Q.push(make_pair(0,src));
  // cout<<"check1"<<endl;

  while(!Q.empty()){
    int node = Q.top().second;
    int dis = Q.top().first;
    Q.pop();

    for(auto it: AdjList[node]){
      int v = it.first;
      int w = it.second;

      if(dis + w < dist[v] ){
        dist[node] = dis + w;
        prev.push_back(node);
        Q.push(make_pair(dis+w, v));
      }
    }
  }

  // cout<<"check2"<<endl;

  stack<int> st;
  int d = dest;

  while(d!=src){
    st.push(d);
    d = prev[d];
  }
  // cout<<"checak3"<<endl;

  st.push(src);
  tuple< stack<int>, int > t = {st, dist[dest]};
  return t;

}


std::tuple<stack<int>, int> GraphAdjList::flowarsh(int src, int dest){
  int N = getnodecount();
  int inf = INT32_MAX;
  int d[N][N];

  for(int i = 0; i<N ;i++){
    for(int j = 0; j<N ; j++){
      for(auto it : AdjList[i]){          
          if(it.first == j){
            d[i][j] = it.second;
          }
          else{
            d[i][j] = inf;
          }
      }
    }
  }



  // for(int i=0;i<Adjl)
  
  for(int i=0;i<N;i++){
    d[i][i] = 0; // for Diagnal Elements 0;
  }

  // cout<<"check11"<<endl;
   // making of Adjmatrix Wrt to their weight
  vector<vector<int>> PI(N,vector<int>(N,-1));

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i==j || d[i][j]==inf){
        
        PI[i][j] = -1;
      }
      else if(i!=j && d[i][j]<inf){
        PI[i][j] = i;
      }
    }
  }

  // cout<<"check12"<<endl;


  for(int k = 0;k <N; k++){
      for(int i=0;i<N;i++){
        for(int j =0;j<N;j++){

          if(d[i][j] > d[i][k] + d[k][j]){
            d[i][j] = d[i][k] + d[k][j];
            PI[i][j] = PI[k][j];
          }

        }
      }
  }
  // cout<<"cehcek13"<<endl;

  stack<int> st = short_Path_FW(PI,src,dest);

  // cout<<"check14"<<endl;
  
  tuple< stack<int> , int > t = {st,d[src][dest]};
  return t;

  

}
// int GraphAdjList::getN(){
//   return getnodecount();
// }

stack<int> GraphAdjList::short_Path_FW(vector<vector<int>> pi,int i, int j){
  int n = getnodecount();
  // cout<<"21"<<endl;
  stack<int> ans;
  if(i==j){
    ans.push(i);
  }
  
  else{
    if(pi[i][j]==-1){
      //do nothing i.e no path exist 
    }
    else{
      short_Path_FW(pi,i,pi[i][j]);
      ans.push(j);
    }

  }
  // cout<<"51"<<endl;
  return ans;
}


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

// Please verify if this code is correct, before proceeding.
// This validates if a given TS output is valid (meeting the edge
// constraints of the graph).  
// bool GraphAdjList::validateTS(vector<int> TS)
// {
//   int nid1, nid2;
  
//   for (int i = 0; i < TS.size(); i++)
//     {
//       nid1 = TS[i];

//       for (int j = i; j < TS.size(); j++)
// 	{
// 	  nid2 = TS[j];
// 	  if (AdjList[nid2].find(nid1) != AdjList[nid2].end())
// 	    return false;
// 	}
//     }

//   return true;
  
// }
