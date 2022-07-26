#include<iostream>
#include<windows.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#define SINHVIEN 10000
#define MAUCHECK 31
#define MAUCHU 28
#define MAU 15

using namespace std;
#pragma warning(disable : 4996)
class SinhVien {
private:
	string TenSV;

public:
	float DiemTB;
	string NamSinh;
	string Lop;
	string MaSV;
	string getNamSinh();
	void setNamSinh(string namsinh);
	string getTenSV();
	void setTenSV(string tensv);
	string getMaSV();
	void setMaSV(string masv);
	string getLop();
	void setLop(string lop);
	float getDiemTB();
	void setDiemTB(float dtb);
	SinhVien();
	SinhVien(string tensv, string masv, string lop, string namsinh, float dtb);
	void NhapThongTin(int a);
	void XuatThongTin();
};
SinhVien ArrSV[10000];
int index = 0;
bool KiemTraSinhVien(string masv, int &vt);
FILE *file;
char FName[] = "filedata.txt";
void clrscr()
{
	COORD origin = { 0, 0 };
	unsigned long len;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	unsigned long size;
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);


	GetConsoleScreenBufferInfo(handle, &csbi);
	size = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(handle, TEXT(' '), size, origin, &len);
	FillConsoleOutputAttribute(handle, csbi.wAttributes, size, origin, &len);
	SetConsoleCursorPosition(handle, origin);
}

void gotoxy(int x, int y) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD menu = { x, y };
	SetConsoleCursorPosition(h, menu);
}
void textcolor(WORD color) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void khungNen() {
	textcolor(247);
	gotoxy(85, 22);
	cout << "Nguyen Ngoc Vy ";
	gotoxy(85, 23);
	cout << "16150199";
	gotoxy(85, 24);
	cout << "Bai thuc hanh 3";

	gotoxy(35, 4);
	textcolor(247);
	cout << "\t  Chuong Trinh Quan Ly Sinh Vien\n";

}

void menu1(int luaChon) {
	int a = 8;
	int b = a + 1;
	textcolor(31);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 23; j++) {
			gotoxy(45 + j, a);
			cout << "-";
		}
		a++;
		if (i != 6) {
			gotoxy(45, a);
			cout << "|";
			gotoxy(45 + 22, a);
			cout << "|";
		}
		a++;
	}
	if (luaChon == 1) {
		textcolor(MAUCHECK);
	}
	else
		textcolor(MAUCHU);
	gotoxy(50, b);
	cout << "1. Them ho so\n";
	gotoxy(50, b + 2);
	if (luaChon == 2) {
		textcolor(MAUCHECK);
	}
	else
		textcolor(MAUCHU);
	cout << "2. In danh sach\n";
	gotoxy(50, b + 4);
	if (luaChon == 3) {
		textcolor(MAUCHECK);
	}
	else
		textcolor(MAUCHU);
	cout << "3. Sap xep\n";
	if (luaChon == 4 ) {
		textcolor(MAUCHECK);
	}
	else
		textcolor(MAUCHU);
	gotoxy(50, b + 6);
	cout << "4. Tim kiem\n";
	if (luaChon == 5) {
		textcolor(MAUCHECK);
	}
	else
		textcolor(MAUCHU);
	gotoxy(50, b + 8);
	cout << "5. Thong ke\n";
	gotoxy(50, 19);
	if (luaChon == 6) {
		textcolor(MAUCHECK);
	}
	else
		textcolor(MAUCHU);
	gotoxy(50, b + 10);
	cout << "6. Thoat\n";
}

