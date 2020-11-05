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
    char recv_buf[sizeof(Pack)];
    udp::endpoint senderEndpoint;
    size_t len = _socket.receive_from(boost::asio::buffer(recv_buf, sizeof(Pack)), senderEndpoint);

    Pack pac;
    memcpy(&pac, recv_buf, sizeof(Pack));

    cout << pac.i << "]  [" << pac.str << "]" <<endl;
}