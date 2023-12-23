#pragma once
#include <random>
class RandomGen{
    public:
        
        RandomGen(std::size_t grid_width, std::size_t grid_height);
        int RandomWidth();
        int RandomHeight();
    
    private:
        std::random_device dev;
        std::mt19937 engine;
        std::uniform_int_distribution<int> random_w;
        std::uniform_int_distribution<int> random_h;

};