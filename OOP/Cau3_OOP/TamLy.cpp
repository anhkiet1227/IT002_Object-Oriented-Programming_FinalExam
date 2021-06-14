#include <bits/stdc++.h>

using namespace std;

class OCEAN_System
{
protected:
    int value;
public:
    OCEAN_System() { this->value = value; }
    ~OCEAN_System() {};
    virtual void Notification() = 0;
};

class OpenToExperience : public OCEAN_System
{
public:
    OpenToExperience(int x) { value = x; }
    void Notification()
    {
        cout << "OpenToExperience: ";
        if (value >= 70)
            cout << "Nguoi co diem cao o yeu to nay thuong la nguoi thich nhung y tuong moi, thieu hieu biet nhieu linh vuc nhung dong thoi thich su tu do, khong thich su rang buoc\n";
        else if (value > 30)
            cout << "Khong xac dinh\n";
        else
            cout << "Nguoi co diem thap o yeu to nay thuong kha bao thu, kho tiep nhan nhung y tuong moi, la. Ho thich su on dinh quen thuoc va thuc te\n";
    }
};

class Coscientiousness : public OCEAN_System
{
public:
    Coscientiousness(int x) { value = x; }
    void Notification()
    {
        cout << "Coscientiousness: ";
        if (value >= 70)
            cout << "Nguoi co diem cao o yeu to nay thuong la nguoi cham chi, co kha nang chiu ap luc tot./nHo thuong la nguoi gan bo, trung thanh voi to chuc\n";
        else if (value > 30)
            cout << "Khong xac dinh\n";
        else
            cout << "Nguoi co diem thap o yeu to nay thuong de bo cuoc, kha nang chiu ap luc, gac bo voi to chuc kem\n";

    }
};

class Extraversion : public OCEAN_System
{
public:
    Extraversion(int x) { value = x; }
    void Notification()
    {
        cout << "Extraversion: ";
        if (value >= 70)
            cout << "Nguoi co diem cao o yeu to nay thuong la nguoi nhiet tinh, nang dong, giao tiep tot, thich the hien ban than\n";
        else if (value > 30)
            cout << "Khong xac dinh\n";
        else
            cout << "Nguoi co diem thap o yeu to nay thuong ngai giao tiep, khong thich su noi bat, thich lam viec doc lap\n";
    }
};

class Agreeableness : public OCEAN_System
{
public:
    Agreeableness(int x) { value = x; }
    void Notification()
    {
        cout << "Agreeableness: ";
        if (value >= 70)
            cout << "Nguoi co diem cao o yeu to nay thuong than thien, coi mo, dong cam voi moi nguoi nhung nhieu khi thieu chinh kien\n";
        else if (value > 30)
            cout << "Khong xac dinh\n";
        else
            cout << "Nguoi co diem thap thuong dat loi ich cua ban than len tren, it dong cam, chia se voi dong nghiep, co tinh canh tranh cao\n";
    }
};

class Neuroticism : public OCEAN_System
{
public:
    Neuroticism(int x) { value = x; }
    void Notification()
    {
        cout << "Neurot: ";
        if (value >= 70)
            cout << "Nguoi co diem cao o yeu to nay thuong co cam xuc tieu cuc nhu: lo lang, buc boi, tu ti, yeu do va kha nang chiu ap luc kem\n";
        else if (value > 30)
            cout << "Khong xac dinh\n";
        else
            cout << "Nguoi co diem thap o yeu to nay thuong kiem soat duoc cam xuc, ung pho voi cang thang tot, it bi ben ngoai anh huong den tam trang cua ban than\n";
    }
};

class Human
{
private:
    OCEAN_System* ElementSystem[5];
    int O, C, E, A, N;
public:
    void DataSet(int valueO, int valueC, int valueE, int valueA, int valueN)
    {
        ElementSystem[0] = new OpenToExperience(valueO);
        ElementSystem[1] = new Coscientiousness(valueC);
        ElementSystem[2] = new Extraversion(valueE);
        ElementSystem[3] = new Agreeableness(valueA);
        ElementSystem[4] = new Neuroticism(valueN);
    }
    void GetValue()
    {
        
        cout << "Nhap chi so O: "; cin >> O;
        cout << "Nhap chi so C: "; cin >> C;
        cout << "Nhap chi so E: "; cin >> E;
        cout << "Nhap chi so A: "; cin >> A;
        cout << "Nhap chi so N: "; cin >> N;
        DataSet(O, C, E, A, N);
    }
    void ShowNotification()
    {
        ElementSystem[0]->Notification();
        ElementSystem[1]->Notification();
        ElementSystem[2]->Notification();
        ElementSystem[3]->Notification();
        ElementSystem[4]->Notification();
    }
};

int main()
{
    cout << "Hello World\n"; //Testcode

    //Cau 1
    Human a;
    a.GetValue();
    a.ShowNotification();

    //Cau 2
    cout << "Nhap so luong nguoi can kiem tra: ";
    int NumberOfPeople;
    cin >> NumberOfPeople;
    Human arr[NumberOfPeople];
    for (int i = 0; i < NumberOfPeople; ++i)
    {
        arr[i].GetValue();
    }
    cout << "Nhap vi tri can kiem tra: ";
    int valueTest;
    cin >> valueTest;
    arr[valueTest - 1].ShowNotification();

    return 0;
}