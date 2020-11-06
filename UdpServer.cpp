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

std::string make_daytime_string()
{
    using namespace std;
    time_t now = time(0);
    return ctime(&now);
}

void UdpServer::start_receive()
{
    _socket.async_receive_from(
        boost::asio::buffer(_recvBuffer), _remoteEndpoint,
        [this](boost::system::error_code e, size_t length)
            {
                makePackage(1, "OUAIS YOLO");
                ostringstream archive_stream;
                boost::archive::text_oarchive arc(archive_stream);
                arc << _toSend;

                _socket.async_send_to(boost::asio::buffer(archive_stream.str()), _remoteEndpoint,
                    [this](boost::system::error_code e, size_t length)
                    {

                    }
                );

                start_receive();
            }
        );
}

// void UdpServer::handle_receive(const boost::system::error_code& error, std::size_t)
// {
//     if (!error)
//     {
// //        boost::shared_ptr<std::string> message(new std::string(make_daytime_string()));
// //        boost::shared_ptr<Pack> send(new Pack(makePackage()));
//         makePackage(1, "salut");
//         ostringstream archive_stream;
//         boost::archive::text_oarchive arc(archive_stream);
//         arc << _toSend;
//         // char buffer[sizeof(Pack)];
//         // memcpy(buffer, &_toSend, sizeof(Pack));

// //        boost::shared_ptr<std::string> message(new std::string(buffer));

//         _socket.async_send_to(boost::asio::buffer(archive_stream.str()), _remoteEndpoint,
//             boost::bind(&UdpServer::handle_send, this, archive_stream.str(),
//             boost::asio::placeholders::error,
//             boost::asio::placeholders::bytes_transferred));

//         start_receive();
//     }
// }

// void UdpServer::handle_send(boost::shared_ptr<std::string>, const boost::system::error_code&, std::size_t)
// {

// }