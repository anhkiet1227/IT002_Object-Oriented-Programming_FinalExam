#include <bits/stdc++.h>

using namespace std;

class CaSy
{
protected:
    string HoTen;
    int NamLamViec, DiaBanDuoc, BuoiTrinhDien;
    float luong;

public:
    CaSy() {}
    ~CaSy() {}
    virtual void Nhap();
    virtual void Xuat();
    virtual float TinhLuong() = 0;
};

void CaSy::Nhap()
{
    cout << "Nhap thong tin ca sy:\n";
    cout << "Ho ten: ";
    cin >> HoTen;
    cout << "So nam lam viec: ";
    cin >> NamLamViec;
    cout << "So dia ban duoc: ";
    cin >> DiaBanDuoc;
    cout << "So buoi trinh dien: ";
    cin >> BuoiTrinhDien;
}

void CaSy::Xuat()
{
    cout << "Thong tin ca sy:\n";
    cout << "Ho ten: " << HoTen << "\n";
    cout << "So nam lam viec: " << NamLamViec << "\n";
    cout << "So dia ban duoc: " << DiaBanDuoc << "\n";
    cout << "So buoi trinh dien: " << BuoiTrinhDien << "\n";
}

class CaSyChuaNoiTieng : public CaSy
{
public:
    CaSyChuaNoiTieng() {}
    ~CaSyChuaNoiTieng() {}
    void Nhap()
    {
        CaSy::Nhap();
    }
    void Xuat()
    {
        CaSy::Xuat();
    }
    float TinhLuong()
    {
        return 3000000 + 500000 * NamLamViec + 1000 * DiaBanDuoc + 200000 * BuoiTrinhDien;
    }
};

class CaSyNoiTieng : public CaSy
{
protected:
    int GameShow;

public:
    CaSyNoiTieng() {}
    ~CaSyNoiTieng() {}
    void Nhap()
    {
        CaSy::Nhap();
        cout << "So luong gameshow tham gia: ";
        cin >> GameShow;
    }
    void Xuat()
    {
        CaSy::Xuat();
        cout << "So luong gameshow tham gia: " << GameShow;
    }
    float TinhLuong()
    {
        return 5000000 + 500000 * NamLamViec + 1200 * DiaBanDuoc + 500000 * BuoiTrinhDien + 500000 * GameShow;
    }
};

int main()
{
    cout << "Hello World!\n";
    //Cau 1
    cout << "Nhap so luong ca sy: ";
    int SoLuongCaSy;
    cin >> SoLuongCaSy;
    CaSy *arr[SoLuongCaSy];
    int loai;
    for (int i = 0; i < SoLuongCaSy; i++)
    {
        cout << "1 Ca sy chua noi tieng 2 Ca sy noi tieng:\n";
        cin >> loai;
        if (loai == 1)
            arr[i] = new CaSyChuaNoiTieng();
        if (loai == 2)
            arr[i] = new CaSyNoiTieng();
        arr[i]->Nhap();
    }
    //Cau 2
    float LuongCaoNhat = -1.0;
    int pos;
    for (int i = 0; i < SoLuongCaSy; i++)
    {
        if (arr[i]->TinhLuong() > LuongCaoNhat)
        {
            LuongCaoNhat = arr[i]->TinhLuong();
            pos = i;
        }
    }
    cout << "Ca sy co luong cao nhat la: ";
    arr[pos]->Xuat();
    return 0;
}