/*
Problem: LeetCode 3120 – Count the Number of Special Characters I

Approach:
1. Use two sets:
   - lower → stores lowercase letters
   - upper → stores uppercase letters
2. Traverse the string:
   - If character is lowercase → insert into lower
   - Else → insert into upper
3. Traverse lowercase set:
   - Check if corresponding uppercase character exists.
4. Count such characters.
5. Return total count.

Key Idea:
- A character is special if both lowercase
  and uppercase forms exist in the string.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set <char> lower;
        unordered_set <char> upper;
        for(char c : word){
            if(islower(c)){
                lower.insert(c);
            }else{
                upper.insert(c);
            }
        }
        int count = 0;
        for(char c : lower) {
            if(upper.count(toupper(c)))
                count++;
        }
        return count;
    }
};
