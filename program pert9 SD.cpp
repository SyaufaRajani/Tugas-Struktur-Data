#include<iostream>
#include<cstdlib> 
using namespace std;

struct SIMPUL{ 
int INFO; 
struct SIMPUL *LINK; 
}; 

SIMPUL *P,*FIRST,*LAST; 

void BUAT_SIMPUL(int x) {
	P= new SIMPUL;
	if (P != NULL)
		P->INFO = x;
	else
		cout<<"Pembuatan Simpul Gagal"<< endl;
}

int main(){
	int x;
	cout<<"Masukkan Data:";
	cin >> x;
	
	BUAT_SIMPUL(x);
	cout<<"Data" << P->INFO << endl;
	
	delete P;
	return 0;
	
}

