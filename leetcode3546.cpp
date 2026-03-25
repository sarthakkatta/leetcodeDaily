/*
Problem: Equal Sum Grid Partition I

Approach:
1. Compute total sum of the grid along with row-wise and column-wise sums.
2. If total sum is odd, partition is not possible.
3. Try horizontal partition:
   - Accumulate row sums and check if it equals half of total.
4. Try vertical partition:
   - Accumulate column sums and check similarly.
5. If any partition gives equal halves, return true.

Time Complexity: O(M * N)
Space Complexity: O(M + N)
*/

class Solution {
public:
    typedef long long ll;

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<ll> rowSum(m, 0);
        vector<ll> colSum(n, 0);

        ll total = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        if(total % 2 != 0) {
            return false;
        }

        //Horizontal split
        ll upper = 0;
        for(int i = 0; i < m - 1; i++) {
            upper += rowSum[i];
            if(upper == total - upper) {
                return true;
            }
        }

        //Vertical split
        ll left = 0;
        for(int j = 0; j < n - 1; j++) {
            left += colSum[j];
            if(left == total - left) {
                return true;
            }
        }

        return false;
    }
};
