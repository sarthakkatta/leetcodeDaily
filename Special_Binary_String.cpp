/*
Problem: LeetCode 761 – Special Binary String


Approach:
1. Special string has equal number of 1s and 0s and prefix always has more 1s.
2. Split string into valid special substrings.
3. Recursively make inner substring largest.
4. Wrap with 1 and 0 and store.
5. Sort all substrings in descending order and join.

Time Complexity: O(N log N)
Space Complexity: O(N)
*/


class Solution {
public:

    string makeLargestSpecial(string s) {

        vector<string> special;

        int start = 0;

        int sum = 0;

        for(int i = 0; i < s.length(); i++){

            sum += s[i] == '1' ? 1 : -1;
            
            if(sum == 0){

                string inner = s.substr(start + 1, i - start - 1);

                special.push_back("1" + makeLargestSpecial(inner) + "0");

                start = i + 1;
            }
        }

        sort(begin(special), end(special), greater<string>());

        string res;

        for(string &str : special){

            res += str;
        }

        return res;
    }
};
