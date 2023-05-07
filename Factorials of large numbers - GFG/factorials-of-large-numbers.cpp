//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
void multiplier(vector<int>& arr, int x,int&size){
    int carry=0;
    for(int i=0;i<size;i++){
        int t=arr[i]*x; t+=carry;
        arr[i]=t%10; carry=t/10;
    }
    while(carry!=0){
        arr[size]=carry%10;
        size++; carry/=10;
    }
}
    vector<int> factorial(int n){
        // code here
        vector<int> arr(10000,0);
        arr[0]=1; int size=1;
        for(int i=2;i<=n;i++){
            multiplier(arr,i,size);
        }
        vector<int> result;
        for(int i=size-1;i>=0;i--){
            result.push_back(arr[i]);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends