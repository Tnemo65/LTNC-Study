#include <iostream>
#include <vector>
using namespace std;

bool isBT(int node, vector<vector<int>> &listNode) {
    if (listNode[node].size() > 2) {
        return false;
    }
    for (int i : listNode[node]) {
        if (isBT(i, listNode) == false) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> listNode(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        listNode[a].push_back(b);
    }
    if (isBT(0, listNode)) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
    return 0;
}