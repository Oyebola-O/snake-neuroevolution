#include "headers.h"
#include "functions.h"

namespace HOBO {
    double randomDouble(double start, double end) {
        static random_device rd;
        uniform_real_distribution<double> dist(start, end);
        return dist(rd);
    }

    double relu(double val){
        return val < 0 ? 0 : val;
    }
}