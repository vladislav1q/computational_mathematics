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

double computateErf(double x){
    double result = 0.0;

    for(unsigned int i = 0; ; i++){
        double part = pow(x, 2*i+1) / (factorial(i)*(2*i+1)) * pow(-1.0, i);
        result += part;
        if(fabs(part) < fabs(pow(10.0, -13.0)))
            break;
    }
    return result * 2/pow(M_PI, 0.5);
}

int main(){

    double approx_erf1;
    double approx_erf2;
    double result;
    double exact_erf;
    double x = 0.0;
    double h =  2*pow(10.0, -6.5);

    std::cout  << std::setprecision(10) << std::fixed;

    for(int i = 0; i < 9; i++){
        x += 0.1;

        exact_erf = exp(-x*x) * 2/pow(M_PI, 0.5);
        approx_erf1 = computateErf(x+h);
        approx_erf2 = computateErf(x);

        result = (approx_erf1 - approx_erf2) / h;

        std::cout   << "\nx=" << x
                    << "\nExact:\t" << exact_erf
                    << "\nApproximate(computated):\t" << result
                    << "\nError:\t" << fabs(result - exact_erf) << std::endl;
    }

    return 0;
};
