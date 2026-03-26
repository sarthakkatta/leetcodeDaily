/*
Problem: Equal Sum Grid Partition II

Approach:
1. Compute total sum and maintain frequency arrays for both halves.
2. Try horizontal and vertical cuts.
3. For each cut, maintain running sum and update frequency maps.
4. If sums are equal, return true.
5. Otherwise, check if removing one element can balance both halves.
6. Handle 1D cases separately (only endpoints can be removed).
7. For 2D regions, check frequency of required difference.

Time Complexity: O(M * N)
Space Complexity: O(100000)
*/

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;

        vector<int> bottomFreq(100001, 0), topFreq(100001, 0);
        vector<int> rightFreq(100001, 0), leftFreq(100001, 0);

        for (auto &row : grid) {
            for (int x : row) {
                total += x;
                bottomFreq[x]++;
                rightFreq[x]++;
            }
        }

        long long sumTop = 0;

        // Horizontal cuts
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                sumTop += val;

                topFreq[val]++;
                bottomFreq[val]--;
            }

            long long sumBottom = total - sumTop;

            if (sumTop == sumBottom) return true;

            long long diff = abs(sumTop - sumBottom);

            if (diff <= 100000) {
                if (sumTop > sumBottom) {
                    if (check(topFreq, grid, 0, i, 0, n - 1, diff)) return true;
                } else {
                    if (check(bottomFreq, grid, i + 1, m - 1, 0, n - 1, diff)) return true;
                }
            }
        }

        long long sumLeft = 0;

        // Vertical cuts
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                int val = grid[i][j];
                sumLeft += val;

                leftFreq[val]++;
                rightFreq[val]--;
            }

            long long sumRight = total - sumLeft;

            if (sumLeft == sumRight) return true;

            long long diff = abs(sumLeft - sumRight);

            if (diff <= 100000) {
                if (sumLeft > sumRight) {
                    if (check(leftFreq, grid, 0, m - 1, 0, j, diff)) return true;
                } else {
                    if (check(rightFreq, grid, 0, m - 1, j + 1, n - 1, diff)) return true;
                }
            }
        }

        return false;
    }

    bool check(vector<int>& freq, vector<vector<int>>& grid,
               int r1, int r2, int c1, int c2, long long diff) {

        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;

        if (rows * cols == 1) return false;

        if (rows == 1) {
            return (grid[r1][c1] == diff || grid[r1][c2] == diff);
        }

        if (cols == 1) {
            return (grid[r1][c1] == diff || grid[r2][c1] == diff);
        }

        return freq[diff] > 0;
    }
};
