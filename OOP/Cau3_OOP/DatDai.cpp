#include <bits/stdc++.h>

using namespace std;

class DatDai{
protected:
    string SoChungNhan, ThongTinCaNhan, DiaChiThuaDat;
    int SoThuaDat, SoToBanDo, DienTich, NgayCap;
    float Thue;
public:
    DatDai() {};
    ~DatDai() {};
    virtual void Get()
    {
        cout << "THONG TIN\n";
		cout << "so giay chung nhan: "; cin >> SoChungNhan; cout << "\n";
		cout << "thong tin ca nhan: "; cin >> ThongTinCaNhan; cout << "\n";
		cout << "so thua: "; cin >> SoThuaDat; cout << "\n";
		cout << "so to ban do: "; cin >> SoToBanDo; cout << "\n";
		cout << "dia chi: "; cin >> DiaChiThuaDat; cout << "\n";
		cout << "dien tich: "; cin >> DienTich; cout << "\n";
		cout << "ngay cap: "; cin >> NgayCap; cout << "\n";
		cout << "don gia thue: "; cin >> Thue; cout << "\n";
    }
    virtual void Show()
    {
        cout << "THONG TIN\n";
		cout << "so giay chung nhan: "; cout << SoChungNhan << "\n";
		cout << "thong tin ca nhan: "; cout << ThongTinCaNhan << "\n";
		cout << "so thua: "; cout << SoThuaDat << "\n";
		cout << "so to ban do: "; cout << SoToBanDo << "\n";
		cout << "dia chi: "; cout << DiaChiThuaDat << "\n";
		cout << "dien tich: "; cout << DienTich << "\n";
		cout << "ngay cap: "; cout << NgayCap << "\n";
		cout << "don gia thue: "; cout << Thue << "\n";
    }
    float CalculatorTax(){
        return Thue * DienTich;
    }
    virtual int GetDateOfUsing() = 0;
};

class DatNongNghiep : public DatDai
{
private:
    int ThoiHanSuDung;
public:
    DatNongNghiep() {};
    void Get(){
        DatDai::Get();
        cout << "thoi han su dung: "; cin >> ThoiHanSuDung; cout << "\n";
    }
    void Show(){
        DatDai::Show();
        cout << "thoi han su dung: "; cout << ThoiHanSuDung << "\n";
    }
    int GetDateOfUsing(){
        return ThoiHanSuDung;
    }
};

class DatPhiNongNghiep : public DatDai
{
public:
    DatPhiNongNghiep() {};
    void Get(){
        DatDai::Get();
    }
    void Show(){
        DatDai::Show();
    }
    int GetDateOfUsing(){
        return 0;
    }
};
int main()
{
    cout << "Hello world\n"; //Testcode

    //Cau 1
    int NumberOfEarths, tmp;
    cout << "Nhap so luong giay to: ";
    cin >> NumberOfEarths;
    DatDai* arr[NumberOfEarths];
    for (int i = 0; i < NumberOfEarths; ++i)
    {
        cout << "1. DatNongNghiep\t2. DatPhiNongNghiep\n";
        cin >> tmp;
        if (tmp == 1)
            arr[i] = new DatNongNghiep();
        else 
            arr[i] = new DatPhiNongNghiep();
        arr[i]->Get();
    }

    //Cau 2
    float ma = -1;
    int addressOfmax;
    for (int i = 0; i < NumberOfEarths; ++i)
    {
        if(ma < arr[i]->CalculatorTax())
        {
            ma = arr[i]->CalculatorTax();
            addressOfmax = i;
        }
    }
    cout << "Thua dat co tien thue lon nhat la so: " << addressOfmax + 1 << "\n";
    arr[addressOfmax]->Show();

    //Cau 3
    cout << "Nhap nam hien tai: ";
    int year; 
    cin >> year;
    for (int i = 0; i < NumberOfEarths; ++i)
    {
        if(arr[i]->GetDateOfUsing() < year)
        cout << "Thua dat so: " << i + 1 << " da het han su dung, thong tin thua dat: \n";
        arr[i]->Show();
    }
    return 0;
}