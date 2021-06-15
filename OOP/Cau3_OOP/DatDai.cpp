#include <bits/stdc++.h>

using namespace std;

class cNguoi
{
private:
	string sHoTen;
	int iNamSinh;
	string sCMND;
	string sDiaChi;
public:
	void Nhap();
	void Xuat();
};
void cNguoi::Nhap()
{
	cout << "Nhap ho ten: ";
	cin >> sHoTen;
	cout << "Nhap nam sinh: ";
	cin >> iNamSinh;
	cout << "Nhap CMND: ";
	cin >> sCMND;
	cout << "Nhap dia chi: ";
	cin >> sDiaChi;
}
void cNguoi::Xuat()
{
	cout << "Ho ten: " << sHoTen;
	cout << ", Nam sinh: " << iNamSinh;
	cout << ", So CMND: " << sCMND;
	cout << ", Dia chi: " << sDiaChi << endl;
}
class cSoHong
{
protected:
	string sSoGiayCN;
	int iSoNguoiSoHuu;
	cNguoi *dsNguoiSoHuu;
	int iSoThua;
	int iSoToBanDo;
	string sDiaChi;
	int iDienTich;
	string sNgayCap;
	int iDonGiaThue;
public:
	virtual void Nhap();
	virtual void Xuat();
	virtual long TinhTienThue();
	virtual int getLoai() = 0;
};
void cSoHong::Nhap()
{
	cout << "Nhap so luong nguoi dung ten tren so hong: ";
	cin >> iSoNguoiSoHuu;
	dsNguoiSoHuu = new cNguoi[iSoNguoiSoHuu];
	for (int i = 0; i < iSoNguoiSoHuu; i++)
	{
		cout << "Nhap thong tin nguoi so huu thu " << (i + 1) << endl;
		dsNguoiSoHuu[i].Nhap();
	}
	cout << "Nhap so giay chung nhan: ";
	cin >> sSoGiayCN;
	cout << "Nhap so thua: ";
	cin >> iSoThua;
	cout << "Nhap so to ban do: ";
	cin >> iSoToBanDo;
	cout << "Nhap dia chi thua dat: ";
	cin >> sDiaChi;
	cout << "Nhap dien tich: ";
	cin >> iDienTich;
	cout << "Nhap ngay cap giay chung nhan: ";
	cin >> sNgayCap;
	cout << "Nhap don gia thue: ";
	cin >> iDonGiaThue;
}
void cSoHong::Xuat()
{
	cout << "So giay chung nhan: " << sSoGiayCN << endl;
	for (int i = 0; i < iSoNguoiSoHuu; i++)
	{
		dsNguoiSoHuu[i].Xuat();
	}
	cout << "So thua dat: " << iSoThua << endl;
	cout << "So to ban do: " << iSoToBanDo << endl;
	cout << "Dia chi thua dat: " << sDiaChi << endl;
	cout << "Dien tich thua dat: " << iDienTich << endl;
	cout << "Ngay cap: " << sNgayCap << endl;
	cout << "Don gia thue: " << iDonGiaThue << endl;
}
long cSoHong::TinhTienThue()
{
	return iDienTich*iDonGiaThue;
}

class cSoHongDatNN : public cSoHong
{
private:
	int iThoiHan;
public:
	void Nhap();
	void Xuat();
	int getLoai();
	int getThoiHan();
};
int cSoHongDatNN::getThoiHan()
{
	return iThoiHan;
}
void cSoHongDatNN::Nhap()
{
	cSoHong::Nhap();
	cout << "Nhap thoi han su dung: ";
	cin >> iThoiHan;
}
void cSoHongDatNN::Xuat()
{
	cSoHong::Xuat();
	cout << "Thoi han su dung: " << iThoiHan << endl;
	cout << "Tien thue phai dong: " << iDonGiaThue * iDienTich << endl;
}
int cSoHongDatNN::getLoai()
{
	return 1;
}
class cSoHongDatO : public cSoHong
{
public:
	void Xuat();
	int getLoai();
};
void cSoHongDatO::Xuat()
{
	cSoHong::Xuat();
	cout << "Tien thue phai dong: " << iDonGiaThue * iDienTich << endl;
}
int cSoHongDatO::getLoai()
{
	return 2;
}
int main()
{
	int n;
	cSoHong *dsGiayCN[50];
	//Câu 1 (1 điểm)
	cout << "Nhap so luong giay chung nhan can cap: ";
	cin >> n;
	int loai;
	for (int i = 0; i < n; i++)
	{
		cout << "Cap giay chung nhan Dat nong nghiep (1) hay dat o (2): ";
		cin >> loai;
		if (loai == 1)
			dsGiayCN[i] = new cSoHongDatNN;
		else
			dsGiayCN[i] = new cSoHongDatO;
		dsGiayCN[i]->Nhap();
	}
	//Câu 2 (1 điểm)
	long max = dsGiayCN[0]->TinhTienThue();
	int vt = 0;
	for (int i = 1; i < n; i++)
	{
		if (dsGiayCN[i]->TinhTienThue() > max)
		{
			max = dsGiayCN[i]->TinhTienThue();
			vt = i;
		}
	}
	dsGiayCN[vt]->Xuat();
	//Câu 3 (1 điểm)
	for (int i = 0; i < n; i++)
		if (dsGiayCN[i]->getLoai()==1)
			if (((cSoHongDatNN*)dsGiayCN[i])->getThoiHan()<2020)
				dsGiayCN[i]->Xuat();
	return 0;
}
