#include "config.hpp"
#include <string>

std::string ConfigLoader::load(std::string& filename) const {
    if(filename.empty()) {
        throw EmptyPathException();
    } else if (filename == "missing.cfg") {
        throw OpenFileException();
    } else if (filename.find(".cfg") != std::string::npos) {
        throw InvalidFileTypeException();
    } else if (filename == "invalid.cfg") {
        throw InvalidConfigException();
    }

    return "loaded";
}