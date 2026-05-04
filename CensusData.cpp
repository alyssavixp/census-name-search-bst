#include "CensusData.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<CensusRecord> loadCensusRecords(const std::string& filename) {
    std::vector<CensusRecord> records;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return records;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name;
        std::string rankText;
        std::string countText;

        std::getline(ss, name, ',');
        std::getline(ss, rankText, ',');
        std::getline(ss, countText, ',');

        if (!name.empty() && !rankText.empty() && !countText.empty()) {
            CensusRecord record;
            record.name = name;
            record.rank = std::stoi(rankText);
            record.count = std::stoi(countText);
            records.push_back(record);
        }
    }

    return records;
}