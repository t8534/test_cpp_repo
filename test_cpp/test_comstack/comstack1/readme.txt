
1.
It could be good example for UDS server implementation.
The class DispatcherFactory can create Request object, base on SID value
from received data header.

2.
The initial code here can get received string buffer.
Than decide which kind of IMessage object create in depend on received SID
number. Than object is created. All UDS services should have separate 
IMessage cleasses.

     