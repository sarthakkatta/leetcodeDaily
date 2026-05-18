/*
Problem: LeetCode 1345 – Jump Game IV

Approach:
1. Use BFS to find minimum jumps from index 0 to n-1.
2. Build hashmap:
   - mp[value] → stores all indices having same value.
3. BFS transitions from current index:
   - Move to left index (cur - 1)
   - Move to right index (cur + 1)
   - Move to all indices having same value as arr[cur]
4. Use visited array to avoid revisiting indices.
5. After processing same-value neighbors:
   - Erase arr[cur] from map to avoid repeated traversals.
6. Return steps when last index is reached.

Key Idea:
- BFS guarantees shortest path in unweighted graph.
- Removing processed value groups optimizes complexity.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int solve(vector<int>& arr, int &n){
        unordered_map<int, vector<int>> mp;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int cur = q.front();
                q.pop();
                if(cur == n -1)return steps;
                int left = cur-1;
                int right = cur+1;

                if(left >= 0 && !visited[left]){
                    q.push(left);
                    visited[left] = true;
                }
                if(right < n && !visited[right]){
                    q.push(right);
                    visited[right] = true;
                }
                for(const int &idx : mp[arr[cur]]) {
                    if(!visited[idx]) {
                        q.push(idx);
                        visited[idx] = true;
                    }
                }
                mp.erase(arr[cur]);
            }
            steps++;
        }
        return -1;
    }
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n==1) return 0;
        return solve(arr,n);
    }
};
