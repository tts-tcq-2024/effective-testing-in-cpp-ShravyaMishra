#include <iostream>
#include <assert.h>

int alertFailureCounter = 0;

int simulateNetworkAlert(float temperatureInCelsius) {
    std::cout << "ALERT: Temperature is " << temperatureInCelsius << " Celsius.\n";
    if(temperatureInCelsius > 250)
        return 500;
    // Return 200 for OK
    // Return 500 for not-OK
    return 200;
}

void checkAndAlertInCelsius(float temperatureInFahrenheit) {
    float temperatureInCelsius = (temperatureInFahrenheit - 32) * 5 / 9;
    int responseCode = simulateNetworkAlert(temperatureInCelsius);
    if (responseCode != 200) {
        // Increment the failure count on non-OK response
        alertFailureCounter++;
    }
}

void runAlertFailureTests() {
    alertFailureCounter = 0;
    
    // Test cases
    checkAndAlertInCelsius(200); 
    std::cout << "AlertFailureCounter = " << alertFailureCounter << std::endl;
    assert(alertFailureCounter == 1);
    
    checkAndAlertInCelsius(300); 
    std::cout << "AlertFailureCounter = " << alertFailureCounter << std::endl;
    assert(alertFailureCounter == 2);
    
    checkAndAlertInCelsius(150);   
    std::cout << "AlertFailureCounter = " << alertFailureCounter << std::endl;
    assert(alertFailureCounter == 2); 

    std::cout << "All tests passed successfully!\n";
}

int main() {    
    runAlertFailureTests();

    std::cout << alertFailureCounter << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
