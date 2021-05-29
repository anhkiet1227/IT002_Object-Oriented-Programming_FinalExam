#include <iostream>

using namespace std;

class cNgay {
private:
    int dd, mm, yy;
public:
    cNgay(int, int, int);
    friend istream& operator>>(istream&, cNgay&);
    friend ostream& operator<<(ostream&, cNgay);
    friend bool operator<(const cNgay&, const cNgay&);
};

cNgay::cNgay(int a = 1, int b = 1, int c = 1)
{
    yy = a; mm = b; dd = c;
}

istream& operator>>(istream& is, cNgay& x)
{
    is >> x.yy >> x.mm >> x.dd;
    return is;
}

ostream& operator<<(ostream& os, cNgay x)
{
    os << x.yy << x.mm << x.dd;
    return os;
}

bool operator<(const cNgay& a, const cNgay& b) 
{
    if (a.yy < b.yy) return true;
    else if (a.yy > b.yy) return false;
    else {
        if (a.mm < b.mm) return true;
        else if (a.mm > b.mm) return false;
        else {
            if (a.dd < b.dd) return true;
            else if (a.dd >= b.dd) return false;
        }
    }
}

int main()
{
    cout << "Hello world!" << "\n";
    cNgay ng1;
    cNgay ng2(2017, 1);
    cNgay ng3(2017, 1, 7);
    cin >> ng1;
    cout << ng2;
    if (ng1 < ng2)
        cout << "ngay 1 truoc ngay 2" << "\n";
    else
        cout << "ngay 2 truoc ngay 1" << "\n";
    return 0;
}
