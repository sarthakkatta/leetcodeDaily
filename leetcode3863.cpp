/*
Problem:
---------
LeetCode 3863 - Minimum Operations to Sort a String


Approach:
---------
First, we check whether the string is already sorted using `is_sorted()`.

If the string is sorted, no operations are needed, so we return 0.

If the string has exactly two characters and is not sorted, we return -1
because it cannot be sorted using the allowed operations.

Next, we find the minimum and maximum characters in the string:
- `min_char` stores the smallest character.
- `max_char` stores the largest character.

We then check the positions of the first and last characters.

1. If the first character is already the minimum character, or the last
   character is already the maximum character, we can sort the string
   in one operation.

2. Otherwise, we find the minimum and maximum characters in the middle
   portion of the string, excluding the first and last characters.

3. If the first character is greater than every middle character and
   the last character is smaller than every middle character, three
   operations are required.

4. In all other unsorted cases, two operations are sufficient.


Key Idea:
---------
The main idea is to determine how many operations are required based on
the positions of the minimum and maximum characters.

- Already sorted string:
      0 operations

- String of length 2 that is not sorted:
      -1

- Minimum character at the beginning OR maximum character at the end:
      1 operation

- Both endpoints are misplaced in a way that requires moving them
  separately:
      3 operations

- Remaining unsorted cases:
      2 operations

The middle minimum and maximum help determine whether both endpoints
need to be handled separately or whether two operations are enough.


Example:
--------
Input:
s = "cba"

Step 1:
The string is not sorted.

Step 2:
    min_char = 'a'
    max_char = 'c'

Step 3:
Check the endpoints:
    s[0] = 'c'
    s[n - 1] = 'a'

The first character is not the minimum, and the last character is not
the maximum.

Step 4:
The middle portion contains only:
    "b"

Therefore:
    max_mid = 'b'
    min_mid = 'b'

Check:
    s[0] > max_mid  -> 'c' > 'b' -> true
    s[n - 1] < min_mid -> 'a' < 'b' -> true

Both conditions are true, so the answer is:

    3


Time Complexity:
----------------
O(n)

Checking whether the string is sorted and finding the minimum and
maximum characters each take O(n) time. All other operations are O(1).


Space Complexity:
-----------------
O(1)

Only a constant number of character and integer variables are used.
*/


class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(begin(s), end(s)))
            return 0;

        if (n == 2) {
            return -1;
        }

        char min_char = *min_element(begin(s), end(s));
        char max_char = *max_element(begin(s), end(s));

        if (s[0] == min_char || s[n - 1] == max_char)
            return 1;

        char max_mid = *max_element(begin(s) + 1, end(s) - 1);
        char min_mid = *min_element(begin(s) + 1, end(s) - 1);

        if (s[0] > max_mid && s[n - 1] < min_mid) {
            return 3;
        }

        return 2;
    }
};
