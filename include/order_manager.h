#pragma once

#include <string>
#include <vector>

class OrderManager {
public:
    std::string placeOrder(const std::string& symbol, const std::string& type, double amount, double price);
    std::string cancelOrder(const std::string& order_id);
    std::string modifyOrder(const std::string& order_id, double new_amount, double new_price);
    std::string getOrderBook(const std::string& symbol);
    std::string getCurrentPositions();
};