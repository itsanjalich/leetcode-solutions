//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends




string buildLowestNumber(string num, int k)
{
    //code here.
    stack<char>s;
    string output;
    for(int i=0;i<num.length();i++)
    {
        while(!s.empty() && (s.top()-'0')>(num[i]-'0') && k)
        {
            s.pop();
            k--;
        }
        s.push(num[i]);
    }
    while(!s.empty() && k--) s.pop();
    while(!s.empty())
    {
        output+=s.top();
        s.pop();
    }
    while(output[output.size()-1] == '0') output.pop_back();
    reverse(output.begin(),output.end());
    return output==""?"0":output;
}