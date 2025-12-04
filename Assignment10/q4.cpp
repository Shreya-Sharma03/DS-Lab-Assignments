//Find the first non-repeating element in an array using a hash map.
#include <iostream>
using namespace std;
int firstNonRepeating(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        bool repeated = false;
        for (int j = 0; j < n; ++j) {
            if (i != j && arr[i] == arr[j]) {
                repeated = true;
                break;
            }
        }
        if (!repeated) {
            return arr[i];
        }
    }
    return -1;  
}
int main() {
    int arr[] = {4, 5, 1, 2, 0, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int res = firstNonRepeating(arr, n);
    if (res != -1)
        cout << res << endl;  
    else
        cout << "No non-repeating element" << endl;
    return 0;
}
