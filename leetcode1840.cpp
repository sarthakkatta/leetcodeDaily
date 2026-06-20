/*
Problem: LeetCode 1840 – Maximum Building Height

Approach:
1. Add mandatory restrictions:
   - Building 1 has height 0.
   - Building n can have height at most n-1.
2. Sort all restrictions by building index.
3. Left → Right Pass:
   - Ensure each restriction can be reached
     from the previous restriction.
   - height[i] <= height[i-1] + distance
4. Right → Left Pass:
   - Ensure each restriction can be reached
     from the next restriction.
   - height[i] <= height[i+1] + distance
5. After adjustment:
   - All restrictions become valid.
6. For every adjacent pair of restrictions:
   - Let:
       x1, h1 = first restriction
       x2, h2 = second restriction
   - Distance = x2 - x1
7. Maximum peak between them:
   - peak = (h1 + h2 + distance) / 2
8. Track the maximum peak over all intervals.
9. Return the maximum achievable building height.

Key Idea:
- Buildings can change height by at most 1
  between adjacent positions.
- After propagating constraints from both sides,
  each interval can independently achieve a peak.

Time Complexity: O(M log M)
  (sorting dominates)

Space Complexity: O(M)

where M = number of restrictions.
*/

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        // Left -> Right
        for (int i = 1; i < m; i++) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] +
                (restrictions[i][0] - restrictions[i - 1][0])
            );
        }

        // Right -> Left
        for (int i = m - 2; i >= 0; i--) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] +
                (restrictions[i + 1][0] - restrictions[i][0])
            );
        }

        long long ans = 0;

        for (int i = 1; i < m; i++) {
            long long x1 = restrictions[i - 1][0];
            long long h1 = restrictions[i - 1][1];

            long long x2 = restrictions[i][0];
            long long h2 = restrictions[i][1];

            long long dist = x2 - x1;

            long long peak = (h1 + h2 + dist) / 2;

            ans = max(ans, peak);
        }

        return (int)ans;
    }
};
