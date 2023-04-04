//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int kadanemin(int nums[],int n){
       // int n=nums.size();
        int sum=nums[0],maxi=nums[0];
       for(int i=1;i<n;i++){
            sum=min(sum+nums[i],nums[i]);
            maxi=min(sum,maxi);
        }
        return maxi;
    }
      int kadanemax(int nums[], int n){
     //   int n=nums.size();
        int sum=nums[0],maxi=nums[0];
       for(int i=1;i<n;i++){
            sum=max(sum+nums[i],nums[i]);
            maxi=max(sum,maxi);
        }
        return maxi;
    }
    int circularSubarraySum(int nums[], int n){
        
        // your code here
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        int k_max=kadanemax(nums,n);
        int k_min=kadanemin(nums,n);
        if(k_max<0) return k_max;
        return max(k_max,sum-k_min);
    }
  
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends