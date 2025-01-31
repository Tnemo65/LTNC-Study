//Last In First Out
#include <iostream>
#include <stack>
using namespace std;
struct Node{
    int data;
    Node* next;
};
struct Stack{
    Node* top;
};
Node* makeNode(int x){
    Node* newNode = new Node;
    newNode-> data = x;
    newNode-> next = NULL;
    return newNode;
}

bool isEmpty(Stack* st){
    if(st -> top == NULL){
        return true;
    }
    return false;
}
//addFirst
void push(Stack* st, int x){
    Node* newNode = makeNode(x);
    if(isEmpty(st) == true){
        st -> top = newNode;
    }
    else{
        newNode -> next = st -> top;
        st -> top = newNode;
    }
}

//deleteFirst (delete top)
void pop(Stack* st){
    if(isEmpty(st)){
        return;
    }
    else{
        Node* cur = st -> top;
        st -> top = st -> top -> next;
        delete cur;
    }
}

void print(Stack* st){
    Node* cur = st -> top;
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void printReverse(Node* top){
    if(top == NULL){
        return;
    }
    printReverse(top -> next);
    cout << top -> data << " ";
}

int main() {
    int n;
    cin >> n;
    int x;
    string ope;
    Stack* st = new Stack;
    st -> top = NULL;
    for(int i = 0; i < n ; i++){
        cin >> ope;
        if(ope == "push"){
            cin >> x;
            push(st, x);
        }
        else if(ope == "pop"){
            pop(st);
        }
    }
    printReverse(st -> top);
    return 0;
}