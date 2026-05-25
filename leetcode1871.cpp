/*
Problem: LeetCode 1871 – Jump Game VII

Approach:
1. Multiple approaches shown:
   - Memoization
   - Tabulation
   - Optimized Sliding Window DP
2. Optimized Approach:
   - dp[i] = true if index i is reachable.
3. Use sliding window to track how many reachable
   indices exist in valid jump range.
4. For every index i:
   - Add index entering window:
       i - minJump
   - Remove index leaving window:
       i - maxJump - 1
5. If:
   - s[i] == '0'
   - reachable > 0
   then current index is reachable.
6. Return dp[n - 1].

Key Idea:
- Sliding window avoids checking all jumps repeatedly.

Time Complexity: O(N)
Space Complexity: O(N)
*/

                                          //MEMOIATION:
// class Solution {
// public:
//     bool solve(int idx, string &s, int minJump, int maxJump,
//                vector<int> &dp) {
//         int n = s.size();
//         // Reached end
//         if (idx == n - 1)
//             return true;
//         // Already computed
//         if (dp[idx] != -1)
//             return dp[idx];

//         for (int jump = minJump; jump <= maxJump; jump++) {
//             int next = idx + jump;
//             if (next < n && s[next] == '0') {
//                 if (solve(next, s, minJump, maxJump, dp))
//                     return dp[idx] = true;
//             }
//         }
//         return dp[idx] = false;
//     }

//     bool canReach(string s, int minJump, int maxJump) {
//         int n = s.size();
//         vector<int> dp(n, -1);
//         return solve(0, s, minJump, maxJump, dp);
//     }
// };



                                     //TABULATION:
// class Solution {
// public: 
//     bool canReach(string s, int minJump, int maxJump) {
//         int n = s.size();
//         vector<bool> dp(n, false);
//         dp[0] = true;
//         for (int i = 0; i < n; i++) {
//             // If current index is reachable
//             if (dp[i]) {
//                 // Try all jumps
//                 for (int jump = minJump; jump <= maxJump; jump++) {
//                     int next = i + jump;
//                     if (next < n && s[next] == '0') {
//                         dp[next] = true;
//                     }
//                 }
//             }
//         }
//         return dp[n - 1];
//     }
// };



class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        int reachable = 0;
        for (int i = 1; i < n; i++) {
            // Add new index entering window
            if (i - minJump >= 0 && dp[i - minJump]) {
                reachable++;
            }
            // Remove index leaving window
            if (i - maxJump - 1 >= 0 && dp[i - maxJump - 1]) {
                reachable--;
            }
            // Current index reachable
            if (s[i] == '0' && reachable > 0) {
                dp[i] = true;
            }
        }
        return dp[n - 1];
    }
};
