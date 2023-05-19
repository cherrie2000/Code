//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
vector<vector<string>>ans;
void solve(string& begin, string& end, unordered_map<string,unordered_set<string>>&adj, vector<string>&curr){
        curr.push_back(begin);
        if(begin==end){
             ans.push_back(curr);
            curr.pop_back();
            return;
        }
        for(auto x:adj[begin]){
            solve(x,end,adj,curr); }
        curr.pop_back();
    }
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        
        unordered_map<string,unordered_set<string>> adj;
        unordered_set<string> dict;
        for(auto it:wordList) dict.insert(it);
         if(dict.find(endWord) == dict.end()) return ans;
        queue<string>q;
        q.push(beginWord); unordered_map<string,int> visited;
        visited[beginWord]=0;
        while(!q.empty()){
            string curr=q.front(); q.pop();
            string temp=curr;
            for(int i=0;i<curr.size();i++){
                for(char ch='a'; ch<='z'; ch++){
                    if(temp[i]==ch) continue; 
                    temp[i]=ch;
                    if(dict.count(temp)>0){
                        if(visited.count(temp)==0){
                            visited[temp]=visited[curr]+1;
                            q.push(temp);
                            adj[curr].insert(temp);
                        }
                        else if(visited[temp]==visited[curr]+1) adj[curr].insert(temp);
                    }
                }
                temp[i]=curr[i];
            }
        }
        vector<string> path;
        solve(beginWord,endWord,adj,path);
        return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends