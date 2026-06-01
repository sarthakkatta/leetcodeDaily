/*
Problem: LeetCode 2144 – Minimum Cost of Buying Candies With Discount

Approach:
1. Sort candies in descending order.
2. For every group of 3 candies:
   - Pay for the two most expensive candies.
   - Get the third candy (cheapest in the group) for free.
3. Traverse sorted array:
   - Add candy cost if index % 3 != 2.
   - Skip every third candy.
4. Return total minimum cost.

Key Idea:
- To maximize discount, make the cheapest candy in every
  group of three the free one by sorting in descending order.

Time Complexity: O(N log N)
Space Complexity: O(1)
*/

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(), greater<int>());
        int ans = 0;
        for(int i = 0; i < cost.size(); i++){
            if (i % 3 != 2) {   
                ans += cost[i];
            }
        }
        return ans;
    }
};
