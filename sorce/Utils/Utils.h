#pragma once
#include <list>
#include <vector>
#include <map>
#include "rapidcsv.h"

class Utills {

public:
    template < typename T > static void CsvToStruct(std::vector<T>& structVector, const char* filename);
    template < typename T > static void CsvToStruct(std::map<std::string, T>& structMap, const char* filename);
    template < typename T> static void CsvToStructVectorMap(std::map<std::string, std::vector<T>>& structVectorMap, const char* filename);
};

template<typename T>
inline void Utills::CsvToStruct(std::vector<T>& structVector, const char* filename)
{
    rapidcsv::Document csvData(filename);

    for (int i = 1; i < csvData.GetRowCount(); ++i) {
        std::vector<std::string> row = csvData.GetRow<std::string>(i);
        T myStruct(row);
        structVector.push_back(myStruct);
    }
}

template<typename T>
inline void Utills::CsvToStruct(std::map<std::string, T>& structMap, const char* filename)
{
    rapidcsv::Document csvData(filename);

    for (int i = 1; i < csvData.GetRowCount(); ++i) {
        std::vector<std::string> row = csvData.GetRow<std::string>(i);
        T myStruct(row);
        structMap.insert({ row[0], myStruct });
    }
}

template<typename T>
inline void Utills::CsvToStructVectorMap(std::map<std::string, std::vector<T>>& structVectorMap, const char* filename)
{
    rapidcsv::Document csvData(filename);

    for (int i = 1; i < csvData.GetRowCount(); ++i) {
        std::vector<std::string> row = csvData.GetRow<std::string>(i);
        T myStruct(row);
        structVectorMap[row[0]].push_back(myStruct);
    }
}
