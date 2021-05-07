class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i=0, j=0, d=0;
        int dy[4] = {0,1,0,-1}, dx[4] = {1,0,-1,0};
        int cnt = matrix.size() * matrix[0].size();
        bool **visited = new bool*[matrix.size()];
        for (int i=0; i<matrix.size(); ++i) visited[i] = new bool[matrix[0].size()];
        for (int i=0; i<matrix.size(); ++i) for (int j=0; j<matrix[0].size(); ++j) visited[i][j] = false;
        
        vector<int> ret;
        while (cnt!=0) {
            ret.push_back(matrix[i][j]);
            visited[i][j] = true;
            if (i+dy[d] >= 0 && i+dy[d] < matrix.size() && j+dx[d] >= 0 && j+dx[d] < matrix[0].size() && visited[i+dy[d]][j+dx[d]] == false) {
                i += dy[d]; j += dx[d];
            }
            else {
                d = (d+1)%4;
                i += dy[d]; j += dx[d];
            }
            --cnt;
        }
        return ret;
    }
};