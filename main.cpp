#include <iostream>
#include <iomanip>

using namespace std;
int  licznik = 0;
void sasiedzi()
{
    int n, m, i, j, w1, w2;
    char ** A;

    for(i=0;i<n;i++)
    {
         for(j=0;j<n;j++)
        {
            if(A[w1][w2] == 1)
            {
                licznik++;
                cout << "sasiadem wierzcholka w" << i << " jest wierzcholek w" << j << endl;
            }
        }

    }




  //  return licznik;
}











int main( )
{
  int n, m, i, j, w1, w2;
  char ** A;


  cout << "podaj liczbe wierzcholkow, a nastepnie liczbe krawedzi grafu " << endl;
  cin >> n >> m;         // Czytamy liczbe wierzcholkow i krawedzi

  A = new char * [ n ];  // Tworzymy tablice wskaznikow

  for( i = 0; i < n; i++ )
    A [ i ] = new char [ n ]; // Tworzymy wiersze

  // Macierz wypelniamy zerami

  for( i = 0; i < n; i++ )
    for( j = 0; j < n; j++ ) A [ i ][ j ] = 0;

  // Odczytujemy kolejne definicje krawedzi
cout << " indeksy wierzcholkow przy wprowadzaniu zaczynaja sie od 0" << endl;
  for( i = 0; i < m; i++ )
  {
    cout << "podaj poczatkowy i koncowy wierzcholek krawedzi " << i+1 << endl;
    cin >> w1 >> w2;    // Wierzcholek startowy i koncowy krawedzi
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

  cout << "1) sasiedzi wierzcholkow :" << endl;
sasiedzi();
 for(i=0;i<n;i++)
    {
         for(j=0;j<n;j++)
        {
            if(A[i][j] == 1)
            {
              //  licznik++;
                cout << "sasiadem wierzcholka w" << i+1 << " jest wierzcholek w" << j+1 << endl;
            }
        }

    }

licznik =0;
    cout << "\n\n2) sasiedzi kazdego wierzcholka" << endl << "sasiadem kazdego wierzcholka sa wierzcholki :" << endl;

    for(j=0;j<n;j++)
    {
         for(i=0;i<n;i++)
        {
            if(A[i][j] == 1)
            {
                licznik++;
            }
        }
        if (licznik == n-1) cout << "w" << j+1  << " ";
 //       else cout << "nie ma takiego wierzcholka";
        licznik = 0;
    }

  return 0;
}
