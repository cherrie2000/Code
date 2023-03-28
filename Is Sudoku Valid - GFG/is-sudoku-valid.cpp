//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> board){
        // code here
         set<string> st;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]==0) continue;
                string row = string(1,board[i][j])+"_ROW_"+to_string(i);
                string col = string(1,board[i][j])+"_COL_"+to_string(j);
                string box = string(1,board[i][j])+"_BOX_"+to_string(i/3)+" "+ to_string(j/3);
                if(st.find(row)!=st.end() || st.find(col)!=st.end() || st.find(box)!=st.end())
                return 0;
                  st.insert(row); st.insert(col); st.insert(box);
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends