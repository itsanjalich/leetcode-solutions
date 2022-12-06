//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
	    queue<pair<int,int>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1){
	             ans[i][j]=0;
	             q.push({i,j});
	            }
	        }
	    }
	    int dx[4] = {0,0,-1,1};
	    int dy[4] = {1,-1,0,0};
	    while(!q.empty())
	    {
	       int x = q.front().first;
	       int y = q.front().second;
	       q.pop();
	       for(int i=0;i<4;i++)
	       {
	           if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<m)
	           if(ans[x][y]+1<ans[x+dx[i]][y+dy[i]])
	           {
	               ans[x+dx[i]][y+dy[i]]=ans[x][y]+1;
	               q.push({x+dx[i],y+dy[i]});
	           }
	       }
	    }
	   return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends