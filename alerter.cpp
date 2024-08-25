#include <iostream>
#include <assert.h>

int failedAlertCount = 0;

class NetworkAlert {
public:
    virtual int sendAlert(float celsius) = 0;
};

class StubNetworkAlert : public NetworkAlert {
public:
    int sendAlert(float celsius) override {
        std::cout << "ALERT: Temperature is " << celsius << " Celsius.\n";
        if (celsius > 200) {
            return 500;
        }
        return 200;
    }
};

float convertFahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

void alertInCelsius(float fahrenheit, NetworkAlert* networkAlert) {
    float celsius = convertFahrenheitToCelsius(fahrenheit);
    int responseCode = networkAlert->sendAlert(celsius);
    if (responseCode != 200) {
        failedAlertCount += 1;
    }
}

void testAlertInCelsius() {
    StubNetworkAlert stubNetworkAlert;
    alertInCelsius(400.5, &stubNetworkAlert);
    alertInCelsius(303.6, &stubNetworkAlert);
    alertInCelsius(102.5, &stubNetworkAlert);
    assert(failedAlertCount == 1);
}

int main() {
    testAlertInCelsius();
    std::cout << failedAlertCount << " alerts failed.\n";
    std::cout << "All tests passed (hopefully!)\n";
    return 0;
}
