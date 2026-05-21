/*
Problem: LeetCode 3043 – Find the Length of the Longest Common Prefix

Approach:
1. Use a set to store all prefixes of numbers from arr1.
2. For each number in arr1:
   - Insert the number into set.
   - Continuously divide by 10 to generate prefixes.
3. Traverse arr2:
   - Keep dividing current number by 10 until a prefix exists in set.
4. If valid prefix found:
   - Compute its digit length using log10(n) + 1
   - Update maximum result.
5. Return longest prefix length found.

Key Idea:
- Numbers sharing same leading digits form common prefixes.

Time Complexity: O(Total Digits)
Space Complexity: O(Total Prefixes)
*/

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(int val : arr1){
            while(!st.count(val) && val > 0){
                st.insert(val);
                val = val/10;
            }
        }
        int res = 0;
        for(int n : arr2){
            while(!st.count(n) && n > 0){
                n =n/10;
            }
            if(n > 0){
                res = max(res, static_cast<int>(log10(n) + 1));
            }
        }
        return res;
    }
};
