/*
 * DispatcherFactory.cpp
 */

/*
Reading messages:

If you look at the Boost.Asio example, the chat_client and chat_server read
from a character buffer that is being filled from a socket. So you need
to decode the header in order to distinguish which message has to be created.

Especially since you tagged this question with design-patterns, I would
recommend to write a small Factory class that keeps a registry of function
pointers. At startup, you fill the factory's registry with function pointers
to the static member functions create() of all the message types in your
application. In this case the registry would be e.g. of type

std::map<std::string, std::function<std::unique_ptr<IMessage>(std::string const&)> Registry;

What this says is that every unique header (encoded in a std::string) stores
a pointer to a function taking a std::string and returning a std::unique_ptr<IMessage>.
Those type of function pointers are preciesly the create() functions of your messages.

Given a buffer that has been read from the socket, and converted to a std::string,
your factory would do something like:

std::unique_ptr<IMessage> Factory::create(std::string const& input) const
    {
            auto const fun = registry_.find(IMessage::header(input));
            // here you can also do your CHECKSUM validation
            return fun? (fun)(IMessage::body(input)) : nullptr;
    }

What this does is to split the message into a header and body. These functions
are static functions of the message interface, so that they can be called
before we have a concrete message object. Then the header is looked up in
the registry.

If it is found, we simply call the corresponding create() message that was stored,
taking the body as argument. This will call the constructor (now you see why we
had both a constructor and a creator, because constructors cannot be stored in
a factory registry). The constructor will finally create a std::unique_ptr to
the concrete message type that was encoded in the header.

If we didn't find a registered message type, we return a nullptr. The caller
of the factory creator would then have to check this before being able to safely
use the returned pointer.

*/


#include "DispatcherFactory.hpp"




DispatcherFactory::DispatcherFactory() {
	// TODO Auto-generated constructor stub

}

DispatcherFactory::~DispatcherFactory() {
	// TODO Auto-generated destructor stub
}


std::map<std::string, std::function<std::unique_ptr<IMessage>(std::string const&)> Registry;


std::unique_ptr<IMessage> Factory::create(std::string const& input) const
{
    auto const fun = registry_.find(IMessage::header(input));
    // here you can also do your CHECKSUM validation
    return fun? (fun)(IMessage::body(input)) : nullptr;
}

