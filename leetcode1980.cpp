/*
Problem: LeetCode 1980 – Find Unique Binary String


Approach:
1. Use diagonal construction (Cantor's diagonalization).
2. For each index i, check nums[i][i].
3. If it is '0', append '1' to result.
4. Otherwise append '0'.
5. This guarantees the new string differs from every given string at least at one position.

Time Complexity: O(N)
Space Complexity: O(N)
*/


class Solution{
public:
    string findDifferentBinaryString(vector<string>& nums){
        string ans = "";

        for(int i = 0; i < nums.size(); i++){
            if(nums[i][i] == '0'){
                ans += '1';
            }
            else{
                ans += '0';
            }
        }

        return ans;
    }
};
