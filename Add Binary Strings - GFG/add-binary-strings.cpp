//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
//User function template for C++
class Solution{
public:	
    pair<int,int>fun(int a,int b){
        if(a+b==0)
        return {0,0};
        if(a+b==1)
        return {1,0};
        return {0,1};
    }
	string addBinary(string str, string ptr)
	{
	    if(ptr.length()>str.length())
	    swap(str,ptr);
	    reverse(ptr.begin(),ptr.end());
	    while(ptr.length()!=str.length())
	        ptr.push_back('0');
	   reverse(ptr.begin(),ptr.end());
	   string ans;
	   int c=0;
	   for(int i=str.length()-1; i>=0; i--){
	       pair<int,int>p=fun(str[i]-48,ptr[i]-48);
	       pair<int,int>q=fun(c,p.first);
	       c=max(p.second,q.second);
	       ans.push_back(q.first+48);
	   }
	   if(c){
	       ans.push_back('1');
	   }
	   while(ans.length()>0&&ans[ans.length()-1]=='0')
	   ans.pop_back();
	   reverse(ans.begin(),ans.end());
	   if(ans.length()==0){
	       return "0";
	   }
	   return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends