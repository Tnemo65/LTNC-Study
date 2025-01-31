#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(){
        next = NULL;
    }
};

class linkedList{
public:

    Node* head;
    linkedList(){
        head = NULL;
    }
    //Insert bất kì
    void insert(int p, int x){
        Node* newNode = new Node;
        newNode -> data = x;
        if(p == 0 || head == NULL){
            newNode -> next = head;
            head = newNode;
        }
        else{
            Node* cur = head;
            int count = 0;
            while(cur -> next != NULL && count != p - 1 ){
                cur = cur -> next;
                count ++;
            }
            newNode -> next = cur -> next;
            cur -> next = newNode;
        }
    }
    //Xóa
    void remove(int p){
        if(head == NULL){
            return;
        }
        Node* cur = head;
        if(p == 0){
            head = head -> next;
            delete cur;
        }
        else{
            Node* lcur = NULL;
            int count = 0;
            while(cur -> next != NULL && count != p){
                lcur = cur; 
                cur = cur -> next;
                count ++;
            }
            if(cur == NULL){
                return;
            }
            lcur -> next = cur -> next;
            delete cur;
        }
    }
    //Print xuôi
    void print(){
        Node* cur = head;
        while(cur != NULL){
            cout << cur -> data << " ";
            cur = cur -> next;
        }
        cout << endl;
    }
};

    //Print ngược
    void printReverse(Node* cur,int n) {
        if (cur == nullptr || n == 0) {
            return;
        }
        printReverse(cur->next, n -1 );
        cout << cur->data << " ";
    }

int main(){
    linkedList ll;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s == "insert"){
            int p, x;
            cin >> p >> x;
            ll.insert(p, x);
        }
        else if(s == "delete"){
            int p;
            cin >> p;
            ll.remove(p);
        }
    }
    ll.print();
    printReverse(ll.head, 4);
    return 0;
}