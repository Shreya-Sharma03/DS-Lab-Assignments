/* Write a program interleave the first half of the queue with second half.
Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9 */
#include <iostream>
using namespace std;

void interleaveQueue(int arr[], int n) {
    if (n % 2 != 0) {
        cout << "Array size must be even.\n";
        return;
    }
    int firstHalf[n/2];
    int secondHalf[n/2];
    for (int i = 0; i < n/2; i++) {
        firstHalf[i] = arr[i];
    }
    for (int i = 0; i < n/2; i++) {
        secondHalf[i] = arr[i + n/2];
    }
    int index = 0;
    for (int i = 0; i < n/2; i++) {
        arr[index++] = firstHalf[i];
        arr[index++] = secondHalf[i];
    }
    cout << "Interleaved output: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    interleaveQueue(arr, n);
    return 0;
}
