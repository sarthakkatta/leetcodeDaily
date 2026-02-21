/*
Problem: LeetCode 762 – Prime Number of Set Bits in Binary Representation


Approach:
1. For each number in range [left, right], count set bits using bitwise shift.
2. Check if the set bit count is prime.
3. If prime, increment answer count.
4. Return total count.

Time Complexity: O(N * log N)
Space Complexity: O(1)
*/


class Solution{
public:

    int countSetBits(int n){
        int count = 0;
        while(n > 0){
            if(n & 1){  //checks if last bit is 1
                count++; 
            }
            n = n >> 1; //shift right
        }
        return count;
    }

    bool isPrime(int n){
        if(n < 2)
            return false;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }

    int countPrimeSetBits(int left, int right){
        int ans = 0;
        for(int i = left; i <= right; i++){
            int bits = countSetBits(i);
            if(isPrime(bits)){
                ans++;
            }
        }
        return ans;
    }
};
