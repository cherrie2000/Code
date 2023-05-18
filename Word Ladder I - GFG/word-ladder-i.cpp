//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string endWord, vector<string>& wordList) {
        // Code here
        unordered_set<string> st;
        bool isPresent=false;
        for(auto it:wordList){
            if(endWord.compare(it)==0) isPresent=true;
            st.insert(it);
        }
        if(!isPresent) return 0;
        queue<string> q;
        q.push(startWord); int ans=0;
        while(!q.empty()){
            int size=q.size();
            ans+=1;
            while(size--){
                string curr=q.front(); q.pop();
                for(int i=0;i<curr.size();i++){
                    string temp=curr;
                    for(char ch='a';ch<='z';ch++){
                        temp[i]=ch;
                        if(curr.compare(temp)==0) continue;
                        if(temp.compare(endWord)==0) return ans+1; 
                        if(st.find(temp)!=st.end()){
                            q.push(temp); st.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends