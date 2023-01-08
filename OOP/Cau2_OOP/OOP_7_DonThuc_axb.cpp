#include <bits/stdc++.h>
using namespace std;

class DonThuc
{
private:
    long long a;
    long long b;
public:
    DonThuc() {}
    DonThuc(long long a, long long b) {
        this->a = a;
        this->b = b;
    }
    ~DonThuc() {}

    friend long long getValue(DonThuc dt, long long x); 
    friend DonThuc operator+(DonThuc dt1, DonThuc dt2);
};

long long getValue(DonThuc dt, long long x) {
    return dt.a * pow(x, dt.b);
}

DonThuc operator+(DonThuc dt1, DonThuc dt2) {
    if (dt1.b == dt2.b) {
        return DonThuc(dt1.a + dt2.a, dt1.b);
    }
    return DonThuc(0, 0);
}

int main()
{
    cout << "Hello World" << endl;
    return 0;
}