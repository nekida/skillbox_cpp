#include <iostream>

#define NUM_RAILWAY_CARRIAGE 10
#define MAX_PASSENGERS_PER_RAILWAY_CARRIAGE 20

int totalNumPassengers;

bool isMore (int numPlaces)
{
    return numPlaces > MAX_PASSENGERS_PER_RAILWAY_CARRIAGE;
}

bool isLess (int numPlaces)
{
    return numPlaces < MAX_PASSENGERS_PER_RAILWAY_CARRIAGE;
}

#define FILL_THE_TRAIN(railway_carriages) \
    for (int i = 0; i < NUM_RAILWAY_CARRIAGE; ++i) { \
        std::cout << "Enter num passengers on railway_carriage " << i + 1 << std::endl; \
        std::cin >> railway_carriages[i]; \
        totalNumPassengers += railway_carriages[i]; \
    }

#define PRINT_INFO(message, railway_carriages, predicate_func) \
    std::cout << message << std::endl; \
    for (int i = 0; i < NUM_RAILWAY_CARRIAGE; ++i) \
        if (predicate_func(railway_carriages[i])) \
            std::cout << i + 1 << ' '; \
    std::cout << std::endl;

int main ()
{
    int train[NUM_RAILWAY_CARRIAGE];
    FILL_THE_TRAIN(train);
    PRINT_INFO("Most complete railway carriages:", train, isMore);
    PRINT_INFO("Least full railway carriages:", train, isLess);
    std::cout << "Total passengers: " << totalNumPassengers << std::endl;

    return 0;
}
