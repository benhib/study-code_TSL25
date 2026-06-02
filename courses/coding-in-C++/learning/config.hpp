#include <stdexcept>
#include <string>

class EmptyPathException : public std::invalid_argument {
    public:
        EmptyPathException() : invalid_argument("Empty Filepath") {};
};

class OpenFileException : public std::runtime_error {
    public:
        OpenFileException() : runtime_error("Can't Open File") {};
};

class InvalidConfigException : public std::invalid_argument {
    public:
        InvalidConfigException() : invalid_argument("Invalid Config File") {};
};

class InvalidFileTypeException : public std::invalid_argument {
    public:
        InvalidFileTypeException() : invalid_argument("Invalid File Type") {};
};

class ConfigLoader {
    
    public:
        std::string load(std::string& filename) const;
};