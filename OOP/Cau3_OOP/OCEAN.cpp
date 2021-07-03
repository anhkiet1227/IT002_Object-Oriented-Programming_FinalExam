#include <bits/stdc++.h>

using namespace std;

class YeuTo
{
protected:
	int GiaTri;

public:
	YeuTo();
	~YeuTo();
	int GetGiaTri();
	virtual void DacDiem() = 0;
	virtual void ChiSoCao() = 0;
	virtual void ChiSoThap() = 0;
};
YeuTo::YeuTo()
{
}
YeuTo::~YeuTo()
{
}
int YeuTo::GetGiaTri()
{
	return GiaTri;
}
class O : public YeuTo
{
public:
	O();
	~O();
	O(int);
	void DacDiem();
	void ChiSoCao();
	void ChiSoThap();
};
O::O()
{
}
O::O(int nn)
{
	GiaTri = nn;
}
void O::DacDiem()
{
	cout << "San sang trai nghiem (0)";
}
O::~O()
{
}
void O::ChiSoCao()
{
	cout << "Nguoi co chi so cao o yeu to nay thuong la nguoi thich nhung y tuong moi...";
}
void O::ChiSoThap()
{
	cout << "Nguoi co chi so thaps o yeu to nay thuong la nguoi kha bao thu ...";
}
class C : public YeuTo
{
public:
	C();
	~C();
	C(int);
	void DacDiem();
	void ChiSoCao();
	void ChiSoThap();
};
C::C()
{
}
C::C(int nn)
{
	GiaTri = nn;
}
void C::DacDiem()
{
	cout << "Tu chu tan tam (C)";
}
C::~C()
{
}
void C::ChiSoCao()
{
	cout << "Nguoi co chi so cao o yeu to nay thuong la nguoi cham chi ...";
}
void C::ChiSoThap()
{
	cout << "Nguoi co chi so thap o yeu to nay thuong la nguoi de bo cuoc ...";
}
class E : public YeuTo
{
public:
	E();
	~E();
	E(int);
	void DacDiem();
	void ChiSoCao();
	void ChiSoThap();
};
E::E()
{
}
E::E(int nn)
{
	GiaTri = nn;
}
void E::DacDiem()
{
	cout << "Huong ngoai (E)";
}
E::~E()
{
}
void E::ChiSoCao()
{
	cout << "Nguoi co chi so cao o yeu to nay thuong la nguoi nhiet tinh, nang dong...";
}
void E::ChiSoThap()
{
	cout << "Nguoi co chi so thap o yeu to nay thuong la ngai giao tieps ...";
}
class A : public YeuTo
{
public:
	A();
	~A();
	A(int);
	void DacDiem();
	void ChiSoCao();
	void ChiSoThap();
};
A::A()
{
}
A::A(int nn)
{
	GiaTri = nn;
}
void A::DacDiem()
{
	cout << "Hoa dong de chiu (A)";
}
A::~A()
{
}
void A::ChiSoCao()
{
	cout << "Nguoi co chi so cao o yeu to nay thuong than thien coi mo ...";
}
void A::ChiSoThap()
{
	cout << "Nguoi co chi so thap o yeu to nay thuong dat loi ich cua ban than len tren ...";
}
class N : public YeuTo
{
public:
	N();
	~N();
	N(int);
	void DacDiem();
	void ChiSoCao();
	void ChiSoThap();
};
N::N()
{
}
N::N(int nn)
{
	GiaTri = nn;
}
void N::DacDiem()
{
	cout << "Bat on cam xuc (N)";
}
N::~N()
{
}
void N::ChiSoCao()
{
	cout << "Nguoi co chi so cao o yeu to nay thuong co cac cam xuc tieu cuc ...";
}
void N::ChiSoThap()
{
	cout << "Nguoi co chi so thap o yeu to nay thuong kiem soat duoc cam xuc ...";
}
class Nguoi
{
private:
	YeuTo *ds[5];

public:
	Nguoi();
	~Nguoi();
	void Nhap();
	void TinhCach();
	bool NguyCo();
};
Nguoi::Nguoi()
{
}
Nguoi::~Nguoi()
{
}
void Nguoi::Nhap()
{
	int temp;
	cout << "Nhap vao gia tri yeu to O";
	cin >> temp;
	ds[0] = new O(temp);
	cout << "Nhap vao gia tri yeu to C";
	cin >> temp;
	ds[1] = new C(temp);
	cout << "Nhap vao gia tri yeu to E";
	cin >> temp;
	ds[2] = new E(temp);
	cout << "Nhap vao gia tri yeu to A";
	cin >> temp;
	ds[3] = new A(temp);
	cout << "Nhap vao gia tri yeu to N";
	cin >> temp;
	ds[4] = new N(temp);
}
void Nguoi::TinhCach()
{
	for (int i = 0; i < 5; i++)
	{
		ds[i]->DacDiem();
		if (ds[i]->GetGiaTri() >= 70)
			ds[i]->ChiSoCao();
		else if (ds[i]->GetGiaTri() <= 30)
			ds[i]->ChiSoThap();
		else
			cout << "Khong xac dinh ro";
	}
}
bool Nguoi::NguyCo()
{
	if ((ds[2]->GetGiaTri() <= 30) && (ds[3]->GetGiaTri() >= 70))
		return true;
	if (ds[3]->GetGiaTri() >= 70)
		return true;
	if (ds[1]->GetGiaTri() <= 30)
		return true;
	return false;
}
int main()
{
	Nguoi dsn[50];
	int n;
	cout << "Nhap so luong nguoi";
	cin >> n;
	for (int i = 0; i < n; i++)
		dsn[i].Nhap();
	int x;
	cout << "Chon nguoi thu ";
	cin >> x;
	dsn[x].TinhCach();
	for (int i = 0; i < n; i++)
		if (dsn[i].NguyCo() == true)
			cout << i << " ";
	system("pause");
}
