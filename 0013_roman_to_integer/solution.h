#pragma once

#include <string>

class Solution {

public:
    constexpr int romanToInt(const std::string& s) {
        int result = 0;
        int prev = 0;
        size_t size = s.size();

        int values[16] = {0};
        bool minus[16] = {false};

        for (int idx = 0; idx < size; idx++) {
            int current = 0;
            switch (s[idx]) {
            case 'I':
                current = 1;
                break;
            case 'V':
                current = 5;
                break;
            case 'X':
                current = 10;
                break;
            case 'L':
                current = 50;
                break;
            case 'C':
                current = 100;
                break;
            case 'D':
                current = 500;
                break;
            case 'M':
                current = 1000;
                break;
            }

            values[idx] = current;

            if (prev && prev < current) {
                minus[idx - 1] = true;
            }

            prev = current;
        }

        for (int idx = 0; idx < size; idx++) {
            result += minus[idx] ? -values[idx] : values[idx];
        }

        return result;
    }
};
