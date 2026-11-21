#include <iostream>

class NetworkPacket {
public:
    virtual ~NetworkPacket() = default;
    virtual void serialize() = 0;
    virtual int getPacketSize() = 0;
};

class VideoPacket : public NetworkPacket {
    int frameID;
    int payloadBytes;
public:
    VideoPacket(int id, int bytes) : frameID(id), payloadBytes(bytes) {}
    void serialize() override {
        std::cout << "Serializing H.264 Video Frame: " << frameID << '\n';
    }
    int getPacketSize() override { return payloadBytes; }
};

int main() {
    VideoPacket packet(1042, 4096);  // Illustrative payload length
    packet.serialize();
    std::cout << "Packet size: " << packet.getPacketSize() << " bytes\n";
}
