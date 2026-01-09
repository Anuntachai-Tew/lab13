#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}
void stat(const double data[], int size, double result[])
{
    double sum = 0.0;
    double sumSq = 0.0;
    double geoProduct = 1.0;
    double harmSum = 0.0;

    double maxVal = data[0];
    double minVal = data[0];

    for(int i = 0; i < size; i++){
        sum += data[i];
        sumSq += data[i] * data[i];
        geoProduct *= data[i];
        harmSum += 1.0 / data[i];

        if(data[i] > maxVal)
            maxVal = data[i];

        if(data[i] < minVal)
            minVal = data[i];
    }

    result[0] = sum / size;
    result[1] = sqrt((sumSq / size) - (result[0] * result[0]));
    result[2] = pow(geoProduct, 1.0 / size);
    result[3] = size / harmSum;
    result[4] = maxVal;
    result[5] = minVal;
}