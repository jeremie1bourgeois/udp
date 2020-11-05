/*
** EPITECH PROJECT, 2020
** udpserver [WSL: Ubuntu]
** File description:
** mainClient
*/

#include "UdpClient.hpp"

using namespace client;

int main(int ac, char **av)
{
    UdpClient client(av[1], av[2]);

    while (1) {
        client.send();
        client.receive();
        sleep(2);
    }

    return (0);
}