void hienThiMenu() {
	clrscr();

	int luaChon = 1;
	khungNen();
	menu1(1);

	while (1) {
		char phim = _getch();
		int key = (int)phim;

		switch (key) {

		case 72:
			luaChon--;
			if (luaChon <= 0)
				luaChon = 6;
			break;
		case 80:
			luaChon++;
			if (luaChon >= 7)
				luaChon = 1;
			break;
		case 13: {
			switch (luaChon) {
			case 1: {
				int n;
				int a = 8;
				clrscr();
				khungNen();
				fflush(stdin);
				textcolor(MAU);
				gotoxy(5, a);
				cout << "Nhap thong tin\n";
				gotoxy(5, a + 1);
				textcolor(MAUCHU);
				cout << "Nhap so luong sinh vien : ";
				cin >> n;
				for (int i = 0; i < n; i++) {
					SinhVien sv1;
					if (i == 0) {
						sv1.NhapThongTin(a + 2 + i);
						ArrSV[i] = sv1;
					}
					else sv1.NhapThongTin(a + 2 + 5 * i);
					ArrSV[i] = sv1;
					index++;
				}
				break;

			}
			case 2: {
				

				fflush(stdin);
				cout << "\t\t\t\t\t         Thong Tin Sinh Vien\n" << endl;
				cout << setw(20) << "MSV" << setw(30) << "Ho & Ten" << setw(10) << "Lop" << setw(20) << "Nam Sinh" << setw(10) << "Diem TB" << endl;
				for (int i = 0; i < index; i++) {
					textcolor(12);
					ArrSV[i].XuatThongTin();
				}
				int a = 8;

				break;
			}
			case 3: {
				int n;
				system("cls");
				fflush(stdin);
				cout << "\t\t\t\t\t--------------Sap xep---------------\n" << endl;
				cout << "Nhap lai tong so sinh vien:" << endl;
				cin >> n;
				SinhVien t;
				for (int i = 0; i < n - 1; i++)
					for (int j = i + 1; j < n; j++)
						if (ArrSV[i].DiemTB > ArrSV[j].DiemTB)
						{
							t = ArrSV[i];
							ArrSV[i] = ArrSV[j];
							ArrSV[j] = t;
						}
				for (int i = 0; i < n; i++) {
					cout << setw(20) << "MSV" << setw(30) << "Ho & Ten" << setw(10) << "Lop" << setw(20) << "Nam Sinh" << setw(10) << "Diem TB" << endl;
					ArrSV[i].XuatThongTin();
				}

				break;
			}
			case 4: {
				int n;
				system("cls");
				fflush(stdin);
				string m = "";
				cout << "Nhap ma sinh vien can tim:" << endl;
				getline(cin, m);
				for (int i = 0; i < 5; i++)
					if (m == ArrSV[i].MaSV) {
						cout << setw(20) << "MSV" << setw(30) << "Ho & Ten" << setw(10) << "Lop" << setw(20) << "Nam Sinh" << setw(10) << "Diem TB" << endl;
						ArrSV[i].XuatThongTin();
					}
				break;
			}
			case 5: {
				int n, a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
				system("cls");
				fflush(stdin);
				cout << "Nhap lai tong so sinh vien" << endl;
				cin >> n;
				cout << setw(20) << "MSV" << setw(30) << "Ho & Ten" << setw(10) << "Lop" << setw(20) << "Nam Sinh" << setw(10) << "Diem TB" << endl;
				cout << "Loai yeu:" << endl;
				for (int i = 0; i < n; i++)
				{
					if (ArrSV[i].DiemTB < 4) {
						a1++;
						ArrSV[i].XuatThongTin();
					}
				}
				cout << "Tong:" << a1 << endl;
				cout << "Loai trung binh:" << endl;
				for (int i = 0; i < n; i++) {
					if (ArrSV[i].DiemTB >= 4 && ArrSV[i].DiemTB < 7) {
						a2++;
						ArrSV[i].XuatThongTin();
					}
				}cout << "Tong:" << a2 << endl;
				cout << "Loai kha:" << endl;
				for (int i = 0; i < n; i++) {
					if (ArrSV[i].DiemTB >= 7 && ArrSV[i].DiemTB < 8) {
						a3++;
						ArrSV[i].XuatThongTin();
					}
				}cout << "Tong:" << a3 << endl;
				cout << "Loai gioi:" << endl;
				for (int i = 0; i < n; i++) {
					if (ArrSV[i].DiemTB >= 8 && ArrSV[i].DiemTB < 9) {
						a4++;
						ArrSV[i].XuatThongTin();
					}
				}cout << "Tong:" << a4 << endl;
				cout << "Loai xuat sac:" << endl;
				for (int i = 0; i < n; i++) {
					if (ArrSV[i].DiemTB >= 9 && ArrSV[i].DiemTB <= 10) {
						a5++;
						ArrSV[i].XuatThongTin();
					}
				}cout << "Tong:" << a5 << endl;
				break;
			}
			case 6: {
				return;
				break;
			}
			}
		}
				 break;
		}
		menu1(luaChon);
	}
}

int main() {
	FILE *file = fopen(FName, "a+");

	fclose(file);
	hienThiMenu();
	return 0;
}


SinhVien::SinhVien() {
	TenSV = "";
	MaSV = "";
	Lop = "";
	NamSinh = "";
	DiemTB = 0;
}
SinhVien::SinhVien(string tensv, string masv, string lop, string namsinh, float dtb) {
	TenSV = tensv;
	MaSV = masv;
	Lop = lop;
	NamSinh = namsinh;
	DiemTB = dtb;
}
string SinhVien::getTenSV() {
	return TenSV;
}
void SinhVien::setTenSV(string tensv) {
	TenSV = tensv;
}
string SinhVien::getMaSV() {
	return MaSV;
}
void SinhVien::setMaSV(string masv) {
	MaSV = masv;
}
string SinhVien::getLop() {
	return Lop;
}
void SinhVien::setLop(string lop) {
	Lop = lop;
}
string SinhVien::getNamSinh() {
	return NamSinh;
}
void SinhVien::setNamSinh(string namsinh) {
	NamSinh = namsinh;
}
float SinhVien::getDiemTB() {
	return DiemTB;
}
void SinhVien::setDiemTB(float dtb) {
	DiemTB = dtb;
}
void SinhVien::NhapThongTin(int a) {

	cin.ignore();
	textcolor(MAUCHU);
	gotoxy(5, a + 1);
	cout << "Ho ten sinh vien : ";
	textcolor(223);
	getline(cin, TenSV);
	textcolor(MAUCHU);
	gotoxy(5, a + 2);
	cout << "Ma sinh vien: ";
	textcolor(223);
	getline(cin, MaSV);
	textcolor(MAUCHU);
	gotoxy(5, a + 3);
	cout << "Lop sinh vien: ";
	textcolor(223);
	getline(cin, Lop);
	textcolor(MAUCHU);
	gotoxy(5, a + 4);
	cout << "Ngay thang nam sinh : ";
	textcolor(223);
	getline(cin, NamSinh);
	textcolor(MAUCHU);
	gotoxy(5, a + 5);
	cout << "Diem trung binh: ";
	textcolor(223);
	cin >> DiemTB;
	cout << endl;
}
void SinhVien::XuatThongTin()
{
	cout << setw(20) << MaSV << setw(30) << TenSV << setw(10) << Lop << setw(20) << NamSinh << setw(10) << DiemTB << endl;
}
bool KiemTraSinhVien(string masv, int &vt) {
	bool kq = false;
	for (int i = 0; i < index; i++) {
		if (masv == ArrSV[i].MaSV) {
			vt = i;
			kq = true;
		}
	}
	return kq;
}