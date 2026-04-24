/*
Problem: LeetCode 2833 – Furthest Point From Origin

Approach:
1. Count:
   - cntR → number of 'R' moves
   - cntL → number of 'L' moves
   - cnt_ → number of '_' (flexible moves)
2. To maximize distance:
   - Assign all '_' in the direction that increases distance.
3. Final distance:
   - abs(cntR - cntL) + cnt_

Key Idea:
- Use flexible moves to maximize imbalance between L and R.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int cntR = 0, cntL = 0, cnt_ = 0;
        for(char c : moves){
            if(c == 'R') cntR++;
            else if(c == 'L') cntL++;
            else cnt_++; 
        }
        return abs(cntR - cntL) + cnt_;
    }
};
