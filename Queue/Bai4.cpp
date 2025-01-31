//First In First Out
#include <iostream>
#include <stack>
using namespace std;
struct Node{
    int data;
    Node* next;
};
struct Queue{
    Node* head;
    Node* tail;
};

Node* makeNode(int x){
    Node* newNode = new Node;
    newNode-> data = x;
    newNode-> next = NULL;
    return newNode;
}

bool isEmpty(Queue* q){
    if(q -> head == NULL){
        return true;
    }
    return false;
}
//addLast
//(first)head -> 0 -> 0 -> 0 -> 0 -> (last)
void enqueue(Queue* q, int x){
    Node* newNode = makeNode(x);
    if(isEmpty(q)){
        q -> head = newNode;
        q -> tail = newNode;
    }
    else{
        q -> tail -> next = newNode;
        q -> tail = newNode;
    }
}
//deleteFirst
void dequeue(Queue* q){
    if(isEmpty(q)){
        return;
    }
    else{
        Node* cur = q -> head;
        q -> head = q -> head -> next;
        delete cur;
    }
}
void print(Queue* q){
    Node* cur = q -> head;
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int x;
    string ope;
    Queue* q = new Queue;
    q -> head = NULL;
    q -> tail = NULL;
    for(int i = 0; i < n ; i++){
        cin >> ope;
        if(ope == "enqueue"){
            cin >> x;
            enqueue(q, x);
        }
        else if(ope == "dequeue"){
            dequeue(q);
        }
    }
    print(q);
    return 0;
}