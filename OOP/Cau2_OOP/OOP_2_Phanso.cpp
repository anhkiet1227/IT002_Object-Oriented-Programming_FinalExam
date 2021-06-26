#include <iostream>

using namespace std;

class PhanSo {
private:
    int tuSo;
    int mauSo;
public:
    PhanSo(int tuSo, int mauSo) {
        this->tuSo = tuSo;
        this->mauSo = mauSo;
    };
    int UCLN(int a, int b) {
        int r;
        while (a % b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        return b;
    }
    PhanSo rutgon()
    {
        int z = UCLN(tuSo, mauSo);
        return PhanSo(tuSo / z, mauSo / z);
    }
    friend PhanSo operator+(PhanSo a, PhanSo b);
    friend PhanSo operator-(PhanSo a, PhanSo b);
    friend istream& operator>>(istream& is, PhanSo& x);
    friend ostream& operator<<(ostream& os, PhanSo x);
    PhanSo& operator++();
    PhanSo operator++(int);
};

PhanSo operator+(PhanSo a, PhanSo b)
{
    a = a.rutgon();
    b = b.rutgon();
    PhanSo res(a.tuSo * b.mauSo + a.mauSo * b.tuSo, a.mauSo * b.mauSo);
    res = res.rutgon();
    return res;
}

PhanSo operator-(PhanSo a, PhanSo b)
{
    a = a.rutgon();
    b = b.rutgon();
    PhanSo res(a.tuSo * b.mauSo - a.mauSo * b.tuSo, a.mauSo * b.mauSo);
    res = res.rutgon();
    return res;
}

istream& operator>>(istream& is, PhanSo& x)
{
    is >> x.tuSo >> x.mauSo;
    return is;
}

ostream& operator<<(ostream& os, PhanSo x)
{
    os << x.tuSo << " " << x.mauSo;
    return os;
}

PhanSo& PhanSo::operator++()
{
    tuSo += mauSo;
    return *this;
}

PhanSo PhanSo::operator++(int)
{
    PhanSo tmp = *this;
    ++(*this);
    return tmp;
}

int main()
{
    cout << "Hello World!\n";
    return 0;
}
