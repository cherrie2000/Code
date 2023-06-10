//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&arr ,int target) {
        //Your code here
        int n=arr.size();
        if(n==1){
            if(abs(arr[0])==target) return 1;
            return 0;
        } int sum=0;
       for(auto it:arr) sum+=it;
       if((target+sum)%2!=0 || (target+sum)<0) return 0;
       int t=(target+sum)/2;
       vector<vector<int>> dp(n+1,vector<int>(t+1,0));
       dp[0][0]=1;
       
       for(int i=1;i<=n;i++){
           for(int j=0;j<=t;j++){
               if(arr[i-1]<=j){
                   dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
               }
               else  dp[i][j]=dp[i-1][j];
           }
       }
       return dp[n][t];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends