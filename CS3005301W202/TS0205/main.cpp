#include <iostream>
// SortIncludes
#include <regex>
#include <string>

bool        process();
std::string Add(std::string lhs, std::string rhs);

struct BigInt {
    std::string lhs;
    std::string rhs;
};

int main() {
    while (true) {
        if (process())
            continue;
        return 0;
    }
}

bool process() {
    using namespace std;

    int    round = 0;
    BigInt data;
    string result;
    regex  reg("^[0-9]*$");

    if (!(cin >> round) && cin.eof())
        return false;

    for (int i = 0; i < round; i++) {
        data.lhs = "";
        data.rhs = "";
        cin >> data.lhs;
        cin >> data.rhs;
        if (regex_match(data.lhs, reg)) {
            result = Add(data.lhs, data.rhs);
            cout << result << endl;
        } else {
            cout << "Not a valid number, please try again.\n";
        }
    }
    return true;
}

std::string Add(std::string lhs, std::string rhs) {
    using namespace std;

    int    tmp    = 0;
    int    index  = 0;
    string result = "";

    reverse(lhs.begin(), lhs.end());
    reverse(rhs.begin(), rhs.end());

    if (lhs.length() > rhs.length()) {
        rhs += string(lhs.length() - rhs.length(), '0');
    } else if (lhs.length() < rhs.length()) {
        lhs += string(rhs.length() - lhs.length(), '0');
    }

    while (true) {
        tmp = (lhs[index] - '0') + (rhs[index] - '0') + tmp;
        result += (tmp % 10) + '0';
        tmp /= 10;

        if (lhs[index + 1] == '\0' && rhs[index + 1] == '\0') {
            if (tmp == 0) {
                reverse(result.begin(), result.end());
                return result;
            }
            result += (tmp % 10) + '0';
            reverse(result.begin(), result.end());
            return result;
        }
        index++;
    }
}