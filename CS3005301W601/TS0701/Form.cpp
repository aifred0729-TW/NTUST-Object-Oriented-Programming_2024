#include "Form.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool compareWord(string tmpWord, string loadWord);

void Form::SetInputWord(std::string inputWord) {
    preProcessStr = inputWord;
    return;
}

void Form::ProcessInputWord() {
    for (unsigned int i = 0; i < preProcessStr.size(); i++) {
        word += tolower(preProcessStr[i]);
    }
    return;
}

void Form::SetFileName(string fileName) {
    file = fileName;
    return;
}

void Form::Load_CompareWord() {
    fstream fp(file);
    string  tmp = "";
    while (fp >> tmp) {
        loadWords.push_back(tmp);
    }
    return;
}

void Form::PrintFoundWords() {
    string tmpLoadWord = "";

    for (unsigned int i = 0; i < loadWords.size(); i++) {
        if (compareWord(word, loadWords[i]))
            cout << loadWords[i] << endl;
    }
}

bool compareWord(string word, string loadWord) {
    for (unsigned int i = 0; i < word.size(); i++) {
        for (unsigned int j = 0; j < loadWord.size(); j++) {
            if (word[i] == loadWord[j]) {
                loadWord.erase(j, 1);
                break;
            }
        }
        if (loadWord.size() == 0)
            return true;
    }
    return false;
}