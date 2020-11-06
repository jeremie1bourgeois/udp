/*
** EPITECH PROJECT, 2020
** udpserver
** File description:
** UdpServer
*/

#include "UdpServer.hpp"
#include <vector>

using namespace server;
using namespace std;


UdpServer::UdpServer(int port): _socket(_io_context, udp::endpoint(udp::v4(), port))
{
    start_receive();
    _io_context.run();
}

UdpServer::~UdpServer()
{
}

void UdpServer::makePackage(int i, std::string str)
{
    _toSend.i = i;
    _toSend.str = str;
}

void UdpServer::start_receive()
{
    _socket.async_receive_from(
        boost::asio::buffer(_recvBuffer), _remoteEndpoint,
        [this](boost::system::error_code e, size_t length)
            {
                handle_receive(e, length);
            }
        );
}

void UdpServer::handle_receive(const boost::system::error_code& error, std::size_t length)
{
    if (!error) {
        makePackage(1, "OUAIS YOLO");
        handle_send();
        start_receive();
    }
}

void UdpServer::handle_send()
{
    ostringstream archive_stream;
    boost::archive::text_oarchive arc(archive_stream);
    arc << _toSend;

    _socket.async_send_to(boost::asio::buffer(archive_stream.str()), _remoteEndpoint,
        [this](boost::system::error_code e, size_t length)
        {

        }
    );
}