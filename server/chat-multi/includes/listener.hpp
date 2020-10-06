//
// Created by vuongdq85 on 06/10/2020.
//

#ifndef WEBSOCKET_CHAT_MULTI_INCLUDES_LISTENER_HPP
#define WEBSOCKET_CHAT_MULTI_INCLUDES_LISTENER_HPP

#include "beast.hpp"
#include "net.hpp"
#include <string>
#include <memory>
#include <boost/smart_ptr.hpp>


// Forward declaration
class shared_state;

// Accepts incoming connections and launches the sessions
class listener : public boost::enable_shared_from_this<listener> {
    net::io_context &ioc_;
    tcp::acceptor acceptor_;
    boost::shared_ptr<shared_state> state_;

    static void fail(beast::error_code ec, char const *what);

    void on_accept(beast::error_code ec, tcp::socket socket);

public:
    listener(
            net::io_context &ioc,
            const tcp::endpoint& endpoint,
            boost::shared_ptr<shared_state> state);

    // Start accepting incoming connections
    void run();
};


#endif //WEBSOCKET_CHAT_MULTI_INCLUDES_LISTENER_HPP
