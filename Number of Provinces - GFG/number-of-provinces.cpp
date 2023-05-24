//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int n;
void bfs( unordered_map<int, vector<int>>& edges,int node, vector<bool>&vis){
   queue<int> q;
   q.push(node); vis[node]=true;
   while(!q.empty()){
       int top=q.front();
       q.pop();
       for(auto it: edges[top]){
           if(!vis[it]) {
               q.push(it); vis[it]=true;
           }
       }
   }
}
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
          n=adj.size();
        int count=0;
        unordered_map<int, vector<int>> edges;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if(adj[i][j]==1) {
                    edges[i].push_back(j);
                     edges[j].push_back(i);
                }
            }
          //  edges.push_back(temp);
        }
       
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(vis[i]==false) { //cout<<count<<" ";
                bfs(edges,i,vis); count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends