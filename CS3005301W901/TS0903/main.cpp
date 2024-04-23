#include <iostream>
#include <map>
#include <vector>

void runProcess(int tCount, int wCount);
bool checkIsPair(std::string a, std::string b, std::map<char, std::vector<char>> dict);
bool runDeepCheck(char a, char b, std::map<char, std::vector<char>> dict, std::vector<char> searchNode);

int main() {
    using namespace std;

    int translateCount = 0;
    int wordPairsCount = 0;

    while (cin >> translateCount) {
        cin >> wordPairsCount;
        if (translateCount == 0)
            break;
        runProcess(translateCount, wordPairsCount);
    }

    return 0;
}

void runProcess(int tCount, int wCount) {
    using namespace std;

    map<char, vector<char>> dict;

    char tmpKey;
    char tmpValue;

    for (unsigned int i = 0; i < tCount; i++) {
        cin >> tmpKey;
        cin >> tmpValue;
        if (dict.find(tmpKey) == dict.end()) {
            dict[tmpKey].push_back(tmpValue);
        } else {
            dict[tmpKey].push_back(tmpValue);
        }
    }

    string a = "";
    string b = "";

    for (unsigned int i = 0; i < wCount; i++) {
        cin >> a;
        cin >> b;
        if (!checkIsPair(a, b, dict)) {
            cout << "no" << endl;
            continue;
        }
        cout << "yes" << endl;
    }

    return;
}

bool checkIsPair(std::string a, std::string b, std::map<char, std::vector<char>> dict) {
    if (a.size() != b.size())
        return false;
    if (a == b)
        return true;

    int runCount = a.size();

    std::vector<char> searchNode;

    for (unsigned int i = 0; i < runCount; i++) {
        if (!runDeepCheck(a[0], b[0], dict, searchNode))
            return false;
        a.erase(a.begin());
        b.erase(b.begin());
    }
    return true;
}

bool runDeepCheck(char a, char b, std::map<char, std::vector<char>> dict, std::vector<char> searchNode) {
    using namespace std;
    if (a == b)
        return true;
    if (dict.find(a) == dict.end())
        return false;
    if (find(searchNode.begin(), searchNode.end(), a) != searchNode.end())
        return false;

    searchNode.push_back(a);
    bool isPair = false;

    for (char c: dict[a]) {
        isPair = runDeepCheck(c, b, dict, searchNode);
        if (isPair)
            return true;
    }

    return false;
}