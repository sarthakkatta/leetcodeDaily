/*
Problem: LeetCode 3020 – Find the Maximum Number of Elements in Subset

Approach:
1. Count frequency of every number using a hashmap.
2. Handle number 1 separately:
   - A valid sequence of 1's must have odd length.
   - If count is even:
       use count - 1
   - If count is odd:
       use count
3. For every other number:
   - Start from x = num.
   - While:
       x exists in map and frequency >= 2
     We can place:
       x at beginning and x at end.
   - Add 2 to sequence length.
   - Move to next value:
       x = x * x
4. After the chain ends:
   - If final x exists:
       add 1 (center element).
   - Otherwise:
       remove one extra count:
       len--
5. Update maximum answer.
6. Return the maximum length found.

Key Idea:
- A valid subset follows the pattern:
      x, x², x⁴, x⁸, ...
  where every intermediate value must appear
  at least twice, while the last value may
  appear once as the center element.

Time Complexity: O(N log log M)
Space Complexity: O(N)
*/

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;

        for (int x : nums)
            mp[x]++;

        int ans = 1;

        // Handle value 1 separately
        if (mp.count(1)) {
            int cnt = mp[1];
            ans = max(ans, cnt % 2 ? cnt : cnt - 1);
        }

        for (auto &[num, f] : mp) {
            if (num == 1)
                continue;

            long long x = num;
            int len = 0;

            while (mp.count(x) && mp[x] >= 2) {
                len += 2;

                if (x > 1e9)
                    break; // avoid overflow

                x = x * x;
            }

            if (mp.count(x))
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};
