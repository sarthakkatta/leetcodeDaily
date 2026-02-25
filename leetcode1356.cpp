/*
Problem: LeetCode 1356 – Sort Integers by The Number of 1 Bits


Approach:
1. For each number, count number of set bits.
2. Store pair of (setBitsCount, number).
3. Sort pairs in ascending order.
4. Extract numbers from sorted pairs.
5. Return sorted array.

Time Complexity: O(N log N)
Space Complexity: O(N)
*/


class Solution{
public:
    vector<int> sortByBits(vector<int>& arr){
        int n = arr.size();
        vector<pair<int,int>> bits;
        for(int num : arr){
            int number = num;
            int count = 0;
            while(number){
                if(number & 1) count++;
                number = number >> 1;
            }
            bits.push_back({count, num});
        }
        sort(bits.begin(), bits.end());
        for(int i = 0; i < n; i++){
            arr[i] = bits[i].second;
        }
        return arr;
    }
};
