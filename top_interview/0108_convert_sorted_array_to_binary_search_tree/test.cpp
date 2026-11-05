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

int main() {
    Solution s;

{ vector<int> v{-10,-3,0,5,9}; TreeNode* r = s.sortedArrayToBST(v); vector<int> in; function<void(TreeNode*)> go = [&](TreeNode* t) { if (!t) return; go(t->left); in.push_back(t->val); go(t->right); }; go(r); check(in == v, "nums = [-10,-3,0,5,9] -> inorder [-10,-3,0,5,9]"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
