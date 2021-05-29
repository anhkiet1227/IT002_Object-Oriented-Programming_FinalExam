#include <iostream>

using namespace std;

class Thoigian
{
private:
    int gio, phut, giay;
public:
    friend istream& operator>>(istream& is, Thoigian&);
    friend ostream& operator<<(ostream& os, Thoigian);
    Thoigian& operator++();     // ++a
    Thoigian& operator--();     // --a
    Thoigian operator++(int);   // a++
    Thoigian operator--(int);   // a--
};

istream& operator>>(istream& is, Thoigian& x)
{
    is >> x.gio >> x.phut >> x.giay;
    return is;
}

ostream& operator<<(ostream& os, Thoigian x)
{
    os << x.gio << " " << x.phut << " " << x.giay;
    return os;
}

Thoigian& Thoigian::operator++()
{
    giay += 1;
    if (giay >= 60)
    {
        giay -= 60; phut += 1;
        if (phut >= 60)
        {
            phut -= 60; gio += 1;
            if (gio >= 24) gio -= 24;
        }
    }
    return *this;
}

Thoigian& Thoigian::operator--()
{
    giay -= 1;
    if (giay < 0)
    {
        giay = 59; phut -= 1;
        if (phut < 0)
        {
            phut = 59; gio -= 1;
            if (gio < 0) gio = 23;
        }
    }
    return *this;
}

Thoigian Thoigian::operator++(int)
{
    Thoigian p = *this;
    giay += 1;
    if (giay >= 60)
    {
        giay -= 60; phut += 1;
        if (phut >= 60)
        {
            phut -= 60; gio += 1;
            if (gio >= 24) gio -= 24;
        }
    }
    return p;
}

Thoigian Thoigian::operator--(int)
{
    Thoigian p = *this;
    giay -= 1;
    if (giay < 0)
    {
        giay = 59; phut -= 1;
        if (phut < 0)
        {
            phut = 59; gio -= 1;
            if (gio < 0) gio = 23;
        }
    }
    return p;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
