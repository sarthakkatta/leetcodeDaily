/*
Problem: LeetCode 1536 – Minimum Swaps to Arrange a Binary Grid


Approach:
1. For each row, count trailing zeroes.
2. For row i, we need at least (n - i - 1) trailing zeroes.
3. Find first row below i that satisfies requirement.
4. If none found, return -1.
5. Bring that row to position i using adjacent swaps.
6. Count total swaps and return.

Time Complexity: O(N^2)
Space Complexity: O(N)
*/


class Solution{
public:
    int minSwaps(vector<vector<int>>& grid){
        int n = grid.size();
        vector<int> zeroes(n);
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = n - 1; j >= 0 && grid[i][j] == 0; j--) count++;
            zeroes[i] = count;
        }
        int swaps = 0;
        for(int i = 0; i < n; i++){
            int needed = n - i - 1;
            int j = i;
            while(j < n && zeroes[j] < needed) j++;
            if(j == n) return -1;
            while(j > i){
                swap(zeroes[j], zeroes[j - 1]);
                j--;
                swaps++;
            }
        }
        return swaps;
    }
};
