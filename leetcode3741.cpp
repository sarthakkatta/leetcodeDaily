/*
Problem: Minimum Distance Between Three Equal Elements II

Approach:
1. Store indices of each number using a hashmap:
   - mp[value] → list of indices where it appears.
2. Traverse each element and fill the map.
3. For each unique number:
   - If it appears less than 3 times → skip.
4. For valid lists:
   - Check every triplet of indices (i, i+1, i+2).
   - Compute distance = 2 * (s[i+2] - s[i]).
5. Track the minimum distance among all such triplets.
6. If no valid triplet exists → return -1.

Key Insight:
- Minimum span of 3 same elements determines answer.
- Multiply by 2 as per requirement.

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
