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

void GraphAdjList::kruskal(ofstream &ofile){
    priority_queue< pair<int,
    pair<int, int> >, vector<pair<int, pair<int, int> > >,
    greater<pair<int, pair<int, int> > > > EdgesPQ;
    
    for(int i=0;i<getnodecount();i++){
        for (auto ptr = AdjList[i /*curnode*/].begin();
        ptr != AdjList[i/*curnode*/].end(); ptr++){
        
        EdgesPQ.push(make_pair(ptr->second,
                make_pair(i/*curnode*/, ptr->first)));
        // cout << curnode
        // << " " << ptr->first << " " << ptr->second << endl;
        }
    }

    vector< pair<int, pair<int, int> > > v;
    int n = getnodecount();


    vector<set<int>> st(n);
    
    while(EdgesPQ.size()){
          
        pair<int, pair<int, int> > edge1;       
        edge1 = EdgesPQ.top();
        int src = edge1.second.first;
        int dest = edge1.second.second;
        int weight = edge1.first;

        int index_1 = -1;
        int index_2 = -1;

        for(int i=0;i<st.size();i++){
           

            //   st[src].merge(st[dest]);
            //   st.erase(st.begin() + dest);
            //   v.push_back(edge1)}
            if(st[i].find(src) != st[i].end()){
                index_1 = i;
            }
            if(st[i].find(dest) != st[i].end()){
                index_2 = i;
            }
        }

        if(index_1==index_2){
          continue;
        }
        else{
            st[index_1].merge(st[index_2]);
            st.erase(st.begin() + index_2);
            v.push_back(edge1);
        }

       
        EdgesPQ.pop(); // Removes the edge with min. cost.

    }
    int sum = 0;

    for(int i =0;i<v.size();i++){
        ofile<<v[i].second.first<<" "<<v[i].second.second<<" "<<v[i].first<<endl;
        sum += v[i].first;
    }
    ofile<<sum<<endl;
}

// void GraphAdjList::minkey(int x){
//     for(auto it= adjlis)
// }

void GraphAdjList::prim(ofstream &ofile){
   set<int> curmst;
    curmst.insert(0);
   /* priority_queue<   pair<int,int>, vector< pair<int, int> >,greater< pair<int,int> > > PQ;
    PQ.push(make_pair(cost[0],0));
    //cout<<3<<endl;
    for(int i=1;i<AdjList.size();i++){
        cost[i]=INT32_MAX;
        PQ.push(make_pair(cost[i],i));
    }
    //cout<<4<<endl;
    */

    priority_queue< pair<int,pair<int, int> >, vector<pair<int, pair<int, int> > >,greater<pair<int, pair<int, int> > > > EdgesPQ;
    
    for(auto itr=AdjList[0].begin();itr!=AdjList[0].end();itr++){
        EdgesPQ.push(make_pair(itr->second, make_pair(0, itr->first)));
       // EdgesPQ.push(make_pair(itr->second, make_pair(itr->first,0)));
    }
    int final=0;
   

    while(curmst.size()!=AdjList.size()){
        pair<int, pair<int, int> > edge1;
        edge1 = EdgesPQ.top();
        EdgesPQ.pop();
        int src = edge1.second.first;
        int dest = edge1.second.second;
       // cout<<dest<<" ";
        int weight = edge1.first;
        
        //int final=0;
        if(curmst.find(dest)==curmst.end()){
            curmst.insert(dest);
            ofile<<src<<" "<<dest<<" "<<weight<<endl;
            final+=weight;
            //cout<<AdjList[dest].size()<<endl;
            for(auto itr=AdjList[dest].begin();itr!=AdjList[dest].end();itr++){
               // cout<<111<<endl;
              //  cout<<itr->second<<" ";
                EdgesPQ.push(make_pair(itr->second, make_pair(dest, itr->first)));
               // EdgesPQ.push(make_pair(itr->second, make_pair(itr->first,dest)));
            }
           
        }
    }
    
        ofile<<final<<endl;
    

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
