#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(const string& str) {
        constexpr int MIN_VAL = -0x80000000; // -2^31
        constexpr int MAX_VAL = 0x7FFFFFFF; // 2^31 - 1

        const char* s = str.c_str();
        int result = 0;
        bool positive = true;


        while(*s == ' ') {
            s++;
        }

        if (*s == '-') {
            positive = false;
            s++;
        } else if (*s == '+') {
            s++;
        }

        while(std::isdigit(*s)) {
            int val = *s - '0';
            if (positive && ((double)(MAX_VAL - val)/10) <= result) {
                goto rounding;
            } else if (!positive && ((double)(MIN_VAL + val))/10 >= -result) {
                goto rounding;
            }

            result *= 10;
            result += val;
            s++;
        }

        return positive ? result : -result;
rounding:
        return positive ? MAX_VAL : MIN_VAL;
    }
};