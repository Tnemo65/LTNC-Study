#include <iostream>
#include <stack>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
};
struct dlist{
    Node* head;
    Node* tail;
};

dlist* createList(int x){
    dlist* l = new dlist;
    l -> head = new Node;
    l -> head -> data = x;
    l -> head -> next = NULL;
    l -> head -> prev = NULL;
    l -> tail = l -> head;
    return l;
}
dlist* addNode(dlist* list, int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    newNode -> prev = list -> tail;
    list -> tail -> next = newNode;
    list -> tail = newNode;
    return list;
}   

int count_triplets(dlist* list){
    //Nếu list rỗng || list có head rỗng 
    //list có 1 phần tử || list có 2 phần tử
    if(list == NULL || list -> head == NULL || 
    list -> head -> next == NULL || list -> head -> next -> next == NULL){
        return 0;
    }
    int count = 0;
    //Xét luôn từ phần tử thứ 2 và dừng ở phần từ trước cuối 
    Node* cur = list -> head -> next;
    while(cur -> next != NULL){
        int check = cur -> prev -> data + cur -> data + cur -> next -> data;
        if(check == 0){
            count++;
        }
        cur = cur -> next;
    }
    return count;
}
void print(dlist* list){
    Node* cur = list -> head;
    while(cur != NULL){
        cout << cur -> data << " ";
        cur = cur -> next;
    }
    cout << endl;
}
int main() {
    int n;
    cin >> n;
    dlist* list = new dlist;
    int x;
    cin >> x;
    list = createList(x);
    for(int i = 0; i < n - 1; i++){
        cin >> x;
        list = addNode(list, x);
    }
    int ans = count_triplets(list);
    print(list);
    cout << ans << endl;
    return 0;
}