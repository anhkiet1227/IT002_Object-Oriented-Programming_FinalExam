#include <bits/stdc++.h>

using namespace std;

class VeTap
{
protected:
    int PersonalTrainer;
public:
    VeTap() {}
    ~VeTap() {}
    virtual int getLoai() = 0;
    virtual int TinhTien() = 0;
    virtual void getInfo() 
    {
        cout << "Can ho tro PT: 1 co 0 khong?\n";
        cin >> PersonalTrainer;
    }
};

class VePremium : public VeTap
{
public:
    VePremium() {}
    ~VePremium() {}
    void getInfo() 
    {
        VeTap::getInfo();
    }
    int getLoai()
    {
        return 1;
    }
    int TinhTien()
    {
        return 1000000;
    }
};

class VeBasic : public VeTap
{
protected:
    int SoLopHoc;
public:
    VeBasic() {}
    ~VeBasic() {}
    void getInfo()
    {
        VeTap::getInfo();
        cout << "Nhap so luong lop hoc tham gia: ";
        cin >> SoLopHoc;
    }
    int getLoai()
    {
        return 2;
    }
    int TinhTien()
    {
        return PersonalTrainer * 100000 + SoLopHoc * 100000 + 500000;
    }
};

class VeNonMember : public VeTap
{
public:
    VeNonMember() {}
    ~VeNonMember() {}
    void getInfo()
    {
        VeTap::getInfo();
    }
    int getLoai()
    {
        return 3;
    }
    int TinhTien()
    {
        return PersonalTrainer * 200000 + 200000;
    }
};

class KhachHang
{
private:
    string HoTen;
    int CMND;
    int SoThangThamGia;
    VeTap* arr[1000];
    int TongTien;
public:
    KhachHang() {}
    ~KhachHang() {}
    void Nhap() 
    {
        cout << "Nhap thong tin khach hang\n";
        cout << "Ho ten: ";
        cin >> HoTen;
        cout << "So CMND: ";
        cin >> CMND;
        cout << "So thang tham gia dich vu: ";
        cin >> SoThangThamGia;
        for (int i = 0; i < SoThangThamGia; i++)
        {   
            int tmp;
            cout << "Nhap loai ve tuong ung: 1.Premium 2.Basic 3.Non-Member\n";
            cin >> tmp;
            if (tmp == 1)
                arr[i] = new VePremium();
            if (tmp == 2)
                arr[i] = new VeBasic();
            if (tmp == 3)
                arr[i] = new VeNonMember();
            arr[i]->getInfo();
        }
    }

    int TinhTienChiTieu()
    {
        for (int i = 0; i < SoThangThamGia; i++)
            TongTien += arr[i]->TinhTien();
        return TongTien;
    }

    void Xuat()
    {
        cout << "Thong tin khach hang\n";
        cout << "Ho ten: " << HoTen << endl;
        cout << "CMND: " << CMND << endl;
        cout << "So thang tham gia: " << SoThangThamGia << endl;
    }
};

int main()
{
    cout << "Hello World!\n"; //Testcode
    cout << "Nhap so luong khach hang: ";
    int SoLuongKhachHang;
    cin >> SoLuongKhachHang;
    KhachHang arrKhachHang[SoLuongKhachHang];
    for (int i = 0; i < SoLuongKhachHang; i++)
    {
        arrKhachHang[i].Nhap();
    }
    int SoTienLonNhat = -1;
    int pos = -1;
    for (int i = 0; i < SoLuongKhachHang; i++)
    {
        if (arrKhachHang[i].TinhTienChiTieu() > SoTienLonNhat)
        {
            SoTienLonNhat = arrKhachHang[i].TinhTienChiTieu();
            pos = i;
        }
    }
    cout << "Luong tien lon nhat ma khach hang da tieu la: " << SoTienLonNhat << "\n";
    cout << "Khac hang do la:\n";
    arrKhachHang[pos].Xuat();
    return 0;
}