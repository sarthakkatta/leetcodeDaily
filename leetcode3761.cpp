/*
Problem: 3761. Minimum Absolute Distance Between Mirror Pairs

Approach:
1. Define helper function:
   - Reverse digits of a number.
2. Use hashmap:
   - mpp[value] → stores latest index of reversed value.
3. Traverse array:
   - For each nums[j], compute its reverse.
   - If nums[j] already exists in map:
       → update minimum distance (j - previous index).
4. Store reversed value in map with current index.
5. Return minimum distance, or -1 if no valid pair found.

Key Idea:
- Mirror pair means a number and its reversed form.
- Use hashmap to track indices efficiently.

Time Complexity: O(N * D) (D = number of digits)
Space Complexity: O(N)
*/

class Solution {
public:
    int reversenum(int n){
        int rev = 0;
        while(n > 0){
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int ans = INT_MAX;
        for(int j = 0; j < nums.size(); j++){
            int rev = reversenum(nums[j]);

            if(mpp.count(nums[j])){
                ans = min(ans, j - mpp[nums[j]]);
            }
            // store reversed value
            mpp[rev] = j;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
