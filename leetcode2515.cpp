/*
Problem: LeetCode 2515 – Shortest Distance to Target String in a Circular Array

Approach:
1. Traverse all indices of the array.
2. For each index i where words[i] == target:
   - Compute right (clockwise) distance:
       (i - startIndex + n) % n
   - Compute left (anticlockwise) distance:
       (startIndex - i + n) % n
3. Take minimum of both distances.
4. Track the overall minimum distance.
5. If target is not found → return -1.

Key Idea:
- Circular movement handled using modulo arithmetic.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDistance = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int rightDist = (i - startIndex + n) % n;
                int leftDist  = (startIndex - i + n) % n;
                minDistance = min(minDistance, min(rightDist, leftDist));
            }
        }

        return minDistance == INT_MAX ? -1 : minDistance;
    }
};
