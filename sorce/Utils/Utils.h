#pragma once
#include <list>
#include <vector>
#include <map>
#include "rapidcsv.h"
#include <SFML/Graphics.hpp>

using namespace sf;

enum class Pivots {
	LeftTop,
	CenterTop,
	RightTop,
	LeftMiddle,
	Center,
	RightMiddle,
	LeftBottom,
	CenterBottom,
	RightBottom
};

class Utils {
public:
	static void SetOrigin(Sprite& sprite, Pivots preset);
	static void SetOrigin(Shape& shape, Pivots preset);
	static void SetOrigin(Text& text, Pivots preset);
	static void SetOrigin(Transformable& tr, FloatRect bounds, Pivots preset);

    template < typename T > static void CsvToStruct(std::vector<T>& structVector, const char* filename);
    template < typename T > static void CsvToStruct(std::map<std::string, T>& structMap, const char* filename);
    template < typename T> static void CsvToStructVectorMap(std::map<std::string, std::vector<T>>& structVectorMap, const char* filename);
};

template<typename T>
inline void Utils::CsvToStruct(std::vector<T>& structVector, const char* filename)
{
    rapidcsv::Document csvData(filename);

    for (int i = 1; i < csvData.GetRowCount(); ++i) {
        std::vector<std::string> row = csvData.GetRow<std::string>(i);
        T myStruct(row);
        structVector.push_back(myStruct);
    }
}

template<typename T>
inline void Utils::CsvToStruct(std::map<std::string, T>& structMap, const char* filename)
{
    rapidcsv::Document csvData(filename);

    for (int i = 1; i < csvData.GetRowCount(); ++i) {
        std::vector<std::string> row = csvData.GetRow<std::string>(i);
        T myStruct(row);
        structMap.insert({ row[0], myStruct });
    }
}

template<typename T>
inline void Utils::CsvToStructVectorMap(std::map<std::string, std::vector<T>>& structVectorMap, const char* filename)
{
    rapidcsv::Document csvData(filename);

    for (int i = 1; i < csvData.GetRowCount(); ++i) {
        std::vector<std::string> row = csvData.GetRow<std::string>(i);
        T myStruct(row);
        structVectorMap[row[0]].push_back(myStruct);
    }
}
