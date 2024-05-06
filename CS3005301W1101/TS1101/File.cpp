#include "File.h"

void File::setPathname(std::string path) {
    pathname = path;
    return;
}

std::string File::getPathname() {
    return pathname;
}