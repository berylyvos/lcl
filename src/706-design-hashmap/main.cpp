#include <cstdio>
#include <list>
#include "headers/vector.h"

using namespace std;

class MyHashMap {
private:
    static const int N = 10007; // 最多调用10000次，N取大于10000的第一个质数
    vector<list<pair<int, int>>> map;
    
    static int hash(int key) {
        return (key % N + N) % N; // 考虑负数
    }

    list<pair<int, int>>::iterator find(int key) {
        int t = hash(key);
        auto it = map[t].begin();
        for (; it != map[t].end(); ++it)
            if (it->first == key) break;
        return it;
    }

public:
    MyHashMap() {
        map.resize(N);
    }
    
    void put(int key, int value) {
        int t = hash(key);
        auto it = find(key);
        if (it != map[t].end()) it->second = value;
        else map[t].push_back(make_pair(key, value));
    }
    
    int get(int key) {
        int t = hash(key);
        auto it = find(key);
        if (it != map[t].end()) return it->second;
        else return -1;
    }
    
    void remove(int key) {
        int t = hash(key);
        auto it = find(key);
        if (it != map[t].end()) map[t].erase(it);
    }
};

static void test()
{
    // 求大于 10000 的第一个质数
    for (int i = 10000; ; ++ i) {
        bool flag = true;
        for (int j = 2; j * j < i; ++ j)
        {
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag) 
        {
            printf("%d\n", i);
            break;
        }
    }
}

int main() {
    
    MyHashMap myHashMap = MyHashMap();
    vector<int> res;
    int x;

    myHashMap.put(1, 1);     // myHashMap 现在为 [[1,1]]
    myHashMap.put(2, 2);     // myHashMap 现在为 [[1,1], [2,2]]
    
    x = myHashMap.get(1);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,2]]
    res.push_back(x);
    
    x = myHashMap.get(3);    // 返回 -1（未找到），myHashMap 现在为 [[1,1], [2,2]]
    res.push_back(x);
    myHashMap.put(2, 1);     // myHashMap 现在为 [[1,1], [2,1]]（更新已有的值）
    
    x = myHashMap.get(2);    // 返回 1 ，myHashMap 现在为 [[1,1], [2,1]]
    res.push_back(x);
    
    myHashMap.remove(2);     // 删除键为 2 的数据，myHashMap 现在为 [[1,1]]
    x = myHashMap.get(2);    // 返回 -1（未找到），myHashMap 现在为 [[1,1]]
    res.push_back(x);

    print_vec(res);

    // test();

    return 0;
}