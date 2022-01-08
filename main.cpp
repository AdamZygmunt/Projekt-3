#include <iostream>
#include <iomanip>

using namespace std;



int main( )
{
  int n, m, i, j, v1, v2;
  char ** A;


  cout << "podaj liczbe wierzcholkow, a nastepnie liczbe krawedzi grafu " << endl;
  cin >> n >> m;         // Czytamy liczb� wierzcho�k�w i kraw�dzi

  A = new char * [ n ];  // Tworzymy tablic� wska�nik�w

  for( i = 0; i < n; i++ )
    A [ i ] = new char [ n ]; // Tworzymy wiersze

  // Macierz wype�niamy zerami

  for( i = 0; i < n; i++ )
    for( j = 0; j < n; j++ ) A [ i ][ j ] = 0;

  // Odczytujemy kolejne definicje kraw�dzi

  for( i = 0; i < m; i++ )
  {
    cout << "podaj poczatkowy i koncowy wierzcholek krawedzi " << i+1 << endl;
    cin >> v1 >> v2;    // Wierzcho�ek startowy i ko�cowy kraw�dzi
    A [ v1 ][ v2 ] = 1; // Kraw�d� v1->v2 obecna
  }

  cout << endl;

  // Wypisujemy zawarto�� macierzy s�siedztwa

  cout << "   ";
  for( i = 0; i < n; i++ ) cout << setw ( 3 ) << i;
  cout << endl << endl;
  for( i = 0; i < n; i++ )
  {
    cout << setw ( 3 ) << i;
    for( j = 0; j < n; j++ ) cout << setw ( 3 ) << ( int ) A [ i ][ j ];
    cout << endl;
  }

  // Usuwamy macierz

  //for( i = 0; i < n; i++ ) delete [ ] A [ i ];
  //delete [ ] A;

  cout << endl;

  return 0;
}
