/*
Problem: LeetCode 1732 – Find the Highest Altitude

Approach:
1. Starting altitude is 0.
2. Build a prefix sum array:
   - prefixsum[i] represents altitude after i gains.
3. Initialize:
   - prefixsum[0] = 0
4. For each gain:
   - prefixsum[i + 1] = prefixsum[i] + gain[i]
5. Traverse the prefix sum array:
   - Track the maximum altitude reached.
6. Return the highest altitude.

Key Idea:
- Altitude at any point equals the cumulative sum
  of gains up to that point.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        vector<int> prefixsum(n + 1);

        prefixsum[0] = 0;

        for(int i = 0; i < n; i++){
            prefixsum[i + 1] = prefixsum[i] + gain[i];
        }

        int alt = INT_MIN;

        for(int i = 0; i <= n; i++){
            alt = max(prefixsum[i], alt);
        }

        return alt;
    }
};
