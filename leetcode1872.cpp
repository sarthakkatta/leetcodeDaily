/*
Problem: LeetCode 1872 – Stone Game VIII

Approach:
1. Pehle prefix sum array banate hain.
   - prefixSum[i] = stones[0] se stones[i] tak ka sum.
2. Game mein actual stones ke bajay prefix sums
   important ho jaate hain.
3. `t[i]` represent karta hai:
   - index i se game start hone par maximum score difference.
4. Base Case:
      t[n - 1] = prefixSum[n - 1]
5. Har index par do choices hoti hain:
   - Take:
       prefixSum[i] - t[i + 1]
   - Skip:
       t[i + 1]
6. Dono mein se maximum choose karte hain.
7. Bottom-Up DP mein n-2 se 1 tak reverse iterate
   karte hain.
8. Final answer `t[1]` hota hai because game effectively
   index 1 se start hota hai.

Key Idea:
- Prefix Sum se har possible move ka total score
  quickly represent ho jaata hai.
- `t[i]` future game ka best possible score difference
  store karta hai.
- Har state mein Take aur Skip mein se maximum choose
  karna hai.

Example:

stones = [-1, 2, -3, 4]

Prefix Sum:
[-1, 1, -2, 2]

Base:
t[3] = 2

Then:
t[2] = max(-2 - 2, 2)
     = 2

Then:
t[1] = max(1 - 2, 2)
     = 2

Answer:
2

Time Complexity: O(N)

Space Complexity: O(N)
*/

                                              // Bottom Up
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + stones[i];
        }
        vector<int> t(n);
        t[n - 1] = prefixSum[n - 1];// base case: solve(n-1)
        for (int i = n - 2; i >= 1; i--) {
            int take = prefixSum[i] - t[i + 1];
            int skip = t[i+1];

            t[i] = max(take, skip);
        }
        return t[1]; // == solve(1)
    }
};
