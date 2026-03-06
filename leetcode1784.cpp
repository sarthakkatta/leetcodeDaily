/*
Problem: LeetCode 1784 – Check if Binary String Has at Most One Segment of Ones


Approach:
1. Traverse the string from index 1.
2. If a '1' appears immediately after a '0', it means a new segment of ones started.
3. In that case, return false.
4. If traversal finishes without finding such a pattern, return true.

Time Complexity: O(N)
Space Complexity: O(1)
*/


class Solution{
public:
    bool checkOnesSegment(string s){
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '1' && s[i - 1] == '0') return false;
        }
        return true;
    }
};
