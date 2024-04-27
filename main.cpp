#include <cmath>

#include "src/readCSV.h"

const std::string FILE_PATH = __FILE__;
const int amountOfSymbolsBeforeRootDirectory = 8;
const std::string DIR_PATH = FILE_PATH.substr(0, FILE_PATH.size() - amountOfSymbolsBeforeRootDirectory);

int main() {
    std::string filename = DIR_PATH + "resources/test.csv";

    std::vector<int> matrix = readCSV(filename);

    const int N = std::sqrt(matrix.size());

    for (int i = 0; i < matrix.size(); ++i)
    {
        std::cout << matrix[i] << " ";
        if (i != 0 and i % N == N - 1)
            std::cout << std::endl;
    }

    return 0;
}