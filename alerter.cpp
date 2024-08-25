#include <iostream>
#include <cassert>

int failedAlertCount = 0;

int simulateNetworkAlert(float temperatureInCelsius) {
    std::cout << "ALERT: Temperature is " << temperatureInCelsius << " Celsius.\n";
    // Return 200 for OK
    // Return 500 for not OK
    if (temperatureInCelsius > 150.0) {
        return 500; // Simulate failure for temperatures above 150 Celsius
    }
    return 200; // Success for all other temperatures
}

void sendAlertInCelsius(float temperatureInFahrenheit) {
    float temperatureInCelsius = (temperatureInFahrenheit - 32) * 5 / 9;
    int responseCode = simulateNetworkAlert(temperatureInCelsius);
    if (responseCode != 200) {
        // Increment the failure count if the network alert failed
        failedAlertCount++;
    }
}

int main() {
    sendAlertInCelsius(400.5);  // This should increment the failure count
    sendAlertInCelsius(303.6);  // This should also increment the failure count
    
    // Test to check if the failure count is correct
    assert(failedAlertCount == 2); 
    
    std::cout << failedAlertCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
