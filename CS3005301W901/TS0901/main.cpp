#include <iostream>
#include <string>
#include <vector>

bool runProcess();
void getStrings(std::vector<std::string>& loadStrs);
void findComparedStr(std::vector<std::string> loadStrs, std::vector<std::string>& comparedStrs);

int main() {
    using namespace std;

    while (true) {
        if (runProcess())
            continue;
        return 0;
    }
}

bool runProcess() {
    using namespace std;

    vector<string> loadStrs;
    vector<string> comparedStrs;

    getStrings(loadStrs);
    findComparedStr(loadStrs, comparedStrs);

    vector<unsigned int> maxLenIndexs;
    int                  maxLen = 0;

    for (unsigned int i = 0; i < comparedStrs.size(); i++) {
        if (maxLen < comparedStrs[i].size()) {
            maxLenIndexs.clear();
            maxLenIndexs.push_back(i);
            maxLen = comparedStrs[i].size();
        }
    }

    for (unsigned int index: maxLenIndexs) {
        cout << comparedStrs[index] << endl;
    }

    return false;
}

void getStrings(std::vector<std::string>& loadStrs) {
    using namespace std;

    string tmpStr = "";

    while (cin >> tmpStr) {
        loadStrs.push_back(tmpStr);
    }

    return;
}

void findComparedStr(std::vector<std::string> loadStrs, std::vector<std::string>& comparedStrs) {
    using namespace std;

    string s = "";

    while (loadStrs.size() > 1) {
        s = loadStrs[0];
        reverse(s.begin(), s.end());
        for (string cStr: loadStrs) {
            if (s == cStr) {
                comparedStrs.push_back(loadStrs[0]);
            }
        }
        loadStrs.erase(loadStrs.begin());
    }

    return;
}