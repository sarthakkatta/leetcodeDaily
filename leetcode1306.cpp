/*
Problem: LeetCode 1306 – Jump Game III

Approach:
1. Use DFS recursion to explore reachable indices.
2. Base cases:
   - If index goes out of bounds → return false
   - If current element is already visited (negative) → return false
   - If current element is 0 → return true
3. Mark current index as visited:
   - Multiply arr[i] by -1
4. Explore:
   - Left jump  → i - arr[i]
   - Right jump → i + arr[i]
5. Return true if either path reaches value 0.

Key Idea:
- Negative marking is used to track visited indices without extra space.

Time Complexity: O(N)
Space Complexity: O(N) (recursive stack)
*/

class Solution {
public:
    int n ;
    bool solve(vector<int>& arr, int i){
        if(i <0 || i >= n || arr[i] < 0) return false;
        if(arr[i] == 0) return true;
        arr[i]*=-1;
        int left = solve(arr, i - arr[i]);
        int right = solve(arr, i + arr[i]);
        return left || right;
    }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        return solve(arr,start);
    }
};
