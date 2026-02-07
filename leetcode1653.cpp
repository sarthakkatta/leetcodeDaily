/*
Problem: LeetCode 1653 – Minimum Deletions to Make String Balanced

Approach:
1. Traverse string from left to right.
2. Count how many 'b' characters appear before current index.
3. When encountering 'a' after some 'b', delete either this 'a' or one previous 'b'.
4. Greedily remove one 'b' and increment deletion count.
5. Final deletion count is answer.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int minimumDeletions(string s) {
        int bBefore = 0, deletion = 0;

        for(auto c : s){
            if(c == 'b') bBefore += 1;
            else if(bBefore > 0){
                bBefore -=1;
                deletion +=1;
            }
        }

        return deletion;
    }
};
