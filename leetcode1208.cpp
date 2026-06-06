/*
Problem: LeetCode 1208 – Get Equal Substrings Within Budget

Approach:
1. Use Sliding Window.
2. Maintain:
   - left → start of window
   - currCost → total conversion cost of current window
   - maxLen → maximum valid window length
3. Expand window by moving right pointer:
   - Add cost = abs(s[right] - t[right])
4. If current cost exceeds maxCost:
   - Shrink window from left.
   - Remove left character's conversion cost.
5. After every valid window:
   - Update maximum length.
6. Return maxLen.

Key Idea:
- Find the longest substring whose total conversion
  cost does not exceed maxCost.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        int left = 0;
        int currCost = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            currCost += abs(s[right] - t[right]);

            while (currCost > maxCost) {
                currCost -= abs(s[left] - t[left]);
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
