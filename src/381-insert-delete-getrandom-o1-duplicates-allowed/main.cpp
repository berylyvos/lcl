#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/

class RandomizedCollection {
public:
    RandomizedCollection() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int x) {
        bool res = idx[x].empty();
        arr.push_back(x);
        idx[x].insert(arr.size() - 1);
        return res;
    }
    
    bool remove(int x) {
        if (idx[x].empty()) {
            return false;
        }
        int i = *idx[x].begin(), j = arr.size() - 1; 
        int t = arr.back();
        swap(arr[i], arr[j]);
        // note! corner case: x == t && i != j

        idx[x].erase(i); idx[x].insert(j);
        idx[t].erase(j); idx[t].insert(i);
        
        arr.pop_back();
        idx[x].erase(j);
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }

private:
    unordered_map<int, unordered_set<int>> idx;
    vector<int> arr;
};