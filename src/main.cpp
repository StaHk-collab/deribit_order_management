#include "order_manager.h"
#include "utils.h"
#include <iostream>

int main() {
    OrderManager orderManager;

    try {
        std::string token = UtilityNamespace::authenticate();
        std::cout << "Token: " << token << std::endl;

        // Place an order
        std::string response1 = orderManager.placeOrder("BTC-PERPETUAL", "buy", 1.0, 30000.0);
        std::cout << "Place Order Response: " << response1 << std::endl;

        // Cancel an order
        std::string orderId = "29119672418";
        std::string response2 = orderManager.cancelOrder(orderId);
        std::cout << "Cancel Order Response: " << response2 << std::endl;

        // Modify an order
        std::string response3 = orderManager.modifyOrder(orderId, 2.0, 32000.0);
        std::cout << "Modify Order Response: " << response3 << std::endl;

        // Get Order Book
        std::string response4 = orderManager.getOrderBook("BTC-PERPETUAL");
        std::cout << "Order Book Response: " << response4 << std::endl;

        // Get Current Positions
        std::string response5 = orderManager.getCurrentPositions();
        std::cout << "Current Positions Response: " << response5 << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "Press Enter to exit...";
    std::cin.get();
    return 0;
}

// WebSocket

// #include "order_manager.h"
// #include "websocket_server.h"
// #include <iostream>

// int main() {
//     OrderManager orderManager;

//     std::string response = orderManager.placeOrder("BTC-PERPETUAL", "buy", 1.0, 40000);
//     std::cout << "Order Response: " << response << std::endl;

//     // start WebSocket server for streaming orderbook
//     WebSocketServer wsServer;
//     wsServer.startServer(9002);

//     return 0;
// }