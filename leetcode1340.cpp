/*
Problem: LeetCode 1340 – Jump Game V

Approach:
1. Multiple approaches shown:
   - Recursion (TLE)
   - Memoization
   - Optimized DP + Sorting
2. Goal:
   - From index i, jump left/right up to distance d.
   - Can only jump to smaller values.
3. Optimized Approach:
   - Store {value, index} pairs.
   - Sort by value in increasing order.
4. DP Definition:
   - dp[i] = maximum jumps starting from index i.
5. For each index:
   - Explore left within distance d.
   - Explore right within distance d.
   - Stop when encountering greater/equal element.
6. Transition:
   - dp[i] = max(dp[i], 1 + dp[j])
7. Final answer:
   - Maximum value in dp array.

Key Idea:
- Processing smaller heights first ensures valid DP transitions.

Time Complexity: O(N * D)
Space Complexity: O(N)
*/

                                   //RECURSION(but it will give tle):
// class Solution {
// public:
//     int n;
//     int solve(vector<int>& arr, int i, int d) {
//         int res = 1;
//         // going i-1,i-2...
//         for(int j = i - 1; j >= max(0, i - d); j--) {
//             if(arr[j] >= arr[i]) break;
//             res = max(res, 1 + solve(arr, j, d));
//         }
//         // going i+1,i+2
//         for(int j = i + 1; j <= min(n - 1, i + d); j++) {
//             if(arr[j] >= arr[i]) break;
//             res = max(res, 1 + solve(arr, j, d));
//         }
//         return res;
//     }
//     int maxJumps(vector<int>& arr, int d) {
//         n = arr.size();
//         int ans = 1;
//         for(int i = 0; i < n; i++) {
//             ans = max(ans, solve(arr, i, d));
//         }
//         return ans;
//     }
// };


                                      //MEMOIATION:
// class Solution {
// public:
//     int n;
//     int solve(vector<int>& arr, int i, int d, vector<int>& dp) {
//         if(dp[i] != -1) return dp[i];
//         int res = 1;
//         // going i-1,i-2...
//         for(int j = i - 1; j >= max(0, i - d); j--) {
//             if(arr[j] >= arr[i]) break;
//             res = max(res, 1 + solve(arr, j, d, dp));
//         }
//         // goinf i+1,i+2...
//         for(int j = i + 1; j <= min(n - 1, i + d); j++) {
//             if(arr[j] >= arr[i]) break;
//             res = max(res, 1 + solve(arr, j, d, dp));
//         }
//         return dp[i] = res;
//     }
//     int maxJumps(vector<int>& arr, int d) {
//         n = arr.size();
//         vector<int> dp(n, -1);
//         int ans = 1;
//         for(int i = 0; i < n; i++) {
//             ans = max(ans, solve(arr, i, d, dp));
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 1);

        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({arr[i], i});
        }
        // sort according to height
        sort(v.begin(), v.end());
        
        for(auto &it : v) {
            int val = it.first;
            int i = it.second;
            // left
            for(int j = i - 1; j >= max(0, i - d); j--) {
                if(arr[j] >= arr[i]) break;
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            // right
            for(int j = i + 1; j <= min(n - 1, i + d); j++) {
                if(arr[j] >= arr[i]) break;
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
