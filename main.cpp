#include "mbed.h"

DigitalOut blue(D12);
DigitalOut yellow(D11);
// D10 NC
DigitalOut pink(D9);
DigitalOut orange(D8);

AnalogIn pot(A0);

DigitalOut led(LED1);

std::chrono::milliseconds delay = 2ms;

std::vector<DigitalOut> stepper = {blue, pink, yellow, orange};

float maxDelayMs = 50.0f;

int main()
{
    int cycle = 0;

    while (true) {
        float potValue = pot.read();
        float delayMs = potValue * maxDelayMs;
        delay = std::chrono::milliseconds(static_cast<int>(delayMs));

        led = !led;

        int count = stepper.size();

        for (int i = 0; i < count; i++) {
            stepper[i] = (i == cycle || i == ((cycle + 1) % count));
        }

        cycle = (cycle + 1) % count;

        ThisThread::sleep_for(delay);
    }
}
