class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans = arr;   // Clone original
        sort(arr.begin(), arr.end());  // Sort copy
        unordered_map<int, int> ranks;
        int rank = 1;
        for (int x : arr) {
            if (ranks.find(x) == ranks.end()) {
                ranks[x] = rank++;
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            ans[i] = ranks[ans[i]];
        }
        return ans;
    }
};
