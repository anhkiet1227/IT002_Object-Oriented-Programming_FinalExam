#include <bits/stdc++.h>

using namespace std;

class Sach
{
    protected:
        string maSach;
        string tenSach;
        string nhaXuatBan;
        int soLuong;
        int donGia;
    
    public:
        Sach() {}
        ~Sach() {}
        virtual void Nhap();
        virtual void Xuat();
        virtual int TinhTien() = 0;
        string getNhaXuatBan();
};

void Sach::Nhap()
{
    cout << "Nhap ma sach: ";
    getline(cin, maSach);
    cout << "Nhap ten sach: ";
    getline(cin, tenSach);
    cout << "Nhap nha xuat ban: ";
    getline(cin, nhaXuatBan);
    cout << "Nhap so luong: ";
    cin >> soLuong;
    cout << "Nhap don gia: ";
    cin >> donGia;
}

void Sach::Xuat()
{
    cout << "Ma sach: " << maSach << endl;
    cout << "Ten sach: " << tenSach << endl;
    cout << "Nha xuat ban: " << nhaXuatBan << endl;
    cout << "So luong: " << soLuong << endl;
    cout << "Don gia: " << donGia << endl;
}

string Sach::getNhaXuatBan()
{
    return nhaXuatBan;
}

class SachGiaoKhoa : public Sach
{
    protected:
        int tinhTrang;
    
    public:
        SachGiaoKhoa() {}
        ~SachGiaoKhoa() {}
        void Nhap();
        void Xuat();
        int TinhTien();
};

void SachGiaoKhoa::Nhap()
{
    Sach::Nhap();
    cout << "Nhap tinh trang: ";
    cin >> tinhTrang;
}

void SachGiaoKhoa::Xuat()
{
    Sach::Xuat();
    cout << "Tinh trang: " << tinhTrang << endl;
}

int SachGiaoKhoa::TinhTien()
{
    return soLuong * donGia;
}

class SachThamKhao : public Sach
{
    protected:
        int tienThue;
    
    public:
        SachThamKhao() {}
        ~SachThamKhao() {}
        void Nhap();
        void Xuat();
        int TinhTien();
};

void SachThamKhao::Nhap()
{
    Sach::Nhap();
    cout << "Nhap tien thue: ";
    cin >> tienThue;
}

void SachThamKhao::Xuat()
{
    Sach::Xuat();
    cout << "Tien thue: " << tienThue << endl;
}

int SachThamKhao::TinhTien()
{
    return soLuong * donGia + tienThue;
}

int main()
{
    cout << "Welcome to Thu Vien" << endl;
    //Cau 1
    cout << "Nhap so luong sach: " << endl;
    int soLuongSach;
    cin >> soLuongSach;
    cin.ignore();

    Sach **sach = new Sach*[soLuongSach];
    int loaiSach;

    //Nhap thong tin sach
    for (int i = 0; i < soLuongSach; i++)
    {
        cout << "Nhap loai sach: " << endl;
        cout << "1. Sach giao khoa" << endl;
        cout << "2. Sach tham khao" << endl;
        cin >> loaiSach;
        cin.ignore();
        if (loaiSach == 1)
        {
            sach[i] = new SachGiaoKhoa();
        }
        else
        {
            sach[i] = new SachThamKhao();
        }
        sach[i]->Nhap();
    }

    //Xuat thong tin sach
    for (int i = 0; i < soLuongSach; i++)
    {
        sach[i]->Xuat();
    }

    //Cau 2
    int tongTien = 0;
    for (int i = 0; i < soLuongSach; i++)
    {
        tongTien += sach[i]->TinhTien();
    }
    int tongThanhTienThapNhat = 0;
    int position = 0;
    for (int i = 0; i < soLuongSach; i++)
    {
        if (sach[i]->TinhTien() < tongThanhTienThapNhat)
        {
            tongThanhTienThapNhat = sach[i]->TinhTien();
            position = i;
        }
    }
    cout << "Sach co tong thanh tien nho nhat: " << endl;
    sach[position]->Xuat();

    //Cau 3
    string tenNhaXuatBan;
    cout << "Nhap ten nha xuat ban: " << endl;
    cin >> tenNhaXuatBan;
    cin.ignore();
    for (int i = 0; i < soLuongSach; i++)
    {
        if (sach[i]->getNhaXuatBan() == tenNhaXuatBan)
        {
            sach[i]->Xuat();
        }
        else 
        {
            cout << "Khong co sach cua nha xuat ban nay" << endl;
        }
    }
    
}