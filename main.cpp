#include "mbed.h"

DigitalOut blue(D12);
DigitalOut yellow(D11);
// D10 NC
DigitalOut pink(D9);
DigitalOut orange(D8);

AnalogIn pot(A0);

DigitalOut led(LED1);

std::chrono::milliseconds delay = 2ms;

float maxDelayMs = 50.0f;

int main()
{
    while (true) {
        float potValue = pot.read();
        float delayMs = potValue * maxDelayMs;
        delay = std::chrono::milliseconds(static_cast<int>(delayMs));

        led = !led;

        blue = false;
        pink = false;
        yellow = true;
        orange = true;
        ThisThread::sleep_for(delay);

        blue = true;
        pink = false;
        yellow = false;
        orange = true;
        ThisThread::sleep_for(delay);

        blue = true;
        pink = true;
        yellow = false;
        orange = false;
        ThisThread::sleep_for(delay);

        blue = false;
        pink = true;
        yellow = true;
        orange = false;
        ThisThread::sleep_for(delay);
    }
}
