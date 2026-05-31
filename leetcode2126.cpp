/*
Problem: LeetCode 2126 – Destroying Asteroids

Approach:
1. Sort asteroids in increasing order.
2. Maintain current mass of planet:
   - Use long long to avoid overflow.
3. Traverse sorted asteroids:
   - If current mass < asteroid mass:
       → cannot destroy it → return false.
   - Else:
       → destroy asteroid.
       → increase mass by asteroid size.
4. If all asteroids are destroyed:
   - Return true.

Key Idea:
- Always destroy the smallest available asteroid first
  to maximize future growth.

Time Complexity: O(N log N)
Space Complexity: O(1) (excluding sorting space)
*/

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long sum = mass;
        for(int n : asteroids){
            if(sum < n)return false;
            sum += n;
        }
        return true;
    }
};
