#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sparkplug_derby(int V,vector<vector<int>>edges[],vector<int>elevation,int S){
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
    int time=0;
    vector<int>distance(V,1e9);
        distance[S]=0;
        pq.push({0,S,10});
        while(!pq.empty()){
             vector<int>t=pq.top();
              int dist=t[0];
              int node=t[1];
              int gas=t[2];
              pq.pop();
              for(auto it:edges[node]){
                 int edgeWeight=it[1];
                int adjNode=it[0];
                if(dist+edgeWeight<distance[adjNode] && elevation[node]<elevation[adjNode]){
                    distance[adjNode]=dist+edgeWeight;
                    pq.push({distance[adjNode],adjNode,gas});
                }
                else if(dist+edgeWeight<distance[adjNode] && elevation[node]>elevation[adjNode]){
                    if(elevation[node]-elevation[adjNode]<gas){
                      distance[adjNode]=dist+edgeWeight;
                      gas-=elevation[node]-elevation[adjNode];
                      pq.push({distance[adjNode],adjNode,gas});
                    }
                    else{
                        distance[adjNode]=dist+edgeWeight+elevation[node]-elevation[adjNode]+1;
                      gas+=1;
                      pq.push({distance[adjNode],adjNode,gas});
                    }
                }
              }
            
            
        }
          return distance[V-1];
}
int main() {
    int V = 5;
    vector<vector<int>> edges[5];
    edges[0].push_back({1, 4});
    edges[0].push_back({2, 2});
    edges[1].push_back({3, 5});
    edges[2].push_back({3, 1});
    edges[3].push_back({4, 3});
    
    vector<int> elevation = {10, 20, 5, 15, 25};
    
    int S = 0; 
    cout << "Minimum time: " << sparkplug_derby(V, edges, elevation, S) << endl;
    
    return 0;
}

