//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution {
  public:
	void shortest_distance(vector<vector<int>>&dist){
	    // Code here
	    int V = dist.size();
	    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if(dist[i][j]==-1) dist[i][j] = INT_MAX;
        }
	    }
	    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INT_MAX && dist[i][k] != INT_MAX))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends