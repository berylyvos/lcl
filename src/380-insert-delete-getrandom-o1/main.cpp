#include <vector>
#include <unordered_map>
using namespace std;
// https://leetcode.cn/problems/insert-delete-getrandom-o1/

class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if (idx.find(val) != idx.end()) {
            return false;
        }
        arr.push_back(val);
        idx[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (idx.find(val) == idx.end()) {
            return false;
        }
        int i = idx[val];
        idx[arr.back()] = i;
        swap(arr[i], arr[arr.size() - 1]);
        arr.pop_back();
        idx.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }

private:
    unordered_map<int, int> idx;
    vector<int> arr;
};