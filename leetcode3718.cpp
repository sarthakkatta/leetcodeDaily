/*
Problem: LeetCode 3718 – Smallest Missing Multiple of K

Approach:
1. Store all elements of nums in an unordered_set.
2. Generate multiples of k one by one:
      k, 2k, 3k, 4k, ...
3. For every multiple, check whether it exists
   in the set.
4. The first multiple that is not present in nums
   is the answer.
5. Since we check multiples in increasing order,
   the first missing one is automatically the
   smallest missing multiple.

Key Idea:
- `unordered_set` gives average O(1) lookup.
- Instead of checking every number, we only check
  numbers that are multiples of k.
- The loop continues until a missing multiple is found.

Example:

nums = [2, 3, 5, 10]
k = 2

Multiples of 2:
2  → present
4  → missing

Answer:
4

Another Example:

nums = [1, 2, 3, 4, 6, 8]
k = 2

Multiples:
2 → present
4 → present
6 → present
8 → present
10 → missing

Answer:
10

Time Complexity:
O(N) average for building the set,
plus O(M) for checking multiples.

Space Complexity: O(N)
*/

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        for (int i = 1; ; i++) {
            int x = k * i;
            if (st.find(x) == st.end()) {
                return x;
            }
        }
    }
};
