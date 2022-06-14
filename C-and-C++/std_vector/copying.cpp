// g++ main.cpp -o main -O3 -march=native

/*
    shows different ways to copy the values of one vector to another vector
    
    output:
    
    populating the original vector...
    method 1 took : 65506 microseconds
    method 2 took : 62557 microseconds
    method 3 took : 115809 microseconds
    method 4 took : 1731641 microseconds
    
    method 1 & 2 are almost close with each other but most of the time method 2 is a little bit faster
*/

#include <iostream>
#include <chrono>
#include <vector>

#define ITERATIONS 10000
#define ELEMENTS 10000

#define START_BENCH { auto start = std::chrono::high_resolution_clock::now();

#define END_BENCH(name) \
auto end = std::chrono::high_resolution_clock::now(); \
auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end-start); \
std::cout << name << " took : " << dur.count() << " microseconds\n"; } \

int main()
{
    std::vector<long> original;
    original.reserve(ELEMENTS);
    std::cout << "populating the original vector...\n";
    for(size_t i=0; i<ELEMENTS; ++i)
        original.push_back(i);
    
    START_BENCH;
    for(size_t i=0; i<ITERATIONS; ++i)
    {
        std::vector<long> uninitialized;
        uninitialized = original;
    }
    END_BENCH("method 1");

    START_BENCH;
    for(size_t i=0; i<ITERATIONS; ++i)
    {
        std::vector<long> uninitialized;
        uninitialized.reserve(original.size());
        uninitialized.insert(uninitialized.begin(),original.begin(),original.end());
    }
    END_BENCH("method 2");


    START_BENCH;
    for(size_t i=0; i<ITERATIONS; ++i)
    {
        std::vector<long> uninitialized;
        uninitialized.resize(original.size());
        std::copy(original.begin(),original.end(),uninitialized.begin());
    }
    END_BENCH("method 3");

    START_BENCH;
    for(size_t i=0; i<ITERATIONS; ++i)
    {
        std::vector<long> uninitialized;
        std::copy(original.begin(), original.end(), std::back_inserter(uninitialized));
    }
    END_BENCH("method 4");

    return 0;
}
