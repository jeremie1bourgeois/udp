/*
** EPITECH PROJECT, 2020
** udpserver [WSL: Ubuntu]
** File description:
** UdpClient
*/

#ifndef UDPCLIENT_HPP_
#define UDPCLIENT_HPP_

#include "Package.hpp"

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/binary_object.hpp>
#include <boost/serialization/serialization.hpp>

using namespace std;
using namespace boost::asio;

using boost::asio::ip::udp;

namespace client {

    class UdpClient {
        public:
            UdpClient(string ip, string port);
            ~UdpClient();

            void send();
            void receive();

        protected:
            io_context    _ioContext;
            udp::resolver _resolver;
            udp::socket   _socket;
            udp::endpoint _receiverEndpoint;
    };

}

#endif /* !UDPCLIENT_HPP_ */
