//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        vector<long long int>ans;
        
        long long int z=0,x=0,y=0;
        
        for(int it=0;it<N;it++)
            z^=Arr[it];
        
        int n = z&~(z-1);
        
        //cout<<n<<endl;
        
        for(int it=0;it<N;it++){
            
            if(Arr[it] & n){
                x^=Arr[it];
            } else
                y^=Arr[it];
            
        }
        
        ans.push_back(x);
        ans.push_back(y);
        
        if(ans[0] < ans[1])
                swap(ans[0], ans[1]);
                
        return ans;        
        
        
        
            
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends