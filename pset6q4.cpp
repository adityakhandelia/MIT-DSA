#include<iostream>
#include<vector>
using namespace std;
bool bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>distance(V,1e8);
        distance[S]=0;
        for(int count=1;count<=V-1;count++){
            for(auto it :edges){
                if(distance[it[0]]!=1e8 &&distance[it[1]]>distance[it[0]]+it[2]){
                    distance[it[1]]=distance[it[0]]+it[2];
                }
            }
            
        }
        for(auto it:edges){
                if(distance[it[0]]!=1e8 && distance[it[1]]>distance[it[0]]+it[2])
                return false;
            }
        return true;
    }
void check_conservative(int V,vector<vector<int>>&edges,int S){
    for(int i=0;i<V-1;i++){
      if(!bellman_ford(V,edges,i)){
        cout<<"Field is not  conservative";
        return;
      }
      }
      cout<<"Field is conservative";
}

 int main() {
        int V = 5;  
    int E = 7;  

    vector<vector<int>> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    
    int S = 0;

        check_conservative(V, edges, S);

    return 0;
}
