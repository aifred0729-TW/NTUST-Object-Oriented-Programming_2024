#pragma once
#include "Document.h"

class File : public Document {
    private:
    std::string pathname = "";

    public:
    File(std::string doc, std::string path) : Document(doc) {    
        pathname = path;
    }

    void setPathname(std::string path);
    std::string getPathname();
};