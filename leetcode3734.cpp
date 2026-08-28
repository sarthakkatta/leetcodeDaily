/*
Problem: 3734. Lexicographically Smallest Palindromic Permutation Greater Than Target

Approach:
1. First count the frequency of every character in `s`.
2. A palindrome can be formed only when:
   - At most one character has an odd frequency.
3. If more than one character has odd frequency,
   forming a palindrome is impossible, so return "".
4. Only the left half of the palindrome needs to be
   constructed.
5. For every character:
      halfCount[c] = count[c] / 2
6. Once the left half is built:
   - Copy it.
   - Reverse the copy to create the right half.
   - If there is an odd-frequency character, place it
     in the middle.
7. This gives a complete palindromic permutation.
8. During backtracking, characters are tried from
   'a' to 'z'.
9. If the current prefix is still equal to `target`,
   we cannot choose a character smaller than target[i].
10. Once a character greater than target[i] is chosen,
    `greater` becomes true and the remaining characters
    can be chosen freely.
11. When the complete palindrome is formed:
    - Check whether it is lexicographically greater
      than `target`.
    - If yes, store it in `result`.

Key Idea:
- A palindrome is completely determined by its left half
  and optional middle character.
- Therefore, instead of generating complete permutations,
  we only generate permutations of the left half.
- Trying characters in increasing order helps find the
  smallest valid lexicographically greater palindrome.

Example:

s = "aabbc"
target = "abcba"

Frequencies:
a → 2
b → 2
c → 1

Left half:
"ab"

Middle:
"c"

Possible palindrome:
"abcba"

If we need a palindrome greater than target,
backtracking tries the next possible left half.

Time Complexity:
O(26 × N!) in the worst case due to backtracking.

Space Complexity: O(N)
- Recursion stack
- Current half
- Frequency arrays
*/

class Solution {
public:
    string result = "";
    char midChar = '$';
    int half = 0;
    bool solve(string& curr, vector<int>& count, string& target, int i, bool greater) {
        if (i == half) {
            string candidate = curr; //left Half
            string rightHalf = candidate;
            reverse(begin(rightHalf), end(rightHalf)); //right half
            
            if(midChar != '$')
                candidate += midChar; //mid character

            candidate += rightHalf;

            if (candidate > target) {
                result = candidate;
                return true;
            }
            return false;
        }
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (count[ch - 'a'] == 0)
                continue;

            if (!greater && ch < target[i])
                continue;

            curr.push_back(ch);
            count[ch - 'a']--;

            bool isGreater = greater || ch > target[i];

            if (solve(curr, count, target, i + 1, isGreater))
                return true;

            curr.pop_back();
            count[ch - 'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char ch : s) 
            count[ch - 'a']++;

        int oddCount = 0;
        for (int c = 0; c < 26; c++) {
            if (count[c] % 2 == 1) { 
                oddCount++; 
                midChar = c + 'a'; 
            }
        }
        if (oddCount > 1) 
            return "";

        // Left-half counts + middle char (only when n is odd).
        vector<int> halfCount(26, 0);
        for (int c = 0; c < 26; c++) {
            halfCount[c] = count[c] / 2;
        }

        half = n / 2;

        string curr;
        solve(curr, halfCount, target, 0, false);
        return result;
    }
};
