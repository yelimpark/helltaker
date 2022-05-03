#pragma once
#include <list>
#include "rapidcsv.h"

class Utills {

public:
	template < typename T > static void CsvToStruct(std::list<T>& structList, const char* filename);
};

template<typename T>
inline void Utills::CsvToStruct(std::list<T>& structList, const char* filename)
{
    rapidcsv::Document csvData(filename, rapidcsv::LabelParams(0, -2));

    for (int i = 1; i < csvData.GetRowCount(); ++i) {
        std::vector<std::string> row = csvData.GetRow<std::string>(i);
        structList.push_back(T(row));
    }
}
