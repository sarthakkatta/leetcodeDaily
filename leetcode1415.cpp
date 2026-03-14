/*
Problem: LeetCode 1415 – The k-th Lexicographical Happy String of Length n

Approach:
1. Use Backtracking to generate all happy strings of length n.
2. A happy string is formed using characters 'a', 'b', and 'c' with no two adjacent characters the same.
3. Recursively build the string by trying each character from 'a' to 'c'.
4. Skip a character if it is the same as the last character added.
5. Count each valid string formed and store the result when the count equals k.

Time Complexity: O(3^N)
Space Complexity: O(N)
*/

class Solution {
public:
    void solve(int n, string &curr, int& count, int& k, string& res){
        if(curr.length() == n){
            count++;
            if(count == k) res = curr;
            return;
        }
        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!curr.empty() && curr.back() == ch) continue;
            curr.push_back(ch);
            solve(n, curr, count, k, res);
            curr.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        string res = "";
        int count = 0;
        solve(n, curr, count, k, res);
        return res;
    }
};
