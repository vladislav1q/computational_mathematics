#include <iostream>
#include <cmath>
#include <iomanip>
//
//Задача 1,1(б)
//
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

double computateErf(double x){
    double result = 0.0;

    for(unsigned int i = 0; ; i++){
        double part = pow(x, 2*i+1) / (factorial(i)*(2*i+1)) * pow(-1.0, i);
        result += part;
        if(fabs(part) < fabs(pow(10.0, -6.0)))
            break;

    }
    return result * 2/pow(M_PI, 0.5);
}

int main(){

    double approx_erf;
    double exact_erf;
    double x = 0.0;

    std::cout   << std::setprecision(20) << std::fixed;

    for(int i = 0; i < 13; i++){
        x += 0.1;

        exact_erf = erf(x);
        approx_erf = computateErf(x);

        std::cout   << "\nx=" << x
                    << "\nExact:\t" << exact_erf
                    << "\nApproximate(computated):\t" << approx_erf
                    << "\nError:\t" << fabs(approx_erf - exact_erf) << std::endl;
    }


    return 0;
};
