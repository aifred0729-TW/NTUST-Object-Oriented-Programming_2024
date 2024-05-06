#pragma once
#include "Document.h"

class Email: public Document {
    private:
    std::string title  = "";
    std::string sender = "";
    std::string recver = "";

    public:
    Email(std::string doc, std::string s, std::string r, std::string t): Document(doc) {
        title  = t;
        sender = s;
        recver = r;
    }

    std::string getSender();
    std::string getRecipient();
    std::string getTitle();
};