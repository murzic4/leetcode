#pragma once

#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        int result = 0;

        // формируем окно поиска
        const char* begin = s.c_str();
        const char* end = begin;
        // сет символов, которые мы встретили
        bool chars[128] = {false};

        // бежим пока конец окна не встретит конец строки
        while (*end) {
            if (chars[*end] == false) {
                // если текущий символ не повторяется:
                // - запоминаем его
                // - увеличиваем окно вправо
                chars[*end] = true;
                end++;
            } else {
                // если текущий символ уже встречался
                // - запоминаем максимальный размер окна, ктороый у нас когда-либо был
                result = std::max(result, (int)std::distance(begin, end));

                // - двигаем начало окна до первого повторяющегося символа
                while (*begin != *end) {
                    // забывая при этом все символы, которые оказываются слева от начала окна
                    chars[*begin] = false;
                    begin++;
                }

                // двигаем начало и конец окна на 1 элемент вправо от повторяющегося символа
                begin++;
                end++;
            }
        }

        // - запоминаем максимальный размер окна, ктороый у нас когда-либо был
        result = std::max(result, (int)std::distance(begin, end));

        // выводим результат
        return result;
    }
};