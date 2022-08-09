#include <iostream>
#include <cmath>
#include <memory>
using namespace std;

float df(float x, float y) {
    return cos(x) - 2 * y;
}

void MethodEiler(float a, float b)
{
    float h = 0.1;
    float n = ((b - a) / h) + 1;
    unique_ptr<float[]> X(new float[(int)n]);
    unique_ptr<float[]> Y(new float[(int)n]);
    X[0] = a;
    cout << "Enter the Y[0] = "; cin >> Y[0];
    for (int i = 1; i < n; i++) {
        X[i] = a + i * h;
        Y[i] = Y[i - 1] + h / 2 * (df(X[i - 1], Y[i - 1]) + df((X[i - 1] + h), (Y[i - 1] + h * df(X[i - 1], Y[i - 1]))));
    }

    cout << "Table Eiler:\n";
    for (int i = 0; i < n; i++) {
        if (i == 0 || i%10==0) cout << "X[" << i << "]=" << X[i] << "\t\t\tY[" << i << "]=" << Y[i] << endl;
        else cout << "X[" << i << "]=" << X[i] << "\t\tY[" << i << "]=" << Y[i] << endl;
    }
}

void MethodRunge(float a, float b)
{
    float h = 0.1;
    float n = ((b - a) / h) + 1;
    unique_ptr<float[]> X(new float[(int)n]);
    unique_ptr<float[]> Y(new float[(int)n]);
    X[0] = a;
    cout << "\n\nEnter the Y[0] = "; cin >> Y[0];
    float k1, k2;
    for (int i = 1; i < n; i++)
    {
        k1 = h * df(X[i - 1], Y[i - 1]);
        k2 = h * df(X[i - 1] + h, Y[i - 1] + k1);
        X[i] = a + i * h;
        Y[i] = Y[i - 1] + (k1 + k2) / 2;
    }
    cout << "Table Runge:\n";
    for (int i = 0; i < n; i++) {
        if (i == 0 || i % 10 == 0) cout << "X[" << i << "]=" << X[i] << "\t\t\tY[" << i << "]=" << Y[i] << endl;
        else cout << "X[" << i << "]=" << X[i] << "\t\tY[" << i << "]=" << Y[i] << endl;
    }

}
int main() {
    float a, b;
    cout << "Enter a = "; cin >> a; cout << "Enter b = "; cin >> b;
    MethodEiler(a, b);
    MethodRunge(a, b);
    return 0;
}


