/*
** EPITECH PROJECT, 2020
** udpserver
** File description:
** Package
*/

#ifndef PACKAGE_HPP_
#define PACKAGE_HPP_

#include <boost/serialization/binary_object.hpp>
#include <boost/serialization/serialization.hpp>

#include <string>

struct Pack {
    int i;
    std::string *str;
};

struct PackageUdp : public Pack {

    public :


        template<class Archive> 
        void serialize(Archive & ar,const Pack& value, const unsigned int version)
        {
            ar & value.i;
            ar & value.str;
        }

};

#endif /* !PACKAGE_HPP_ */
