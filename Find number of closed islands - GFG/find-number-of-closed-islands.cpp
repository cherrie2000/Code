//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
     bool dfs(vector<vector<int>>& grid,int r, int c){
        //check for out of bound
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size()){
            return false;
        }
        if(grid[r][c]==0) return true; //closed found
        grid[r][c]=0; //marking visited
        bool left=dfs(grid,r,c-1);
        bool right= dfs(grid,r,c+1);
        bool up= dfs(grid,r-1,c);
        bool down= dfs(grid,r+1,c);
          return up && down && left && right;
    }
    int closedIslands(vector<vector<int>>& grid, int m, int n) {
        // Code here
        int count=0;
       // m =grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(dfs(grid,i,j)) count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends