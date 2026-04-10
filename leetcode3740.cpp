/*
Problem: Minimum Distance Between Three Equal Elements I

Approach:
1. Store indices of each number using a hashmap:
   - mp[value] → list of indices where it appears.
2. For each number:
   - If occurrences < 3 → skip (need at least 3 positions).
3. Traverse indices in groups of 3:
   - For indices i, i+1, i+2:
     → Calculate distance = 2 * (s[i+2] - s[i])
4. Track minimum distance across all valid triplets.
5. If no valid triplet found → return -1.

Key Idea:
- We need minimum span covering 3 same elements.
- Multiply by 2 as per problem requirement.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0 ; i < nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto &m: mp){
            vector<int> s = m.second;
            if(s.size() <  3) continue;
            for(int i = 0; i + 2 < s.size();i++){
                int dist = 2 * (s[i + 2] - s[i]);
                ans = min(ans, dist);
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
