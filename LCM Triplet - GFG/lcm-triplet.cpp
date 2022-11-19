//{ Driver Code Starts
// Initial Template for C++

// Initial Template for C++
// Back-end complete function Template for C++
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution {
  public:
    long long gcd(long long a, long long b){

        if(b==0) return a;

        else gcd(b,a%b);

    }
    long long lcmTriplets(long long N) {
        // code here
         if(N==1) return 1;

        long long lcm=(N*(N-1))/gcd(N,N-1);

        if(N&1) return (lcm*(N-2))/gcd(lcm,N-2);

        else{

            long long lcm_=((N-1)*(N-2))/gcd(N-1,N-2);

            return max(((lcm*(N-3))/gcd(lcm,N-3)),(lcm_*(N-3))/gcd(lcm_,N-3));
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        cout << ob.lcmTriplets(N) << "\n";
    }
}
// } Driver Code Ends