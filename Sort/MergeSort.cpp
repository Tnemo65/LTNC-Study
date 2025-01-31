// MergeSort sẽ chia mảng lớn ra 2 mảng nhỏ, cho đến khi không chia được nữa thì thôi
// Khi không chia được nữa ta sẽ đến bước merge
// Merge sẽ chạy i của mảng 1 và j của mảng 2 song song
// Nếu L[i] < M[j] thì sẽ lấy L[i] gán vào 1 mảng lớn và tăng i lên để check tiếp
// Nếu như đang soát mà 1 trong 2 mảng L M hết phần từ thì gán phần còn lại của mảng vẫn còn vào mảng mới luôn

#include <iostream>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++){
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++){
        M[j] = arr[q + 1 + j];
    }

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2){
        if (L[i] <= M[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r){
    if (l < r){
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

// 4 3 2 9
// me (0, 3)
//     m = 0 + 1 = 1
//     me (0, 1)
//         m = 0 + 0 = 0
//         me (0, 0) => return
//         me (1, 1) => return
//         merge(a, 0, 0, 1)
//     me (2, 3)
//         m = 2 + 0 = 2
//         me (2, 2) => return
//         me (3, 3) => return
//         merge (a, 1, 2, 3)
//     merge (a, 0, 1, 3)


// Print the array
void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver program
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}