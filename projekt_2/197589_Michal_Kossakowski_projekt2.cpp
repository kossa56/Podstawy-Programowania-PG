#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>

//Micha³ Kossakowski 197589 ACiR Gr2 sem1 Projekt 2 
using namespace std;

void powitanie ();
void menu ();
void wybor_pliku();
void logo();
void zapisz_do_struktur(char nazwa[]);
void generuj_wykres(int licznik);
void zapisz_do_pliku(char nazwa[]);
double min(int licznik);
double max(int licznik);

char wykres[60][300];
double skala_wartosci[60];

struct data
{
	int dzien;
	int miesiac;
	int rok;
};
struct swieca
{
	double open;
	double close;
	double high;
	double low;
	double volume;
	data d;
};

const int N= 10000;
swieca swiece[N];

int main ()
{
	
	powitanie();
	menu();
	
return 0;
}

void powitanie() 
{
	
	cout << "  __  __ _      _           _   _  __                   _                     _    _  " << endl;
    cout << " |  \\/  (_) ___| |__   __ _| | | |/ /___  ___ ___  __ _| | _______      _____| | _(_) " << endl;
    cout << " | |\\/| | |/ __| '_ \\ / _` | | | ' // _ \\/ __/ __|/ _` | |/ / _ \\ \\ /\\ / / __| |/ / | " << endl;
    cout << " | |  | | | (__| | | | (_| | | | . \\ (_) \\__ \\__ \\ (_| |   < (_) \\ V  V /\\__ \\   <| | " << endl;
    cout << " |_| _|_|_|\\___|_| |_|\\__,_|_| |_|\\_\\___/|___/___/\\__,_|_|\\_\\___/ \\_/\\_/ |___/_|\\_\\_| " << endl;
    cout << " / |/ _ \\___  | ___| ( _ )/ _ \\                                                       " << endl;
   	cout << " | | (_) | / /|___ \\ / _ \\ (_) |                                                      " << endl;
    cout << " | |\\__, |/ /  ___) | (_) \\__, |                                                      " << endl;
    cout << " |_|  /_//_/  |____/ \\___/  /_/                                                       " << endl;
	
	Sleep(4000);


}
void menu ()
{

	while (true)
	{
		system("cls");
		
		cout << " 	  	 	 _____ _____ _____ _____    _____ __    _____ _ _ _ _____ _____ " << endl;
	    cout << " 			|     |   __|   | |  |  |  |   __|  |  |     | | | |   | |   __|" << endl;
	    cout << " 			| | | |   __| | | |  |  |  |  |  |  |__|  |  | | | | | | |   __|" << endl;
	    cout << " 			|_|_|_|_____|_|___|_____|  |_____|_____|_____|_____|_|___|_____|" << endl;
	    
	    cout << endl;
		
		cout << "			          __      __          _         _   ___ _ _ _   " << endl;
	    cout << "			  __ _    \\ \\    / /_ ____  _| |_ __ _ (_) | _ \\ (_) |__" << endl;
	    cout << "			 / _` |_   \\ \\/\\/ / _|_ / || |  _/ _` || | |  _/ | | / /" << endl;
	    cout << "			 \\__, (_)   \\_/\\_/\\__/__|\\_, |\\__\\__,_|/ | |_| |_|_|_\\_\\" << endl;
	    cout << "			 |___/                   |__/        |__/                " << endl;
		
		cout << endl;
		
		cout << "		   		             __      __     _    _    " << endl;
	    cout << "				     __ _    \\ \\    / /  _ (_)__| |___" << endl;
	    cout << "				    / _` |_   \\ \\/\\/ / || || / _` |_ /" << endl;
	    cout << "				    \\__, (_)   \\_/\\_/ \\_, |/ \\__,_/__|" << endl;
	    cout << "				       |_|             |__/__/         " << endl;
	
	 	cout << endl;
			
		cout << "Twoj wybor: ";
		char a = cin.get();
			
		cout << endl;
	
		if (a == 'g'){
			wybor_pliku();
		} 
		else if (a == 'q'){
			exit(0);
		}	
		else if (a == '&'){
			logo ();
		} 

	}
}

