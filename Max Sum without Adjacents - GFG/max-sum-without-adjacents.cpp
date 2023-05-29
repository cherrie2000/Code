//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *nums, int n) {
	    // code here
	   
        //int n=nums.size();
        vector<int> t(n+1,0);

        t[0]=0;
        t[1]=nums[0];
        for(int i=2;i<=n;i++){
            int steal = nums[i-1]+t[i-2];
            int skip=t[i-1];
            t[i]=max(steal,skip);
        }
        return t[n];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends