/*
Problem: Earliest Finish Time for Land and Water Rides I

Approach:
1. Try every possible pair:
   - One land ride
   - One water ride
2. Consider both possible orders:
   a) Land → Water
   b) Water → Land
3. For Land → Water:
   - Calculate land finish time.
   - Water ride can start only after:
       max(land finish, water start time)
   - Compute total finish time.
4. For Water → Land:
   - Calculate water finish time.
   - Land ride can start only after:
       max(water finish, land start time)
   - Compute total finish time.
5. Store the minimum finish time among all combinations.
6. Return the earliest possible finish time.

Key Idea:
- Check every land-water combination and both ride orders.

Time Complexity: O(N × M)
Space Complexity: O(1)
*/

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // Land -> Water
                int landfinish = landStartTime[i] + landDuration[i];
                int waterstart = max(landfinish, waterStartTime[j]);
                int finish1 = waterstart + waterDuration[j];
                // Water -> Land
                int waterfinish = waterStartTime[j] + waterDuration[j];
                int landstart = max(waterfinish, landStartTime[i]);
                int finish2 = landstart + landDuration[i];

                ans = min(ans, min(finish1, finish2));
            }
        }

        return ans;
    }
};
