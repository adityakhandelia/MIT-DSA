#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S,vector<int>elevation)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int>distance(V,1e9);
        distance[S]=0;
        pq.push({0,S});
        
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int edgeWeight=it[1];
                int adjNode=it[0];
                if(dist+edgeWeight<distance[adjNode] && elevation[node]<elevation[adjNode]){
                    distance[adjNode]=dist+edgeWeight;
                    pq.push({distance[adjNode],adjNode});
                }
            }
        }
        return distance;
    }
void bombdetonation(vector<vector<int>> adj_full[],int V,vector<vector<int>> adj_tilld[],vector<vector<int>> adj_afterd[],int D,int e,vector<int>elevation ){
     vector<int>distance=dijkstra(V,adj_full,0,elevation);
     vector<int>distance2=dijkstra(V,adj_tilld,0,elevation);
     for(int i=0;i<elevation.size();i++){
        elevation[i]-=e;
     }
     vector<int>distance3=dijkstra(V,adj_afterd,D,elevation);
     int dis=min(distance[distance.size()-1],(distance2[distance2.size()-1]+distance3[distance3.size()-1]));
     cout<<"Minimum Distance is:"<<dis;

}
int main() {
    int V = 5; 
    vector<int> elevation = {0, 1, 2, 3, 4}; 
    
    // Graph before detonation
    vector<vector<int>> adj_full[V];
    adj_full[0].push_back({1, 10});
    adj_full[1].push_back({2, 20});
    adj_full[2].push_back({3, 30});
    adj_full[3].push_back({4, 40});

    // Graph till detonation
    vector<vector<int>> adj_tilld[V];
    adj_tilld[0].push_back({1, 10});
    adj_tilld[1].push_back({2, 20});
    
    
    vector<vector<int>> adj_afterd[V];
    adj_afterd[2].push_back({3, 30});
    adj_afterd[3].push_back({4, 40});

    int D = 2;
    int e = 1;

    bombdetonation(adj_full, V, adj_tilld, adj_afterd, D, e, elevation);

    return 0;
}
