class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return {};
        
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix.front().size(), false));
        vector<vector<int>> instructions {{0,1}, {1,0}, {0, -1}, {-1, 0}};
        vector<int> res{matrix[0][0]};
        visited[0][0] = true;
        for(int i = 0, j = 0, moved = true;moved;){
            moved = false;
            for(auto& instruction : instructions){
                bool tmoved = true;
                while(tmoved){
                    tmoved = false;
                    int nextI = i + instruction[0], nextJ = j + instruction[1];
                    if(nextI < 0 || nextI >= matrix.size() || nextJ < 0 || nextJ >= matrix.front().size() || visited[nextI][nextJ])
                    {
                        continue;
                    }
                    visited[nextI][nextJ] = true;
                    moved = true; tmoved = true;
                    res.push_back(matrix[i = nextI][j = nextJ]);
                }
            }
        }
        return res;
    }
};