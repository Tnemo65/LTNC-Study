#include <iostream>
using namespace std;
void selectionSort(int* a, int n) {
    //Duyệt từng phần tử của mảng
    for (int i = 1; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n - 1; j++) {
            //Cứ thằng nào nhỏ hơn a[minIndex] thì gán minIndex bằng nó
            //Cuối cùng sẽ ra vị trí thằng có giá trị nhỏ nhất
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        //Nếu mà minIndex không còn ở vị trí ban đầu thì đổi chỗ
        //Tức là tìm thấy thằng nhỏ hơn đó
        if (minIndex != i) {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}