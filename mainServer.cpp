/*
** EPITECH PROJECT, 2020
** udpserver
** File description:
** main
*/

#include "UdpServer.hpp"

#include <string>

using namespace server;

int main(int ac, char **av)
{
    UdpServer server(std::stoi(av[1]));

    return (0);
}