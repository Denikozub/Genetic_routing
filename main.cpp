#include <iostream>
#include "polygon.hpp"
#include "point.hpp"
#include "genetic_algo.hpp"
using namespace std;

int main()
{
    try {
        Polygon p1({ { 1, 0 }, { 2, 0 }, { 2, 4 }, { 1, 4 }, { 1, 0 } }),
                p2({ { 3, 3 }, { 3, 4 }, { 5, 4 }, { 5, 3 }, { 3, 3 } }),
                p3({ { 6, 0 }, { 7, 0 }, { 7, 4 }, { 6, 4 }, { 6, 0 } }),
                p4({ { 4, 5 }, { 4, 6 }, { 8, 6 }, { 8, 5 }, { 4, 5 } }),
                p5({ { 0, 5 }, { 0, 7 }, { 3, 7 }, { 3, 5 }, { 0, 5 } }),
                p6({ { 3, 7 }, { 3, 8 }, { 7, 8 }, { 7, 7 }, { 3, 7 } });
        vector<pair<Polygon, int>> obstacles({ {p1, 100}, {p2, 100}, {p3, 100}, {p4, 100}, {p5, 100}, {p6, 100} });
        Point start({ 4, 2 }), end({ 4, 10 });

        GeneticAlgo pathfinder(obstacles, start, end);
        size_t population_size = 50;
        size_t epoch_number = 300;
        size_t valueless_epoch_number = 15;
        size_t preserve_best = 3;
        size_t preserve_worst = 3;
        double cross_percent = 0.5;
        double mutate_percent = 0.5;

        const auto& path = pathfinder.find_path(population_size, epoch_number, valueless_epoch_number,
                preserve_best, preserve_worst, cross_percent, mutate_percent, true);
        cout << "Path found: " << start << " -> ";
        for (const auto& point : path) {
            cout << point << " -> ";
        }
        cout << end << endl;
    }
    catch (std::exception& e) {
        std::cerr << typeid(e).name() << ": " << e.what() << std::endl;
    }
    
    return 0;
}