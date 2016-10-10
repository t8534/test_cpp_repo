/*
 * Request.hpp
 */

#ifndef COMSTACK1_REQUEST_HPP_
#define COMSTACK1_REQUEST_HPP_

#include <iostream>
#include "Imessage.hpp"

class Request: public IMessage
{
    Request(std::string const& body) { /* decode the buffer */ }

    static std::unique_ptr<IMessage> create(std::string body const&)
    {
        return std::make_unique<Request>(body);
    }

    // Request specific overrides of virtual functions
    // Request unique functions
};

#endif /* COMSTACK1_REQUEST_HPP_ */
