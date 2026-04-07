/*
Problem: LeetCode 2069 – Walking Robot Simulation II

Approach:
1. Precompute all boundary (perimeter) positions of the grid:
   - Bottom row → moving East
   - Right column → moving North
   - Top row → moving West
   - Left column → moving South
2. Store each position as {x, y, direction}.
3. Maintain an index `idx` to track current position on perimeter.
4. For step(num):
   - Move forward by updating index cyclically:
     idx = (idx + num) % pos.size()
5. getPos():
   - Return current coordinates from pos[idx].
6. getDir():
   - If robot hasn't moved → return "East"
   - Else return direction stored at current index.
7. Special handling:
   - Set starting cell (0,0) direction to South to correctly handle edge case after full cycle.

Time Complexity:
- Constructor: O(width + height)
- step(): O(1)
- getPos(), getDir(): O(1)

Space Complexity: O(width + height)
*/

class Robot {
public:
    int idx = 0;
    bool moved = false;
    vector<vector<int>> pos; //store all perimter/boundary cell positions
    //O(width + height)
    //S.C : (width + height)
    Robot(int width, int height) {
        //Bottom Row (left to right) -> East(0);
        for (int x = 0; x < width; x++) {
            pos.push_back({x, 0, 0});
        }

        //Right Col (bottom to top) -> North(1);
        for (int y = 1; y < height; y++) {
            pos.push_back({width - 1, y, 1});
        }

        // Top row (right to left) -> West(2)
        for (int x = width - 2; x >= 0; x--) {
            pos.push_back({x, height - 1, 2});
        }

        // Left column (top to bottom) -> South(3)
        for (int y = height - 2; y > 0; y--) {
            pos.push_back({0, y, 3});
        }

        //pos = {{0, 0, 0}, ....}
        pos[0][2] = 3; //Make it South for handkling corner case when it comes to (0,0) after moving

    }
    
    void step(int num) {
        moved = true;
        idx = (idx + num) % pos.size();
    }
    
    vector<int> getPos() {
        return {pos[idx][0], pos[idx][1]};
    }
    
    string getDir() {
        if(!moved)
            return "East";
        
        int d = pos[idx][2];
        if(d == 0) return "East";
        else if(d == 1) return "North";
        else if(d == 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
