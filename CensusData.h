#ifndef CENSUS_DATA_H
#define CENSUS_DATA_H

#include "CensusRecord.h"
#include <string>
#include <vector>

std::vector<CensusRecord> loadCensusRecords(const std::string& filename);

#endif