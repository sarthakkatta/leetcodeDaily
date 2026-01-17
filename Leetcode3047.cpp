/*
 Problem: Largest Square Area

 Approach:
 - For every pair of rectangles, compute their intersection
 - If they overlap, the maximum square that can fit inside
   the intersection has side = min(width, height)
 - Track the maximum possible side and return its area

 Time Complexity: O(N^2)
 Space Complexity: O(1)
*/

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {

        int n = bottomLeft.size();
        long long maxSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // Intersection bottom-left
                long long x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long y1 = max(bottomLeft[i][1], bottomLeft[j][1]);

                // Intersection top-right
                long long x2 = min(topRight[i][0], topRight[j][0]);
                long long y2 = min(topRight[i][1], topRight[j][1]);

                long long width  = x2 - x1;
                long long height = y2 - y1;

                // Check if rectangles overlap
                if (width > 0 && height > 0) {
                    long long side = min(width, height);
                    maxSide = max(maxSide, side);
                }
            }
        }

        return maxSide * maxSide;
    }
};
