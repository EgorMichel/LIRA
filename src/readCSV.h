//
// Created by artem on 27.04.24.
//

#ifndef LIRA_READCSV_H
#define LIRA_READCSV_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<int> readCSV(const std::string& filename) {
    std::vector<int> matrix;

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return matrix;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ','))
        {
            matrix.push_back(std::stoi(cell));
        }

    }

    file.close();
    return matrix;
}

#endif //LIRA_READCSV_H
