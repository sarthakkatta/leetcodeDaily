/*
Problem: Minimum Number of Seconds to Reduce Mountain Height

Approach:
1. Use Binary Search on time to find the minimum seconds required.
2. For a given time (mid), calculate how many units of height each worker can remove.
3. The height removed follows the formula derived from the sum of natural numbers.
4. Sum the heights removed by all workers.
5. If the total height removed is >= mountainHeight, the time is feasible.
6. Adjust binary search to find the minimum feasible time.

Time Complexity: O(N log T)
Space Complexity: O(1)
*/

class Solution {
public:
    typedef long long ll;

    bool Check(ll mid, vector<int>& workerTimes, int mH) {
        ll h = 0;

        for(int &t : workerTimes) {
            h += (ll)(sqrt(2.0 * mid / t + 0.25) - 0.5);

            if(h >= mH)
                return true;
        }

        return h >= mH;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime = *max_element(begin(workerTimes), end(workerTimes));

        ll left = 1;
        ll right = (ll)maxTime * mountainHeight * (mountainHeight + 1) / 2;
        ll res = 0;

        while(left <= right) {
            ll mid = left + (right - left) / 2;

            if(Check(mid, workerTimes, mountainHeight)) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return res;
    }
};
