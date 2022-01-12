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
// petla dla kazdego wierzcholka poczatkowego szuka wierzcholka koncowego ktory jest jego sasiadem
 for(i=0;i<n;i++)
    {
         for(j=0;j<n;j++)
        {
            if(A[i][j] == 1)
            {
                cout << "sasiadem wierzcholka w" << i+1 << " jest wierzcholek w" << j+1 << endl;
            }                                  // +1 ponieważ indeksy w tablicy zaczynaja sie od 0
        }
    }
}

void sasiedzikazdego (char **A, int n)
{
    cout << "\n\n2) sasiedzi kazdego wierzcholka" << endl << "sasiadem kazdego wierzcholka sa wierzcholki :" << endl;

    int i, j, licznik = 0;
// petla dla kazdego wierzcholka sprawdza czy jest on stopniem wyjsciowym kazdego innego wierzcholka
    for(j=0;j<n;j++)
    {
         for(i=0;i<n;i++)
        {
            if(A[i][j] == 1)
            {
                licznik++;
            }
        }
        if (licznik == n-1) cout << "w" << j+1  << " "; // n-1 poniewaz dla samego siebie nie moze byc saiadem
 //       jezeli taki wierzcholek wystepuje, jego indeks zostanie wypisany na ekranie
 licznik =0;
    }

}

void stwychodzace (char **A, int n)
{
     cout << "\n\n3) stopnie wychodzace z wierzcholkow" << endl << endl;

    int i, j, licznik = 0;
// petla zlicza ile razy dany wierzcholek jest wiercholkiem poczatkowym
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

void stwchodzace (char **A, int n)
{
    cout << "\n\n4) stopnie wchodzace wierzcholkow" << endl << endl;

    int i, j, licznik = 0;
//petla zlicza ile razy dany wierzcholek jest wierzcholkiem koncowym
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

void wizolowane (char **A, int n)
{
    //wierzcholek stopnia 0, to znaczy wierzcholek niebedacy koncem zadnej krawedzi grafu

    cout << "\n\n5) Wierzcholki izolowane :" << endl;
    int i, j, k, licznik = 0, tab[n];
// ta funkcja sprawdza czy dla wierzcholka o danym indeksie odpowiadajacy mu rzad oraz kolumna
// macierzy zawieraja tylko 0

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
// tworze pomocnicza tabele aby zapisac kandydatow na wierzcholek izolowany

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

        if (licznik == 0 && tab [j] == 1) // sprawdzam czy wiersz i kolumna w macierzy to zera
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

    //sprawcza czy na przekatnej macierzy jest wartosc 1
    //to oznacza ze znalazlem petle bo w1 i w2 maja ta sama wartosc

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
            if(A[i][j] == 1 && A[j][i] == 1 && i!=j) cout << "krawedz dwukierunkowa miedzy wierzcholkami w" << i+1 << " oraz w" << j+1 << endl;


}
int main( )
{

  int n, m, i, j, w1, w2;
  char ** A;

    // Start odmierzania czasu
    double begin = get_cpu_time();


  cout << "podaj liczbe wierzcholkow, a nastepnie liczbe krawedzi grafu " << endl;
  cin >> n;

  //zabezpieczam zeby nie wpisywac ujemnych wartosci
  while (n<1)      // wczytuje liczbe wierzcholkow i krawedzi
  {
      cout << "\n\n\npodaj dodatnia liczbe wierzcholkow   --> ";
      cin >> n;
  }

  cin >> m;
  while (m<0)
  {
      cout << "\n podaj dodatnia liczbe wierzcholkow   --> ";
      cin >> m;
  }



  A = new char * [ n ];    // tworze tablice wskaznikow

  for( i = 0; i < n; i++ )    // tworze wiersze macierzy
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
        while (w2 < 0 || w2 >n-1)   // zabezpieczenie przed wpisaniem indeksu ujemnego lub wiekszego od liczby wierzcholkow
        {
            cout << "niepoprawna wartosc, wprowadz wprowadz wartosc z zakresu <0," << n-1 << ">    --> ";
            cin >> w2;
        }


   // zabezpieczam przed dublowaniem krawedzi oraz wartosciami ujemnymi i wiekszymi od liczby wierzcholkow
    while(A[w1][w2] == 1)
    {
        cout << "taka krawedz juz istnieje, wprowadz inne wartosci" << endl;
        cin >> w1;
        while (w1 < 0 || w1 > n-1 )
        {
            cout << "niepoprawna wartosc, wprowadz jeszcze raz:" << endl;
            cout << "--> ";
            cin >> w1;
        }




        cin >> w2;
        while (w2 < 0 || w2 >n-1)
        {
            cout << "niepoprawna wartosc, wprowadz jeszcze raz:" << endl;
            cout  << "--> ";
            cin >> w2;
        }
    }
    A [ w1 ][ w2 ] = 1; // tworze krawedz w1 --> w2
  }

  cout << endl;

  // ewentualnie wypisuje zawartosc macierzy sasiedztwa, ale to znacznie wydluza dzialanie programu

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

  // kolejno wywoluje funkcje

      sasiedzi(A, n);

      sasiedzikazdego (A, n);

      stwychodzace(A, n);

      stwchodzace(A, n);

      wizolowane(A, n);

      petle(A,n);

      krdwukierunkowe(A,n);


  cout << endl << endl;
// Stop  mierzenia i podliczenie czasu
    double end = get_cpu_time();
    double elapsed = (end - begin);

    printf("Zmierzony czas: %.3f seconds.\n", elapsed);

  return 0; //0.859 0.891
}
