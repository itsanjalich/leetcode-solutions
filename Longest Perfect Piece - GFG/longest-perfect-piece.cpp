//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
    int longestPerfectPiece(int arr[], int N) {
        // code here
        int len=1;
        int i=0,j=0;
        map<int,int> mp;
        while(j<N){
            mp[arr[j]]++;
            
            while((--mp.end())->first-mp.begin()->first>1){
                mp[arr[i]]--;
                if(mp[arr[i]]==0)mp.erase(arr[i]);
                
                i++;
            }
            len=max(len,j-i+1);
            j++;
        }
        return len;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends