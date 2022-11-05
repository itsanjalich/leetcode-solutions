//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++



class Solution{
public:
   vector<int> minPartition(int n)
{
    int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int p = sizeof(a)/sizeof(int)-1;
    vector<int> res;
    for(int i=p; i>=0; i--){
        if(a[i]<=n){
            int x = n/a[i];
            for(int j=0; j<x; j++) res.push_back(a[i]);
            n = n%a[i];
        }
    }
    return res;
}
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends