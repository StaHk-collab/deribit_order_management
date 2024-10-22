#include "order_manager.h"
#include "utils.h"
#include <nlohmann/json.hpp>

// function to place an order using the access token
std::string OrderManager::placeOrder(const std::string& symbol, const std::string& type, double amount, double price) {
    std::string access_token = UtilityNamespace::authenticate();
    std::string url = "https://test.deribit.com/api/v2/private/place_order";
    
    std::string payload = "{\"jsonrpc\":\"2.0\", \"method\":\"private/place_order\", \"params\":{\"instrument_name\":\"" + symbol + "\", \"amount\":" + std::to_string(amount) + ", \"price\":" + std::to_string(price) + ", \"type\":\"limit\", \"side\":\"" + type + "\"}, \"id\":2}";
    
    // authorization header with the access token
    std::string authHeader = "Authorization: Bearer " + access_token;

    // POST request with authorization header
    return UtilityNamespace::sendPostRequestWithAuth(url, payload, authHeader);
}

// function to cancel an order
std::string OrderManager::cancelOrder(const std::string& order_id) {
    std::string access_token = UtilityNamespace::authenticate();
    std::string url = "https://test.deribit.com/api/v2/private/cancel";
    std::string payload = "{\"jsonrpc\":\"2.0\", \"method\":\"private/cancel\", \"params\":{\"order_id\":\"" + order_id + "\"}, \"id\":2, \"token\":\"" + access_token + "\"}";
    return UtilityNamespace::sendPostRequest(url, payload);
}

// function to modify an order
std::string OrderManager::modifyOrder(const std::string& order_id, double new_amount, double new_price) {
    std::string access_token = UtilityNamespace::authenticate();
    std::string url = "https://test.deribit.com/api/v2/private/edit";
    std::string payload = "{\"jsonrpc\":\"2.0\", \"method\":\"private/edit\", \"params\":{\"order_id\":\"" + order_id + "\", \"amount\":" + std::to_string(new_amount) + ", \"price\":" + std::to_string(new_price) + "}, \"id\":3, \"token\":\"" + access_token + "\"}";
    return UtilityNamespace::sendPostRequest(url, payload);
}

// function to get order book
std::string OrderManager::getOrderBook(const std::string& symbol) {
    std::string url = "https://test.deribit.com/api/v2/public/get_order_book";
    std::string payload = "{\"jsonrpc\":\"2.0\", \"method\":\"public/get_order_book\", \"params\":{\"instrument_name\":\"" + symbol + "\"}, \"id\":4}";
    return UtilityNamespace::sendPostRequest(url, payload);
}

// function to get current positions
std::string OrderManager::getCurrentPositions() {
    std::string access_token = UtilityNamespace::authenticate();
    std::string url = "https://test.deribit.com/api/v2/private/get_positions";
    std::string payload = "{\"jsonrpc\":\"2.0\", \"method\":\"private/get_positions\", \"params\":{\"currency\":\"BTC\", \"kind\":\"future\"}, \"id\":5, \"token\":\"" + access_token + "\"}";
    return UtilityNamespace::sendPostRequest(url, payload);
}