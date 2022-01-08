#include <iostream>
#include <iomanip>

using namespace std;



int main( )
{
  int n, m, i, j, w1, w2;
  char ** A;


  cout << "podaj liczbe wierzcholkow, a nastepnie liczbe krawedzi grafu " << endl;
  cin >> n >> m;         // Czytamy liczbê wierzcholków i krawedzi

  A = new char * [ n ];  // Tworzymy tablicê wskaŸników

  for( i = 0; i < n; i++ )
    A [ i ] = new char [ n ]; // Tworzymy wiersze

  // Macierz wype³niamy zerami

  for( i = 0; i < n; i++ )
    for( j = 0; j < n; j++ ) A [ i ][ j ] = 0;

  // Odczytujemy kolejne definicje krawêdzi

  for( i = 0; i < m; i++ )
  {
    cout << "podaj poczatkowy i koncowy wierzcholek krawedzi " << i+1 << endl;
    cin >> w1 >> w2;    // Wierzcholek startowy i koncowy krawêdzi
    A [ w1 ][ w2 ] = 1; // Krawedz w1->w2 obecna
  }

  cout << endl;

  // Wypisujemy zawartosc macierzy sasiedztwa

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
