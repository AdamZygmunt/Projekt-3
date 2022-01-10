#include <iostream>
#include <iomanip>

using namespace std;

void sasiedzi(char **A, int n, int m)
{
    int  i, j;


    cout << "1) sasiedzi wierzcholkow :" << endl;

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
}

void sasiedzikazdego (char **A, int n, int m)
{
    cout << "\n\n2) sasiedzi kazdego wierzcholka" << endl << "sasiadem kazdego wierzcholka sa wierzcholki :" << endl;

    int i, j, licznik = 0;

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
 licznik =0;
    }

}


void stwychodzace (char **A, int n, int m)
{
     cout << "\n\n3) stopnie wychodzace z wierzcholkow" << endl << endl;

    int i, j, licznik = 0;

    for(i=0;i<n;i++)
    {
         for(j=0;j<n;j++)
        {
            if(A[i][j] == 1)
            {
                licznik++;
            }

        }
        cout << "wierzcholek w" << i+1 << " ma " << licznik << " stopni wychodzacych"<< endl;
            licznik = 0;

    }
}

void stwchodzace (char **A, int n, int m)
{
    cout << "\n\n4) stopnie wchodzace wierzcholkow" << endl << endl;

    int i, j, licznik = 0;

    for(j=0;j<n;j++)
    {
         for(i=0;i<n;i++)
        {
            if(A[i][j] == 1)
            {
                licznik++;
            }
        }

        cout << "wierzcholek w" << j+1 << " ma " << licznik << " stopni wchodzacych" << endl;
        licznik = 0;
    }
}

void wizolowane (char **A, int n, int m)
{
    //wierzcho³ek stopnia 0, to znaczy wierzcho³ek niebêd¹cy koñcem ¿adnej krawêdzi grafu

    cout << "\n\n5) Wierzcholki izolowane :" << endl;
    int i, j, k, licznik = 0, tab[n];



    for(i=0;i<n;i++)
    {
         for(j=0;j<n;j++)
        {
            if(A[i][j] == 1)
            {
                licznik++;
            }

        }
        if (licznik == 0) tab[i] = 1; else tab[i] = 0;
            licznik = 0;
// cout << tab[i] << " ";

    }

for(j=0;j<n;j++)
    {
         for(i=0;i<n;i++)
        {
            if(A[i][j] == 1)
            {
                licznik++;
            }
        }

        if (licznik == 0 && tab [j] == 1)
        {
                cout << "wierzcholek w" << j+1 << " jest wierzcholkiem izolowanym " << endl;
        }
            licznik = 0;

    }
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

  sasiedzi(A, n, m);

  sasiedzikazdego (A, n, m);

  stwychodzace(A, n, m);

  stwchodzace(A, n, m);

  wizolowane(A, n, m);





  return 0;
}
