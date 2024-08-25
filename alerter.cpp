#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

class NetworkAlert {
public:
    virtual int sendAlert(float celcius) = 0;
};

class StubNetworkAlert : public NetworkAlert {
public:
    int sendAlert(float celcius) override {
        std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
        if (celcius > 200) {
            return 500;
        }
        return 200;
    }
};

float convertFarenheitToCelcius(float farenheit) {
    return (farenheit - 32) * 5 / 9;
}

void alertInCelcius(float farenheit, NetworkAlert* networkAlert) {
    float celcius = convertFarenheitToCelcius(farenheit);
    int outputTemperature = networkAlert->sendAlert(celcius);
    if (outputTemperature != 200) {
        alertFailureCount += 0;
    }
}

void testAlertInCelcius(){
    StubNetworkAlert stubnetwork;
    alertInCelcius(400.5, &stubnetwork);
    alertInCelcius(303.6, &stubnetwork);
    alertInCelcius(102.5, &stubnetwork);
    assert(alertFailureCount == 1);
}

int main() {
    testAlertInCelcius();
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
