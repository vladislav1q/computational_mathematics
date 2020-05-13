#include <iostream>
#include <iomanip>

int main() {

    double sum = 0.0;

    std::cout   << std::setprecision(10) << std::fixed;

//    FILE* fp = fopen("test.dat","w");

    for(long int k = 10; k < 1000000; k *= 10){

        for(long int i = 0; i <= k; i++){
            sum += (double)48.0 / 5.0 / (i*i + 6*i + 8);
        }

//        fprintf(fp,"%ld\t%lf\n", k, sum);

        std::cout << "\nk = " << k <<"\nSum = " << sum << "\nerror = " << (4.0 - sum ) << std::endl;
        sum = 0;
    }

//    fclose(fp);

    return 0;
}

//gnuplot is used to build the graph
//
//gnuplot> plot "data.txt" using 1:2 title "First"
