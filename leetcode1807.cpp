/*
Problem:
---------
LeetCode 1807 - Evaluate the Bracket Pairs of a String

Approach:
---------
1. Store all key-value pairs from `knowledge` in an unordered map:
   
       knowledgempp[key] = value

   This allows us to find the value of any key in O(1) average time.

2. Traverse the string `s` from left to right.

3. If the current character is not `(`:
   - It is a normal character.
   - Directly add it to `result`.

4. If the current character is `(`:
   - Find the corresponding closing `)` using `find()`.
   - Extract the key between the brackets using `substr()`.

   For example:

       "(name)"

   gives:

       key = "name"

5. Check whether the key exists in the knowledge map:
   - If it exists, append its corresponding value to `result`.
   - If it does not exist, append `?`.

6. Move `i` directly to the closing bracket:
   
       i = closingBracketIndex

   This skips the entire bracket expression because it has already
   been processed.

7. Continue until the complete string has been processed.

8. Return the final evaluated string.

Key Idea:
---------
The problem is essentially a string parsing + hash map lookup problem.

The knowledge list gives mappings like:

    "name" -> "bob"
    "age"  -> "20"

Whenever the string contains:

    (name)

we replace it with:

    bob

If the key does not exist:

    (unknown)

it becomes:

    ?

The unordered map makes key lookup efficient.

Example:
--------
s = "hi(name)"
knowledge = [["name", "bob"]]

Map:

    name -> bob

While traversing the string:

    h -> result = "h"
    i -> result = "hi"

Then `(name)` is encountered.

Key:

    "name"

It exists in the map, so:

    result += "bob"

Final result:

    "hibob"

Example 2:
----------
s = "(name)is(age)"
knowledge = [["name","bob"],["age","20"]]

The replacements are:

    (name) -> bob
    (age)  -> 20

So:

    "(name)is(age)"

becomes:

    "bobis20"

If a key is missing:

    "(unknown)"

it becomes:

    "?"

Time Complexity:
----------------
O(n)

The string is traversed once, and each key lookup in the unordered map
takes O(1) average time.

The `find()` and `substr()` operations together process the bracketed
parts of the string.

Space Complexity:
-----------------
O(k + n)

where:
- `k` is the total size of the knowledge map.
- `n` is the size of the resulting string.

The unordered map stores all key-value pairs, and `result` stores the
final evaluated string.
*/

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> knowledgempp;
        for (auto& pair : knowledge) {
            knowledgempp[pair[0]] = pair[1];
        }
        string result;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                int closingBracketIndex = s.find(')', i + 1);
                string key = s.substr(i + 1, closingBracketIndex - i - 1);
                if (knowledgempp.count(key)) {
                    result += knowledgempp[key];
                } else {
                    result += '?';
                }
                i = closingBracketIndex;
            } else {
                result += s[i];
            }
        }
        return result;
    }
};
