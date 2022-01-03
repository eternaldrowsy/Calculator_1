//
// Created by eternaldrowsy on 25.12.2021.
//


#include "header.hpp"

std::string expressions(std::string &str) {

    std::map<char, std::function<double(const double &, const double &)>> operations;
    operations['+'] = [](const double &a, const double &b) { return a + b; };
    operations['-'] = [](const double &a, const double &b) { return a - b; };
    operations['*'] = [](const double &a, const double &b) { return a * b; };
    operations['/'] = [](const double &a, const double &b) { return a / b; };

    std::map<char, std::function<double(const double &)>> harder;
    harder['c'] = [](const double &a) { return cos(a); };
    harder['s'] = [](const double &a) { return sin(a); };
    harder['t'] = [](const double &a) { return round(tan(a)*pow(10,12))/pow(10,12); };
    harder['k'] = [](const double &a) { return round(cos(a)/sin(a)*pow(10,12))/pow(10,12); };
    harder['e'] = [](const double &a) { return exp(a); };

    std::string expression = str, n;
    std::stack<double> stack;
    double number;
    bool truth = true;
    char art = 'a';
    char *end;

    for (auto i = expression.begin(); i < expression.end(); i++) {
        if (isdigit(*i) || *i == '.' || *i == 'm') {
            if (*i == 'm') n += '-';
            else n += *i;
            truth = true;
        } else {
            if (*i != ' ') {
                if (*i == 'c' || *i == 's' || *i == 't' || *i == 'k' || *i == 'e') {
                    art = *i;
                    continue;
                }
                double num2 = stack.top();
                stack.pop();
                double num1 = stack.top();
                stack.pop();
                stack.push(operations[*i](num1, num2));
                truth = false;
            } else if (*i == ' ' && truth) {
                number = strtod(n.c_str(), &end);
                if (art != 'a') {
                    number = harder[art](number);
                    art = 'a';
                }
                if (number == 0)
                    number = 0;
                stack.push(number);
                n.clear();
            }
        }
    }

    std::ostringstream stream;
    stream << std::setprecision(15) << stack.top();
    str = stream.str();

    return str;
}
