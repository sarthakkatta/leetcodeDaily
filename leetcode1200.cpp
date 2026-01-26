/*
 Problem: Minimum Absolute Difference
 Platform: LeetCode

 Approach:
 - Sort the array
 - Find minimum difference between adjacent elements
 - Collect all pairs having that minimum difference

 Time Complexity: O(N log N)
 Space Complexity: O(N)
*/

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> result;
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        for(int i = 0; i < n - 1; i++) {
            mini = min(mini, arr[i + 1] - arr[i]);
        }
        for(int i = 0; i < n - 1; i++) {
            if(arr[i + 1] - arr[i] == mini) {
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        return result;
    }
};
