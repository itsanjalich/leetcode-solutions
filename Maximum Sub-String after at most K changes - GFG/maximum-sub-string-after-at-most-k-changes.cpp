//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
		public:
		int characterReplacement(string s, int k){
		   unordered_map<char,int>mp;
		   int ans =0;
		   int maxi =0,j=0,i=0;
		   while(j<s.length()){
		       mp[s[j]]++;
		        maxi = max(maxi,mp[s[j]]);
		       if((j-i+1)-maxi>k){
		           mp[s[i]]--;
		           i++;
		       }
//		       int ans =0;
		       ans = max(ans,j-i+1);
		       j++;
		   }
		  
return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends