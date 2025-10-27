#include "stock.h"
#include <sstream>

Stock::Stock(std::string symbol, int shares, double price)
    : symbol_(std::move(symbol)), shares_(shares), price_(price) {}

double Stock::market_value() const {
    return shares_ * price_;
}

std::string Stock::description() const {
    std::ostringstream os;
    os << "Stock " << symbol_ << " x" << shares_ << " @ " << price_;
    return os.str();
}
