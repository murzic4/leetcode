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

{ TreeNode* r = makeTree({6,2,8,0,4,7,9,-1,-1,3,5}); auto find = [&](TreeNode* root, int v) -> TreeNode* { vector<TreeNode*> st{root}; while (!st.empty()) { TreeNode* t = st.back(); st.pop_back(); if (!t) continue; if (t->val == v) return t; st.push_back(t->left); st.push_back(t->right); } return nullptr; }; check(s.lowestCommonAncestor(r, find(r,2), find(r,8))->val == 6, "LCA(2,8) -> 6"); }

    cout << "\nResult: " << passed << " passed, " << failed << " failed\n";
    return failed == 0 ? 0 : 1;
}
