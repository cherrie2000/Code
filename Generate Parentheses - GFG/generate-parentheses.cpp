//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
         vector<string> ans;
        int op=n, cl=n;
        solve(n,ans,op,cl,"");
        return ans;
    }
    void solve(int n, vector<string>&ans, int op, int cl, string st){
        if(op==0 && cl==0){
            ans.push_back(st); return;
        }
        if(op>0){
            
            solve(n,ans,op-1,cl,st+"(");
        }
        if(cl>0 && cl>op){ 
            solve(n,ans,op,cl-1,st+")");
        }
      
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends