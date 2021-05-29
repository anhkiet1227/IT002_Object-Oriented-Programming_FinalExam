#include <iostream>

using namespace std;

class dathuc {
private:
    float* heso;
    int bac;
public:
    //int laybac();
    //float layheso(int bac);
    friend istream& operator>>(istream& is, dathuc& d);
    friend ostream& operator<<(ostream& os, dathuc d);
    friend dathuc operator+(dathuc a, dathuc b)
    {
        dathuc c;
        if (a.bac >= b.bac)
        {
            c.bac = a.bac;
            c.heso = new float[c.bac + 1];
            for (int i = c.bac; i >= 0; i--)
            {
                if (i > b.bac)
                    c.heso[i] = a.heso[i];
                else
                {
                    if (i == b.bac)
                    {
                        c.heso[i] = a.heso[i] + b.heso[i];
                        b.bac--;
                    }
                }
            }
        if(a.bac < b.bac)
        {
            c.bac = b.bac;
            c.heso = new float[c.bac + 1];
            for (int i = c.bac; i >= 0; i--)
            {
                if (i > a.bac)
                    c.heso[i] = b.heso[i];
                else
                {
                    if (i == a.bac)
                    {
                        c.heso[i] = a.heso[i] + b.heso[i];
                        a.bac--;
                    }
                    else c.heso[i] = a.heso[i];
                }
            }
        }
        return c;
        }
    }
};

istream& operator>>(istream& is, dathuc& d)
{
    cin >> d.bac;
    while (d.bac < 0)
    {
        cout << "nhap lai: ";
        cin >> d.bac;
        if (d.bac > 0) break;
    }
    d.heso = new float[d.bac + 1];
    for (int i = d.bac; i >= 0; --i)
    {
        is >> d.heso[i];
    }
    return is;
}
ostream& operator<<(ostream& os, dathuc d)
{
    for (int i = d.bac; i >= 0; --i)
    {
        os << d.heso[i] << " ";
    }
    return os;
}
int main()
{
    cout << "Hello World!\n";
    dathuc a;
    cin >> a;
    dathuc b;
    cin >> b;
    dathuc c;
    c = operator+(a,b);
    cout << c;
    return 0;
}