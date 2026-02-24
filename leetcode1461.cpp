/*
Problem: LeetCode 1461 – Check If a String Contains All Binary Codes of Size K


Approach:
1. If k > length of string, return false.
2. Use unordered_set to store all substrings of length k.
3. Traverse string and insert each substring of length k. 
4. Total possible binary codes of size k = 2^k.
5. If set size equals 2^k, return true, else false.

Time Complexity: O(N * K)
Space Complexity: O(2^K)
*/


class Solution{
public:
    bool hasAllCodes(string s, int k){
        if(k > s.length()) return false;
        unordered_set<string> st;
        for(int i = 0; i <= s.length() - k; i++){
            st.insert(s.substr(i, k));
        }
        return st.size() == (1 << k);
    }
};
