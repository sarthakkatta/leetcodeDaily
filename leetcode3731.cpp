/*
Problem: Find Missing Elements

Approach:
1. Create a boolean array `contains` to mark
   which numbers are present.
2. Traverse the given array:
   - Mark each element as present.
   - Find the minimum and maximum values.
3. Traverse all numbers from:
      minVal to maxVal
4. For each number:
   - If it is not marked present,
     add it to the result.
5. Return the list of missing elements.

Key Idea:
- Mark every existing number using a boolean array.
- Then simply check which numbers are missing
  within the range [minimum element, maximum element].

Example:
Input:
nums = [2, 5, 1, 8]

Range:
1 → 8

Present:
1, 2, 5, 8

Missing:
3, 4, 6, 7

Output:
[3, 4, 6, 7]

Time Complexity: O(N + R)
where:
- N = size of array
- R = maxVal - minVal + 1

Space Complexity: O(1)
(Boolean array of fixed size 101)
*/

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        vector<bool> contains(101, false);

        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for (int ele : nums) {
            minVal = min(minVal, ele);
            maxVal = max(maxVal, ele);
            contains[ele] = true;
        }

        for (int i = minVal; i <= maxVal; i++) {
            if (!contains[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};
