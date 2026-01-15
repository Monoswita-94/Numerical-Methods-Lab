#include<iostream>
#include<cmath>
using namespace std;
double f(double x)
{
    return x/(1+x);
}
int main()
 {
    double a,b;
    int n;
    cout << "Enter lower limit (a):";
    cin >> a;
    cout << "Enter upper limit (b):";
    cin >> b;
    cout << "Enter number of subintervals:";
    cin >> n;
    if (n % 2 != 0)
        {
        cout << "error: the subintervals";
        return 1;
    }
     double h=(b-a)/n;
    double sum=f(a)+f(b);
for(int i=0; i<n; i++)
    {
    double x+ i*a;
    if (i % 2 == 0){
    sum += 2*f(x);
    else
    sum += 4 * f(x);
    }
    double area = (h/3)* sum;
    cout << "\narea under the curve" << " x/(1+x)dx= " <<area<<endl;
    }
    return 0;
    }


























