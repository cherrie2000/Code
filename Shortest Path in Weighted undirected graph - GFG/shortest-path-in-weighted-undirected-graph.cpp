//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<pair<int,int>>> adj;
           for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> result(n+1, INT_MAX);
        vector<int> parent(n+1);
        for(int i = 1; i<=n; i++) {
            parent[i] = i;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,1});
        result[1]=0;
        while(!pq.empty()){
             pair<int,int> temp=pq.top();
             int u=temp.second; int d=temp.first; pq.pop();
             
             for(auto it:adj[u]){
                 
                 int v=it.first; int dist=it.second;
                 
                 if(d+dist<result[v]){
                     result[v]=dist+d;
                     parent[v]=u;
                     pq.push({(d+dist),v});
                 }
             }
        }
        if(result[n]==INT_MAX) return {-1};
       vector<int> path;
       int node=n; path.push_back(n);
       while(parent[node]!=node){
           path.push_back(parent[node]);
           node=parent[node];
       }
      // res.push_back(1);
       reverse(path.begin(),path.end());
       return path;
       
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends