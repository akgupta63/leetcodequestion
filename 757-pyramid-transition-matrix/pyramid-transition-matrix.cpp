#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;   // memoization

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }

    bool dfs(string bottom) {
        if (bottom.size() == 1)
            return true;

        // If already computed
        if (memo.count(bottom))
            return memo[bottom];

        vector<string> nextRows;
        string current;
        buildNext(bottom, 0, current, nextRows);

        for (string &row : nextRows) {
            if (dfs(row)) {
                memo[bottom] = true;
                return true;
            }
        }

        memo[bottom] = false;
        return false;
    }

    void buildNext(string &bottom, int index, string &current,
                   vector<string> &nextRows) {
        if (index == bottom.size() - 1) {
            nextRows.push_back(current);
            return;
        }

        string key = bottom.substr(index, 2);
        if (!mp.count(key))
            return;

        for (char c : mp[key]) {
            current.push_back(c);
            buildNext(bottom, index + 1, current, nextRows);
            current.pop_back();
        }
    }
};
