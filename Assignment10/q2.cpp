//Given two arrays, find the common elements using a hash set.
#include <bits/stdc++.h>
using namespace std;
vector<int> commonElements(const vector<int>& A, const vector<int>& B) {
    unordered_map<int, int> freq;
    vector<int> result;
    for (int x : B) {
        freq[x]++;
    }
    for (int x : A) {
        if (freq[x] > 0) {
            result.push_back(x);
            freq[x]--;
        }
    }
    return result;
}
int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};
    vector<int> com = commonElements(A, B);
    for (int x : com) {
        cout << x << " ";
    }
    cout << endl;  
    return 0;
}
