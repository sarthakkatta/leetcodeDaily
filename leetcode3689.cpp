/*
Problem: Maximum Total Subarray Value I

Approach:
1. Find:
   - Global minimum element in array.
   - Global maximum element in array.
2. Compute difference:
   - gmax - gmin
3. Multiply the difference by k.
4. Return the result as long long.

Key Idea:
- Maximum contribution comes from the largest
  possible spread between array elements.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    long long maxTotalValue(vector<int>& A, int k) {
        int gmin = A.front(), gmax = A.front();

        for (auto& n : A) {
            gmin = min(gmin, n);
            gmax = max(gmax, n);
        }

        return (long long)(gmax - gmin) * k;
    }
};
