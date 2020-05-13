#include <iostream>
#include <iomanip>
#include <cmath>

//computate (x-2)^9 by using Horner's method of calculations
// x^9 - 18 x^8 + 144 x^7 - 672 x^6 + 2016 x^5 - 4032 x^4 + 5376 x^3 - 4608 x^2 + 2304 x - 512 = (x-2)^9

int main() {

    double result;

    std::cout   << std::setprecision(30) << std::fixed;

//    FILE* fp = fopen("test.dat","w");

    for(double t(1.920000000000000000000000000000); t <= 2.080000000000000000000000000000; t += 0.00010000000000000000000000000000){
        result = t - 18;
        result = result*t + 144;
        result = result*t - 672;
        result = result*t + 2016;
        result = result*t - 4032;
        result = result*t + 5376;
        result = result*t - 4608;
        result = result*t + 2304;
        result = result*t - 512;

        double y = result * 1000000000000000;
        double x = t;
        double z = pow(t-2, 9);
        double res_mnogochlen = pow(t, 9) - 18*pow(t, 8) + 144*pow(t, 7) - 672*pow(t, 6) + 2016*pow(t, 5) - 4032*pow(t, 4)
                + 5376*pow(t, 3) - 4608*pow(t, 2) +2304*pow(t, 1) - 512;

//        fprintf(fp,"%lf\t%lf\t%lf\n", x, y, z);

        std::cout << "\nx0 = " << t << "\ncalculated (x-2)^9 = " << result << std::endl;
        std::cout << "exact (x-2)^9 = " << pow(t-2, 9) << std::endl;
        std::cout << "full mnogochlen (x-2)^9 = " << res_mnogochlen << std::endl;
        std::cout << "error = " << fabs(pow(t-2, 9) - result) << std::endl;
    }

//    fclose(fp);

    return 0;
}

//gnuplot is used to build the graph
//
//gnuplot> plot "data.txt" using 1:2 title "First",\
//              "data.txt" using 1:3 title "Second"


