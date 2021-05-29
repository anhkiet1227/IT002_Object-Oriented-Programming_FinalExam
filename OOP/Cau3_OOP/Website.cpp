#include <bits/stdc++.h>

using namespace std;

class ThanhPhan
{
protected:
    string text;
    int mauText;
    int mauNen;
public:
    ThanhPhan();
    virtual ~ThanhPhan();
    virtual void nhap();
    virtual int getMauNen();
    virtual int getMauText();
};

ThanhPhan::ThanhPhan()
{
    text = "";
    mauNen = 0;
    mauText = 0;

}

ThanhPhan::~ThanhPhan() {}

void ThanhPhan::nhap()
{
    cout << "Chon mau bang so duoi day : \n";
    cout << "1. Red, 2. Orange, 3.Yellow, 4. Spring Green\n";
    cout << "5. Red, 6. Orange, 7.Yellow, 8. Spring Green\n";
    cout << "9. Red, 10. Orange, 11.Yellow, 12. Spring Green\n";
    cout << "Chon mau nen : ";
    cin >> mauNen;
    cout << "Chon mau text : ";
    cin >> mauText;
    cin.ignore();
    cout << "Nhap text : ";
    getline(cin, text);
}

int ThanhPhan::getMauNen()
{
    return mauNen;
}

int ThanhPhan::getMauText()
{
    return mauText;
}

class Nhan : public ThanhPhan
{
public:
    Nhan() {};
    ~Nhan() {};
    void nhap()
    {
        cout << "Nhap label: \n";
        ThanhPhan::nhap();
    }
};

class Nut : public ThanhPhan
{
public:
    Nut() {};
    ~Nut() {};
    void nhap()
    {
        cout << "Nhap button: \n";
        cout << "Chon 1: Nhap button image\n Chon 2: Button text\n";
        int tl;
        cin >> tl;
        if (tl == 1)
        {
            cout << "Nhap button image: \n";
            cout << ".....Xog!!";
            text = "";
            mauNen = 0;
            mauText = 0;
        }
        else
        {
            cout << "Nhap button text: \n";
            ThanhPhan::nhap();
        }
    }
};

bool isMauBoTuc(int x, int y)
{
    return abs(x - y) == 6;
}

bool isMauTuongDong(int x, int y, int z) // x, y, z tang dan
{
    int data[15] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,1,2 };
    return (data[x + 1] == y && data[x + 2] == z);
}

int main()
{
    ThanhPhan* DS[1000];
    int n;
    cout << "Nhap so luong thanh phan : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Chon 1: Nhap Label\nChon 2: Nhap button\n";
        int tl;
        cin >> tl;
        if (tl == 1)
            DS[i] = new Nhan();
        else
            DS[i] = new Nut();
        DS[i]->nhap();
        cout << endl << endl;
    }

    //cau b
    if (isMauBoTuc(DS[0]->getMauNen(), DS[0]->getMauText()))
        cout << "Thanh phan dau tien la mau bo tuc!\n";
    else
        cout << "Thanh phan dau tien Khong la mau bo tuc!\n";

    //cau c
    int dd[13];
    for (int i = 0; i <= 12; i++)
        dd[i] = 0;
    for (int i = 0; i < n; i++)
        dd[DS[i]->getMauNen()]++;

    int spt = 0;
    int mau[13];
    for (int i = 1; i <= 12; i++)
        if (dd[i] != 0)
            mau[spt++] = i;
    cout << "Mau nen cac thanh phan: ";
    if (spt == 1)
        cout << "Theo nguyen tac: mau don sac\n";
    else
        if (spt == 2 && isMauBoTuc(mau[0], mau[1]))
            cout << "Theo nguyen tac: Mau bo tuc\n";
        else
            if (spt == 3 && isMauTuongDong(mau[0], mau[1], mau[2]))
                cout << "Theo nguyen tac: Mau tuong dong\n";
            else
                cout << "Khong theo nguyen tac nao!\n";
    return 0;
}