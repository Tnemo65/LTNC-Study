// Bubble sort sẽ chạy 2 vòng for
// Vòng for i để lấy 1 số làm mốc từ đầu đến cuối
// Từ vòng for j, chạy j từ 0 -> n-2, so sánh từng cặp liền kề
// Nếu số trước lớn hơn số sau thì swap
#include <bits/stdc++.h>
using namespace std;
void BubbleSort(int a[], int n){
    int temp; // biến tạm temp
    for (int i = 0; i < n; i++){
	    for (int j = 0; j < n - 1; j++){
		    if (a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
			}
		}
	}
}
int main() {
    int arr[] = {5, 3, 8, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    BubbleSort(arr, size);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}