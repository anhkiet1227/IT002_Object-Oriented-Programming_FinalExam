#include <iostream>

using namespace std;

class bac2 {
private:
    long long a;
    long long b;
    long long c;
public:
    bac2() {};
    bac2(long long a, long long b, long long c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    friend long long fxo(bac2 f, long long xo);
    friend bac2 operator+(bac2 f1, bac2 f2);    
};

bac2 operator+(bac2 f1, bac2 f2) {
    bac2 res(f1.a + f2.a, f1.b + f2.b, f1.c + f2.c);
    return res;
}

long long fxo(bac2 f, long long xo) {
    return xo * xo * f.a + xo * f.b + f.c;
}

int main()
{
    cout << "Hello World!\n";
    return 0;
}