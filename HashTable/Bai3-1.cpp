#include <iostream>
#include <vector>

using namespace std;

// Node structure for linked list
struct Node {
    int key;
    Node* next;

    Node(int k) : key(k), next(nullptr) {}
};

// Hash function
int hashFunction(int key, int size) {
    return (key + 3) % size;
}

// Function to print hash table
void printHashTable(const vector<Node*>& hashTable) {
    int size = hashTable.size();
    for (int i = 0; i < size; ++i) {
        cout << i << ": ";
        Node* node = hashTable[i];
        while (node != nullptr) {
            cout << node->key << " -> ";
            node = node->next;
        }
        cout << endl;
    }
}

// Function to handle collisions using chaining
void handleCollisionsByChaining(const vector<int>& keys) {
    int size = 17; // Size of the hash table
    vector<Node*> hashTable(size, nullptr); // Initialize hash table with nullptr

    for (int key : keys) {
        int index = hashFunction(key, size);
        if (hashTable[index] == nullptr) {
            hashTable[index] = new Node(key);
        } else {
            // Handle collision by chaining
            Node* node = hashTable[index];
            while (node->next != nullptr) {
                node = node->next;
            }
            node->next = new Node(key);
        }
    }

    // Print the hash table
    printHashTable(hashTable);
}

int main() {
    vector<int> keys = {1, 3, 18, 8, 23, 35, 11, 36, 20, 16};

    cout << "Using chaining to handle collisions:" << endl;
    handleCollisionsByChaining(keys);

    return 0;
}