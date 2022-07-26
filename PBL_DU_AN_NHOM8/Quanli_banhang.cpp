#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <cstdlib>
using namespace std;

//system("cls");

class HangHoa
{
private:
	 
    
public:
    string MaHang;	
	int SoLuong;
	unsigned long long Gia;
	string TenSP;
friend class ChucNang;

void GetIf_H ()
{
	fflush(stdin);
    cout<<"Ten Hang :"<<endl;
    getline(cin,TenSP);
    fflush(stdin);
    cout<<"Ma San Pham :"<<endl;
    getline(cin,MaHang);
    
    cout<<"So Luong :"<<endl;
    cin>>this->SoLuong;
    cout<<"Gia Tien Cua San Pham :"<<endl;
    cin>>this->Gia;
}

    
};

class KhachHang
{
private:


public:
	string TenKH;
	string SDT;
	string CCCD;
	string DiaChi;
    string Phanloai;
friend class ChucNang;

void GetIf_K ()
{
	fflush(stdin);
	cout<<"Ten Khach Hang :"<<endl;
	getline(cin,TenKH);
	fflush(stdin);
	cout<<"So Dien Thoai :"<<endl;
	getline(cin,SDT);
	fflush(stdin);
	cout<<"So CCCD :"<<endl;
	getline(cin,CCCD);
	fflush(stdin);
	cout<<"Dia Chi Khach Hang"<<endl;
	getline(cin,DiaChi);
	fflush(stdin);
	cout<<"Phan Loai Khach Hang ( A-B )"<<endl;
	getline(cin,Phanloai);

}
};

class ChucNang :public HangHoa, public KhachHang
{
	
	
    private:

    public:
	
	void InIF_H()
	{		
		cout<<left<<setw(15)<<MaHang<<left<<setw(30)<<TenSP<<left<<setw(30)<<SoLuong<<left<<setw(30)<<Gia<<endl;				
	}

	void InIF_K()
	{
		cout<<left<<setw(17)<<CCCD<<left<<setw(8)<<Phanloai<<left<<setw(30)<<TenKH<<left<<setw(30)<<SDT<<left<<setw(50)<<DiaChi<<endl;
	}

	void GetIF_GD ()
	{
		fflush(stdin);
		cout<<"Ho Va Ten : "; 
		    getline(cin,TenKH);
		fflush(stdin);   
		cout<<"CCCD : ";    
		    getline(cin,CCCD);    
		fflush(stdin);
		cout<<"Xep Loai :";  
		    cin>>this->Phanloai;
		fflush(stdin);
		cout<<"SDT :";      
		    cin>>this->SDT;     
		fflush(stdin);
		cout<<"Dia Chi: ";  
		    getline(cin,DiaChi);  
		fflush(stdin);
		cout<<"Ten San Pham: ";
			getline(cin,TenSP);   
		fflush(stdin);
		cout<<"Ma San Pham : ";
			cin>>this->MaHang;  
		fflush(stdin);
		cout<<"So Luong :"; 
		    cin>>this->SoLuong;
		
		    
	}

	void INIF_GD ()
	{
		cout<<left<<setw(30)<<TenKH<<left<<setw(17)<<CCCD<<left<<setw(30)<<TenSP<<left<<setw(30)<<left<<setw(10)<<SoLuong<<left<<setw(15)<<SoLuong*Gia<<endl;
	}

	int TongTien()
	{
		unsigned long long s;
		s=SoLuong*Gia;
		return s;
	}
};