void logo ()
{
	system("cls");
	
 	cout << "                                                    ,&(                                                                                /&, " << endl;
    cout << "                                                   ,&&&&&(.%(*.                                                                .*(# /&&&&&*   " << endl;
    cout << "                                                (&&/*&(   ,%/ /&/         (%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%         *&(.,%*   /&,*&&#. " << endl;
    cout << "                                           ,#&%, .#&&(     /#%&,         (&,                                     &%          %&#(.    /&&#. ,#&%,   " << endl;
    cout << "                                            */ ,%&#.,&#,  /%*          #&(%&, #&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&. &&(&#          ,%/  ,%&,.#&&* **    " << endl;
    cout << "                                            /  (  *&&%.*%&&(%&%       (&/ (&, #&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&. %% *&#.     .&&&(&&&/ #&&/  *  (,    " << endl;
    cout << "                                            ,&&*.#/  /&&(  .(&&%*(%&%/.   (&, #&&&&&(//(#&&&&&(/&&&&*(% ,&/*&&&&. &%   ./%&%(*#&&#,  /&&(  *# *&&,          " << endl;
    cout << "                                    ,%&&&*   .#&%*%%*          /&(   .(&&&&, #&&&&&./&&* %&&&*,&&&&* .  . (&&&&. %&&&#.   #&/          *%%,%&#,   ,%&&%*    " << endl;
    cout << "                                  (&#.  .%&,  . .%&%,          ,&(.%&%,..(&, #&&&&&....*%&&&&*,&&&&&&&&&&&&&&&&. %%  .%&&,(&.          ,%&%,    .%&,   (&(   " << endl;
    cout << "                                   *&&&/ .&#   %&.             ,&&#   %&*,,  #&&&&&./&&&&&&&&*,&&&&&&% ,&&&&&&&. %&(,..,(%&&&&%%(  (&&/        &&&&/&(       " << endl;
    cout << "                                        #&%*    %%        *&%.   ,,*(#%&*     #&&&&&&&&&&&&&&&*,&&&&%., .**&&&&&.   .&%/%&&(,   .%&*        (&,   *&&#.        " << endl;
    cout << "                                       (&,  .(&%*        ,#&&&.          .#&, #&&&&&* . .%&&&&*,&&&&&&%((&&&&&&&. ..  /.        %&&%,        *%&#.  ,&(         " << endl;
    cout << "                                       (&/%&&&*       *&&#. #%%&&&&&&&%%%/#&, #&&&&/.&&%%%&&&&*,&&&&&&%/(&&&&&&&. %&(,..,(%&&&&%%(  (&&/        &&&&/&(         " << endl;
    cout << "                                        *#  (&*    (&&/ /&&&(             (&, #&&&&/.&&&,.&&&&*,&&&&%     ,&&&&&. %% .,,         /%&&(.*&&(     &%  (/           " << endl;
    cout << "                                            (&,    #&.      ./%&#         (&, #&&&&&%(//#&&&&&*,&&&&&&% ,&&&&&&&. %%         %%    #&&% .&#   &&&&&&&(           " << endl;
    cout << "                                       /&&&&&&&,  #&. &&&#   .&%         (&, #&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&. %%         %%    #&.  .&#         .&&*           " << endl;
    cout << "                                     *&%          #&.  ,&(   .&%         (&,  .(%&&&&&&&&&&&&&&&&&&&&&&&&&&&(,   &%         %%    #&.  .&#         .&&*         " << endl;
    cout << "                                     *&#   *&&&&&&&&. #&#    %&*          .(&&&%(.  .*#&&&&&&&&&&&&&&#*.  ./%&&&(,          ,&&.   /&# .@&&&&&&&*   #&*         " << endl;
    cout << "                                        %&.  .%&,..    .&%.  .&%...              .*#&&%(*   ,/%%(,   *(%&&#*.              ...#&*   #&*    ...%&,   %&,          " << endl;
    cout << "                                         %&,   ***&&.   .&&.   ***&%                    ,(%&&%/*%&&%(,                    (&(**   .&%     #&/**   ,&%            " << endl;
    cout << "                                          (&(,,,,,*&&     (&(,,,,,/&%                                                   .&&*,,,,,*&%    .&&,,,,,,/&#              " << endl;
    cout << "                                           ..........      ..........                                                    ..........      ..........               " << endl;
    cout << "                                                                                                                                                                  " << endl;
    cout << "                                                                                                                                                                  " << endl;
    cout << "                              ,&&&&&&&*   ,&&&&&&&(   /&%       /&% ,&&&&&&&&&&/ #&&&&&&%   ,&&&&&&&, .&&*     &&(  (&&&.    (&#  /&%   &&*   /&&#     (&&&       " << endl;
    cout << "                              ,&&,  .&&( #&&.    ,&&* /&%       /&%     .&&*     #&%       #&%     ,  .&&*     &&(  (&#&&*   (&#  /&%   &&* /&&(      *&%*&&.     " << endl;
    cout << "                              ,&&,  ,&&( %&#      %&* /&%       /&%     .&&*     #&&####,  %&#        .&&(*****&&(  (&/ #&(  (&#  /&%   &&&&&(       .&&* (&#     " << endl;
    cout << "                               ,&&%%%#/   %&%      %&* /&%       /&%     .&&*     #&%       %&#        .&&(,,,,*&&(  (&/  (&&.(&#  /&%   &&*.&&#     .&&#*,*&&(    " << endl;
    cout << "                              ,&&,       (&&*    #&&, /&%       /&%     .&&*     #&%       (&&,    /, .&&*     &&(  (&/   *&&%&#  /&%   &&*  /&&(   #&#    .&&*       " << endl;
    cout << "                              .%%,         *#%&&%(,   /%%%%%%#/ *%#     .%%,     (%%%%%%%*   *#%&%#/. .%%*     #%/  /%/     #%%(  *%#   #%,    #%%*/%%.     *%#       " << endl;
    cout << "                                                                                                                                                                      " << endl;
    cout << "                                                                                              .&#                                                                    " << endl;
    cout << "                                                    *&&&%%&&&#  /&&&&&&&&/     #&&&/     %&&&,    #&/  *&&&%%&&&* .&&*  .&&&,     (&&&/                              " << endl;
    cout << "                                                   .&&,         /&%    .&&*   /&# &&*    %&,#&(   #&/ .&&#        .&&*.%&&,      /&&,&&,                           " << endl;
    cout << "                                                   .&&,  %%%%&, /&%     &&*  ,&&, *&%    %&, #&%  #&/   /%&&&&#,  .&&&&&(       *&&  *&&.                           " << endl;
    cout << "                                                   .&&,    .&&, /&%     &&* ,&&&&&&&&&   %&,  *&& #&/         #&% .&&* #&&/     &&&&&&&&%                           " << endl;
    cout << "                                                    #&&#/*/%&&, /&&(((%&&#  %&(     #&(  %&,    %&&&/ ,&&&#//#&&( .&&*  .&&&* .&&#     &&#                           " << endl;
    cout << "                                                       ,**,.    .,,,,..    .,,       ,,  .,      ,,,.     ,,,,     ,,     .,,..,.       ,,                           " << endl;

    Sleep(5560);
}   	
void wybor_pliku()
{	
	system ("cls");
	char nazwaPliku[100]; 

  
    cout << "Podaj nazwe pliku do wczytania: ";
  	cin >> nazwaPliku;							
	zapisz_do_struktur(nazwaPliku);
	cout << "Podaj nazwe pliku do zapisania: ";
	cin >> nazwaPliku;
	zapisz_do_pliku(nazwaPliku);
	cout << "Wykres zostal wygenerowany w pliku: " << nazwaPliku << endl;
	system("PAUSE");
			
}

