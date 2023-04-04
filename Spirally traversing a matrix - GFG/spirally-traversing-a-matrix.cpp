//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > arr, int r, int c) 
    {
        // code here 
        int dir=0, top=0,down=r-1,left=0,right=c-1;
        vector<int>ans;
        while(top<=down && left<=right){
            if(dir==0){
                //move from left to right
                for(int i=left; i<=right;i++){
                    ans.push_back(arr[top][i]);
                }
                top++;
            }
            if(dir==1){
                //move from top right to bottom
                for(int i=top;i<=down;i++){
                    ans.push_back(arr[i][right]);
                }
                right--;
            }
            if(dir==2){
                for(int i =right;i>=left;i--){
                    ans.push_back(arr[down][i]);
                }
                down--;
            }
            if(dir==3){
                //move from bottom to top
                for(int i=down;i>=top;i--){
                    ans.push_back(arr[i][left]);
                }
                left++;
            }
            dir++;
            if(dir==4) dir=0;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends