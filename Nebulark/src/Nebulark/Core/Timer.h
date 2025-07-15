#include <chrono>

namespace Nebulark
{
    class Timer {
    public:
        Timer() {
            lastTime = std::chrono::high_resolution_clock::now();
        }

        // Call this once per frame to update the timer and get delta time
        float getDeltaTime() {
            auto currentTime = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> delta = currentTime - lastTime;
            lastTime = currentTime;
            return delta.count(); // seconds as float
        }

    private:
        std::chrono::high_resolution_clock::time_point lastTime;
    };
}