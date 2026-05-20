/*
Problem: LeetCode 2657 – Find the Prefix Common Array of Two Arrays

Approach:
1. Use frequency array to track occurrences of elements.
2. Traverse both arrays simultaneously:
   - Increment frequency of A[i]
   - If frequency becomes 2 → element is common
   - Increment frequency of B[i]
   - If frequency becomes 2 → element is common
3. Maintain count of common elements so far.
4. Store count in answer array for each prefix.
5. Return result array.

Key Idea:
- An element becomes prefix-common when it appears in both arrays.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        int cnt = 0;
        vector<int> freq(n+1,0);
        for(int i = 0; i < n; i++){
            freq[A[i]]++;
            if(freq[A[i]] == 2){
                cnt++;
            }
            freq[B[i]]++;
            if(freq[B[i]] == 2){
                cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
