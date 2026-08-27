/*
Problem:  Leetcode 3720. Lexicographically Smallest Permutation Greater Than Target

Approach:
1. Count the frequency of every character in `s`.
2. Use Backtracking to build the answer character by character.
3. At every position:
   - Try characters from 'a' to 'z' so that the first
     possible valid permutation is obtained.
4. If the permutation is still equal to `target`:
   - We cannot choose a character smaller than target[i].
5. If we choose a character greater than target[i],
   `greater` becomes true.
6. Once `greater` becomes true:
   - Remaining characters can be chosen freely because
     the permutation is already lexicographically greater.
7. When all characters are used:
   - If `greater == true`, we found a valid answer.
8. Backtracking restores the character count if the
   current choice does not lead to an answer.

Key Idea:
- Lexicographical comparison depends on the first
  position where two strings differ.
- Until that position, characters must remain equal
  or become greater.
- We never choose a character smaller than target[i]
  while the strings are still equal.
- Trying characters from 'a' to 'z' ensures that the
  first valid answer is the smallest lexicographically
  greater permutation.

Example:

s = "abc"
target = "abb"

Possible permutations:
abc, acb, bac, ...

"abc" > "abb"

So answer:
"abc"

Another Example:

s = "abc"
target = "abc"

"abc" is not greater than target.
Next valid permutation:
"acb"

Answer:
"acb"

Time Complexity:
O(26 × N!) in the worst case due to backtracking.

Space Complexity: O(N)
- Recursion stack
- Current permutation
- Character frequency array
*/

class Solution {
public:
    string result = "";
    bool solve(string& curr, vector<int>& count, string& target, int i, bool greater) {
        if(i == target.length()) {
            if(greater) {
                result = curr;
                return true;
            }
            return false;
        }
        for(char ch = 'a'; ch <= 'z'; ch++) {
            if(count[ch-'a'] == 0)
                continue;
            
            if(greater == false && ch < target[i])
                continue;
            
            curr.push_back(ch);
            count[ch-'a']--;

            bool isGreater = greater || ch > target[i];

            if(solve(curr, count, target, i+1, isGreater)) {
                return true;
            }

            curr.pop_back();
            count[ch-'a']++;
        }
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26, 0);
        for(char &ch : s)
            count[ch-'a']++;
        
        string curr;
        solve(curr, count, target, 0, false);
        return result;
    }
};
