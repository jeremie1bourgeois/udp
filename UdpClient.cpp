/*
** EPITECH PROJECT, 2020
** udpserver [WSL: Ubuntu]
** File description:
** UdpClient
*/

#include "Package.hpp"
#include "UdpClient.hpp"

using namespace client;

UdpClient::UdpClient(string ip, string port): _resolver(_ioContext), _socket(_ioContext)
{
    _receiverEndpoint = *_resolver.resolve(udp::v4(), ip, port).begin();
    _socket.open(udp::v4());
}

UdpClient::~UdpClient()
{
}

void UdpClient::send()
{
    boost::array<char, 1> send_buf  = {{ 0 }};
    _socket.send_to(boost::asio::buffer(send_buf), _receiverEndpoint);
}

void UdpClient::receive()
{
    std::string str;
    str.resize(DEFAULT_SIZE);
    udp::endpoint senderEndpoint;
    size_t len = _socket.receive_from(boost::asio::buffer(str), senderEndpoint);

    PackageUdp pac;
    std::istringstream archive_stream(str);
    boost::archive::text_iarchive archive(archive_stream);
    archive >> pac;

    cout << "[" << pac.i << "]  [" << pac.str << "]" <<endl;
}

// eujrferjfe
// erf
// erf

