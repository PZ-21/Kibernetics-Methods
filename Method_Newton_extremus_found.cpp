#include <iostream>
#include <string>
#include <cmath>

using namespace std;


double newton(double x, double eps)
{
    int m = 0;
    double f, df, df2;
    do {

        f = (5 / x) + pow(x, 2); //функция
        df = (double)(2 * x - (5 / (pow(x, 2))));  //первая производная
        df2 = (double)(2 + (10 / pow(x, 3)));  //вторая производная
        x = x - df / df2;
        m++;
    } while (fabs(df) > eps && m < 10000); //если достигнута необходимая точность решения или произошло более 10000 итераций, то расчет прекращаем
    return x; //расчитанное значение х
}

int main()
{
    double a;
    int h = 0;
   double k[150], m[150];
    for (a = 0.5; a < 2; a += 0.01) { 
        k[h] = newton(a, 0.01);
        m[h] = (5 / k[h]) + pow(k[h],2);
        h++;
    }
    for (h = 0; h < 150; h++) {
        cout << "x[" << h <<  "] " << k[h] << "    " << m[h] << endl;
    }
    return 0;
}
