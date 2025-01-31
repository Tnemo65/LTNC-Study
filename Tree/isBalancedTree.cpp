#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
vector<int> depth;

bool isBalancedTree(int node) {
    if (tree[node].empty()) {
        return true;
    }

    vector<int> childDepths;
    for (int child : tree[node]) {
        if (!isBalancedTree(child)) {
            return false;
        }
        childDepths.push_back(depth[child]);
    }

    sort(childDepths.begin(), childDepths.end());

    if (childDepths.back() - childDepths.front() > 1) {
        return false;
    }

    depth[node] = childDepths.back() + 1;

    return true;
}

int main() {
    int n;
    cin >> n;

    tree.resize(n);
    depth.resize(n, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
    }

    if (isBalancedTree(0)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}