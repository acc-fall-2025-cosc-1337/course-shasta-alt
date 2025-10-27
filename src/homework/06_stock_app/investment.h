#ifndef INVESTMENT_H
#define INVESTMENT_H
#include <string>

class Investment {
public:
    virtual ~Investment() = default;
    virtual double market_value() const = 0;
    virtual std::string description() const = 0;
};
#endif
