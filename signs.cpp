//
// Created by eternaldrowsy on 25.12.2021.
//

#include "header.hpp"

std::string signs(std::string &a) {
    std::stack<char> sign;
    std::string b;
    int truth = 1;
    for (auto i = a.begin(); i < a.end(); i++) {
        if (isdigit(*i) || *i == 'm' || *i == 'k' || *i == 't' || *i == 's' || *i == 'e' || *i == 'c' || *i == '.')
            b.push_back(*i);
        else if (*i == '+' || *i == '-' || *i == '*' || *i == '/') {
            b.push_back(' ');
            if (*i == '+' || *i == '-') {
                if (truth == 1) sign.push(*i);
                if (truth == 2) {
                    for (int j = 0; j < sign.size();) {
                        b += sign.top();
                        b += ' ';
                        sign.pop();
                    }
                    sign.push(*i);
                    truth = 1;
                }
            }
            if (*i == '*' || *i == '/') {
                sign.push(*i);
                truth = 2;
            }
        }

    }
    b.push_back(' ');
    for (int n = 0; n < sign.size();) {
        b += sign.top();
        b += ' ';
        sign.pop();
    }
    return b;
}
