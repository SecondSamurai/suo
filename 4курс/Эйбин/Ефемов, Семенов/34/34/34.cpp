
#include <cmath>
#include <iostream>
#include <vector>
int main()
{
    using namespace std;
    setlocale(LC_ALL, "rus");
    double n = 4;
    vector<double> aa = { 0,-2,0.1,-1 };
    vector<double> bb = { 10,9,4,8 };
    vector<double> cc = { 1,1,-1,0 };
    vector<double> dd = { 5,-1,-5,40 };

    
    vector<double> a(100), b(100), c(100), d(100), u(100), v(100), x(100), r(100);
    for (int i = 1; i < 5; i++)
    {
        a[i] = aa[i-1];
        b[i] = bb[i-1];
        c[i] = cc[i-1];
        d[i] = dd[i-1];
        u[i] = -c[i] / (a[i] * u[i - 1] + b[i]);
        v[i] = (d[i] - a[i] * v[i - 1]) / (a[i] * u[i - 1] + b[i]);
    }
    for (int i = 5; i > 1; i--)
    {
        x[i] = u[i] * x[i + 1] + v[i];
    }
    for (int i = 1; i < 5; i++)
    {
        r[i] = d[i] - a[i] * x[i - 1] - b[i] * x[i] - c[i] * x[i + 1];
        cout << " x " << x[i];
        cout << " r " << r[i] << endl;
    }

}


