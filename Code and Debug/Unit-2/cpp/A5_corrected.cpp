#include <iostream>
class TelemetryAuditor;
class Engine {
    int temperature;
    int rpm;
public:
    Engine(int t, int r) : temperature(t), rpm(r) {}
    friend void inspectDiagnostics(const Engine&, const TelemetryAuditor&);
};
class TelemetryAuditor {
    int alertThreshold;
public:
    explicit TelemetryAuditor(int t) : alertThreshold(t) {}
    friend void inspectDiagnostics(const Engine&, const TelemetryAuditor&);
};
void inspectDiagnostics(const Engine& e, const TelemetryAuditor& a) {
    if (e.temperature > a.alertThreshold)
        std::cout << "Warning: Engine overheat!" << '\n';
    else
        std::cout << "Engine operating nominally at " << e.rpm << " RPM." << '\n';
}
int main() {
    Engine v8(105, 3200);
    TelemetryAuditor audit(100);
    inspectDiagnostics(v8, audit);
}