void textcolor(WORD color) 
{
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

void gotoxy(unsigned short a, unsigned short b) 
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD menu = { a , b };
	SetConsoleCursorPosition(h, menu);
}
void TT()
{
	for (int i = 0; i < 70; i++)
	{
		cout<<"-";
	}
	cout<<endl;
}
void menu()
{
	system("cls");
	textcolor(14);
	gotoxy(50,1);
		cout<<"************************\n";
	gotoxy(50,2);
        cout<<"| 1.QUAN LY HANG HOA   |"<<endl;
	gotoxy(50,3);
	    cout<<"| 2.QUAN LY KHACH HANG |"<<endl;
	gotoxy(50,4);
	    cout<<"| 3.QUAN LY GIAO DICH  |"<<endl;
	gotoxy(50,5);
	    cout<<"| 4.QUAN LY TAI CHINH  |"<<endl;
	gotoxy(50,6);
		cout<<"************************\n";
	textcolor(7);
}
void menu1()
{	
	system("cls");
	textcolor(14);
	gotoxy(50,1);
        cout<<"| 1.NHAP THONG TIN     |"<<endl;
	gotoxy(50,2);
        cout<<"| 2.THEM HANG HOA      |"<<endl;
	gotoxy(50,3);
		cout<<"| 3.IN BANG THONG TIN  |"<<endl;
	gotoxy(50,4);
		cout<<"| 4.TIM KIEM THONG TIN |"<<endl;
	gotoxy(50,5);
		cout<<"| 5.XOA THONG TIN      |"<<endl;
	gotoxy(50,6);
		cout<<"| 6.SUA THONG TIN      |"<<endl; 
	textcolor(7);
}
void menu2()
{
	system("cls");
     textcolor(14);
	gotoxy(50,1);   
		cout<<"| 1.TIM KIEM THONG TIN |"<<endl;
	gotoxy(50,2);
 		cout<<"| 2.IN BANG THONG TIN  |"<<endl;
	gotoxy(50,3);
		cout<<"| 3.SUA THONG TIN      |"<<endl;
	textcolor(7);	

}


void menu3()
{
	system("cls");
	textcolor(14);
    gotoxy(50,1);
	   cout<<"| 1.THUC HIEN GIAO DICH |"<<endl;
	gotoxy(50,2);
	   cout<<"| 2.IN BANG GIAO DICH   |"<<endl;
	gotoxy(50,3);
	   cout<<"| 3.THEM GIAO DICH      |"<<endl;
	textcolor(7);
}

void menu4(int &s)
{
	
	for (int i = 0; i < 30; i++)
	 {
		cout<<"-";
	 }
	cout<<endl;
	textcolor(14);
	cout<<"TIEP TUC VOI MAN HINH CHINH\n";
	cout<<"1.Next\n";
	cout<<"2.Exit\n";
	cout<<"CHON : ";cin>>s;
	textcolor(7);
}
 void menu5a(int &d)
 {
	 
	 for (int i = 0; i < 30; i++)
	 {
		cout<<"-";
	 }
	 textcolor(14);
	 cout<<endl;
	 cout<<"1.Next\n";
	 cout<<"2.Exit\n";
	 cout<<"CHON : ";cin>>d;
	 textcolor(7);
 }


