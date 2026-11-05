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

static vector<int> levelOrder(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        if (!cur) {
            out.push_back(-1);
            continue;
        }
        out.push_back(cur->val);
        q.push(cur->left);
        q.push(cur->right);
    }
    while (!out.empty() && out.back() == -1) out.pop_back();
    return out;
}

int main() {
    Solution s;

{ vector<int> in{9,3,15,20,7}; vector<int> post{9,15,7,20,3}; check(levelOrder(s.buildTree(in, post)) == vector<int>{3,9,20,-1,-1,15,7}, "inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
