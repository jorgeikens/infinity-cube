//
// Created by Samuel on 28/07/2020.
//

#ifndef INFINITY_CUBE_DELAYS_H
#define INFINITY_CUBE_DELAYS_H


#include <cmath>

class Delays {
public:
    static double gaussian(int index, int size, float gamma){
        return (exp(-pow((((float) index / (float) size) - 0.5) / gamma, 2.0) / 2.0));
    }

    static double circular(int index, int size){
        return sqrt(1.0 -  pow(std::abs((2.0*((float) index/ (float)size))-1.0),2.0));
    }
};


#endif //INFINITY_CUBE_DELAYS_H
