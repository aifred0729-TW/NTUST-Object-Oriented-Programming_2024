#include <iostream>
#include <string>

class NumberSet {
    private:
    int         number1  = 0;
    int         number2  = 0;
    int         answer   = 0;
    std::string number1S = "";
    std::string number2S = "";
    std::string answerS  = "";

    public:
    ~NumberSet() {
        number1  = 0;
        number2  = 0;
        answer   = 0;
        number1S = "";
        number2S = "";
        answerS  = "";
    }

    NumberSet(std::string n1S, std::string n2S, std::string ans) {
        number1S = n1S;
        number2S = n2S;
        answerS  = ans;
        number1  = resolveFourBaseByString(number1S);
        number2  = resolveFourBaseByString(number2S);
        answer   = resolveFourBaseByString(answerS);
    }

    int  resolveFourBaseByString(std::string inputString);
    void runOperation(char opcode);
    void checkYesOrNo();
};