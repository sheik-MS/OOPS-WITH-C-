#include <iostream>
#include <algorithm>

class AudioBuffer {
    int* samples;
    int capacity;
    int allocationId;
    static int nextId;
public:
    explicit AudioBuffer(int cap) : samples(new int[cap]), capacity(cap), allocationId(++nextId) {
        for (int i = 0; i < capacity; ++i) samples[i] = i * 10;
        std::cout << "Allocated buffer #" << allocationId << " (" << capacity << " samples)\n";
    }
    AudioBuffer(const AudioBuffer& other) : samples(new int[other.capacity]),
        capacity(other.capacity), allocationId(++nextId) {
        std::copy(other.samples, other.samples + capacity, samples);
        std::cout << "Deep-copied into buffer #" << allocationId << " from #" << other.allocationId << '\n';
    }
    AudioBuffer& operator=(const AudioBuffer& other) {
        if (this != &other) {
            int* replacement = new int[other.capacity];
            std::copy(other.samples, other.samples + other.capacity, replacement);
            delete[] samples;
            samples = replacement;
            capacity = other.capacity;
        }
        return *this;
    }
    ~AudioBuffer() {
        std::cout << "Deallocating buffer #" << allocationId << '\n';
        delete[] samples;
    }
    int firstSample() const { return capacity ? samples[0] : 0; }
};
int AudioBuffer::nextId = 0;
void processAudio(AudioBuffer buf) {
    std::cout << "Processing sample 0: " << buf.firstSample() << '\n';
}
int main() {
    AudioBuffer track(5);
    processAudio(track);
    std::cout << "Back in main, sample 0: " << track.firstSample() << '\n';
}
