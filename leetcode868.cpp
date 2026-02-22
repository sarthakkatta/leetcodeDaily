/*
Problem: LeetCode 868 – Binary Gap


Approach:
1. Traverse bits of number using right shift.
2. Track position of last set bit.
3. When new set bit is found, calculate distance from last set bit.
4. Update maximum distance.
5. Return maximum distance.

Time Complexity: O(log N)
Space Complexity: O(1)
*/


class Solution{
public:
    int binaryGap(int n){
        int last = -1;
        int curr = 0;
        int maxD = 0;
        while(n > 0){
            if(n & 1){
                if(last != -1){
                    maxD = max(maxD, curr - last);
                }
                last = curr;
            }
            curr++;
            n = n >> 1;
        }
        return maxD;
    }
};
