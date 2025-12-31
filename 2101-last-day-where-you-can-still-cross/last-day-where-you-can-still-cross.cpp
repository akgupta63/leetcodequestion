#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rows, cols;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    bool canCross(int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(rows, vector<int>(cols, 0));

        // Flood cells up to "day"
        for (int i = 0; i < day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Start BFS from top row land cells
        for (int c = 0; c < cols; c++) {
            if (grid[0][c] == 0) {
                q.push({0, c});
                visited[0][c] = true;
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == rows - 1) return true; // reached bottom

            for (auto &d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                    !visited[nr][nc] && grid[nr][nc] == 0) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        rows = row;
        cols = col;

        int left = 0, right = cells.size();
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canCross(mid, cells)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
