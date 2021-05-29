#include <bits/stdc++.h>

using namespace std;

class KyHieu
{
	protected:
		float TruongDo;
	public:
		virtual void Nhap();
		virtual bool LaDauLangDen();
		virtual int LayCaoDo() = 0;
};
void KyHieu::Nhap()
{
	int t;
	cout << "Nhap gia tri truong do:";
	cout << "1.Tron 2.Trang 3.Den 4.Moc don";
	cout << "5.Moc kep 6.Moc tam 7.Moc tu";
	cin >> t;
	switch(t)
	{
		case 1: TruongDo = 4;
			break;
		case 2: TruongDo = 2;
			break;
		case 3: TruongDo = 1;
			break;
		case 4: TruongDo = 0.5; 
			break;
		case 5: TruongDo = 0.25; 
			break;
		case 6: TruongDo = 0.125;
			break;
		case 7: TruongDo = 0.0625;
			break;
	}
}
bool KyHieu::LaDauLangDen()
{
	return false;
}
class NotNhac :public KyHieu
{
	private:
		int CaoDo;
	public:
		void Nhap();
		int LayCaoDo();
};
void NotNhac::Nhap()
{
	//Nhap cao do
	int t;
	cout << "Nhap gia tri cao do:";
	cout << "1.Do(C) 2.Re(D) 3.Mi(E) 4.Fa(F)";
	cout << "5.Sol(G) 6.La(A) 7.Si(B)";
	cin >> t;
	CaoDo = t;
	//Nhap truong do
	KyHieu::Nhap();
}
int NotNhac::LayCaoDo()
{
	return CaoDo;
}
class DauLang :public KyHieu
{
	public:
		bool LaDauLangDen();
		int LayCaoDo();
};
bool DauLang::LaDauLangDen()
{
	if (TruongDo == 1)
		return true;
	return false;
}
int DauLang::LayCaoDo()
{
	return 0;
}
void main()
{
	KyHieu *BanNhac[50];
	int n;
	//cau 1. Soan ban nhac
	cout << "Nhap vao so luong cac ky hieu am nhac";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cout << "Chon 1 de soan not nhac";
		cout << " va 2 de soan dau lang";
		cin >> t;
		switch (t)
		{
		case 1: BanNhac[i] = new NotNhac();
			break;
		case 2: BanNhac[i] = new DauLang();
			break;
		}
		BanNhac[i]->Nhap();
	}

	//cau 2. Dem dau lang den
	int count = 0;
	for (int i = 0; i < n; i++)
		if (BanNhac[i]->LaDauLangDen() == true)
			count++;
	cout << "So dau lang den la" << count;

	//cau 3.Tim not nhac co cao do cao nhat
	int max = BanNhac[0]->LayCaoDo();
	int vt = 0;
	for (int i = 1; i < n;i++)
		if (BanNhac[i]->LayCaoDo()>max)
		{
			max = BanNhac[i]->LayCaoDo();
			vt = i;
		}
	cout << "Vi tri not nhac co cao do cao nhat" << vt;
    return 0;
}
