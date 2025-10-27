#ifndef STOCK_H
#define STOCK_H
#include "investment.h"
#include <string>

class Stock : public Investment {
public:
    Stock(std::string symbol, int shares, double price);
    double market_value() const override;
    std::string description() const override;

private:
    std::string symbol_;
    int shares_{0};
    double price_{0.0};
};
#endif
