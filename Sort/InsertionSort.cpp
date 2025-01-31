#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        int count = 0;
        // Di chuyển các phần tử của arr[0..i-1] lớn hơn key về sau một vị trí so với vị trí hiện tại
        while (j >= 0 && arr[j] > key) {
            cout << "Lan thu : " << count <<endl;
            count ++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // In mảng sau mỗi bước
        cout << "Buoc " << i << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;

        
    }
}

// Hàm main để kiểm tra thuật toán sắp xếp chèn
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr, n);

    cout << "Mang da sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


// void insertionSort(int arr[]):
 
//     for(int i = 1; i < arr.size(); i++){
//         int key = arr[i];
//         // Di chuyển các phần tử của mảng arr[0..i-1], lớn hơn key, 
//         // đến một vị trí phía trước vị trí hiện tại
//         int j = i-1;
//         //Khi j >= 0 tức là j có thể = -1, tức là phân tử đầu mảng thỏa mãn
//         //Khi ấy sẽ gán arr[j+1] = arr[0] = key
//         //Nếu như key vẫn nhỏ hơn arr[j] thì vẫn duyệt
//         while (j >= 0 && key < arr[j]){
//             //Đẩy số lớn hơn key dần về đuôi mảng
//             arr[j + 1] = arr[j];
//             //Cho j về đầu mảng tìm tiếp
//             j -= 1;
//         }
//         arr[j + 1] = key;
//     }
// //Ý tưởng:
// //Ta sẽ key chạy lần lượt từ đầu mảng đến cuối mảng
// //Chạy 1 biến j ngay trước đó, ta sẽ duyệt biến j này từ số trước key về đến đầu mảng
// //Nếu gặp số nào mà lớn hơn key thì sẽ đẩy số đó về sau của mảng, đồn dần về sau
// //Và key sẽ được đặt vào vì trị cuối cùng mà có phần tử lớn hơn key

// // 12, 11, 13, 5, 6
// // **12, 11(key), 13, 5, 6
// // bắt đầu vòng for i = 1 (phần tử thứ 2 array) to 4 (phần tử cuối cùng của array)
//     // i = 1. thấy 11 nhỏ hơn 12, di chuyển 12 và chèn 11 trước 12 
// // **11, **12 13, 5, 6
//     // i = 2. 13 sẽ vẫn giữ vị trí của nó vì tất cả phần tử từ A[0..I-1] đều nhỏ hơn 13
// // **12, **12, **13, 5, 6
//     // i = 3. 5 sẽ di chuyển về đầu tiên và tất cả các phần tử từ 11 đến 13 di chuyển về phái sau 1 chỉ số. 
// // **5, **11, **12, **13, 6
//     // i = 4. 6 sẽ chạy về sau 5, và tất cả các phần tử từ 11 đến 13 di chuyển về phái sau 1 chỉ số . 
// // **5, **6, **11, **12, **13 