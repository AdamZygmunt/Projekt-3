#include <iostream>
#include <iomanip>
#include <processthreadsapi.h>
#include <stdio.h>

using namespace std;

double get_cpu_time(){
    FILETIME a,b,c,d;
    if (GetProcessTimes(GetCurrentProcess(),&a,&b,&c,&d) != 0){
        //  Returns total user time.
        //  Can be tweaked to include kernel times as well.
        return
            (double)(d.dwLowDateTime |
            ((unsigned long long)d.dwHighDateTime << 32)) * 0.0000001;
    }else{
        //  Handle error
        return 0;
    }
}

void sasiedzi(char **A, int n)
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

void petle (char **A, int n)
{
    cout << "\n\n6) Wszystkie petle:" << endl;
    int i;
    for(i=0; i<n; i++)
    {
        if (A[i][i] == 1) cout << "petla wierzcholka w" << i+1 << endl;
    }
}

void krdwukierunkowe (char **A, int n)
{
    cout << "\n\n7) Krawedzie dwukierunkowe: " << endl;
    int i, j;

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            if(A[i][j] == 1 && A[j][i] == 1 && i!=j) cout << "krawedz dwukierunkowa miedzy wierzcholkami w" << i << " oraz w" << j << endl;


}
int main( )
{

  int n, m, i, j, w1, w2;
  char ** A;

    // Start measuring time
    double begin = get_cpu_time();


  cout << "podaj liczbe wierzcholkow, a nastepnie liczbe krawedzi grafu " << endl;
  cin >> n;
  while (n<1)                                   // wczytuje liczbe wierzcholkow i krawedzi
  {
      cout << "\n podaj dodatnia liczbe wierzcholkow   --> ";
      cin >> n;
  }

  cin >> m;
  while (m<0)
  {
      cout << "\n podaj dodatnia liczbe wierzcholkow   --> ";
      cin >> m;
  }



  A = new char * [ n ];    // tworze tablice wskaznikow

  for( i = 0; i < n; i++ )    // tworze wiersze
    A [ i ] = new char [ n ];

  // macierz wypelniam zerami

  for( i = 0; i < n; i++ )
    for( j = 0; j < n; j++ ) A [ i ][ j ] = 0;

  // Odczytujemy kolejne definicje krawedzi
cout << " indeksy wierzcholkow przy wprowadzaniu zaczynaja sie od 0" << endl << endl;
  for( i = 0; i < m; i++ )
  {
    cout << "podaj poczatkowy i koncowy wierzcholek krawedzi " << i+1 << endl;

// wierzcholek startowy i koncowy krawedzi


        cin >> w1;
        while (w1 < 0 || w1 > n-1 )  // zabaezpieczenie przed wpisaniem indeksu ujemnego lub wiekszego od liczby wierzcholkow
        {
            cout << "niepoprawna wartosc, wprowadz wartosc z zakresu <0," << n-1 << ">    --> ";
            cin >> w1;
        }




        cin >> w2;
        while (w2 < 0 || w2 >n-1)   // zabaezpieczenie przed wpisaniem indeksu ujemnego lub wiekszego od liczby wierzcholkow
        {
            cout << "niepoprawna wartosc, wprowadz wprowadz wartosc z zakresu <0," << n-1 << ">    --> ";
            cin >> w2;
        }
while(A[w1][w2] == 1)
    {
        cout << "taka krawedz juz istnieje, wprowadz inne wartosci" << endl;
        cin >> w1;
        while (w1 < 0 || w1 > n-1 )
        {
            cout << "niepoprawna wartosc, wprowadz jeszcze raz:    --> ";
            cin >> w1;
        }




        cin >> w2;
        while (w2 < 0 || w2 >n-1)
        {
            cout << "niepoprawna wartosc, wprowadz jeszcze raz:    --> ";
            cin >> w2;
        }
    }
    A [ w1 ][ w2 ] = 1; // Krawedz w1->w2 obecna
  }

  cout << endl;

  // Wypisujemy zawartosc macierzy sasiedztwa

 /* cout << "   ";
  for( i = 0; i < n; i++ ) cout << setw ( 3 ) << i;
  cout << endl << endl;
  for( i = 0; i < n; i++ )
  {
    cout << setw ( 3 ) << i;
    for( j = 0; j < n; j++ ) cout << setw ( 3 ) << ( int ) A [ i ][ j ];
    cout << endl;
  }
*/

  cout << endl;

  sasiedzi(A, n);

  sasiedzikazdego (A, n, m);

  stwychodzace(A, n, m);

  stwchodzace(A, n, m);

  wizolowane(A, n, m);

  petle(A,n);

  krdwukierunkowe(A,n);

// Stop measuring time and calculate the elapsed time
    double end = get_cpu_time();
    double elapsed = (end - begin);

    printf("Time measured: %.3f seconds.\n", elapsed);

  return 0;
}