int CTQLBH() 
{
	ChucNang mang[1000]; // Khai bao doi tuong dung cho hang hoa hien co.

	ChucNang mang_GD[1000]; // Khai bao doi tuong dung cho viec giao dich.
	
	ChucNang mang_TT[1000];//

	
	unsigned long long s1=0,s2=0;// TONG TIEN NHAP VA BAN
//	unsigned long long chenhlec=s1-s2;
	int n; // so luong loai hang
	int tongs1=0;// tong so luong hang nhap vao
	int tongs2=0;// tong so luong hang ban ra
	int m; // so luoc khach hang giao dich
	// muc tim kiem cua hang hoa
	string msp;
	string mspp;
	string ten1;
	int sol;
	unsigned long long gi;
	int gg;
	//muc tim kiem cua khach hang

	string cc;
	string cc1;
	string name;
	string loai;
	string number;
	string dc;

	//SU DUNG TRONG DG
	string dg;
	int sldg;

/*
	cout<<"1.Quan Ly Hang Hoa"<<endl;
	cout<<"2.Quan Ly Khach Hang"<<endl;
	cout<<"3.Quan Ly Giao Dich"<<endl;
	cout<<"4.Quan Ly Tai Chinh"<<endl;
*/	
// DUNG CHO VONG LAP BAO QUAT
	int s=1;
// DUNG CHO VONG LAP CHI TIET 4 CASE
	int d=1,f=1,v=1;	
	int x,y,z,t,w,r,ra; // dung cho 4 case menu

while(s==1)
{ 	
	menu();
	do 
	{
	cout<<"CHON: "<<endl;
	cin>>x;
    }
    while( x!=1 && x!=2 && x!=3 && x!=4 );
    
    
    switch(x)
   {
   	case 1:	

/*	    cout<<"1.Nhap Thong Tin"<<endl;
		cout<<"2.Nhap them sp"<<endl;
		cout<<"3.In Bang Thong Tin"<<endl;
		cout<<"4.Tim kiem Thong Tin"<<endl;
		cout<<"5.Xoa Thong Tin"<<endl;
		cout<<"6.Sua Thong Tin"<<endl; 
*/

	  do
	  {
								
		
		menu1();

		do
	 	{
			cout<<"CHON: ";cin>>y;

		} while ( y!=1 && y!=2 && y!=3 && y!=4 && y!=5 && y!=6 );

		switch (y)
		{
		case 1:

			cout<<"NHAP SO SP: ";cin>>n;
			for (int i = 0; i < n; i++)
			{
				mang[i].GetIf_H();
			}
			for (int i = 0; i < n; i++)
			{
				mang_TT[i].SoLuong=mang[i].SoLuong;
				mang_TT[i].Gia=mang[i].Gia;
			}
			
		  break;
		case 2:
		cout<<"***THEM SAN PHAM***"<<endl;
				cout<<"SO LUONG HANG HOA THEM: ";cin>>ra;

				for (int i = n; i < n+ra; i++)
				{
					mang[i].GetIf_H();
				}
				n+=ra;
			for (int i = 0; i < n; i++)
			{
				mang_TT[i].SoLuong=mang[i].SoLuong;
				mang_TT[i].Gia=mang[i].Gia;
			}
			
		break;
		case 3:
		TT();
		cout<<"\t\t\t\t\t BANG THONG TIN HANG HOA"<<endl<<endl<<endl;

			cout<<left<<setw(15)<<"MA SO"<<left<<setw(30)<<"SAN PHAM"<<left<<setw(30)<<"SO LUONG"<<left<<setw(30)<<"DON GIA"<<endl;
			
			for (int j = 0; j < n; j++)
			{					
				mang[j].InIF_H();
			}
						
			break;
		case 4:
		TT();
			cout<<"TIM KIEM\n";

			cout<<"NHAP MA SP: \n";
			cin>>msp;
			cout<<left<<setw(15)<<"MA SO"<<left<<setw(30)<<"SAN PHAM"<<left<<setw(30)<<"SO LUONG"<<left<<setw(30)<<"DON GIA"<<endl;
			for (int l = 0; l < n; l++)
			{				
				if (msp == mang[l].MaHang )
				{
					mang[l].InIF_H();
				}
			}
			break;

		case 5:
		TT();
			cout<<"\t\t\t\t\t **XOA THONG TIN**\n";

			cout<<left<<setw(15)<<"MA SO"<<left<<setw(30)<<"SAN PHAM"<<left<<setw(30)<<"SO LUONG"<<left<<setw(30)<<"DON GIA"<<endl;			
			for (int j = 0; j < n; j++)
			{					
				mang[j].InIF_H();
			}
			cout<<"Nhap MA SO SP MUON XOA: ";cin>>msp;

			for (int h = 0; h < n; h++)
			{
				if (msp==mang[h].MaHang)	
				{
					for ( int i=h ; i < n-1 ; i++)
					{
						mang[i]=mang[i+1];
					}
				}
				
			}
			--n;
			cout<<"BANG THONG TIN SAU KHI XOA\n";
			cout<<left<<setw(15)<<"MA SO"<<left<<setw(30)<<"SAN PHAM"<<left<<setw(30)<<"SO LUONG"<<left<<setw(30)<<"DON GIA"<<endl;
			
			for (int j = 0; j < n; j++)
			{					
				mang[j].InIF_H();
			}
			
			break;

		case 6:
		TT();
			cout<<"***Sua Thong Tin***\n";
			cout<<left<<setw(15)<<"MA SO"<<left<<setw(30)<<"SAN PHAM"<<left<<setw(30)<<"SO LUONG"<<left<<setw(30)<<"DON GIA"<<endl;
			
			for (int j = 0; j < n; j++)
			{					
				mang[j].InIF_H();
			}
			cout<<"NHAP MA SP MUON THAY DOI\n";
			cin>>msp;
			for (int i = 0; i < n; i++)
			{
				if (msp==mang[i].MaHang)
				{	
					cout<<"CHON THANH PHAN MUON DOI\n";
					cout<<"1.Ma San Pham\n";
					cout<<"2.Ten San Pham\n";
					cout<<"3.Gia\n";
					cout<<"4.So luong\n";
					cout<<"CHON : ";cin>>gg;
					switch (gg)
					{
						case 1:
							cout<<"Nhap MA SP muon thay doi : ";cin>>mspp;
							mang[i].MaHang=mspp;
							cout<<"THONG TIN SAU KHI THAY DOI\n";
							cout<<left<<setw(15)<<"MA SO"<<left<<setw(30)<<"SAN PHAM"<<left<<setw(30)<<"SO LUONG"<<left<<setw(30)<<"DON GIA"<<endl;
							mang[i].InIF_H();
							break;
						case 2:
							fflush(stdin);
							cout<<"Nhap TEN SP muon thay doi : ";getline(cin,ten1);
							mang[i].TenSP=ten1;
							cout<<"THONG TIN SAU KHI THAY DOI\n";
							cout<<left<<setw(15)<<"MA SO"<<left<<setw(30)<<"SAN PHAM"<<left<<setw(30)<<"SO LUONG"<<left<<setw(30)<<"DON GIA"<<endl;
							mang[i].InIF_H();
							break;
						case 3:
							cout<<"Nhap GIA SP muon thay doi : ";cin>>gg;
							mang[i].Gia=gg;
							cout<<"THONG TIN SAU KHI THAY DOI\n";
							cout<<left<<setw(15)<<"MA SO"<<left<<setw(30)<<"SAN PHAM"<<left<<setw(30)<<"SO LUONG"<<left<<setw(30)<<"DON GIA"<<endl;
							mang[i].InIF_H();
							break;
						case 4:
							cout<<"Nhap SO LUONG SP muon thay doi : ";cin>>sol;
							mang[i].SoLuong=sol;
							cout<<"THONG TIN SAU KHI THAY DOI\n";
							cout<<left<<setw(15)<<"MA SO"<<left<<setw(30)<<"SAN PHAM"<<left<<setw(30)<<"SO LUONG"<<left<<setw(30)<<"DON GIA"<<endl;
							mang[i].InIF_H();
							break;
						default:
							break;
					}
				}
				
			}
			
			break;

		default:
			break;
		}
		menu5a(d);
	}
	while(d==1);
		
	break;

	 
   	case 2:
/*   		
		cout<<"1.Tim kiem Thong Tin"<<endl;
		cout<<"2.In Bang Thong Tin"<<endl;
		cout<<"3.Sua Thong Tin"<<endl; 
*/
					
		menu2();
		do 
		{
		cout<<"CHON : ";cin>>t;
		}
		while(t!=1 && t!=2 && t!=3);
		
		switch (t)
		{
		case 1:
		TT();
			cout<<"TIM KIEM\n";

			cout<<"NHAP CCCD CUA KH: \n";
			cin>>cc;
			cout<<left<<setw(17)<<"CCCD"<<left<<setw(8)<<"NHOM"<<left<<setw(30)<<"HO VA TEN"<<left<<setw(30)<<"SDT"<<left<<setw(50)<<"DIA CHI"<<endl;
			for (int l = 0; l < m; l++)
			{
		     
				if (cc == mang_GD[l].CCCD )
				{
					
					cout<<left<<setw(17)<<mang_GD[l].CCCD<<left<<setw(8)<<mang_GD[l].Phanloai<<left<<setw(30)<<mang_GD[l].TenKH<<left<<setw(30)<<mang_GD[l].SDT<<left<<setw(50)<<mang_GD[l].DiaChi<<endl;
				}
			}
			break;
		case 2:
		TT();
			cout<<"\t\t\t\t\t BANG THONG TIN KHACH HANG"<<endl<<endl<<endl;

			cout<<left<<setw(17)<<"CCCD"<<left<<setw(8)<<"NHOM"<<left<<setw(30)<<"HO VA TEN"<<left<<setw(30)<<"SDT"<<left<<setw(50)<<"DIA CHI"<<endl;

			for (int k = 0; k < m; k++)
			{
				mang_GD[k].InIF_K();             
			}
			break;
		case 3:
		TT();
			cout<<"**THAY DOI THONG TIN**"<<endl;
			cout<<left<<setw(17)<<"CCCD"<<left<<setw(8)<<"NHOM"<<left<<setw(30)<<"HO VA TEN"<<left<<setw(30)<<"SDT"<<left<<setw(50)<<"DIA CHI"<<endl;
			for (int k = 0; k < m; k++)
			{
				mang_GD[k].InIF_K();             
			}
			cout<<"\n";
			cout<<"NHAP CCCD KH muon thay doi\n";
			cin>>cc;
			
			for (int i = 0; i < m; i++)
			{
				if (cc==mang_GD[i].CCCD)
				{
					cout<<"CHON THANH PHAN MUON DOI\n";
					cout<<"1.CCCD \n";
					cout<<"2.LOAI KH\n";
					cout<<"3.HO & TEN\n";
					cout<<"4.SDT\n";
					cout<<"5.DIA CHI\n";
					cout<<"CHON : ";cin>>w;
					switch (w)
					{
						case 1:
							cout<<"CCCD muon doi : ";cin>>cc1;
							mang_GD[i].CCCD=cc1;
							cout<<"THONG TIN SAU KHI THAY DOI\n";
							cout<<left<<setw(17)<<"CCCD"<<left<<setw(8)<<"NHOM"<<left<<setw(30)<<"HO VA TEN"<<left<<setw(30)<<"SDT"<<left<<setw(50)<<"DIA CHI"<<endl;
							mang_GD[i].InIF_K();             							
							break;
						case 2:
							cout<<"Nhap LOAI KH muon doi : ";cin>>loai;
							mang_GD[i].Phanloai=loai;
							cout<<"THONG TIN SAU KHI THAY DOI\n";
							cout<<left<<setw(17)<<"CCCD"<<left<<setw(8)<<"NHOM"<<left<<setw(30)<<"HO VA TEN"<<left<<setw(30)<<"SDT"<<left<<setw(50)<<"DIA CHI"<<endl;
							mang_GD[i].InIF_K();
							break;
						case 3:
							cout<<"Nhap HO&TEN muon doi : ";cin>>name;
							mang_GD[i].TenKH=name;
							cout<<"THONG TIN SAU KHI THAY DOI\n";
							cout<<left<<setw(17)<<"CCCD"<<left<<setw(8)<<"NHOM"<<left<<setw(30)<<"HO VA TEN"<<left<<setw(30)<<"SDT"<<left<<setw(50)<<"DIA CHI"<<endl;
							mang_GD[i].InIF_K();
							break;
						case 4:
							cout<<"Nhap SDT muon doi : ";cin>>number;
							mang_GD[i].SDT=number;
							cout<<"THONG TIN SAU KHI THAY DOI\n";
							cout<<left<<setw(17)<<"CCCD"<<left<<setw(8)<<"NHOM"<<left<<setw(30)<<"HO VA TEN"<<left<<setw(30)<<"SDT"<<left<<setw(50)<<"DIA CHI"<<endl;
							mang_GD[i].InIF_K();
							break;
						case 5:
							cout<<"Nhap DIA CHI muon doi : ";cin>>dc;
							mang_GD[i].DiaChi=dc;
							cout<<"THONG TIN SAU KHI THAY DOI\n";
							cout<<left<<setw(17)<<"CCCD"<<left<<setw(8)<<"NHOM"<<left<<setw(30)<<"HO VA TEN"<<left<<setw(30)<<"SDT"<<left<<setw(50)<<"DIA CHI"<<endl;
							mang_GD[i].InIF_K();
							break;
						default:
							break;
					}
				}				
			}

			break;

		default:
			break;
		}
			
   	break; 
   	case 3:
/*	 
	   cout<<"1.Thuc Hien Giao Dich"<<endl;
	   cout<<"2.In Bang Giao Dich"<<endl;
	   cout<<"3.Them Giao Dich"<<endl;

*/	
	do{
		
	
		menu3();
	  do
	   {
		   cout<<"CHON: ";cin>>z;
	   }
	   while(z!=1 && z!=2 && z!=3);
	   
	   switch (z)
	   {
	  	   case 1:
			 // IN THONG TIN HANG HOA => TIM DUNG SAN PHAM CAN CHON
			 TT();
			 cout<<"\t\t\t\t\t BANG THONG TIN HANG HOA"<<endl<<endl<<endl;

			cout<<left<<setw(15)<<"MA SO"<<left<<setw(30)<<"SAN PHAM"<<left<<setw(30)<<"SO LUONG"<<left<<setw(30)<<"DON GIA"<<endl;
			
			for (int j = 0; j < n; j++)
			{
					
				mang[j].InIF_H();

			}
			// THUC HIEN GIAO DICH ( CO DIEU KIEN DE THUC HIEN )
				cout<<"SO LUOC GIAO DICH: ";cin>>m;

				for (int i = 0; i < m; i++)
				{
					mang_GD[i].GetIF_GD();
				}
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{
						if( mang_GD[i].MaHang == mang[j].MaHang)
						{
							mang_GD[i].Gia=mang[j].Gia;
						}
					}
										
				}
				
				// DIEU KIEN AP DUNG 
				// TRUONG HOP SO LUONG DAT GIOI HAN
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{
						if (  mang_GD[i].MaHang == mang[j].MaHang )
						{
							if( mang_GD[i].SoLuong > mang[j].SoLuong )
							{
								cout<<"GIAO DICH DA VUOT QUA SO LUONG GIOI HAN"<<endl;
								cout<<"GIAO DICH KHONG THANH CONG";

								--m;
							}
							
						}
						
					}
					
				}
				
				// KHI MUA HANG THI DONG THOI GIAM SO LUONG HANG DUOC MUA TRONG KHO HANG
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{
						if (  mang_GD[i].MaHang == mang[j].MaHang )
						{						
							if( mang_GD[i].SoLuong < mang[j].SoLuong )
							{
								mang[j].SoLuong=mang[j].SoLuong-mang_GD[i].SoLuong;
							}
						}
						
					}
					
				}
				
			break;	
		   case 2:
		   TT();
		   		cout<<"\t\t\t\t\t DANH SACH GIAO DICH"<<endl;

                cout<<left<<setw(30)<<"HO VA TEN"<<left<<setw(17)<<"CCCD"<<left<<setw(30)<<"MAT HANG"<<left<<setw(30)<<left<<setw(10)<<"SO LUONG"<<left<<setw(15)<<"TONG TIEN"<<endl;
				for (int i = 0; i < m; i++)
				{
					mang_GD[i].INIF_GD();
				}
	   
	       break;
		   case 3:
		   TT();
		   cout<<"\t\t\t\t\t BANG THONG TIN HANG HOA"<<endl<<endl<<endl;

			cout<<left<<setw(15)<<"MA SO"<<left<<setw(30)<<"SAN PHAM"<<left<<setw(30)<<"SO LUONG"<<left<<setw(30)<<"DON GIA"<<endl;
			
			for (int j = 0; j < n; j++)
			{					
				mang[j].InIF_H();
			}
				cout<<"SO LUOC GIAO DICH: ";cin>>r;

				for (int i = m; i < m+r; i++)
				{
					mang_GD[i].GetIF_GD();
				}
				
				for (int i = m; i < m+r; i++)
					{
						for (int j = 0; j < n; j++)
						{
							if( mang_GD[i].MaHang == mang[j].MaHang)
							{
								mang_GD[i].Gia=mang[j].Gia;
							}
						}
											
					}
				m+=r;
				//SU DUNG DIEU KIEN
				// KIEM TRA GIOI HAN SO LUONG HANG HOA
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{
						if (  mang_GD[i].MaHang == mang[j].MaHang )
						{
							if( mang_GD[i].SoLuong > mang[j].SoLuong )
							{
								cout<<"GIAO DICH DA VUOT QUA SO LUONG GIOI HAN"<<endl;
								cout<<"GIAO DICH KHONG THANH CONG";

								--m;
							}
							
						}
						
					}
					
				}
	   
	       default:
		   break;	
	   }
	   menu5a(d);
	   
   }while(d==1);
			 
   	break; 
   	case 4:
	TT();
	    cout<<"TONG SO LUONG HANG HOA NHAP VAO= ";
		for (int i = 0; i < n; i++)
		{
			tongs1+=mang_TT[i].SoLuong;
		}
		cout<<tongs1<<endl;
		cout<<"TONG SO LUONG HANG HOA BAN RA  = ";
		for (int i = 0; i < m; i++)
		{
			tongs2+=mang_GD[i].SoLuong;
		}
		cout<<tongs2<<endl;
	TT();
		cout<<"TONG TIEN NHAP VAO = ";
		   for (int i = 0; i < n; i++)
		   {
			   s1+=mang_TT[i].SoLuong*mang_TT[i].Gia;
			   
		   }
		cout<<s1;
		cout<<endl;
		cout<<"TONG TIEN BAN RA   = ";
			for (int i = 0; i < m; i++)
			{
				s2+=mang_GD[i].SoLuong*mang_GD[i].Gia;
			}
		cout<<s2<<endl;
	TT();
//		chenhlec=s2-s1;
		cout<<"CHENH LECH TIEN ="<<(s1-s2)<<endl;
	TT(); 
   	break; 
   }  
   menu4(s);
  }
    return 0;
}
int main()
{
	CTQLBH();
	return 0;
}