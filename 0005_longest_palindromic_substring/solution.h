#pragma once

#include <string>
#include <tuple>

using namespace std;

class Solution {
public:
    std::tuple<std::ptrdiff_t, const char*>
          getPalyndrome(const char* str, int left, int right) {

        const char* result_p = nullptr;
        std::ptrdiff_t result_len = 0;

        while (left >= 0 && *(str + right) && str[left] == str[right]) {
            left--;
            right++;
        }

        result_p = str + left + 1;
        result_len = right - (left + 1);
        return {result_len, result_p};
    }

    string longestPalindrome(const string& s) {
        const char* str = s.c_str();
        std::tuple<std::ptrdiff_t, const char*> max_result{};

        for (size_t idx = 0; str[idx]; idx++) {
            auto result1 = getPalyndrome(str, idx, idx);
            auto result2 = getPalyndrome(str, idx, idx + 1);

            if (std::get<0>(max_result) < std::get<0>(result1)) {
                max_result = result1;
            }

            if (std::get<0>(max_result) < std::get<0>(result2)) {
                max_result = result2;
            }
        }

        return std::string(std::get<1>(max_result), std::get<0>(max_result));
    }
};