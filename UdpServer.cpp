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

const PackageUdp UdpServer::makePackage(int i, std::string str) const noexcept
{
    return (PackageUdp {
        i,
        str
    });
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
        boost::bind(&UdpServer::handle_receive, this,
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void UdpServer::handle_receive(const boost::system::error_code& error, std::size_t)
{
    if (!error)
    {
//        boost::shared_ptr<std::string> message(new std::string(make_daytime_string()));
//        boost::shared_ptr<Pack> send(new Pack(makePackage()));
        PackageUdp test = makePackage(1, "salut");
        ostringstream archive_stream;
        boost::archive::text_oarchive arc(archive_stream);
        arc << test;
        // char buffer[sizeof(Pack)];
        // memcpy(buffer, &_toSend, sizeof(Pack));

//        boost::shared_ptr<std::string> message(new std::string(buffer));

        _socket.async_send_to(boost::asio::buffer(archive_stream.str()), _remoteEndpoint,
            boost::bind(&UdpServer::handle_send, this, archive_stream.str(),
            boost::asio::placeholders::error,
            boost::asio::placeholders::bytes_transferred));

        start_receive();
    }
}

void UdpServer::handle_send(boost::shared_ptr<std::string>, const boost::system::error_code&, std::size_t)
{

}