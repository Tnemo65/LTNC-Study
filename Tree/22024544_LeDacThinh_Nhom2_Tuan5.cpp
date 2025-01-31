#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    vector<Node *> listOfChild;

    Node(int x){
        this->data = x;
    }
};

struct Tree
{
    Node *root;
    bool binaryTree = true;
    // Tính chiều cao của cây
    int calculateHeight(Node *root){
        if (root == nullptr){
            return 0;
        }
        int height = 0;
        for (int i = 0; i < root->listOfChild.size(); i++){
            // Đệ quy tính chiều cao của từng cây con và so sánh
            int heightOfChild = calculateHeight(root->listOfChild[i]);
            height = max(height, heightOfChild);
        }
        return height + 1;
    }
    bool isLeaf(Node *root){
        // Lá là không có con
        if (root->listOfChild.size() == 0)
        {
            return true;
        }
        return false;
    }
    // Print tiền thứ tự
    void preorderTraversal(Node *root){
        if (root == nullptr){
            return;
        }
        cout << root->data << " ";
        for (int i = 0; i < root->listOfChild.size(); i++){
            preorderTraversal(root->listOfChild[i]);
        }
    }

    // Print hậu thứ tự
    void postorderTraversal(Node *root){
        if (root == nullptr){
            return;
        }
        for (int i = 0; i < root->listOfChild.size(); i++){
            postorderTraversal(root->listOfChild[i]);
        }
        cout << root->data << " ";
    }
    // Kiểm tra xem có phải binary trê không, nếu có thì in
    // theo thứ tự inorder traversal

    bool isBinaryTree(Node *root){
        // Cây rỗng là cây nhị phân
        if (root == NULL){
            return true;
        }
        // Tính từ cha
        // Nếu mà không phải lá + có 2 con trở lên
        if (root->listOfChild.size() > 2 && !isLeaf(root)){
            binaryTree = false;
        }
        for (int i = 0; i < root->listOfChild.size(); i++){
            // Tính từ các con trở đi
            binaryTree *= isBinaryTree(root->listOfChild[i]);
        }

        return binaryTree;
    }

    void inorderTraversal(Node *root){
        if (root == NULL){
            return;
        }

        int n = root->listOfChild.size();
        if (n >= 1){
            inorderTraversal(root->listOfChild[0]);
        }
        cout << root->data << " ";
        if (n == 0){
            return;
        }
        if (n == 2){
            inorderTraversal(n == 2 ? root->listOfChild[1] : NULL);
        }
    }
    // Thêm node vào, cách này sẽ thêm mà không bị mặc định là cây nào
    void addNode(Node *rootNode, int root, int child){
        if (root == rootNode->data){
            Node *newChild = new Node(child);
            rootNode->listOfChild.push_back(newChild);
            return;
        }
        else{
            int n = rootNode->listOfChild.size();
            for (int i = 0; i < n; i++)
            {
                addNode(rootNode->listOfChild[i], root, child);
            }
        }
    }
    //Kiểm tra cây cân bằng
    bool isBalanced(Node* root) {
        if (root == nullptr) {
            return true;
        }

        for (int i = 0; i < root->listOfChild.size(); i++) {
            if (!isBalanced(root->listOfChild[i])) {
                return false;
            }
        }

        int maxHeight = 0;
        int minHeight = INT_MAX;

        for (int i = 0; i < root->listOfChild.size(); i++) {
            int height = calculateHeight(root->listOfChild[i]);
            maxHeight = max(maxHeight, height);
            minHeight = min(minHeight, height);
        }

        return (maxHeight - minHeight) <= 1;
    }
};
//  //Đầu vào sẽ là 2 số N M , N là số nốt, M là số cạnh
//  //M dòng sau chứa u và v, u là cha của v
int main(){
    int n, m;
    cin >> n >> m;

    Tree *tree = new Tree();

    int root;
    int child;
    for (int i = 0; i < m; i++){
        cin >> root;
        cin >> child;

        if (tree->root == NULL){
            Node *newRoot = new Node(root);
            tree->root = newRoot;
        }
        tree->addNode(tree->root, root, child);
    }
    cout << tree->calculateHeight(tree->root) << endl;
    tree->preorderTraversal(tree->root);
    cout << endl;
    tree->postorderTraversal(tree->root);
    cout << endl;
    if (tree->isBinaryTree(tree->root)){
        tree->inorderTraversal(tree->root);
    }
    else{
        cout << "NOT BINARY TREE" << endl;
    }

    return 0;
}