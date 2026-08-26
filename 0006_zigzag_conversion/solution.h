#pragma once

#include <string>

using namespace std;

class Solution {
public:
    string convert(const string& s, int numRows) {
        std::string strings[numRows];
        size_t len = s.size();

        if (numRows == 1) {
            return s;
        }

        for (auto str : strings) {
            str.reserve(len / (numRows > 2 ? numRows - 1 : numRows));
        }

        int list_index = 0;
        bool forward = true;

        for(auto ch : s) {
            strings[list_index] += ch;
            if (forward) {
                list_index++;
            } else {
                list_index--;
            }

            if (list_index == numRows - 1 || list_index == 0) {
                forward = !forward;
            }
        }

        std::string result;
        for (const auto& str : strings) {
            result += str;
        }

        return result;
    }
};