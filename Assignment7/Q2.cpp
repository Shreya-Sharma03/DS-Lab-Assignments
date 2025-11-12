/* 2. A slightly improved selection sort – We know that selection sort algorithm takes the minimum on
every pass on the array, and place it at its correct position. The idea is to take also the maximum on
every pass and place it at its correct position. So in every pass, we keep track of both maximum and
minimum and array becomes sorted from both ends. Implement this logic.
 */
#include <iostream>
using namespace std;
void improvedSelectionSort(int arr[], int n) {
    int start = 0;
    int end = n - 1;
while (start < end) {
        int minIndex = start;
        int maxIndex = start;
        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[minIndex]) minIndex = i;
            if (arr[i] > arr[maxIndex]) maxIndex = i;
        }
        if (minIndex != start) {
            int temp = arr[start];
            arr[start] = arr[minIndex];
            arr[minIndex] = temp;
            if (maxIndex == start) maxIndex = minIndex;
        }
        if (maxIndex != end) {
            int temp = arr[end];
            arr[end] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
        start++;
        end--;
    }
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    improvedSelectionSort(arr, n);
    cout << "Sorted array: ";
    display(arr, n);
    return 0;
}
