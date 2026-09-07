/*
Problem:
---------
LeetCode 940 - Distinct Subsequences II

Approach:
---------
1. Maintain `dp`:
   - `dp` represents the total number of distinct subsequences INCLUDING
     the empty subsequence that can be formed using the characters
     processed so far.

   Initially:
       dp = 1

   because the empty subsequence is always present.

2. Maintain `last[26]`:
   - `last[c]` stores the value of `dp` from the moment when character
     `c` was processed previously.
   - This helps us remove duplicate subsequences created by repeating
     the same character.

3. For every character `c`:
   - Before processing it, store the current value:
       prevdp = dp

   - Normally, adding a new character to every existing subsequence
     would double the number of subsequences:

       dp = 2 * dp

     because:
       - old subsequences remain as they are
       - new subsequences are created by appending `c`

4. Problem with repeated characters:
   - If `c` appeared before, some of the newly created subsequences
     already existed when the previous `c` was processed.
   - Therefore, those duplicate subsequences must be removed.

   The number of duplicate subsequences is exactly:
       last[idx]

   So:

       dp = 2 * dp - last[idx]

5. Add `MOD` before taking `% MOD`:
   - The subtraction can make the value negative.
   - Adding MOD keeps the value non-negative.

6. Update the last occurrence information:
   - After processing character `c`, store the OLD value of `dp`:

       last[idx] = prevdp

   This is important because `last[idx]` must represent the number of
   subsequences that existed before the previous occurrence of `c`.

7. At the end:
   - `dp` includes the empty subsequence.
   - The problem asks only for non-empty subsequences.
   - Therefore, subtract 1.

Key Idea:
---------
For every new character, we can think:

    New subsequences = old subsequences + old subsequences + character

So initially we would have:

    dp = 2 * dp

But when the same character has appeared before, some of these newly
formed subsequences are duplicates.

`last[character]` tells us exactly how many such duplicate subsequences
need to be removed.

Therefore:

    dp = 2 * dp - last[character]

The `last` array is what allows us to handle duplicates in O(1) per
character instead of comparing every pair of positions.

Example:
--------
s = "aba"

Start:
    dp = 1
    last = [0, 0, ..., 0]

Process 'a':
    prevdp = 1
    dp = 2 * 1 - 0 = 2
    last['a'] = 1

Subsequences:
    ""
    "a"

Process 'b':
    prevdp = 2
    dp = 2 * 2 - 0 = 4
    last['b'] = 2

Subsequences:
    ""
    "a"
    "b"
    "ab"

Process second 'a':
    prevdp = 4
    dp = 2 * 4 - last['a']
       = 8 - 1
       = 7

The empty subsequence is included in these 7.

So the number of non-empty distinct subsequences is:

    7 - 1 = 6

They are:
    "a", "b", "ab", "aa", "ba", "aba"

Time Complexity:
----------------
O(n)

Each character is processed exactly once, and the `last` array lookup
and update both take O(1).

Space Complexity:
-----------------
O(26) = O(1)

We only maintain the `last` array for the 26 lowercase English letters.
*/

/*
class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int MOD = 1e9 + 7;
        vector<int> dp(n, 1);
        int result = 0;
        for(int i = 0; i < n; i++){
            // Try extending subsequences ending before i
            for(int j = 0; j < i; j++){
                if(s[i] != s[j]) {
                    dp[i] = (dp[i] + dp[j]) % MOD;
                }
            }
            result = (result + dp[i]) % MOD;
        }
        return result;
    }
};
*/


class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;
        long long dp = 1;
        vector<long long> last(26, 0);
        for (char c : s) {
            int idx = c - 'a';
            long long prevdp = dp;
            dp = (2 * dp - last[idx] + MOD) % MOD;
            last[idx] = prevdp;
        }
        return (dp - 1 + MOD) % MOD;
    }
};
