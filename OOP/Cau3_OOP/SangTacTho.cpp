#include <bits/stdc++.h>

using namespace std;

bool ktgieovan(string a, string b)
{
    bool check = true;
    //...
    return check;
}

class BaiTho
{
protected:
    int SoCau;
    string Cau[99][102];
    string Chu;

public:
    BaiTho() {};
    ~BaiTho() {};
    virtual void SangTac();
    virtual bool KiemTra() = 0;
    int getSoCau() { return SoCau; }
};

void BaiTho::SangTac() 
{
    cout << "Nhap so cau: "; cin >> SoCau;
    cout << "Nhap bai tho (1 de ket thu):\n";
    int i = 0;
    int j = 1;
    while(getline(cin,Chu))
    {
        if(Chu == "1")
            break;
        ++i;
        int k = 0;
        while(Chu[k] != '\0')
        {
            Cau[i][j] = Chu[k];
            ++k;
            if (Chu[k] == ' ')
            {
                ++j; 
                ++k;
            }
        }
    }
}

class LucBac : public BaiTho {
public:
    LucBac() {}
    void SangTac(){
        BaiTho::SangTac();
    }
    bool KiemTra();
    
};

bool LucBac::KiemTra()
    {
        if (SoCau % 2 == 1) return false;
        for (int i = 1; i <= SoCau; ++i)
        {
            if(i % 2 == 1)
                if(i != 1)
                    if(ktgieovan(Cau[i][6], Cau[i][8]) == false)
                        return false;
            else
                if (ktgieovan(Cau[i][6], Cau[i][8]) == false)
                    return false;
            return true;            
        }
    }

class SongThatLucBac : public BaiTho {
public:
    SongThatLucBac() {}
    void SangTac(){
        BaiTho::SangTac();
    }
    bool KiemTra();
};

bool SongThatLucBac::KiemTra()
{
    if (SoCau % 4 != 0)
        return false;
    int i = 0;
    while (i <= SoCau - 3)
    {
        if(ktgieovan(Cau[i][7], Cau[i][5]) == false) return false;
        if(ktgieovan(Cau[i + 1][7], Cau[i + 2][6]) == false) return false;
        if(ktgieovan(Cau[i + 2][6], Cau[i + 3][6]) == false) return false;
        i += 4;
    }
    return true;
    
}

class DuongLuatThatNgonBatCuu : public BaiTho {
public:
    DuongLuatThatNgonBatCuu() {}
    void SangTac(){
        BaiTho::SangTac();
    }
    bool KiemTra();
};

bool DuongLuatThatNgonBatCuu::KiemTra()
{
    if(SoCau != 8) return false;
    if(ktgieovan(Cau[1][7], Cau[2][7]) == false) return false;
    if(ktgieovan(Cau[2][7], Cau[4][7]) == false) return false;
    if(ktgieovan(Cau[4][7], Cau[6][7]) == false) return false;
    if(ktgieovan(Cau[6][7], Cau[8][7]) == false) return false;
    return true;
}

int main()
{
    cout << "hello world\n"; //TestCode

    cout << "Nhap so bai tho: ";  
    int SoBaiTho;
    cin >> SoBaiTho;
    BaiTho* BaiTho[SoBaiTho];
       
    for (int i = 1; i <= SoBaiTho; ++i)
    {
        cout << "Chon loai tho muon nhap:\n";
        cout << "1. Luc Bat 2.Song That Luc Bat 3.Duong Luat That Ngon Bat Cuu\n";
        int TheLoai;
        cin >> TheLoai;
        switch(TheLoai)
        {
            case 1:        
                BaiTho[i] = new LucBac();
                BaiTho[i]->SangTac();
                break;
            
            case 2:        
                BaiTho[i] = new SongThatLucBac();
                BaiTho[i]->SangTac();
                break;
        
            
            case 3:            
                BaiTho[i] = new DuongLuatThatNgonBatCuu();
                BaiTho[i]->SangTac();
                break;
        }        
    }

    int max = 0;
    int position;
    for (int i = 1; i <= SoBaiTho; ++i)
    {
        if(BaiTho[i]->getSoCau() > max)
        {
            position = i;
            max = BaiTho[i]->getSoCau();
        }
    }
    cout << "Bai Tho co so cau nhieu nhat la bai tho thu: " << max << "\n";
    for (int i = 1; i <= SoBaiTho; ++i)
    {
        if(BaiTho[i]->KiemTra() == false)
            cout << "Khong thoa cach gieo van";
        else cout << "Thoa cach gieo van";
    }
    return 0;
}