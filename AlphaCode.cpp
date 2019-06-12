#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>

/**
 * Checks whether the character 'a' could represent a letter (1 to 9).
 */
bool isletter(char a) {
    return '1' <= a && a <= '9';
}

/**
 * Checks whether the string "ab" could represent a letter (10 to 26).
 */
bool isletter(char a, char b) {
    return (a == '1' && ('0' <= b && b <= '9')) ||
           (a == '2' && ('0' <= b && b <= '6'));
}

/**
 * Counts the number of ways the message could be decoded.
 */
std::int64_t decodings(const std::string& msg) {
    std::string::size_type len = msg.length();
    if (len == 0) return 1;

    std::int64_t prev_count = 1,
                 curr_count = isletter(msg[0]);
    for (int i = 1; i < len; ++i) {
        // Try decoding the last two characters as a letter, and
        // try decoding the final character as a letter.
        std::int64_t new_count = prev_count * isletter(msg[i - 1], msg[i]) +
                                 curr_count * isletter(msg[i]);
        prev_count = curr_count;
        curr_count = new_count;
    }

    return curr_count;
}

int main() {
    assert(decodings("25114") == 6);
    assert(decodings("1111111111") == 89);
    assert(decodings("3333333333") == 1);

    std::string msg;
    while ((std::cin >> msg) && (msg != "0")) {
        std::cout << decodings(msg) << '\n';
    }
}