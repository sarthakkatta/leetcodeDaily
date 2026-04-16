/*
Problem: Closest Same Element Distance in Circular Array (Custom)

Approach:
1. Build a hashmap:
   - mp[value] → stores all indices where that value appears.
2. For each query index qi:
   - Get the element nums[qi].
   - Fetch its index list from map.
3. If only one occurrence → answer = -1.
4. Use binary search (lower_bound) to find position of qi in index list.
5. Check two neighbors:
   - Right neighbor → (pos + 1) % size
   - Left neighbor → (pos - 1 + size) % size
6. For both neighbors:
   - Compute direct distance = |qi - index|
   - Compute circular distance = n - direct distance
   - Take minimum.
7. Store result for each query.

Key Idea:
- Circular array → consider both direct and wrap-around distance.
- Only nearest neighbors matter due to sorted indices.

Time Complexity: O(N + Q log N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> result;

        for(int qi : queries) { //O(Q)
            int element = nums[qi];
            vector<int>& vec = mp[element];

            int sz = vec.size();

            //no more occurence of this element
            if(sz == 1) {
                result.push_back(-1);
                continue;
            }

            int pos = lower_bound(begin(vec), end(vec), qi) - begin(vec); //log(n)
            int res = INT_MAX;

            //Right Neighbour - pos+1
            int right = vec[(pos+1) % sz];
            int d = abs(qi - right);//straught forqward distance
            int circularDist = n-d;
            res = min({res, d, circularDist});


            //Left Neighbour - pos-1
            int left = vec[(pos-1+sz) % sz];
            d = abs(qi - left);//straught forqward distance
            circularDist = n-d;
            res = min({res, d, circularDist});

            result.push_back(res);
        }

        return result;
    }
};
