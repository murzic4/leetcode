#pragma once

#include <string>
#include <vector>


class Solution {
public:
    bool isValid(const std::string& s) {
        auto size = s.size();
        std::vector<char> stack;
        stack.reserve(size);

        for (auto c : s) {
            switch (c) {
            case '(':
            case '{':
            case '[':
                stack.push_back(c);
                break;

            case ')':
                if (stack.size() && stack.back() == '(') {
                    stack.pop_back();
                } else {
                    return false;
                }
                break;
            case '}':
                if (stack.size() && stack.back() == '{') {
                    stack.pop_back();
                } else {
                    return false;
                }
                break;
            case ']':
                if (stack.size() && stack.back() == '[') {
                    stack.pop_back();
                } else {
                    return false;
                }
            }
        }

        return stack.size() == 0;
    }
}
;
