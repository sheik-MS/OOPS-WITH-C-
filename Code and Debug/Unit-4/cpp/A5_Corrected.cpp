#include <iostream>
class RawSocket {public:void openPort(int p){std::cout<<"Port "<<p<<" opened.\n";}void closePort(){std::cout<<"Port closed.\n";}};
class SecureChannel:private RawSocket {public:using RawSocket::closePort;void establishEncryptedTunnel(int p){openPort(p);std::cout<<"Tunnel encrypted with TLS 1.3\n";}};
int main(){SecureChannel channel;channel.establishEncryptedTunnel(443);channel.closePort();}
