class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n,INT_MIN);
        vector<int> mini(n,INT_MAX);
        maxi[0] = nums[0];
        mini[n-1] = nums[n-1];
        for(int i = 1; i < n; i++){
                maxi[i] = max(nums[i],maxi[i-1]);
        }
        for(int i = n-2; i >= 0; i--){
                mini[i] = min(nums[i],mini[i+1]);
        }
        int idx = n;
        for(int i = 0; i < n; i++){
                int score = maxi[i] - mini[i];
                if(score <= k){
                    idx = min(idx,i);
                }
        }
        return idx == n? -1 : idx;
    }
};