void zapisz_do_struktur(char nazwa[])
{
	
	 ifstream plik(nazwa);
	if (!plik.is_open()) 
	{
        cout  << "Nie mozna otworzyc pliku: " << nazwa << endl;
        
    }

	 char znak;
	 int licznik = 0;
	
	 for (int i = 0; i < 31; i++)
	 {
	 	plik >> znak;
	 }
	
	 for (int i = 0; plik >> swiece[i].d.rok; i++)
	 {
	 	plik >> znak;
	 	plik >> swiece[i].d.miesiac;
	 	plik >> znak;
	 	plik >> swiece[i].d.dzien;
	 	plik >> znak;
	 	plik >> swiece[i].open;
	 	plik >> znak;
	 	plik >> swiece[i].high;
	 	plik >> znak;
	 	plik >> swiece[i].low;
	 	plik >> znak;
	 	plik >> swiece[i].close;
	 	plik >> znak;
	 	plik >> swiece[i].volume;
	 	
	 	licznik ++;
	 	
	 }
	 
	 plik.close();
	 generuj_wykres(licznik);
    
}

void generuj_wykres(int licznik)
{
	int liczba = licznik;
	if (licznik > 200) liczba = liczba - 200;
	
	wykres[0][1] = 94;
	wykres [50][200] =  62;
	
	for (int wiersze = 0; wiersze < 51; wiersze++)
	{
		for (int kolumny = 0; kolumny < 201; kolumny++)
		{
			if (kolumny == 1 && wiersze != 0 && wiersze !=50) wykres[wiersze][kolumny] = '|';
			if (wiersze == 50 && kolumny != 0 && kolumny != 200) wykres[wiersze][kolumny] = '_';
		}
	}
	
	double MIN, MAX;
	
	MIN = min (licznik);
	MAX = max(licznik);
	
	double skala = (MAX - MIN)/49;
	skala_wartosci[0] = MAX;
	
	for (int i = 0; i < 49; i++)
	 {
		skala_wartosci[i + 1] = skala_wartosci[i] - skala;
	 }

	int i = liczba;

	for (int kolumny = 2; i < licznik; kolumny++)
	{
		for (int wiersze  = 0; wiersze < 49; wiersze++)
		{
			if (swiece[i].high <= skala_wartosci[wiersze] && swiece[i].high >= skala_wartosci[wiersze + 1])
			{
				if ((swiece[i].open < swiece[i].close))
				{
				
					while(!((swiece[i].close <= skala_wartosci[wiersze]) && (swiece[i].close >= skala_wartosci[wiersze + 1] )))
					{
						wykres[wiersze][kolumny] = '|';
						wiersze++;
					}
				}
				else if (swiece[i].open > swiece[i].close)
				{
					while(!((swiece[i].open <= skala_wartosci[wiersze]) && (swiece[i].open >= skala_wartosci[wiersze + 1])))
					{
						wykres[wiersze][kolumny] = '|';
						wiersze++;
					}
				}	
			} 
			
			if((swiece[i].open < swiece[i].close) && (swiece[i].close <= skala_wartosci[wiersze] && swiece[i].close >= skala_wartosci[wiersze + 1] ))
			{
				while (!((swiece[i].open <= skala_wartosci[wiersze]) && (swiece[i].open >= skala_wartosci[wiersze + 1] )))
				{
					wykres[wiersze][kolumny] = 'O';
					wiersze++;
				}
				
			} 
			 if((swiece[i].open > swiece[i].close) && (swiece[i].open <= skala_wartosci[wiersze] && swiece[i].open >= skala_wartosci[wiersze + 1] ))
			{
				while(!((swiece[i].close <= skala_wartosci[wiersze]) && (swiece[i].close >= skala_wartosci[wiersze + 1])))
				{
					wykres[wiersze][kolumny] = '#';
					wiersze++;
				}
				
			}
			 if ((swiece[i].open > swiece[i].close) && (swiece[i].close <= skala_wartosci[wiersze] && swiece[i].close >= skala_wartosci[wiersze + 1] ))
			{
				while(!((swiece[i].low <= skala_wartosci[wiersze]) && (swiece[i].low >= skala_wartosci[wiersze + 1])))
				{
					wykres[wiersze][kolumny] = '|';
					wiersze++;
				}
			}
			else if ((swiece[i].open < swiece[i].close) &&  (swiece[i].open <= skala_wartosci[wiersze] && swiece[i].open >= skala_wartosci[wiersze + 1] ))
			{
				
				while( !((swiece[i].low <= skala_wartosci[wiersze]) && (swiece[i].low >= skala_wartosci[wiersze + 1])))
				{
					wykres[wiersze][kolumny] = '|';
					wiersze++;
				}
			}
		
			else wykres[wiersze][kolumny] = ' ';
		}
		i++;
	}
	
	
}

