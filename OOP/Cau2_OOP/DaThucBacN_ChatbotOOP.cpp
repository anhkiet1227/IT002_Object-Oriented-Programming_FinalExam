#include <iostream>
using namespace std;

class DaThuc {
    int* a;
    int n;

public:
    DaThuc(int n) {
        this->n = n;
        a = new int[n];
    }
    DaThuc operator+(DaThuc p2) {
        int ma = n > p2.n ? n : p2.n;
        int mi = n < p2.n ? n : p2.n;
        int g = ma - mi;

        DaThuc p(ma);
        for (int i = 0; i < g; i++)
        {
            p.a[i] = n == ma ? a[i] : p2.a[i];
        }
        for (int i = g; i < ma; i++)
        {
            p.a[i] = n == ma ? a[i] + p2.a[i - g] :
                a[i - g] + p2.a[i];
        }

        return p;
    }
    friend istream& operator>>(istream& is, DaThuc& p);
    friend ostream& operator<<(ostream& os, DaThuc p);
};

istream& operator>>(istream& is, DaThuc& p) {
    cout << "Nhap vao bac da thuc: ";
    is >> p.n;
    p.a = new int[p.n];
    for (int i = 0; i < p.n; i++)
    {
        cout << "a" << i << ": ";
        is >> p.a[i];
    }
    return is;
}

ostream& operator<<(ostream& os, DaThuc p) {
    for (int i = 0; i < p.n; i++)
    {
        os << p.a[i] << "x^" << i;
        if (i < p.n - 1)
            os << "+";
    }
    return os;
}

int main()
{
    cout << "Hello World!\n";
    DaThuc p1(5), p2(4);
    cin >> p1;
    cin >> p2;
    cout << p1 + p2;

    cout << "\n";
    system("pause");

    return 1;
}