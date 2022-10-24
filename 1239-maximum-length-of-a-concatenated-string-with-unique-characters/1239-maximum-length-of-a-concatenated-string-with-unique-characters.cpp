class Solution {
public:
    int maxLength(vector<string>& arr) {
        return dfs(arr, "", 0);
    }
    int dfs(vector<string>& arr, string cur, int idx) {
        unordered_set<char> st(cur.begin(), cur.end());
        if (st.size() != cur.size()) return 0;
        int res = cur.size();
        for (int i = idx; i < arr.size(); ++i) {
            res = max(res, dfs(arr, cur + arr[i], i + 1));
        }
        return res;
    }
};