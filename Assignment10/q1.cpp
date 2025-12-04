//Given an integer array, check if it contains any duplicates using hash set.
#include <bits/stdc++.h>
using namespace std;
bool hasDuplicate(const vector<int>& nums) {
    unordered_set<int> seen;
    for (int x : nums) {
        if (seen.count(x)) {
            return true;
        }
        seen.insert(x);
    }
    return false;
}
int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << (hasDuplicate(nums) ? "true" : "false") << endl; 
    return 0;
}
