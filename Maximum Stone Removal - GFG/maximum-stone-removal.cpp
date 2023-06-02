//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void dfs(vector<vector<int>>& stones, vector<bool>&vis, int id){
    vis[id]=true;
    int r=stones[id][0];
    int c=stones[id][1];
    for(int i=0;i<stones.size();i++){
        if(vis[i]==true) continue;
        if(stones[i][0]==r || stones[i][1]==c) dfs(stones,vis,i); 
    }
}
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
      //  int n=stones.size();
        vector<bool> vis(n,false);
        int g=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(stones,vis,i);
                g++;
            }
        }
        return n-g;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends