/*
    Problem: Robot Return to Origin

    Approach:
    - Track movement in x (vertical) and y (horizontal) directions
    - U -> x++
    - D -> x--
    - L -> y++ 
    - R -> y--
    - If final position is (0,0), return true
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c : moves) {
            if (c == 'U') x++;
            else if (c == 'D') x--;
            else if (c == 'L') y++;
            else if (c == 'R') y--;
        }
        return (x == 0 && y == 0);
    }
};
