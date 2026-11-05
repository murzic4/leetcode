#pragma once

#include <string>
#include <set>
#include <array>

class Solution {
public:
    using RomanArabicPair = std::pair<char, int>;

    std::set<std::string> allowed_subtractive_forms = {"IV", "IX", "XL",
                                                       "XC", "CD", "CM"};

    std::array<RomanArabicPair, 7> hash = {{{'M', 1000},
                                            {'D', 500},
                                            {'C', 100},
                                            {'L', 50},
                                            {'X', 10},
                                            {'V', 5},
                                            {'I', 1}}};

    std::string intToRoman(int num) {
        std::string result = "";
        auto symbol_iterator = hash.begin();
        while (num) {
            const auto& [latin, arabic] = *symbol_iterator;

            if (num >= arabic) {
                result += latin;
                num -= arabic;
            } else {
                if (symbol_iterator + 1 != hash.end()) {
                    const auto& [_, next_arabic] = *(symbol_iterator + 1);
                    if (num <= next_arabic) {
                        symbol_iterator++;
                        continue;
                    }
                }
                for (auto reverse_iterator = hash.end() - 1;
                     symbol_iterator != reverse_iterator; reverse_iterator--) {
                    const auto& [next_latin, next_arabic] = *reverse_iterator;
                    if (num >= arabic - next_arabic) {
                        std::string subtractive_form;
                        subtractive_form += next_latin;
                        subtractive_form += latin;

                        if (allowed_subtractive_forms.count(subtractive_form)) {
                            result += subtractive_form;
                            num -= (arabic - next_arabic);
                            break;
                        }
                    }
                }
                symbol_iterator++;
            }
        }
        return result;
    }
};