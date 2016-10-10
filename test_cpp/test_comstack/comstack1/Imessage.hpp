/*
 * Imessage.hpp
 */

#ifndef COMSTACK1_IMESSAGE_HPP_
#define COMSTACK1_IMESSAGE_HPP_

#include <iostream>

// I would recommend to factor all the common message stuff HEADER|BODY|CHECKSUM
// into an abstract base class IMessage.
class IMessage
{
public:
    virtual ~IMessage() {} // virtual destructor

    // virtual functions that can be overriden for concrete message types

    static std::string header(std::string const& input)
    {
            return input.substr(0, HeaderLength);
    }

    static std::string body(std::string const& input)
    {
            return input.substr(HeaderLength, HeaderLength + BodyLength);
    }

    enum {
        HeaderLength = 4,    /* bla */
        BodyLength = 128,    /* bla */
        ChecksumLength = 2  /* bla */
    };
};

#endif /* COMSTACK1_IMESSAGE_HPP_ */
