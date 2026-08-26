#pragma once

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        constexpr int MIN_VAL = -0x80000000; // -2^31
        constexpr int MAX_VAL = 0x7FFFFFFF; // 2^31 - 1

        while(x) {
            if (x > 0) {
                if (MAX_VAL / 10 < result) {
                    return 0;
                }
            } else {
                if (MIN_VAL / 10 > result) {
                    return 0;
                }
            }
            result *= 10;
            result += x % 10;
            x = x / 10;
        }

        return result;
        
    }
};