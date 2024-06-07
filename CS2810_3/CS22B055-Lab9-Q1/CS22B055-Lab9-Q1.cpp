// Roll Number: CS22B055
// Name: Neeraj Bandhey
// CS2810 Lab Number: 9
// Date: 16 Apr, 2024, 2pm
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

// #include "GraphAdjList.h"
using namespace std;

void frackn(vector<int> value, vector<int> weight, int capacity) 
{ 
  
    int n = value.size(); 
 
  
    // Multimap container to store 
    // ratio and index 
    multimap<double, int> ratio; 
    vector<int> used(n);
  
    // Variable to store maximum profit 
    double max_profit = 0; 
    for (int i = 0; i < n; i++) { 
  
        ratio.insert(make_pair( 
            (double)value[i] / weight[i], i)); 
    } 
  
    // Declare a reverse iterator 
    // for Multimap 
    multimap<double, int>::reverse_iterator it; 
  
    // Traverse the map in reverse order 
    for (it = ratio.rbegin(); it != ratio.rend(); it++){ 

        double fraction = (double)capacity / weight[it->second]; 

        if (capacity >= 0 && capacity >= weight[it->second]) { 
            used[it->second] = 1;
            max_profit += value[it->second];
            capacity -= weight[it->second]; 
        } 
  
        else if (capacity < weight[it->second]) { 
            used[it->second] = 1;
            max_profit += fraction * value[it->second]; 
            break; 
        } 
    } 

    for(int i=0;i<n;i++){
        cout<<i<<" "<<used[i]<<endl;
    }
    
      cout<<int(max_profit)<<endl;
} 

void un01kn(vector<int> value, vector<int> weight, int capacity,int cap){

    int n = value.size();
    vector<int>wt(n+1);
    vector<int>val(n+1);
    int sum_wt=0;

    for(int i=0;i<n;i++){

        wt[i+1]=weight[i];
        val[i+1]=value[i];
    }
   // cout<<"Wt Val accepted\n";

    int demo=1;
    // int maxwt,c;
        // double m;
        // cin>>m;
        // cin>>c;
       // capacity
        
        // max_wt=m*sum_wt;
        
       // cout<<"Base Case\n";

        int dp[n+1][capacity+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=capacity;j++){
                dp[i][j]=0;
            }
        }

       // cout<<"Dp reln\n";
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=capacity;j++){

               for(int k=1;k*wt[i] <=j && k>0 && k<=cap;k++){
               // cout<<i<<" "<<j<<" "<<k<<" "<<k*wt[i]<<endl;
              
                if(j-k*wt[i]>=0)
                dp[i][j]=max(dp[i][j],dp[i-1][j-k*wt[i]]+ k*val[i]);
               }
                 if(i!=0)dp[i][j]=max(dp[i-1][j],dp[i][j]);
            }
        }

        
       //cout<<"Printing dp array\n";

        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=max_wt;j++){
        //        cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        //cout<<"0/1 value= "<<endl;
        // cout<<dp[n][max_wt]<<endl;

       // cout<<"FRACTIONAL KNAPSACK \n";

        vector<pair<double,int>>v;
        for(int i=1;i<=n;i++){
            v.push_back({(val[i]*1.0)/wt[i],i});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
       // cout<<"array\n";
        for(int i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second<<endl;
        vector<int>vis(n+1,0);
        int wght=capacity;
        cout<<wght<<endl;
        int i=0;
        int total=0;
        while(wght>=0 && i<v.size()){
           // cout<<"While enter\n";
            if(wght==0)break;
              int ratio=v[i].first;
              int value=val[v[i].second];
              int w=wt[v[i].second];
              if(w<=wght){
               // cout<<"Adding "<<value<<endl;
                total+=value;
               // cout<<"curr total= "<<total<<endl;
                wght=wght-w;
                vis[v[i].second]=1;
               
                i++;
              }
              else {
               // cout<<"Entering fractional\n";
                total+=(wght* value)/w;
                wght=0;
                vis[v[i].second]=1;
                 //cout<<"Visited "<<v[i].second-1<<endl;
                i++;
              }
        }
        //cout<<"Final knapsack val= "<<endl;
       
        for(int i=1;i<=n;i++){
            cout<<i-1<<" "<<vis[i]<<endl;
        }
         cout<<total<<endl;


}

int main(int argc, char *argv[])
{ 
  int option_read;
  
  static struct option long_options[] =
    {
      
      
      {"in",   required_argument,       0, 'i'},
      {"out",  required_argument,       0, 'o'},
      {"alg",  required_argument, 0, 'a'},
      {"frac", required_argument, 0,'s'},
      {"cap", required_argument,0 ,'t'},
      {0, 0, 0, 0}
    };
    int algo = 0;
    string st;
    ifstream ifile;
    ofstream ofile;
    float frac;
    int cap;


  while (1)
    {
      /* getopt_long stores the option index here. */
      int option_index = 0;

      option_read = getopt_long (argc, argv, "i:o:a:s;t",long_options, &option_index);

      /* Detect th(argv[4],ios::out);e end of the options. */
      if (option_read == -1)
        break;

      switch (option_read)
        {
        case 'i':{
        ifile.open(optarg, ios::in);
          break;
        }

        case 'o':{
           ofile.open(optarg,ios:: out);
          break;
        }
        case 'a': {
          if(optarg=="frackn"){
            algo = 0;
          }
          if(optarg=="un01kn"){
            algo = 1;
          } 
          break;
        }

        case 's':{
          frac = atof(optarg);
          break;
        }

        case 't':{
          cap =  atoi(optarg);
          break;
        }

        default:
          abort ();
        }
    }
  //cout << argv[1] << " " << N << endl;
    int N;
    ifile >> N;
    vector<int> v;
    vector<int> w;
    float capacity = 0;

 for(int i =0;i<N;i++){
    int wt,val;
    ifile>>wt>>val;
    capacity += wt;

    v.push_back(val);
    w.push_back(wt);  w[i]=wt; 
    v[i]=val;

  
}
// cout<<capacity<<endl;
// cout<<frac<<endl;

capacity = capacity * frac;
capacity = int(capacity);

if (algo == 0){
  frackn(v,w,capacity);
}
if (algo==1){
  // un01kn(v,w,capacity,cap);
}

}
