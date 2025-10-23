// Program C++ untuk mencetak elemen a
// Array dua dimensi 
#include<iostream> 
using namespace std; 
int main() 
{ 
 // array dengan 4 baris dan 3 kolom. 
 int x[4][3] = {{0,1,2}, {3,4,5}, {6,7,8},{9,10,11}}; 
 // // keluarkan nilai setiap elemen array 
 for ( int i = 0; i < 4; i++) 
 { 
 for ( int j = 0; j < 3; j++) 
 {
 	cout << "Elemen di x[" << i 
 << "][" << j << "]: " ; 
 cout << x[i][j]<<endl; 
 } 
 } 
 return 0; 
}
