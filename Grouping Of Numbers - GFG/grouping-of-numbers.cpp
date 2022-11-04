//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution {
  public:
     int maxGroupSize(int arr[], int N, int K) {
        // code here
        int ans{};
        vector<int> a(K,0);
        for(int i=0;i<N;i++) a[arr[i]%K]++;
        for(int i=1;i<=K/2;i++)
        {
            if(i!=K-i) ans+=max(a[i],a[K-i]);
            else
            {
                if(a[i]!=0) ans++;
            }
        }
        if(a[0]!=0) ans++;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends