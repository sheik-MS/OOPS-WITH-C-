#include <iostream>
#include <exception>
#include <string>
#include <utility>

class DatabaseError : public std::exception {
    std::string errorDetails;
public:
    explicit DatabaseError(std::string msg) : errorDetails(std::move(msg)) {}
    const char* what() const noexcept override { return errorDetails.c_str(); }
};

class TimeoutError : public DatabaseError {
public:
    int timeoutMs;
    TimeoutError(std::string msg, int ms)
        : DatabaseError(std::move(msg)), timeoutMs(ms) {}
};

void executeQuery() {
    throw TimeoutError("Query timed out connecting to shard 3", 5000);
}

void intermediateAuditor() {
    try {
        executeQuery();
    } catch (const DatabaseError& e) {
        std::cout << "[AUDIT LOG]: Intercepted DB error.\n";
        std::cout << "[AUDIT LOG]: " << e.what() << '\n';
        throw;
    }
}

int main() {
    try {
        intermediateAuditor();
    } catch (const TimeoutError& te) {
        std::cout << "Client caught TimeoutError! Duration: "
                  << te.timeoutMs << " ms\n";
    } catch (const DatabaseError& de) {
        std::cout << "Client caught generic DatabaseError: " << de.what() << '\n';
    }
}
