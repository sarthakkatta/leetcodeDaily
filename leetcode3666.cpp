/*
Problem: Minimum Operations to Transform Binary String


Approach:
1. Count number of zeros and ones in string.
2. If no zeros, return 0.
3. Try operations from 1 to n.
4. For each ops, compute total flips = ops * k.
5. Check parity condition (totalFlip - zero must be even).
6. Based on odd/even ops, check valid flip range.
7. Return minimum valid ops, otherwise -1.

Time Complexity: O(N^2)
Space Complexity: O(1)
*/


class Solution{
public:
    int minOperations(string s, int k){
        long long n = s.size();
        long long zero = 0;
        for(char c : s)
            if(c == '0') zero++;
        if(zero == 0) return 0;
        long long one = n - zero;
        for(long long ops = 1; ops <= n; ops++){
            long long totalFlip = ops * 1LL * k;
            if((totalFlip - zero) % 2 != 0)
                continue;
            if(ops % 2 == 1){
                if(totalFlip >= zero &&
                   totalFlip <= zero * ops + one * (ops - 1))
                    return ops;
            }
            else{
                if(totalFlip >= zero &&
                   totalFlip <= zero * (ops - 1) + one * ops)
                    return ops;
            }
        }
        return -1;
    }
};
