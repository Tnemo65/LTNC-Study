#include <iostream>
#include <vector>

using namespace std;

// Hash function
int hashFunction(int key, int size) {
    return (key + 3) % size;
}

// Function to print hash table
void printHashTable(const vector<int>& hashTable) {
    int size = hashTable.size();
    for (int i = 0; i < size; ++i) {
        cout << i << ": " << hashTable[i] << endl;
    }
}

// Function to handle collisions using linear probing
void handleCollisionsByLinearProbing(const vector<int>& keys) {
    int size = 17; // Size of the hash table
    vector<int> hashTable(size, -1); // Initialize hash table with -1 (indicating empty slot)

    for (int key : keys) {
        int index = hashFunction(key, size);
        int originalIndex = index;

        // Find the next available slot using linear probing
        while (hashTable[index] != -1) {
            index = (index + 1) % size; // Move to the next slot
            if (index == originalIndex) {
                // If we have traversed the entire table and returned to the original index,
                // then the table is full and we cannot insert the key
                cout << "Hash table is full. Cannot insert key: " << key << endl;
                return;
            }
        }

        // Insert the key into the hash table
        hashTable[index] = key;
    }

    // Print the hash table
    printHashTable(hashTable);
}

int main() {
    vector<int> keys = {1, 3, 18, 8, 23, 35, 11, 36, 20, 16};

    cout << "Using linear probing to handle collisions:" << endl;
    handleCollisionsByLinearProbing(keys);

    return 0;
}