void zapisz_do_pliku(char nazwa[])
{
	
	ofstream plik(nazwa);
	
	if (!plik.is_open()) 
	{
        cout  << "ERROR" << nazwa << endl;
        
    }
    
    for (int wiersze = 0; wiersze < 51; wiersze++)
	{
		for (int kolumny = 0; kolumny < 201; kolumny++)
		{
			plik << wykres[wiersze][kolumny];
		}
		plik << endl;
	}
	plik.close();
    
}

double min(int licznik){
	
	double MIN = swiece[licznik - 200].close;
	
	for (int i = licznik - 200; i < licznik; i++)
	{
		if (swiece[i].close < MIN) MIN = swiece[i].close;
		else if (swiece[i].high < MIN) MIN = swiece[i].high;
		else if (swiece[i].low < MIN) MIN = swiece[i].low;
		else if (swiece[i].open < MIN) MIN = swiece[i].open;
	}
	
	return MIN;
	
}

double max(int licznik){
	
	double MAX = 0;
	
	for (int i = licznik - 200; i < licznik; i++)
	{
		if (swiece[i].close > MAX) MAX = swiece[i].close;
		else if (swiece[i].high > MAX) MAX = swiece[i].high;
		else if (swiece[i].low > MAX) MAX = swiece[i].low;
		else if (swiece[i].open > MAX) MAX = swiece[i].open;
	}
	
	return MAX;
	
}











