//Count the frequency of each number in an array using a hash map
#include <bits/stdc++.h>
using namespace std;
void printFrequencies(const vector<int>& nums) {
    unordered_map<int, int> freq;
    for (int x : nums) {
        freq[x]++;
    }
    for (auto &p : freq) {
        cout << p.first << " → " << p.second << " times" << endl;
    }
}
int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2};
    printFrequencies(nums);
    return 0;
}
