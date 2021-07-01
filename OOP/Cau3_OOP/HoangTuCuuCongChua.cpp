#include <bits/stdc++.h>

using namespace std;

class Cong{
protected:
    int loai;
public:
    Cong() {}
    ~Cong() {}
    virtual void Nhap() = 0;
    virtual int Xuat() = 0;
    int LayLoai() { return loai; }
};

class CongTien : public Cong
{
protected:
    int gia;
    int hang;
public:
    CongTien() {}
    ~CongTien() {}
    void Nhap() {
        cout << "Nhap gia: ";
        cin >> gia;
        cout << "Nhap hang: ";
        cin >> hang;
    }
    int Xuat() { return gia * hang; }
};

class CongTriTue : public Cong
{
protected:
    int tritue;
public:
    CongTriTue() {}
    ~CongTriTue() {}
    void Nhap() {
        cout << "Tri tue cua nha hien triet: ";
        cin >> tritue; 
    }
    int Xuat() { return tritue; }
};

class CongSucManh : public Cong
{
protected:
    int sucmanh;
public:
    CongSucManh() {}
    ~CongSucManh() {}
    void Nhap(){
        cout << "Suc manh cua Dung Si: ";
        cin >> sucmanh;
    }
    int Xuat() { return sucmanh; }
};

int main()
{
    cout << "Hello World!\n"; //Tescode
    //cau A
    int SoLuongCong;
    cout << "Nhap so luong cong: ";
    cin >> SoLuongCong;
    Cong* arr[SoLuongCong];
    for (int i = 0; i < SoLuongCong; ++i)
    {
        int loai;
        cin >> loai;
        if (loai == 1)
            arr[i] = new CongTien();
        if (loai == 2)
            arr[i] =  new CongTriTue();
        if (loai == 3)
            arr[i] = new CongSucManh();
        arr[i]->Nhap();
    }
    //cau B
    int htTien, htSucManh, htTriTue;
    cout << "Nhap thong so cua hoang tu: ";
    cin >> htTien >> htSucManh >> htTriTue;
    int i = 0;
    while ((i < SoLuongCong) and (htTien > 0) and (htTriTue > 0) and (htSucManh > 0))
    {
        if (arr[i]->LayLoai() == 1)
        {
            htTien -= arr[i]->Xuat();
            if (htTien < 0)
            {
                cout << "hoang tu da chet tai: " << i + 1;
                break;
            }
            else 
            {
                cout << "hoang tu da vuot qua cong: " << i + 1;
            }
        }
        if (arr[i]->LayLoai() == 2)
        {
            if (arr[i]->Xuat() > htTriTue)
            {
                cout << "hoang tu da chet tai: " << i + 1;
                break;
            }
            else 
            {
                cout << "hoang tu da vuot qua cong: " << i + 1;
            }
        }
        if (arr[i]->LayLoai() == 3)
        {
            htSucManh -= arr[i]->Xuat();
            if (htSucManh < 0)
            {
                cout << "hoang tu da chet tai: " << i + 1;
                break;
            }
            else 
            {
                cout << "huong tu da vuot qua cong: " << i + 1;
            }
        }
        if (i >= (SoLuongCong - 1))
        {
            cout << "hoang tu da cuu duoc cong chua\n";
        }
        cout << "thong so hien tai: " << htTien << "\t" << htTriTue << "\t" << htSucManh << "\t";
        ++i;
    }
    return 0;
}