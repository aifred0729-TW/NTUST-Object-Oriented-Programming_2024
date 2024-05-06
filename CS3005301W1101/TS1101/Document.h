#pragma once
#include <string>

class Document {
    private:
    std::string text = "";

    public:
    Document(std::string t) {
        text = t;
    }

    std::string getText() const;
};