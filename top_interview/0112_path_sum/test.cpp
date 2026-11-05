#include "solution.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

static int passed = 0;
static int failed = 0;

static void check(bool ok, const string& name) {
    if (ok) {
        ++passed;
        cout << "[PASS] " << name << "\n";
    } else {
        ++failed;
        cout << "[FAIL] " << name << "\n";
    }
}

static TreeNode* makeTree(const vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (i < (int)vals.size() && !q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if (i < (int)vals.size()) {
            if (vals[i] != -1) {
                cur->left = new TreeNode(vals[i]);
                q.push(cur->left);
            }
            ++i;
        }
        if (i < (int)vals.size()) {
            if (vals[i] != -1) {
                cur->right = new TreeNode(vals[i]);
                q.push(cur->right);
            }
            ++i;
        }
    }
    return root;
}

int main() {
    Solution s;

check(s.hasPathSum(makeTree({5,4,8,11,-1,13,4,7,2,-1,-1,-1,1}), 22) == true, "targetSum = 22 -> true");
    check(s.hasPathSum(makeTree({1,2,3}), 5) == false, "targetSum = 5 -> false");
    check(s.hasPathSum(makeTree({}), 0) == false, "empty -> false");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
