#ifndef PATHFINDER_HPP
#define PATHFINDER_HPP

#include "point.hpp"
#include <vector>
using std::vector;

class Pathfinder {
public:
    virtual void set_start(const Point&) = 0;
    virtual void set_end(const Point&) = 0;
    virtual vector<Point> find_path(size_t, size_t, size_t, size_t, size_t, double, double, bool=false) const = 0;
};

#endif