#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> vec = {4,1,3,0};

    std::sort(vec.begin(), vec.begin()+3);

    for(int element : vec) {
        std::cout << element << std::endl;
    }
}