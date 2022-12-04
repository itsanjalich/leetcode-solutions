//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    string rearrange (string s, int n)
    {
        // your code here
        
        // priority_queue<char,vector<char>,greater<char>>pq1;
        // priority_queue<char,vector<char>,greater<char>>pq2;
        
        
        // string ans="",ans1="";
        // for(int i=0;i<N;i++)
        // {
            
        //     if(s[i]=='a' ||  s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
        //     {
                
        //         pq1.push(s[i]);
                
        //     }
            
        //     else
        //     pq2.push(s[i]);
        // }
        
        // if(abs(pq1.size()-pq2.size())>1)
        // return "-1";
        
        
        
            
        //     while(!pq1.empty() and !pq2.empty())
        //     {
                
        //         char ch1=pq1.top();
                
        //         char ch2=pq2.top();
                
                
        //         ans+=ch1;
        //         ans+=ch2;
                
                
        //         pq1.pop();
        //         pq2.pop();
        //     }
        //     while(pq1.size())
        //     {
        //     ans+=pq1.top();
        //     pq1.pop();
        //     }
            
        //      while(!pq1.empty() and !pq2.empty())
        //     {
                
        //         char ch1=pq1.top();
                
        //         char ch2=pq2.top();
                
                
        //         ans1+=ch2;
        //         ans1+=ch1;
                
                
        //         pq1.pop();
        //         pq2.pop();
        //     }
        
        //  while(pq2.size())
        //     {
        //     ans1+=pq2.top();
        //     pq2.pop();
        //     }
            
        //     for(int i=0;i<ans1.size();i++)
        //     {
                
        //         if(ans[i]<ans1[i])
        //         return ans;
        //     }
            
        //     return ans1;
        
         vector<int> mp1(26),mp2(26); // to store vowels and consonants
        int v = 0,c = 0;
        for(char ch:s){
            if(ch=='a' ||ch=='e' ||ch=='i' ||ch=='o' ||ch=='u'){ // if it's vowel
                mp1[ch-'a']++;
                v++;
            }
            else{ // consonant
                mp2[ch-'a']++;
                c++;
            }
        }
        
        if(abs(v-c)>1) return "-1"; // if their diff is greater than one then the given condition can't be prove
        int it1 = 0,it2 = 0,i=0;
        while(it1<mp1.size() && mp1[it1]==0) it1++; // to find first vowel
        while(it2<mp2.size() && mp2[it2]==0) it2++; // to find first consonant
        
        bool f = c>v; // if number of consonant is greater then we will place consonant first else vowel
        if(v==c){
            f = it1>it2; // if both are equal then check which is lexiographically smaller
        }
        
        while((it1<mp1.size() && it2<mp2.size()) && i<n){
            if(f){ 
                s[i] = it2+'a';
                --mp2[it2];
                while(it2<mp2.size() && mp2[it2]==0) it2++;
                f = false; // this will trigger to place vowel next
            }
            else{
                s[i] = it1+'a';
                --mp1[it1];
                while(it1<mp1.size() && mp1[it1]==0) it1++;
                f = true; // this will trigger to place consonant next
            }
            ++i;
        }
        
        if(it1!=mp1.size()) s[i] = it1+'a'; // if one vowel left
        else if(it2!=mp2.size()) s[i] = it2+'a'; // if one consonant left
        
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		Solution ob;
		cout << ob.rearrange (s, n) << endl;
	}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends