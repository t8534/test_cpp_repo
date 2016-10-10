/*
 * Acknowledge.hpp
 */

#ifndef COMSTACK1_ACKNOWLEDGE_HPP_
#define COMSTACK1_ACKNOWLEDGE_HPP_

#include <iostream>
#include "Imessage.hpp"


class Acknowledge: public IMessage
{
    Acknowledge(std::string const& body) { /* decode the buffer */ }

    static std::unique_ptr<IMessage> create(std::string const& body)
    {
         return std::make_unique<Acknowledge>(body);
    }

    // Acknowledge specific overrides of virtual functions
    // Acknowledge unique functions
};
#endif /* COMSTACK1_ACKNOWLEDGE_HPP_ */
