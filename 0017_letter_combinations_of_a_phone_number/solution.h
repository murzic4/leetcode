#pragma once

#include <string>
#include <vector>
#include <array>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        std::array<std::string, 10> digit_to_string = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        for (auto digit : digits) {
            printf("digit = %c\n", digit);
            auto& prefixes = digit_to_string[digit - '0'];
            size_t prefixes_size = prefixes.size();

            if (result.size()) {
                std::vector<std::string> new_result;
                new_result.reserve(result.size() * prefixes_size);

                for (auto& prefix : result) {
                    new_result.insert(new_result.end(), prefixes_size, prefix);
                }

                result = new_result;

                for (int i = 0; i < result.size(); i++) {
                result[i] = result[i] + prefixes[i % prefixes_size];
            }

            } else {
                result.reserve(prefixes_size);
                for (auto c : prefixes) {
                    result.emplace_back(1, c);
                }
            }
        }

        return result;
    }
};