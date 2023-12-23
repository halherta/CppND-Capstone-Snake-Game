#include "random_gen.h"

RandomGen::RandomGen(std::size_t grid_width, std::size_t grid_height):engine(dev()),
        random_w(0, static_cast<int>(grid_width - 1)),
        random_h(0, static_cast<int>(grid_height - 1)){}
    
int RandomGen::RandomWidth(){ return random_w(engine);}
int RandomGen::RandomHeight(){ return random_h(engine);}