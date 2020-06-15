#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string validIPAddress(string IP)
    {
        vector<string> tokens4, tokens8;
        string acc = "";
        char cur, pp = ' ';
        for (int i = 0; i < IP.size(); i++) {
            cur = IP[i];
            if (cur == '.') {
                pp = '.';
                tokens4.push_back(acc);
                acc = "";
                continue;
            } else if (cur == ':') {
                pp = ':';
                tokens8.push_back(acc);
                acc = "";
                continue;
            }
            acc += cur;
        }
        if (pp == '.')
            tokens4.push_back(acc);
        else if (pp == ':')
            tokens8.push_back(acc);

        if (tokens4.size() == 4 && tokens8.size() == 0) {
            for (int i = 0; i < tokens4.size(); i++) {
                string& cur = tokens4[i];
                if (cur == "" || (cur.size() >= 2 && cur[0] == '0') || cur.size() > 3)
                    return "Neither";
                for (int j = 0; j < cur.size(); j++) {
                    if (!(cur[j] >= '0' && cur[j] <= '9'))
                        return "Neither";
                }
                int temp = stoi(cur);
                if (!(temp >= 0 && temp <= 255))
                    return "Neither";
            }
            return "IPv4";
        } else if (tokens8.size() == 8 && tokens4.size() == 0) {
            for (int i = 0; i < tokens8.size(); i++) {
                string cur = tokens8[i];
                if (cur == "" || cur.size() > 4)
                    return "Neither";
                for (int j = 0; j < cur.size(); j++) {
                    if (!((cur[j] >= '0' && cur[j] <= '9') || (cur[j] >= 'a' && cur[j] <= 'f') || (cur[j] >= 'A' && cur[j] <= 'F')))
                        return "Neither";
                }
            }
            return "IPv6";
        } else {
            return "Neither";
        }
    }
};
