/*
Problem:
---------
LeetCode 1520 - Maximum Number of Non-Overlapping Substrings

Approach:
---------
1. Find the first and last occurrence of every character:
   - `start[c]` stores the first position of character `c`.
   - `end[c]` stores the last position of character `c`.

2. For every character that appears in the string, consider the substring
   starting from its first occurrence and ending at its last occurrence.

3. Check whether this substring can be made valid:
   - Traverse from `start[c]` to `end[c]`.
   - For every character inside this range, its first occurrence must not
     be before `start[c]`.
   - If we find a character whose first occurrence is before `start[c]`,
     then the current substring cannot contain all occurrences of that
     character.
   - Mark it invalid.

4. Expand the ending position when necessary:
   - If a character inside the current substring has a later last
     occurrence, extend `end[c]`.
   - This ensures that all occurrences of every character inside the
     substring are included.

5. After finding all valid substrings, traverse the string from right
   to left:
   - If the current position is the first occurrence of its character
     and its substring ends before the previously selected substring
     starts, it can be selected.
   - Add that substring to `result`.
   - Update `lastTakenStart`.

6. Traversing from right to left allows us to select the smallest valid
   substrings while keeping them non-overlapping.
   This maximizes the total number of substrings.

Key Idea:
---------
A valid substring must contain ALL occurrences of every character that
appears inside it.

For a character `c`, initially consider:

    [start[c] ... end[c]]

While scanning this range:
- If some character has its first occurrence before `start[c]`, the
  substring is invalid.
- Otherwise, extend the right boundary whenever another character's
  last occurrence goes beyond the current boundary.

After determining all valid intervals, we choose non-overlapping ones.

The important greedy idea is to prefer smaller valid intervals. Smaller
intervals leave more space for other substrings, which helps maximize
the number of selected substrings.

Example:
--------
s = "adefaddaccc"

For character `a`:

    first a = 0
    last a  = 7

The interval initially is:

    [0 ... 7]

All characters inside this interval have their complete occurrences
inside the interval, so it forms a valid substring:

    "adefadda"

For character `c`:

    first c = 8
    last c  = 10

So:

    "ccc"

is also a valid substring.

These substrings do not overlap, so they can both be selected.

The algorithm identifies all such valid intervals and greedily selects
the maximum number of non-overlapping ones.

Time Complexity:
----------------
O(n)

There are only 26 lowercase English characters.

Finding first and last occurrences takes O(n).

For each of the at most 26 characters, we scan its possible interval.
Since the alphabet size is fixed at 26, the overall complexity is
effectively O(n).

Space Complexity:
-----------------
O(n)

The result strings and the substring storage can require O(n) space.
The `start`, `end`, and `isValid` arrays use O(26) = O(1) extra space.
*/

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> start(26, -1);
        vector<int> end(26, 0);
        vector<bool> isValid(26, true);
        vector<string> result;
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if(start[idx] == -1) {
                start[idx] = i;
            }
            end[idx] = i;
        }
        for(int c = 0; c < 26; c++) { //checking all characters
            if(start[c] == -1) continue;
            for(int i = start[c]; i <= end[c]; i++) {
                if(start[s[i]-'a'] < start[c]) {
                    isValid[c] = false;
                    break;
                }
                end[c] = max(end[c], end[s[i]-'a']);
            }
        }
        int lastTakenStart = INT_MAX;
        for(int i = n-1; i >= 0; i--) {
            int c = s[i] - 'a';
            if(!isValid[c]) continue;
            if(i == start[c] && end[c] < lastTakenStart) {
                result.push_back(s.substr(i, end[c] - i + 1));
                lastTakenStart = i;
            }
        }
        return result;
    }
};
