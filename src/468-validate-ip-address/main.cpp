#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> split(const string& s, char t) {
        vector<string> res;
        string item;
        for (int i = 0; i < (int)s.size(); ++ i) {
            if (s[i] != t) item += s[i];
            else {
                res.push_back(item);
                item.clear();
            }
        }
        return res;
    }

    bool check_ipv4(string ip) {
        auto items = split(ip + '.', '.');
        if (items.size() != 4) return false;
        for (auto item: items) {
            if (item.empty() || item.size() > 3) return false;
            if (item.size() > 1 && item[0] == '0') return false;
            int x = 0;
            for (auto c: item) {
                if (c < '0' || c > '9') return false;
                x = x * 10 + (c - '0');
            }
            if (x > 255) return false;
        }
        return true;
    }

    bool check(char c) {
        if (c >= '0' && c <= '9') return true;
        if (c >= 'a' && c <= 'f') return true;
        if (c >= 'A' && c <= 'F') return true;
        return false;
    }

    bool check_ipv6(string ip) {
        auto items = split(ip + ':', ':');
        if (items.size() != 8) return false;
        for (auto item: items) {
            if (item.empty() || item.size() > 4) return false;
            for (auto c: item) if (!check(c)) return false;
        }
        return true;
    }

    string validIPAddress(string queryIP) {
        int a = queryIP.find('.'), b = queryIP.find(':');
        if (a != -1 && b != -1) return "Neither";
        if (a != -1) return check_ipv4(queryIP) ? "IPv4" : "Neither";
        if (b != -1) return check_ipv6(queryIP) ? "IPv6" : "Neither";
        return "Neither";
    }
};

int main() {
    string ip4 = "172.0.254.1";
    printf("%s\n", Solution().validIPAddress(ip4).c_str());
    string ip6 = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    printf("%s\n", Solution().validIPAddress(ip6).c_str());

    return 0;
}