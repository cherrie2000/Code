//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    class node{
    public:
    int data; int row; int col;
    node(int d, int r, int c){
        this->data=d; this->row=r; this->col=c; 
    }
};
class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data>b->data;
    }
};
    pair<int,int> findSmallestRange(int nums[][N], int n, int k)
    {
          //code here
         //  int n=nums.size();// int m=nums[0].size(); //cout<<n<<" "<<m<<"\n";
                priority_queue<node*,vector<node*>,compare> pq;
        int maxi=INT_MIN; int mini=INT_MAX;

        for(int i=0;i<k;i++){
            maxi=max(nums[i][0],maxi);
            mini=min(nums[i][0],mini);
            pq.push(new node(nums[i][0],i,0));
        }
        
     int start=mini, end=maxi;

     while(!pq.empty()){

         node*temp=pq.top(); pq.pop();
         mini=temp->data; 
         //cout<<mini<<" "<<maxi<<" \n";

         if(maxi-mini < end-start){
             start=mini; end=maxi;
         } 
        // int m=nums[temp->row].size();
        if(temp->col+1<n){
            maxi=max(maxi,nums[temp->row][temp->col+1]);
            pq.push(new node(nums[temp->row][temp->col+1],temp->row,temp->col+1));
        }
        else {
            break;
        }
     }
        return {start,end};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends