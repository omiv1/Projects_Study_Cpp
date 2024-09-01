// functions.cpp
#include "dzielenie.h"

double divide(double a, double b) {
    if (b == 0.0) {
        // Dzielenie przez zero nie jest zdefiniowane, zwracamy NaN
        return 0.0 / 0.0;  // Alternatywnie można użyć std::numeric_limits<double>::quiet_NaN() z nagłówka <limits>
    }
    return a / b;
}
