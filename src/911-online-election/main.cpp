#include <vector>
using namespace std;
// https://leetcode.cn/problems/online-election/

class TopVotedCandidate {
public:
    vector<int> topVoteId;
    vector<int> time;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n = persons.size();
        topVoteId.resize(n);
        time = times;

        vector<int> voteCnt(n);
        int maxc = 0, maxp;
        for (int i = 0; i < n; ++i) {
            int p = persons[i];
            if (++voteCnt[p] >= maxc) {
                maxc = voteCnt[p];
                maxp = p;
            }
            topVoteId[i] = maxp;
        }
    }
    
    int q(int t) {
        int k = upper_bound(time.begin(), time.end(), t) - time.begin() - 1;
        return topVoteId[k];
    }
};