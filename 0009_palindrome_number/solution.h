#pragma once

class Solution {
public:
    static constexpr int MAX_VAL = 0x7FFFFFFF; // 2^31 - 1

    int reverse(int x) {
        int result = 0;
        while(x) {
            if (x > 0) {
                if (MAX_VAL / 10 < result) {
                    return 0;
                }
            }
            result *= 10;
            result += x % 10;
            x = x / 10;
        }

        return result;        
    }

    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x > 0 && x > MAX_VAL) {
            x = MAX_VAL;
        }

        int reversed_x = reverse(x);

        return reversed_x == x;
    }
};
