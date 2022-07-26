#include <iostream>
using namespace std;
#include <iomanip>
#include <string>
int main()
{
    string ma="GH";
    string ten="CHOCOLATE";
    int soluong=100;
    int dongia=100000;

 /*   getline(cin,ma);
    getline(cin,ten);
    cin>>soluong>>dongia;
*/
    cout<<left<<setw(15)<<"Ma So"<<left<<setw(30)<<"Ten San Pham"<<left<<setw(30)<<"So Luong"<<left<<setw(30)<<"Don Gia"<<endl;
    cout<<left<<setw(15)<<ma<<left<<setw(30)<<ten<<left<<setw(30)<<soluong<<left<<setw(30)<<dongia<<endl;

    return 0;
}