//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++


class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        // code here 
         int n1= S.length();
        int n2= W.length();
        int k=0;
        int ans=0;
        for(int i=0;i<S.length();i++){
            int  j=0;
                    k=i;
                 int len=0;
           
                while(k<n1 && j<n2){
                    if(S[k]==W[j]){
                           S[k]='#';
                        k++;
                        j++;
                    
                        len++;
                    }else{
                        k++;
                    }
                }
            if(len==n2) ans++;
           
        }
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
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends