#pragma once

#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    void backtrack(std::vector<std::string>& results, std::string current,
                   int open, int close, int n) {
        // printf("current = \"%s\" open = %d close = %d n = %d\n", current.c_str(),
        //        open, close, n);

        if (current.size() == 2 * n) {
            // printf("results current = \"%s\"\n", current.c_str());
            results.push_back(current);
            return;
        }

        if (open < n) {
            backtrack(results, current + "(", open + 1, close, n);
        }

        if (close < open) {
            backtrack(results, current + ")", open, close + 1, n);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        std::string current;

        backtrack(result, current, 0, 0, n);

        return result;
    }
};
