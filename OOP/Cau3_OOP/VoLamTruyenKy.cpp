#include <bits/stdc++.h>

using namespace std;

class Base
{
private:
	int He;// 0. KIm, 1. Moc , 2. Thuy, 3.Hoa,4. Tho
	double Satthuong;
public:

	Base();
	~Base();
	virtual void nhap();
	virtual void xuat();
	bool tinhTuongtac(Base &b);
	double getST()
	{
		return Satthuong;
	}
	void setST(double _ST)
	{
		Satthuong = _ST;
	}
	void setHe(int m)
	{
		He = m;
		
	}
	int getHe()
	{
		return He;
	}
};
Base::Base() {}
Base::~Base() {}

void Base::nhap()
{

	cout << "Nhap he: 0.Kim 1.Moc 2.Thuy 3.Hoa 4.Tho";
	cin >> He;
}
void Base::xuat()
{
	cout << "He ngu hanh:" << endl;
	switch (He)
	{
	case 0: cout << "He Kim" << endl; break;
	case 1: cout << "He Moc" << endl; break;
	case 2: cout << "He Thuy" << endl; break;
	case 3: cout << "He Hoa" << endl; break;
	case 4: cout << "He Tho" << endl; break;
	}
	cout << "Sat thuong" << Satthuong << endl;
}
bool Base::tinhTuongtac(Base &b)
{
	double STtuongtacAB = this->getST();
	double STtuongtacBA = b.getST();
	if ((this->He == 0 && b.getHe() == 1) || 
		(this->He == 1 && b.getHe() == 4)||
		(this->He == 2 && b.getHe() == 3)||
		(this->He == 3 && b.getHe() == 0)||
		(this->He == 4 && b.getHe() == 2))
	{
		STtuongtacAB = this->getST() * 120 / 100;
		STtuongtacBA = b.getST() * 80 / 100;

	}
	else {
		if ((b.getHe() == 0 && this->He == 1) ||
			(b.getHe() == 1 && this->He == 4) ||
			(b.getHe() == 2 && this->He == 3) ||
			(b.getHe() == 3 && this->He == 0) ||
			(b.getHe() == 4 && this->He == 2))
		{
			STtuongtacBA = this->getST() * 120 / 100;
			STtuongtacAB = b.getST() * 80 / 100;
		}
	}
	if ((this->He == 0 && b.getHe() == 2)||
		(this->He == 1 && b.getHe() == 3)||
		(this->He == 2 && b.getHe() == 1)||
		(this->He == 3 && b.getHe() == 4)||
		(this->He == 4 && b.getHe() == 0))
		
	{
		STtuongtacAB = this->getST() * 110 / 100;
	}
	

	if (STtuongtacAB > STtuongtacBA)
		return true;
	return false;
}

class NhanVat : public Base
{
private:
	char Monphai[40];
	int cap;
public:
	NhanVat();
	virtual ~NhanVat();
	void nhap();
	void xuat();
};
NhanVat::NhanVat() {}
NhanVat::~NhanVat() {}

void NhanVat::nhap()
{
	int chose = 0;
	Base::nhap();
	//
	switch (Base::getHe())
	{
	case 0: 
	{
		cout << "Chon mon phai: 0.Thieu lam 1.Thien vuong " << endl;
		cin >> chose;
		switch (chose)
		{
		case 0: strcpy(Monphai, "Thieu lam");  break;
		case 1: strcpy(Monphai, "Thien vuong"); break;
		}
		break;
	}
	case 1:
	{
		cout << "Chon mon phai: 0.Ngu doc 1.Duong mon " << endl;
		cin >> chose;
		switch (chose)
		{
		case 0: strcpy(Monphai, "Ngu doc");  break;
		case 1: strcpy(Monphai, "Duong mon"); break;
		}
		break;
	}
	case 2:
	{
		cout << "Chon mon phai: 0.Nga my 1.Thuy yen " << endl;
		cin >> chose;
		switch (chose)
		{
		case 0: strcpy(Monphai, "Nga my");  break;
		case 1: strcpy(Monphai, "Thuy yen"); break;
		}
		break;
	}
	case 3:
	{
		cout << "Chon mon phai: 0.Cai bang 1.Thien nhan " << endl;
		cin >> chose;
		switch (chose)
		{
		case 0: strcpy(Monphai, "Cai bang");  break;
		case 1: strcpy(Monphai, "Thien nhan"); break;
		}
		break;
	}
	case 4:
	{
		cout << "Chon mon phai: 0.Con lon 1.Vo dang " << endl;
		cin >> chose;
		switch (chose)
		{
		case 0: strcpy(Monphai, "Con lon");  break;
		case 1: strcpy(Monphai, "Vo dang"); break;
		}
		break;
	}
	}
	cout << "Nhap vao cap do nhan vat"<<endl;
	cin >> cap;
	Base::setST(cap * 5);
}

void NhanVat::xuat()
{
	Base::xuat();
	cout << Monphai;
	cout << cap << endl;
}

class Quai : public Base
{
private:
	int cap;
	int Loai; // 0. Thuong 1.Boss
public:
	Quai();
	~Quai();
	void nhap();
	void xuat();
};
Quai::Quai() {}
Quai::~Quai() {}

void Quai::nhap()
{
	Base::nhap();
	cout << "Nhap vao cap do quai" << endl;
	cin >> cap;
	cout << "Nhap loai quai 0.Thuong 1.boss";
	cin >> Loai;
	switch (Loai)
	{
	case 0: Base::setST(cap * 3); break;
	case 1:Base::setST(cap * 7); break;
	default:Base::setST(cap * 3);
	}
}
void Quai::xuat()
{
	Base::xuat();
	switch (Loai)
	{
	case 0: cout << "Thuong" << endl; break;
	case 1:cout << "Boss" << endl; break;
	}
	cout << cap << endl;
}

class QuanLy
{
private:
	int n;
	Base ** danhsach;
public:
	QuanLy();
	~QuanLy();
	void nhap();
	void xuat();
	void tuongtac();
	void timSTLN();
};
QuanLy::QuanLy() {}
QuanLy::~QuanLy() {}

void QuanLy::nhap()
{
	cout << "Nhap vao so phan tu" << endl;
	cin >> n;
	danhsach = new Base *[n];
	int chon;
	for (int i = 0; i < n; i++)
	{
		cout << "Chon 0.Nhan vat 1.Quaivat" << endl;
		cin >> chon;
		switch (chon)
		{
		case 0: danhsach[i] = new NhanVat; danhsach[i]->nhap(); break;
		case 1:danhsach[i] = new Quai; danhsach[i]->nhap(); break;
		}
	}

}

void QuanLy::xuat()
{
	for (int i = 0; i < n; i++)
	{
		danhsach[i]->xuat();
	}
}
void QuanLy::tuongtac()
{
	int x, y;
	cout << "chon phan tu tuong tac"<<endl;
	cin >> x >> y;
	bool flag = danhsach[x]->tinhTuongtac(* danhsach[y]);
	if (flag)
		cout << "x co st tuong tac cao hon y";
	else
		cout << "y co st tuong tac cao hon x";

}
void QuanLy::timSTLN()
{
	double max = 0;
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if (max <= danhsach[i]->getST())
		{
			max = danhsach[i]->getST();
			index = i;
		}
	}
	cout << "Phan tu co sat thuong lon nhat" << index << " " << max;
}


int main()
{
	QuanLy a;
	a.nhap();
	a.xuat();
	a.timSTLN();
	a.tuongtac();
	system("pause");
	return 0;
}
