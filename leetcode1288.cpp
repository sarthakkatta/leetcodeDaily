/*
Problem: LeetCode 1288 – Remove Covered Intervals

Approach:
1. Sort the intervals:
   - Increasing order of start point.
   - If starts are equal:
       Sort by decreasing end point.
2. Maintain:
   - maxEnd = largest ending point seen so far.
   - count = number of intervals that are
     not covered.
3. Traverse the sorted intervals.
4. For each interval:
   - If its end point is greater than maxEnd:
       → It is not covered.
       → Count it.
       → Update maxEnd.
   - Otherwise:
       → It is completely covered by a
         previously processed interval.
5. Return the count.

Key Idea:
- Sorting by increasing start and decreasing end
  ensures that any covered interval appears after
  the interval covering it.
- Comparing only the end points is sufficient
  to detect covered intervals.

Example:
Input:
[[1,4],[3,6],[2,8]]

After Sorting:
[[1,4],[2,8],[3,6]]

Covered:
[3,6] is covered by [2,8]

Answer:
2

Time Complexity: O(N log N)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] > b[1];

                return a[0] < b[0];
            });

        int count = 0;
        int maxEnd = 0;

        for (auto& interval : intervals) {

            if (interval[1] > maxEnd) {
                count++;
                maxEnd = interval[1];
            }
        }

        return count;
    }
};
