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

check(s.levelOrder(makeTree({3,9,20,-1,-1,15,7})) == vector<vector<int>>{{3},{9,20},{15,7}}, "[3,9,20,null,null,15,7] -> [[3],[9,20],[15,7]]");

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
