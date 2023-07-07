//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string X){
        // code here 
          int m=X.length();
		    string Y=X;
		    reverse (Y.begin(),Y.end());
		    int dp[m+1][m+1];
		    
		    for(int i=0;i<=m;i++){
		        for(int j=0;j<=m;j++){
		           if(i==0 || j==0) dp[i][j]=0;
		        }
		    }
		    
		    for(int i=1;i<=m;i++){
		        for(int j=1;j<=m;j++){
		            if(X[i-1]==Y[j-1]) 
		            dp[i][j]=1+dp[i-1][j-1];
		            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		        }
		    }
		    
		    return m-dp[m][m];
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends