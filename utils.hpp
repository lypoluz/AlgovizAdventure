#include <cstdlib>

float randomFloat(float min=0, float max=1) {
    return (float) std::rand() / RAND_MAX * std::abs(min - max) + min;
}