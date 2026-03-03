#include "FastVector.hpp"
#include <cassert>
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>

int main() {
    const std::clock_t c_start = std::clock();
    auto t_start = std::chrono::high_resolution_clock::now();
    FastVector<int,10> v;

    assert(v.size() == 0);

    for(int i = 0; i < 20; ++i){
        v.emplace_back(i+1);
    }
    assert(v.size() == 20);
    assert(v.at(0) == 1);
    assert(v.at(1) == 2);

    v.clear();
    assert(v.size() == 0);
    v.push_back(1);
    v.emplace_back(2);
    FastVector<int, 10> v2 = std::move(v);

    assert(v2.size() == 2);
    assert(v2.at(0) == 1);
    assert(v2.at(1) == 2);

    const std::clock_t c_end = std::clock();
    const auto t_end = std::chrono::high_resolution_clock::now();
 
    std::cout << std::fixed << std::setprecision(2)
              << "Fast vector\n"  
              << "CPU time used: " << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: " << std::chrono::duration<double, std::nano>(t_end - t_start).count() << " ns\n";

//==================================================================================================================
    
    const std::clock_t c_start2 = std::clock();
    auto t_start2 = std::chrono::high_resolution_clock::now();
    std::vector<int> vec;


    assert(vec.size() == 0);

    for(int i = 0; i < 20; ++i){
        vec.emplace_back(i+1);
    }
    assert(vec.size() == 20);
    assert(vec.at(0) == 1);
    assert(vec.at(1) == 2);


    vec.clear();
    assert(vec.size() == 0);
    vec.push_back(1);
    vec.emplace_back(2);
    std::vector<int> vec2 = std::move(vec);
    assert(vec2.size() == 2);
    assert(vec2.at(0) == 1);
    assert(vec2.at(1) == 2);
    const std::clock_t c_end2 = std::clock();
    const auto t_end2 = std::chrono::high_resolution_clock::now();
 
    std::cout << std::fixed << std::setprecision(2)
              << "Normal vector\n" 
              << "CPU time used: " << 1000.0 * (c_end2 - c_start2) / CLOCKS_PER_SEC << " ms\n"
              << "Wall clock time passed: " << std::chrono::duration<double, std::nano>(t_end2 - t_start2).count() << " ns\n";
    return 0;
}