#include <iostream>
#include <cmath>
#include <iomanip>
//
//Задача 1,1(б)
//продифференцированный ряд
//
//
//
//


unsigned factorial(unsigned n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

float computateErf(double x){
    float result = 0.0;
    float part = 1.0;

    for(unsigned int i = 0; i < 20; i++){
        if(i > 0)
            part *= pow(x, 2) / (i);
        else
            part == 1.0;

        result += part * pow(-1.0, i);
        if(fabs(part) < fabs(pow(10.0, -6.0)))
            break;

    }
    return result * 2/pow(M_PI, 0.5);
}

int main(){

    double approx_erf;
    double exact_erf;
    double x = 0.0;

    std::cout  << std::setprecision(50) << std::fixed;

    for(int i = 0; i < 1; i++){
        x += 20;

        exact_erf = exp(-x*x) * 2/pow(M_PI, 0.5);
        approx_erf = computateErf(x);

        std::cout   << "\nx=" << x
                    << "\nExact:\t" << exact_erf
                    << "\nApproximate(computated):\t" << approx_erf
                    << "\nError:\t" << fabs(approx_erf - exact_erf) << std::endl;
    }

    return 0;
};
