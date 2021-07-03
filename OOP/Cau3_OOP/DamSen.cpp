#include <bits/stdc++.h>

using namespace std;

class Ve
{
protected:
    string MaVe, HoTen;
    int NamSinh, SoTroChoi;
    int GiaVe;
    int SoLuongTroChoi;

public:
    Ve() {}
    ~Ve() {}
    virtual int getGiaVe() = 0;
    virtual void Nhap();
    virtual int getLoai() = 0;
};

void Ve::Nhap()
{
    cout << "Nhap thong tin\n";
    cout << "Ma Ve: ";
    cin >> MaVe;
    cout << "Ho Ten: ";
    cin >> HoTen;
    cout << "Nam Sinh: ";
    cin >> NamSinh;
    cout << "So luong tro choi: ";
    cin >> SoLuongTroChoi;
}

class VeTronGoi : public Ve
{
public:
    VeTronGoi() {}
    ~VeTronGoi() {}
    int getGiaVe()
    {
        return 200000;
    }
    void Nhap()
    {
        Ve::Nhap();
    }
    int getLoai() { return 1; }
};

class VeTungPhan : public Ve
{
public:
    VeTungPhan() {}
    ~VeTungPhan() {}
    int getGiaVe()
    {
        return 70000 + 20000 * SoLuongTroChoi;
    }
    void Nhap()
    {
        Ve::Nhap();
    }
    int getLoai() { return 2; }
};

int main()
{
    cout << "Hello World!\n";
    //cau A
    int SoLuongVe;
    cout << "Nhap so luong ve: ";
    cin >> SoLuongVe;
    Ve *arr[SoLuongVe];
    int loai;

    for (int i = 0; i < SoLuongVe; i++)
    {
        cout << "Nhap loai ve: 1 Ve tron goi 2 Ve tung phan\n";
        cin >> loai;
        if (loai == 1)
        {
            arr[i] = new VeTronGoi();
        }
        if (loai == 2)
        {
            arr[i] = new VeTungPhan();
        }
        arr[i]->Nhap();
    }
    //cau B
    int TongTien = 0;
    for (int i = 0; i < SoLuongVe; i++)
        TongTien += arr[i]->getGiaVe();
    cout << "Tong tien ve thu duoc: " << TongTien << "\n";
    //cau C
    int SoVeTungPhan = 0;
    for (int i = 0; i < SoLuongVe; i++)
        if (arr[i]->getLoai() == 2)
            ++SoVeTungPhan;
    cout << "So luong ve tung phan: " << SoVeTungPhan << "\n";
    return 0;
}
