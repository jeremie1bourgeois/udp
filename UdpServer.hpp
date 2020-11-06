/*
** EPITECH PROJECT, 2020
** udpserver
** File description:
** UdpServer
*/

#ifndef UDPSERVERHPP
#define UDPSERVERHPP

#include "Package.hpp"

#include <iostream>
#include <string>
#include <ctime>
#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/binary_object.hpp>
#include <boost/serialization/serialization.hpp>

using boost::asio::io_context;
using boost::asio::ip::udp;

namespace server {

    class UdpServer {
        public:
            UdpServer(int port);
            ~UdpServer();

        private:
            void start_receive();
            void handle_receive(const boost::system::error_code& error, std::size_t);
            void handle_send();
            void makePackage(int i, std::string str);


        protected:
            io_context _io_context;
            udp::socket _socket;
            udp::endpoint _remoteEndpoint;
            boost::array<char, 1> _recvBuffer;
            PackageUdp _toSend;
    };

}

#endif /* !UDPSERVERHPP */