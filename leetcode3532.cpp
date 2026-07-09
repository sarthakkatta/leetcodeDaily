/*
Problem: Path Existence Queries in a Graph I

Approach:
1. Divide the array into connected components.
2. Initialize:
   - comp[i] = component id of index i.
   - id = 0 for the first component.
3. Traverse the array from left to right:
   - If the difference between consecutive
     elements exceeds maxDiff:
         nums[i] - nums[i-1] > maxDiff
       → Start a new component.
       → Increment id.
   - Assign:
       comp[i] = id
4. Process each query:
   - If both indices belong to the same
     component:
         comp[u] == comp[v]
       → Path exists.
   - Otherwise:
       → No valid path.
5. Store the result for every query.
6. Return the answer vector.

Key Idea:
- Consecutive elements whose difference is
  at most maxDiff belong to the same connected
  component.
- Two indices have a valid path iff they are
  in the same component.

Example:
nums = [1,2,3,8,9]
maxDiff = 2

Components:
[0,0,0,1,1]

Queries:
(0,2) → true
(1,4) → false

Time Complexity:
- Preprocessing: O(N)
- Queries: O(Q)

Overall: O(N + Q)

Space Complexity: O(N)
*/

class Solution {
public:
    vector<bool> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries) {

        vector<int> comp(n);

        int id = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i - 1] > maxDiff)
                id++;

            comp[i] = id;
        }

        vector<bool> ans;

        for(auto &q : queries) {
            ans.push_back(comp[q[0]] == comp[q[1]]);
        }

        return ans;
    }
};
