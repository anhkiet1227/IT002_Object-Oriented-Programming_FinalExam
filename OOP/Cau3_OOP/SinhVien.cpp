#include <bits/stdc++.h>

using namespace std;

class SinhVien
{
protected:
    int MSSV;
    string HoTen;
    string DiaChi;
    float DTB;
    int TongSoTinChi;

public:
    SinhVien() {}
    ~SinhVien() {}
    virtual void Nhap();
    virtual void Xuat();
    virtual bool XetTotNghiep() = 0;
    float getDTB() { return DTB; }
};

void SinhVien::Nhap()
{
    cout << "Nhap thong tin sinh vien\n";
    cout << "Nhap MSSV: ";
    cin >> MSSV;
    cout << "Nhap HoTen: ";
    cin >> HoTen;
    cout << "Nhap DiaChi: ";
    cin >> DiaChi;
    cout << "Nhap DTB: ";
    cin >> DTB;
    cout << "Nhap So Tin Chi: ";
    cin >> TongSoTinChi;
}

void SinhVien::Xuat()
{
    cout << "Thong tin sinh vien\n";
    cout << "MSSV: " << MSSV << "\n";
    cout << "HoTen: " << HoTen << "\n";
    cout << "DiaChi: " << DiaChi << "\n";
    cout << "DTB: " << DTB << "\n";
    cout << "Tong So Tin Chi: " << TongSoTinChi << "\n";
}

class SinhVienCaoDang : public SinhVien
{
protected:
    float DiemTotNghiep;

public:
    SinhVienCaoDang() {}
    ~SinhVienCaoDang() {}
    void Nhap();
    void Xuat();
    bool XetTotNghiep();
};

void SinhVienCaoDang::Nhap()
{
    SinhVien::Nhap();
    cout << "Diem tot nghiep: ";
    cin >> DiemTotNghiep;
}

void SinhVienCaoDang::Xuat()
{
    SinhVien::Xuat();
    cout << "Diem tot nghiep: " << DiemTotNghiep << "\n";
}

bool SinhVienCaoDang::XetTotNghiep()
{
    if (TongSoTinChi >= 120 and DTB >= 5)
        return true;
    else
        return false;
}

class SinhVienDaiHoc : public SinhVien
{
protected:
    string TenLuanVan;
    float DiemLuanVan;

public:
    SinhVienDaiHoc() {}
    ~SinhVienDaiHoc() {}
    void Nhap();
    void Xuat();
    bool XetTotNghiep();
};

void SinhVienDaiHoc::Nhap()
{
    SinhVien::Nhap();
    cout << "Nhap ten luan van: ";
    cin >> TenLuanVan;
    cout << "Nhap diem luan van: ";
    cin >> DiemLuanVan;
}

void SinhVienDaiHoc::Xuat()
{
    SinhVien::Xuat();
    cout << "Ten luan van: " << TenLuanVan << "\n";
    cout << "Diem luan van: " << DiemLuanVan << "\n";
}

bool SinhVienDaiHoc::XetTotNghiep()
{
    if (TongSoTinChi >= 170 and DTB >= 5 and DiemLuanVan >= 5)
        return true;
    else
        return false;
}

int main()
{
    cout << "Hello World!\n"; //TestCode
    //cau 1
    int SoLuongSinhVien;
    cout << "Nhap so luong sinh vien: ";
    cin >> SoLuongSinhVien;
    SinhVien *arr[SoLuongSinhVien];
    int loai;
    for (int i = 0; i < SoLuongSinhVien; i++)
    {
        cout << "1. Sinh vien cao dang  2. Sinh vien dai hoc\n";
        cout << "Nhap loai sinh vien: ";
        cin >> loai;
        if (loai == 1)
            arr[i] = new SinhVienCaoDang();
        else
            arr[i] = new SinhVienDaiHoc();
        arr[i]->Nhap();
    }
    //cau 2
    int SoLuongSinhVienTotNghiep = 0;
    for (int i = 0; i < SoLuongSinhVien; i++)
    {
        if (arr[i]->XetTotNghiep() == true)
            ++SoLuongSinhVienTotNghiep;
    }
    cout << "SoLuongSinhVienTotNghiep: " << SoLuongSinhVienTotNghiep;
    //cau 3
    float DiemCaoNhat = -1.0;
    int pos;
    for (int i = 0; i < SoLuongSinhVien; i++)
    {
        if (arr[i]->getDTB() > DiemCaoNhat)
        {
            DiemCaoNhat = arr[i]->getDTB();
            pos = i;
        }
    }
    cout << "Diem trung binh cao nhat la: " << DiemCaoNhat << "\n";
    cout << "Sinh vien do la: ";
    arr[pos]->Xuat();
    return 0;
}
