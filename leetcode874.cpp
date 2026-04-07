/*
Problem: LeetCode 874 – Walking Robot Simulation

Approach:
1. Store all obstacles in a set using string keys "x_y" for O(1) lookup.
2. Initialize:
   - Position (x, y) = (0, 0)
   - Direction = (0, 1) → facing North
3. Traverse each command:
   - If command == -2 → turn left (update direction vector)
   - If command == -1 → turn right
   - Else → move forward step by step
4. For each step:
   - Compute next position (newx, newy)
   - If it's an obstacle → stop moving further for this command
   - Else → update position
5. After each command, update maximum distance from origin:
   - maxD = max(maxD, x² + y²)
6. Return maxD.

Time Complexity: O(N * K) (K = max steps per command)
Space Complexity: O(M) (for obstacles set)
*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for(vector<int> &obs : obstacles){
            string key = to_string(obs[0]) + "_" + to_string(obs[1]);
            st.insert(key);
        }
        int x = 0;
        int y = 0;
        int maxD = 0;

        pair<int,int> dir = {0,1};

        for(int i = 0 ; i < commands.size();i++){
            if(commands[i] == -2){
                dir = {-dir.second, dir.first};
            }else if(commands[i] == -1){
                dir = {dir.second, -dir.first};
            }else{
                for(int steps = 0; steps < commands[i]; steps++){
                    int newx = x + dir.first;
                    int newy = y + dir.second;

                    string nextkey = to_string(newx)+ "_" + to_string(newy);

                    if(st.find(nextkey) != st.end()){
                        break;
                    }

                    x = newx;
                    y = newy;
                }
            }
            maxD = max(maxD, x*x + y*y);
        }
        return maxD;
    }
};
