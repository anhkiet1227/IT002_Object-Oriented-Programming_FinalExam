#include <bits/stdc++.h>

using namespace std;

class NhomMau
{
protected:
    bool Rh;

public:
    NhomMau();
    ~NhomMau();
    void Nhap();
    bool GetRh();
    virtual bool KTDiTruyen(char, char) = 0;
    virtual char GetTen() = 0;
    virtual bool TuongThich(char nm, bool) = 0;
};

NhomMau::NhomMau() {}
NhomMau::~NhomMau() {}

void NhomMau::Nhap()
{
    char t;
    cout << "Nhap Rhesus";
    cin >> t;
    if (t == '+')
        Rh = true;
    else
        Rh = false;
}
bool NhomMau::GetRh()
{
    return Rh;
}

class NhomA : public NhomMau
{
public:
    NhomA();
    ~NhomA();
    bool KTDiTruyen(char, char);
    char GetTen();
    bool TuongThich(char nm, bool b);
};

NhomA::NhomA() {}
NhomA::~NhomA() {}

char NhomA::GetTen()
{
    return 'A';
}

bool NhomA::TuongThich(char nm, bool b)
{
    if (this->GetRh() == false)
        if (nm == 'B' || nm == 'C')
            return true;
    if (this->GetRh() == true)
        if (b == true)
            if (nm == 'A' || nm == 'C')
                return true;
    return false;
}

bool NhomA::KTDiTruyen(char me, char con)
{
    switch (me)
    {
    case 'A':
        if (con == 'A' || con == 'O')
            return true;
        break;
    case 'B':
        if (con == 'A' || con == 'O' || con == 'B' || con == 'C')
            return true;
        break;
    case 'C':
        if (con == 'A' || con == 'B' || con == 'C')
            return true;
        break;
    case 'O':
        if (con == 'A' || con == 'O')
            return true;
        break;
    }
    return false;
}

class NhomB : public NhomMau
{
public:
    NhomB();
    ~NhomB();
    bool KTDiTruyen(char, char);
    char GetTen();
    bool TuongThich(char nm, bool b);
};

NhomB::NhomB() {}
NhomB::~NhomB() {}

char NhomB::GetTen()
{
    return 'B';
}

bool NhomB::TuongThich(char nm, bool b)
{
    if (this->GetRh() == false)
        if (nm == 'B' || nm == 'C')
            return true;
    if (this->GetRh() == true)
        if (b == true)
            if (nm == 'A' || nm == 'C')
                return true;
    return false;
}

bool NhomB::KTDiTruyen(char me, char con)
{
    switch (me)
    {
    case 'A':
        if (con == 'A' || con == 'O' || con == 'B' || con == 'C')
            return true;
        break;
    case 'B':
        if (con == 'B' || con == 'O')
            return true;
        break;
    case 'C':
        if (con == 'A' || con == 'B' || con == 'C')
            return true;
        break;
    case 'O':
        if (con == 'B' || con == 'O')
            return true;
        break;
    }
    return false;
}

class NhomAB : public NhomMau
{
public:
    NhomAB();
    ~NhomAB();
    bool KTDiTruyen(char, char);
    char GetTen();
    bool TuongThich(char nm, bool b);
};

NhomAB::NhomAB() {}
NhomAB::~NhomAB() {}

char NhomAB::GetTen()
{
    return 'C';
}

bool NhomAB::TuongThich(char nm, bool b)
{
    if (this->GetRh() == false)
        if (nm == 'C')
            return true;
    if (this->GetRh() == true)
        if (b == true)
            if (nm == 'C')
                return true;
    return false;
}

bool NhomAB::KTDiTruyen(char me, char con)
{
    switch (me)
    {
    case 'A':
        if (con == 'A' || con == 'B' || con == 'C')
            return true;
        break;
    case 'B':
        if (con == 'A' || con == 'B' || con == 'C')
            return true;
        break;
    case 'C':
        if (con == 'A' || con == 'B' || con == 'C')
            return true;
        break;
    case 'O':
        if (con == 'A' || con == 'B')
            return true;
        break;
    }
    return false;
}

class NhomO : public NhomMau
{
public:
    NhomO();
    ~NhomO();
    bool KTDiTruyen(char, char);
    char GetTen();
    bool TuongThich(char nm, bool b);
};

NhomO::NhomO() {}
NhomO::~NhomO() {}

bool NhomO::KTDiTruyen(char me, char con)
{
    switch (me)
    {
    case 'A':
        if (con == 'A' || con == 'O')
            return true;
        break;
    case 'B':
        if (con == 'B' || con == 'O')
            return true;
        break;
    case 'C':
        if (con == 'A' || con == 'B')
            return true;
        break;
    case 'O':
        if (con == 'O')
            return true;
        break;
    }
    return false;
}

char NhomO::GetTen()
{
    return 'O';
}

bool NhomO::TuongThich(char nm, bool b)
{
    if (this->GetRh() == false)
        return true;
    if (b == true)
        return true;
    return false;
}

int main()
{
    //Cau 1
    int n, chon;
    NhomMau *list[50];
    cout << "Nhap so nguoi";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Hay chon 1 cho nguoi nhom mau O";
        cout << "Hay chon 2 cho nguoi nhom mau A";
        cout << "Hay chon 3 cho nguoi nhom mau B";
        cout << "Hay chon 4 cho nguoi nhom mau AB";
        cin >> chon;
        switch (chon)
        {
        case 1:
            list[i] = new NhomO();
            break;
        case 2:
            list[i] = new NhomA();
            break;
        case 3:
            list[i] = new NhomB();
            break;
        case 4:
            list[i] = new NhomAB();
            break;
        }
        list[i]->Nhap();
    }

    //Cau 2
    int cha, me, con;
    cout << "Hay nhap theo thu tu cha, me, con";
    cin >> cha >> me >> con;
    bool KQ = list[cha]->KTDiTruyen(list[me]->GetTen(), list[con]->GetTen());

    //Cau 3
    int x;
    cout << "Nhap x";
    cin >> x;
    for (int i = 0; i < n; i++)
        if ((i != x) && (list[x]->TuongThich(list[i]->GetTen(), list[i]->GetRh())))
            cout << "\t" << i;
    return 0;
}
