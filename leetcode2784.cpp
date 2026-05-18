/*
Problem: LeetCode 2784 – Check if Array is Good

Approach:
1. Count frequency of all elements using hashmap.
2. A good array of size n must contain:
   - Numbers from 1 to n-1
   - Numbers 1 to n-2 appear exactly once
   - Number (n-1) appears exactly twice
3. Check:
   - Map size must be n-1
4. Traverse from 1 to n-1:
   - If i == n-1:
       → frequency should be 2
   - Else:
       → frequency should be 1
5. If all conditions satisfy → return true.

Key Idea:
- Good array follows exact frequency pattern.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto x : nums){
            mp[x]++;
        }
        if(mp.size() != n - 1) return false;
        for(int i = 1; i < n; i++){
            if(i == n - 1){
                if(mp[i] != 2) return false;
            }
            else if(mp[i] != 1) return false;
        }
        return true;
    }
};
