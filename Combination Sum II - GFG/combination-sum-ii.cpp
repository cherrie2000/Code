//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<int> temp;
    vector<vector<int>> combinationSum2(vector<int> &nums, int target) {
        // Write your code here
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(ans,nums,0,target);
        return ans;
    }
    void solve(vector<vector<int>>&ans, vector<int>& nums, int index, int target){
        if(target==0){
            ans.push_back(temp); return;
        }
        if(target<0) return;
        int prev=-1;
        for(int i=index;i<nums.size();i++){
            if(prev==nums[i]) continue;
            temp.push_back(nums[i]);
            solve(ans,nums,i+1,target-nums[i]);
            temp.pop_back();
            prev=nums[i];
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends