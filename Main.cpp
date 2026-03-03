#include "FastVector.hpp"
#include <cassert>
#include <iostream>
#include <vector>

int main() {
    FastVector<int,4> v;
    // std::vector<int> v;

    assert(v.size() == 0);

    // push_back and emplace_back
    v.push_back(1);
    v.emplace_back(2);
    assert(v.size() == 2);
    assert(v.at(0) == 1);
    assert(v.at(1) == 2);

    // clear should destroy elements and reset size
    v.clear();
    assert(v.size() == 0);
    v.push_back(1);
    v.emplace_back(2);
    FastVector<int, 4> v2 = std::move(v);
    // std::vector<int> v2 = std::move(v);
    assert(v2.size() == 2);
    assert(v2.at(0) == 1);
    assert(v2.at(1) == 2);
    std::cout << "FastVector basic operations passed" << std::endl;
    return 0;
}