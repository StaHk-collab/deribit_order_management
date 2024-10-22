#include "websocket_server.h"
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

typedef websocketpp::server<websocketpp::config::asio> server;

void on_message(server* s, websocketpp::connection_hdl hdl, server::message_ptr msg) {
    std::string symbol = msg->get_payload();
    // fetch orderbook updates from Deribit API and send updates to client
    s->send(hdl, "Orderbook update for " + symbol, websocketpp::frame::opcode::text);
}

void WebSocketServer::startServer(int port) {
    server ws_server;

    ws_server.init_asio();
    ws_server.set_message_handler(std::bind(&on_message, &ws_server, std::placeholders::_1, std::placeholders::_2));

    ws_server.listen(port);
    ws_server.start_accept();
    ws_server.run();
}