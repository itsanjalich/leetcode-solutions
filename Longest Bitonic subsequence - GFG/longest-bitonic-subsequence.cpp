//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	void lis(vector<int>nums,vector<int>&dp){
	    for(int i=1;i<nums.size();i++){
	        for(int j=0;j<i;j++){
	            if(nums[i]>nums[j])
	            dp[i]=max(dp[i],dp[j]+1);
	        }
	    }
	}
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int mx=1;
	    int n=nums.size();
	    vector<int>lTr(n,1),rTl(n,1); //lTr for left to right LIS to get the longest increasing half of the bitonic
	    lis(nums,lTr);
	    reverse(nums.begin(),nums.end());
	    lis(nums,rTl);  //rTl for right to left LIS in reverse order to get the longest decreasing half of the bitonic
	    reverse(rTl.begin(),rTl.end());
	    for(int i=0;i<n;i++){
	        mx=max(mx,lTr[i]+rTl[i]-1);
	    }
	    return mx;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends