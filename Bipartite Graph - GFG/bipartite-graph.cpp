//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool solve(vector<int>adj[],vector<int>&color, int i, int currColor){
color[i]=currColor;
for(auto it:adj[i]){
    if(color[it]==currColor) return false;
    if(color[it]==-1){
       int c=1-currColor;
       if(solve(adj,color,it,c)==false)
	            return false;  
    }
}
return true;
}
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    vector<int> color(v,-1);
	    for(int i=0;i<v;i++){
	        if(color[i]==-1){
	            if(solve(adj,color,i,1)==false)
	            return false;
	            
	        }
	    } return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends