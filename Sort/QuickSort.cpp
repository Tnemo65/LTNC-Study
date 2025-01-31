#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& a, int l, int r) {
    if (l >= r) {
        return;
    }
    
    int pivot = a[l];  // Chọn pivot là phần tử đầu tiên của đoạn
    int i = l , j = r;
    
    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }
        cout << "Sau khi while i : " << i << " " << endl;
        while (a[j] > pivot) {
            j--;
        }
        cout << "Sau khi while j : " << j << " " << endl;
    
        if (i <= j) {
            cout << "Truoc khi swap thi i va j la" <<endl;
            cout << i << " " << j << endl;
            swap(a[i], a[j]);
            i++;
            j--;
        }

            cout << "Sau khi swap thi i va j la" <<endl;
            cout << i << " " << j << endl;
            cout << "Sau khi swap thi mang la " << endl;
            for (int num : a) {
                cout << num << " ";
             }
            cout << endl;
    }
    cout << endl;
    cout << "Lan cat thu 1" << endl;
    if (i < r){
        quickSort(a, i, r);  // Đệ quy sắp xếp đoạn bên phải pivot
    }
    cout << endl;
    cout << "Lan cat thu 2" << endl;
    if (l < j){
        quickSort(a, l, j);  // Đệ quy sắp xếp đoạn bên trái pivot
    }
}

int main() {
    vector<int> arr = {80,90,70};
    
    cout << "Mang truoc khi sap xep: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    quickSort(arr, 0, arr.size() - 1);
    
    cout << "\nMang sau khi sap xep: ";
    for (int num : arr) {
        cout << num << " ";
    }
    
    return 0;
}


