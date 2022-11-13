//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
public:
    int totalWays(int n, vector<int>c) {
        // code here
     sort (c.begin(),c.end());
        long long ans=c[0];
        for(int i=1;i<c.size();i++){
            ans=ans*(c[i]-i)%1000000007;
            ans=ans%1000000007;
        }
        return (int)ans%1000000007;

    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>capacity(n);
		for(int i = 0; i < n; i++)
			cin >> capacity[i];
		Solution ob;
		int ans = ob.totalWays(n, capacity);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends