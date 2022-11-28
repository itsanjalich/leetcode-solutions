//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    // code here
	    vector<int> ans;
	    int mx = INT_MIN;
	    int curr_sum = 0;
	    vector<int> tmp;
	    for(int i =0;i<n;i++){
	        if(a[i]<0){
	            if(curr_sum > mx){
	                mx= curr_sum;
	                ans = tmp;
	             
	            } 
	            else if( curr_sum == mx){
	                if(tmp.size()>ans.size())ans =tmp;
                
	            }
	            curr_sum = 0;
	             tmp = {};
	            
	        }
	        else {
	            curr_sum += a[i];
	            tmp.push_back(a[i]);
	        }
	    }
	    
	    if(curr_sum > mx){
	                mx= curr_sum;
	                ans = tmp;
	            } 
	            else if( curr_sum == mx){
	                if(tmp.size()>ans.size())ans =tmp;
                
	            }
	    if(mx==0)return {-1};
	    return ans;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends