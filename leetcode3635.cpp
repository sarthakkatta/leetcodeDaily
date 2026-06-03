/*
Problem: Earliest Finish Time for Land and Water Rides II

Approach:
1. Create helper function getAns():
   - Find the earliest possible finishing time
     among all rides of the first category.
   - minFinish = minimum(startTime + duration)
2. Try taking a ride from the second category after it:
   - Ride can start at:
       max(secondRideStartTime, minFinish)
   - Compute finishing time.
3. Update global answer.
4. First call:
   - Land → Water
5. Swap arrays:
   - Land becomes Water
   - Water becomes Land
6. Second call:
   - Water → Land
7. Return minimum finish time obtained.

Key Idea:
- Instead of checking every pair,
  only the earliest finishing ride of the first category matters.

Time Complexity: O(N + M)
Space Complexity: O(1)
*/

class Solution {
public:

void getAns(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration ,int &ans){
        int minFinish = INT_MAX;
    
        for(int i = 0 ; i<landStartTime.size() ; i++)
            minFinish = min(minFinish , landStartTime[i] + landDuration[i]);

        for(int i = 0 ; i<waterStartTime.size() ; i++)
            ans = min(ans ,max( waterStartTime[i] , minFinish) + waterDuration[i]);
}
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX;
        getAns(landStartTime, landDuration, waterStartTime, waterDuration , ans);

        swap(landStartTime,waterStartTime);
        swap(landDuration, waterDuration);

        getAns(landStartTime, landDuration, waterStartTime, waterDuration , ans);
        return ans;
    }
};
