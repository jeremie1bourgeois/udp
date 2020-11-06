/*
** EPITECH PROJECT, 2020
** udpserver
** File description:
** Package
*/

#ifndef PACKAGE_HPP_
#define PACKAGE_HPP_

#include <string>

#include <boost/serialization/string.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/array.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/binary_object.hpp>

struct Package
{
    int i;
    std::string str;
};

struct PackageUdp : public Package
{
    template<typename Archive>
    void serialize(Archive &ar, const unsigned int version)
    {
        ar & i;
        ar & str;
    }

};

#endif /* !PACKAGE_HPP_ */
