/*
Problem: LeetCode 1833 – Maximum Ice Cream Bars

Approach:
1. Sort the ice cream costs in increasing order.
2. Start buying from the cheapest ice cream.
3. For each cost:
   - If cost > remaining coins:
       → Cannot buy further.
       → Stop.
   - Otherwise:
       → Buy the ice cream.
       → Subtract cost from coins.
       → Increase answer count.
4. Return total number of ice creams bought.

Key Idea:
- Greedily buying the cheapest ice creams first
  maximizes the number of bars purchased.

Time Complexity: O(N log N)
  (due to sorting)

Space Complexity: O(1)
  (excluding sorting space)
*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int ans = 0;

        for(int x : costs){
            if(x > coins)
                break;

            coins -= x;
            ans++;
        }

        return ans;
    }
};
