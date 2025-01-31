#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int id;
    vector<Node*> children;
};

bool isFullBinaryTree(Node* root) {
    if (root == nullptr) {
        return true;
    }

    if (root->children.size() == 0 || root->children.size() == 2) {
        bool isFull = true;
        for (Node* child : root->children) {
            isFull = isFull && isFullBinaryTree(child);
        }
        return isFull;
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<Node*> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node{i};
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        nodes[x]->children.push_back(nodes[y]);
    }

    bool isFullBinary = isFullBinaryTree(nodes[0]);

    if (isFullBinary) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    // Giải phóng bộ nhớ
    for (Node* node : nodes) {
        delete node;
    }

    return 0;
}