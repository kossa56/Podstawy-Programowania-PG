#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>
//Micha³ Kossakowski 197589 ACiR Gr2 sem1 Projekt 1 gra BLACKBOX
using namespace std;

char plansza[14][15][15];
char kalka[13][15][15];

void powitanie ();
void wybor_planszy ();
void sterowanie ();
void koniec_gry ();
void logo ();
void menu ();
void generuj_plansze ();
void wypisz_plansze (int n, int x, int y);
void wypisz_cala_plansze (int x, int y, int n);
void generuj_kalke ();
void wyniki(int n);
void gra ();
void atomy ();
void ustaw_kolor (int tekst, int tlo);
void strzal (int n, int x, int y);
void do_gory (int n, int x, int y);
void do_dolu (int n, int x, int y);
void w_prawo (int n, int x, int y);
void w_lewo (int n, int x, int y);
bool czy_krawedz (int n, int x, int y);
void przepisz_plansze(int n);

 
int rozmiar = 1;
int *wsk_rozmiar = &rozmiar;
int ilosc_atomow = 3;
int *wsk_atomy = &ilosc_atomow;


int main()
{
	srand(time(NULL));
	
	powitanie();
	menu();
	
	system("PAUSE");
return 0;
}

void powitanie() 
{
	cout << ".______    __          ___       ______  __  ___    .______     ______   ___   ___ " << endl;
	cout << "|   _  \\  |  |        /   \\     /      ||  |/  /    |   _  \\   /  __  \\  \\  \\ /  / " << endl;
	cout << "|  |_)  | |  |       /  ^  \\   |  ,----'|  '  /     |  |_)  | |  |  |  |  \\  V  /  " << endl;
	cout << "|   _  <  |  |      /  /_\\  \\  |  |     |    <      |   _  <  |  |  |  |   >   <   " << endl;
	cout << "|  |_)  | |  `----./  _____  \\ |  `----.|  .  \\     |  |_)  | |  `--'  |  /  .  \\  " << endl;
	cout << "|______/  |_______/__/     \\__\\ \\______||__|\\__\\    |______/   \\______/  /__/ \\__\\ " << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
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
	system("cls");

}


void menu()
{

	while(true)
	{
	
		system("cls");
		
		cout << "		.______    __          ___       ______  __  ___    .______     ______   ___   ___ " << endl;
		cout << "		|   _  \\  |  |        /   \\     /      ||  |/  /    |   _  \\   /  __  \\  \\  \\ /  / " << endl;
		cout << "		|  |_)  | |  |       /  ^  \\   |  ,----'|  '  /     |  |_)  | |  |  |  |  \\  V  /  " << endl;
		cout << "		|   _  <  |  |      /  /_\\  \\  |  |     |    <      |   _  <  |  |  |  |   >   <   " << endl;
		cout << "		|  |_)  | |  `----./  _____  \\ |  `----.|  .  \\     |  |_)  | |  `--'  |  /  .  \\  " << endl;
		cout << "		|______/  |_______/__/     \\__\\ \\______||__|\\__\\    |______/   \\______/  /__/ \\__\\ " << endl;
		
		cout << endl;
		cout << endl;
		
		cout << " 	  	 	 _____ _____ _____ _____    _____ __    _____ _ _ _ _____ _____ " << endl;
    	cout << " 			|     |   __|   | |  |  |  |   __|  |  |     | | | |   | |   __|" << endl;
    	cout << " 			| | | |   __| | | |  |  |  |  |  |  |__|  |  | | | | | | |   __|" << endl;
    	cout << " 			|_|_|_|_____|_|___|_____|  |_____|_____|_____|_____|_|___|_____|" << endl;
    	
    	cout << " 				 	 ___       _____           _ " << endl;
    	cout << "					|_  |     |   __|___ ___  |_|" << endl;
    	cout << "				 	 _| |_ _  |  |  |  _| .'| | |" << endl;
    	cout << "					|_____|_| |_____|_| |__,|_| |" << endl;
    	cout << "							        |___|"         << endl;
    	
		cout << "  				 ___     ___ _                                _     " << endl;
   	 	cout << " 				|_  )   / __| |_ ___ _ _ _____ __ ____ _ _ _ (_)___ " << endl;
    	cout << "  				 / / _  \\__ \\  _/ -_) '_/ _ \\ V  V / _` | ' \\| / -_)" << endl;
    	cout << " 				/___(_)  ___/\\__\\___|_| \\___/\\_/\\_/\\__,_|_||_|_\\___|" << endl;
    	
    	cout << endl;
		
	 	cout << "   	 				  __    __      __     _    _    " << endl;
    	cout << "  					 /  \\   \\ \\    / /  _ (_)__| |___" << endl;
    	cout << " 					| () |   \\ \\/\\/ / || || / _` |_ /" << endl;
    	cout << "  					 \\__(_)   \\_/\\_/ \\_, |/ \\__,_/__|" << endl;
    	cout << "                  					 |__/__/         " << endl;
    	
		cout << endl;
		
		cout << "Twoj wybor: ";
		char a = cin.get();
		
		cout << endl;

		if (a == '1') wybor_planszy();
		else if (a == '2') sterowanie();
		else if (a == '0')
		{
			koniec_gry();
			system("PAUSE");
			exit(0);
		}
		else if (a == '&')
		{
			logo ();
		}

	}
}


void wybor_planszy()
{
	
	while (true)
	{
		
		system("cls");
		
		cout << "		.______    __          ___       ______  __  ___    .______     ______   ___   ___ " << endl;
		cout << "		|   _  \\  |  |        /   \\     /      ||  |/  /    |   _  \\   /  __  \\  \\  \\ /  / " << endl;
		cout << "		|  |_)  | |  |       /  ^  \\   |  ,----'|  '  /     |  |_)  | |  |  |  |  \\  V  /  " << endl;
		cout << "		|   _  <  |  |      /  /_\\  \\  |  |     |    <      |   _  <  |  |  |  |   >   <   " << endl;
		cout << "		|  |_)  | |  `----./  _____  \\ |  `----.|  .  \\     |  |_)  | |  `--'  |  /  .  \\  " << endl;
		cout << "		|______/  |_______/__/     \\__\\ \\______||__|\\__\\    |______/   \\______/  /__/ \\__\\ " << endl;
		
		cout << endl;
		cout << endl;
		
		cout << " 		 	   __      __    _    _                   _                     " << endl;
    	cout << " 		 	   \\ \\    / /  _| |__(_)___ _ _ ___  _ __| |__ _ _ _  _________ " << endl;
    	cout << "  		  	    \\ \\/\\/ / || | '_ \\ / -_) '_|_ / | '_ \\ / _` | ' \\(_-<_ / -_)" << endl;
    	cout << "   		  	     \\_/\\_/\\_, |_|.__/_\\___|_| /__| | .__/_\\__,_|_||_/__/__\\___|" << endl;
    	cout << "          		   	    |__/                    |_|                         " << endl;
    	
    	cout << "					   ___     ______     ______" << endl;
    	cout << "					  <  /    / ____/  __/ ____/" << endl;
    	cout << "					  / /    /___ \\| |/_/___ \\  " << endl;
    	cout << "					 / /    ____/ />  <____/ /  " << endl;
    	cout << "					/_(_)  /_____/_/|_/_____/   " << endl;
    	
    	cout << endl;

     	cout << "				        ___        ____       ____ " << endl;
    	cout << "				       |__ \\      ( __ )_  __( __ )" << endl;
    	cout << "				       __/ /     / __  | |/_/ __  |" << endl;
    	cout << "				      / __/_    / /_/ />  </ /_/ / " << endl;
    	cout << "				     /____(_)   \\____/_/|_|\\____/  " << endl;
    	
    	cout << endl;
    	
    	cout << "				       _____      _______      _______ " << endl;
    	cout << " 				      |__  /     <  / __ \\_  _<  / __ \\" << endl;
    	cout << "				       /_ <      / / / / / |/_/ / / / /" << endl;
    	cout << "				     ___/ /     / / /_/ />  </ / /_/ / " << endl;
    	cout << "				    /____(_)   /_/\\____/_/|_/_/\\____/  " << endl;
    	
    	cout << endl;
    	
    	
	 	cout << "   	 			       __    __      __     _    _    " << endl;
    	cout << "  				      /  \\   \\ \\    / /  _ (_)__| |___" << endl;
    	cout << " 				     | () |   \\ \\/\\/ / || || / _` |_ /" << endl;
    	cout << " 				      \\__(_)   \\_/\\_/ \\_, |/ \\__,_/__|" << endl;
    	cout << "              					      |__/__/         " << endl;
    	
		cout << endl;
		
		cout << "Twoj wybor: ";
		char a =  cin.get();
		
		cout << endl;
		
		if (a == '1')
		{
			*wsk_rozmiar = 5;
			gra();	
		} 
		else if (a == '2')
		{
			*wsk_rozmiar = 8;		
			gra();	
		} 
		else if (a == '3')
		{
			*wsk_rozmiar = 10;			
			gra();	
		} 
		else if (a == '0') menu();
	}
}


void sterowanie(){
	
	while (true){
		
		system("cls");
		
		cout << "		.______    __          ___       ______  __  ___    .______     ______   ___   ___ " << endl;
		cout << "		|   _  \\  |  |        /   \\     /      ||  |/  /    |   _  \\   /  __  \\  \\  \\ /  / " << endl;
		cout << "		|  |_)  | |  |       /  ^  \\   |  ,----'|  '  /     |  |_)  | |  |  |  |  \\  V  /  " << endl;
		cout << "		|   _  <  |  |      /  /_\\  \\  |  |     |    <      |   _  <  |  |  |  |   >   <   " << endl;
		cout << "		|  |_)  | |  `----./  _____  \\ |  `----.|  .  \\     |  |_)  | |  `--'  |  /  .  \\  " << endl;
		cout << "		|______/  |_______/__/     \\__\\ \\______||__|\\__\\    |______/   \\______/  /__/ \\__\\ " << endl;
		
		cout << endl;
		cout << endl;
		
		cout << "				  _____ _                                    _      " << endl;
    	cout << " 				 / ____| |                                  (_)     " << endl;
    	cout << "				 | (___ | |_ ___ _ __ _____      ____ _ _ __  _  ___ " << endl;
    	cout << "				  \\___ \\| __/ _ \\ '__/ _ \\ \\ /\\ / / _` | '_ \\| |/ _ \\" << endl;
    	cout << "				  ____) | ||  __/ | | (_) \\ V  V / (_| | | | | |  __/" << endl;
    	cout << "				 |_____/ \\__\\___|_|  \\___/ \\_/\\_/ \\__,_|_| |_|_|\\___|" << endl;
    	
    	cout << endl;
    	
    	cout << "				---------------------------------------------------" << endl;
    	cout << "				|  w, s, a, d i (W, S, A, D) – poruszanie siê po   |" << endl;
		cout << "				|  planszy odpowiednio: w gorê, w do³, w lewo i    |" << endl;
		cout << "				|  prawo                                           |" << endl;
		cout << "				|  q, Q – wyjscie do menu g³ownego                 |" << endl;
		cout << "				|  u, U – undo (cofnij ruch)                       |" << endl;
		cout << "				|  r, R – redo (powtorz cofniety ruch)             |" << endl;
		cout << "				|  spacja oddanie strza³u (gdy kursor jest na      |" << endl;
		cout << "				|  dowolnej scianie)                               |" << endl;
		cout << "				|  o - na planszy umozliwia zaznaczenie            |" << endl;
		cout << "				|  przypuszczalnego polozenia atomu                |" << endl;
		cout << "				|  z – na planszy umozliwia usuniecie zaznaczenia  |" << endl;
		cout << "				|  przypuszczalnego polozenia atomu                |" << endl;
		cout << "				|  k – konczy rozgrywkê i umozliwia wyswietlenie   |" << endl;
		cout << "				|  rozwiazania i liczby uzyskanych punktow         |" << endl;
    	cout << "				|  (poprawnie znalezionych atomow)                 |" << endl;
		cout << "				|  p – umozliwia wyswietlenie rozwiazania (przerywa|" << endl;
		cout << "				|  etap gry, brak mozliwoœci                       |" << endl;
    	cout << "				|  kontynuowaniatego etapu gry)                    |" << endl;
		cout << "				|  H – Help/Pomoc – pokazuje na chwile umieszczenie|" << endl;
		cout << "				|  atomow na planszy                               |" << endl;
    	cout << "				----------------------------------------------------" << endl;
    	
    	
    	
    	cout << "   	 			       __    __      __     _    _    " << endl;
    	cout << "  				      /  \\   \\ \\    / /  _ (_)__| |___" << endl;
    	cout << " 				     | () |   \\ \\/\\/ / || || / _` |_ /" << endl;
    	cout << " 				      \\__(_)   \\_/\\_/ \\_, |/ \\__,_/__|" << endl;
    	cout << "              					      |__/__/         " << endl;
    	
		cout << endl;
		
		cout << "Twoj wybor: ";
		char a = cin.get();
		
		cout << endl;
		
		if (a == '0') menu();
	}
		
}


void koniec_gry()
{
	system ("cls");
	
	cout << " __  ___   ______   .__   __.  __   _______   ______      _______ .______     ____    ____ " << endl;
    cout << "|  |/  /  /  __  \\  |  \\ |  | |  | |   ____| /      |    /  _____||   _  \\    \\   \\  /   / " << endl;
    cout << "|  '  /  |  |  |  | |   \\|  | |  | |  |__   |  ,----'   |  |  __  |  |_)  |    \\   \\/   /  " << endl;
    cout << "|    <   |  |  |  | |  . `  | |  | |   __|  |  |        |  | |_ | |      /      \\_    _/   " << endl;
    cout << "|  .  \\  |  `--'  | |  |\\   | |  | |  |____ |  `----.   |  |__| | |  |\\  \\----.   |  |     " << endl;
    cout << "|__|\\__\\  \\______/  |__| \\__| |__| |_______| \\______|    \\______| | _| `._____|   |__|     " << endl;
    
    cout << endl;
    cout << endl;
	
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

void generuj_plansze()
{
	
	
	
	for (int n = 0; n < 14; n++)
	{
	int liczba = 1;
	
	for (int i = 2; i < rozmiar + 2; i++)
	{
				plansza[n][0][i] = liczba;
				liczba++;		
	}
	
	for (int i = 2; i < rozmiar + 2; i++)
	{
				plansza[n][i][rozmiar + 3] = liczba;
				liczba++;	
	}
	
	for (int i = rozmiar + 1; i > 1; i--)
	{
				plansza[n][rozmiar + 3][i] = liczba;
				liczba++;
		
	}
	
	for (int i = rozmiar + 1; i > 1; i--)
	{
				plansza[n][i][0] = liczba;
				liczba++;
	}
	
	for(int wiersze = 0; wiersze < rozmiar + 4; wiersze++)
	{
		for(int kolumny = 0; kolumny < rozmiar + 4; kolumny++)
		{
			if (wiersze == 0 && kolumny == 0) 	plansza[n][wiersze][kolumny] = 255;
			else if (wiersze == 0 && kolumny == 1) 	plansza[n][wiersze][kolumny] = 255;
			else if (wiersze == 1 && kolumny == 0) plansza[n][wiersze][kolumny] = 255;
			else if (wiersze == rozmiar + 2 && kolumny == 0) plansza[n][wiersze][kolumny] = 255;
			else if (wiersze == rozmiar + 3 && kolumny == 0) plansza[n][wiersze][kolumny] = 255;
			else if (wiersze == rozmiar + 3 && kolumny == 1) plansza[n][wiersze][kolumny] = 255;
			else if (wiersze == 1 && kolumny == 1) plansza[n][wiersze][kolumny] = 201;
			else if (wiersze == 1 && kolumny == rozmiar + 2) plansza[n][wiersze][kolumny] = 187;
			else if (wiersze == rozmiar + 2 && kolumny == 1) plansza[n][wiersze][kolumny] = 200;
			else if (wiersze == rozmiar + 2 && kolumny == rozmiar + 2) plansza[n][wiersze][kolumny] = 188;
			else if (wiersze == 1 && (kolumny > 1 && kolumny < rozmiar + 2)) plansza[n][wiersze][kolumny] = 205;
			else if (wiersze == rozmiar + 2 && (kolumny > 1 && kolumny < rozmiar + 2)) plansza[n][wiersze][kolumny] = 205;
			else if (kolumny == 1 && (wiersze > 1 && wiersze < rozmiar + 2)) plansza[n][wiersze][kolumny] = 186;
			else if (kolumny == rozmiar + 2 && (wiersze > 1 && wiersze < rozmiar + 2)) plansza[n][wiersze][kolumny] = 186;
		}
	}
	
	
	for (int wiersze = 2; wiersze < rozmiar + 2; wiersze++ )
	{
		for (int kolumny = 2; kolumny < rozmiar + 2; kolumny++ )
		{
			plansza[n][wiersze][kolumny] = 255;
		}
	}
	
}
	
}

void generuj_kalke ()
{
	
	for(int n = 0; n < 13; n++)
	{
		for (int wiersze = 0; wiersze < rozmiar + 4; wiersze++ )
		{
			for (int kolumny = 0; kolumny < rozmiar + 4; kolumny++)
			{
				kalka[n][wiersze][kolumny] = 255;
			}
		}
	}
}


void atomy()
{
	int x, y;
	int bomby = 0;
	
	if (rozmiar == 5)
	{
		*wsk_atomy = 3;
		while (bomby < 42)
		{
			x = 2 + rand() % 5;
			y = 2 + rand() % 5;
			
			for (int n = 0; n < 14; n++)
			{
			
				if (plansza[n][x][y] == 'A') continue;
				else
				{
					plansza[n][x][y] = 'A';
					bomby++;
				}
			}
			
		}
		
	}
	else if (rozmiar == 8)
	{
		
		int los = 4 + rand() % 4;
		*wsk_atomy = los;
		
		while (bomby < los * 14)
		{
			x = 2 + rand() % 8;
			y = 2 + rand() % 8;
			
			for (int n = 0; n < 14; n++)
			{
			
				if (plansza[n][x][y] == 'A') continue;
				else
				{
					plansza[n][x][y] = 'A';
					bomby++;
				}
			}
			
		}	
		
	}
	else if (rozmiar == 10)
	{
		
		int los = 8;
		*wsk_atomy = 8;
		
		while (bomby < los * 14)
		{
			x = 2 + rand() % 10;
			y = 2 + rand() % 10;
			
			for (int n = 0; n < 14; n++)
			{
			
				if (plansza[n][x][y] == 'A') continue;
				else
				{
					plansza[n][x][y] = 'A';
					bomby++;
				} 
			
			}
		}
	}
}

void wypisz_plansze(int n, int x, int y)
{
	for (int wiersze = 0; wiersze < rozmiar + 4; wiersze++)
	{
		for (int kolumny = 0; kolumny < rozmiar + 4; kolumny++)
		{
			
				if((wiersze == 0 && (kolumny > 1 && kolumny < rozmiar + 2)) || (wiersze == rozmiar + 3 && (kolumny > 1 && kolumny < rozmiar + 2)) || (kolumny == 0 && (wiersze > 1 && wiersze < rozmiar + 2)) || (kolumny == rozmiar + 3 && (wiersze > 1 && wiersze < rozmiar + 2)) )
				{
					
					ustaw_kolor(10, 0);
					cout  << setw(3) << static_cast<int>(plansza[n][wiersze][kolumny]);
					ustaw_kolor(15, 0);
				
				}
				else if((wiersze == 1 && (kolumny >= 1 && kolumny <= rozmiar + 2)) || (wiersze == rozmiar + 2 && (kolumny >= 1 && kolumny <= rozmiar + 2)) || (kolumny == 1 && (wiersze >= 1 && wiersze <= rozmiar + 2)) || (kolumny == rozmiar + 2 && (wiersze >= 1 && wiersze <= rozmiar + 2)))
				{
					
					if (wiersze == x && kolumny == y)
					{
						ustaw_kolor(15, 9); 
						cout << setw(3) <<  plansza[n][wiersze][kolumny];
						ustaw_kolor(15, 0);
					}
					else
					{
						
						cout << setw(3) <<  plansza[n][wiersze][kolumny];
					}
					
				
				}
				else
				{
					
					if (wiersze == x && kolumny == y)
					{
						ustaw_kolor(15, 9);
						if (kalka[n][wiersze][kolumny] == 'o')
						{
							cout << setw(3) << 'o';
						}
						else
						{
							cout << setw(3) << char(255);
						}
						
						ustaw_kolor(15, 0);
					}
					else
					{
						if (kalka[n][wiersze][kolumny] == 'o')
						{
							cout << setw(3) << 'o';
						}
						else
						{
							cout << setw(3) << char(255);
						}
					}	
				
				}
			
		}
		cout << endl;
	}
}

void wypisz_cala_plansze(int x, int y, int n = 13)
{
	for (int wiersze = 0; wiersze < rozmiar + 4; wiersze++)
	{
		for (int kolumny = 0; kolumny < rozmiar + 4; kolumny++)
		{
			
			if((wiersze == 0 && (kolumny > 1 && kolumny < rozmiar + 2)) || (wiersze == rozmiar + 3 && (kolumny > 1 && kolumny < rozmiar + 2)) || (kolumny == 0 && (wiersze > 1 && wiersze < rozmiar + 2)) || (kolumny == rozmiar + 3 && (wiersze > 1 && wiersze < rozmiar + 2)) )
			{
				ustaw_kolor(10, 0);
				cout << setw(5) << static_cast<int>(plansza[n][wiersze][kolumny]);	
				ustaw_kolor(15, 0);
			}
			else
			{
					if (wiersze == x && kolumny == y)
					{
						ustaw_kolor(15, 9); 
						cout << setw(5) << plansza[n][wiersze][kolumny];
						ustaw_kolor(15, 0);
					}
					else
					{
						cout << setw(5) << plansza[n][wiersze][kolumny];
					}
			}
		}
		cout << endl;
	}
}

void wyniki(int n)
{
	int poprawnie = 0;
	for (int wiersze = 0; wiersze < rozmiar + 4; wiersze++)
	{
		for (int kolumny = 0; kolumny < rozmiar + 4; kolumny++)
		{
			
			if((wiersze == 0 && (kolumny > 1 && kolumny < rozmiar + 2)) || (wiersze == rozmiar + 3 && (kolumny > 1 && kolumny < rozmiar + 2)) || (kolumny == 0 && (wiersze > 1 && wiersze < rozmiar + 2)) || (kolumny == rozmiar + 3 && (wiersze > 1 && wiersze < rozmiar + 2)) )
			{
				ustaw_kolor(10, 0);
				cout << setw(5) << static_cast<int>(plansza[n][wiersze][kolumny]);	
				ustaw_kolor(15, 0);
			}
			else
			{
					if ((kalka[n][wiersze][kolumny] == 'o') && (plansza[n][wiersze][kolumny] == 'A') )
					{
						cout << setw(5) << 'O';
						poprawnie++;
					}
					else if((kalka[n][wiersze][kolumny] == 'o') && (plansza[n][wiersze][kolumny] != 'A') )
					{
						cout << setw(5) << 'X';
					}
					else
					{
						cout << setw(5) << plansza[n][wiersze][kolumny];
					}
			}
		}
		cout << endl;
	}
	cout << endl;
	cout << "Poprawnie zaznaczone atomy: " << poprawnie << endl;
}



void ustaw_kolor (int tekst, int tlo)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tekst + (tlo * 16));
}

void strzal (int n, int x, int y)
{
	
	if (y == 1 && (x >= 2 && x <= rozmiar + 1 )) 				w_prawo(n, x, y);
	else if (y == rozmiar + 2 && (x >=2 && x <= rozmiar + 1 ) ) w_lewo(n, x, y);
	else if (x == 1 && (y >= 2 && y <= rozmiar + 1 )) 			do_dolu(n, x, y);
	else if (x == rozmiar + 2 && (y >= 2 && y <= rozmiar + 1)) 	do_gory(n, x, y);
			
}

bool czy_krawedz(int n, int x, int y)
{
	if ( x == 1 || x == rozmiar + 2 || y == 1 || y == rozmiar + 2 ) return true;
	else return false;
}

void do_gory (int n, int x, int y)
{
		int x0 = x;
		int y0 = y;
		
		for (int w = x; w >=  1; w--)
		{
			
			if ((plansza[n][w - 1][y] == 'A') && (czy_krawedz(n, x0, y0) == true)  && (plansza[n][w - 1][y + 1] != 'A') && (plansza[n][w - 1][y - 1] != 'A'))
			 {
				plansza[n][x0][y0] = 'H';
				break;
			}
			else if (plansza[n][w][y] == 'A') break;
			else if (czy_krawedz(n, w, y) == true && ((plansza[n][w - 1][y + 1] == 'A') || (plansza[n][w - 1][y - 1] == 'A'))) break;
	
			else if (plansza[n][w - 1][y + 1] == 'A')
			{
				w_lewo(n, w, y);
				break;
			} 	
			else if (plansza[n][w - 1][y - 1] == 'A')
			{
				w_prawo(n, w, y);
				break;
			}
			else if ((plansza[n][w - 1][y + 1] == 'A') && (plansza[n][w - 1][y - 1] == 'A'))
			{
				do_dolu(n, w, y);
				break;
			} 
			else if(czy_krawedz(n, w, y) == true )
			{
				if(w == x)
				{
					continue;
				}
				else
				{
					plansza[n][w][y] = 'R';
					break;
				}
				
			} 
			
		}
}

void do_dolu(int n, int x, int y)
{
		int x0 = x;
		int y0 = y;
		
		for (int w = x; w <= rozmiar + 2; w++)
		{
			if ((plansza[n][w+1][y] == 'A') && (czy_krawedz(n, x0, y0) == true) && (plansza[n][w + 1][y + 1] != 'A') && (plansza[n][w + 1][y - 1] != 'A') )
			{
				plansza[n][x0][y0] = 'H';
				break;
			}
			else if (plansza[n][w][y] == 'A') break;
			else if (czy_krawedz(n, w, y) == true && ((plansza[n][w + 1][y + 1] == 'A') || (plansza[n][w + 1][y - 1] == 'A'))) break;
			else if (plansza[n][w + 1][y + 1] == 'A')
			{
				w_lewo(n, w, y);
				break;
			} 	
			else if (plansza[n][w + 1][y - 1] == 'A')
			{
				w_prawo(n, w, y);
				break;
			} 
			else if ((plansza[n][w + 1][y + 1] == 'A') && (plansza[n][w + 1][y - 1] == 'A'))
			{
				do_gory(n, w, y);
				break;
			} 
			else if(czy_krawedz(n, w, y) == true)
			{
				if (w == x)
				{
					continue;
				}
				else
				{
					plansza[n][w][y] = 'R';
					break;
				}
				
			} 
			
		}
}
void w_prawo(int n, int x, int y)
{
	int x0 = x;
	int y0 = y;
	
	for (int k = y; k <= rozmiar + 2; k++)
	{
		if ((plansza[n][x][k+1] == 'A') && (czy_krawedz(n, x0, y0) == true) && (plansza[n][x + 1][k + 1] != 'A') && (plansza[n][x - 1][k + 1] != 'A') )
		{
			plansza[n][x0][y0] = 'H';
			break;
		}
		else if(plansza[n][x][k] == 'A') break;
		else if(czy_krawedz(n, x, k) == true && ((plansza[n][x + 1][k + 1] == 'A') || (plansza[n][x - 1][k + 1] == 'A'))) break;
		else if(plansza[n][x + 1][k + 1] == 'A')
		{
			do_gory(n, x, k);
			break;
		} 
		else if(plansza[n][x - 1][k + 1] == 'A')
		{
			do_dolu(n, x, k);
			break;
		} 
		else if((plansza[n][x + 1][k + 1] == 'A') && (plansza[n][x - 1][k + 1] == 'A'))
		{
			w_lewo(n, x, k);
			break;
		} 
		else if(czy_krawedz(n, x, k) == true)
		{
			if(k == y)
			{
				continue;
			}
			else
			{
			plansza[n][x][k] = 'R';
			break;
			}
		} 
		
	}
}
void w_lewo (int n, int x, int y)
{
	int x0 = x;
	int y0 = y;
	
	for (int k = y; k >= 1; k--)
	{
		if ((plansza[n][x][k - 1] == 'A') && (czy_krawedz(n, x0, y0) == true) && (plansza[n][x + 1][k - 1] != 'A') && (plansza[n][x - 1][k - 1] != 'A') )
		{
			plansza[n][x0][y0] = 'H';
			break;
		}
		else if(plansza[n][x][k] == 'A') break;
		else if(czy_krawedz(n, x, k) == true && ((plansza[n][x + 1][k - 1] == 'A') || (plansza[n][x - 1][k - 1] == 'A'))) break;
		else if(plansza[n][x + 1][k - 1] == 'A')
		{
			do_gory(n, x, k);
			break;
		} 
		else if(plansza[n][x - 1][k - 1] == 'A')
		{
			do_dolu(n, x, k);
			break;
		} 
		else if((plansza[n][x + 1][k - 1] == 'A') && (plansza[n][x - 1][k - 1] == 'A'))
		{
			w_prawo(n, x, k);
			break;
		} 
		else if(czy_krawedz(n, x, k) == true)
		{
					if(k == y) continue;
					else
					{	
		 			plansza[n][x][k] = 'R';
		 			break;
		 			}
			}
	}
}

void przepisz_plansze(int n)
{
	
	for (int wiersze = 0; wiersze < rozmiar + 4; wiersze++)
	{
		for (int kolumny = 0; kolumny < rozmiar + 4; kolumny++)
		{
				
				if (n == 13)
				{
					plansza[0][wiersze][kolumny] = plansza[12][wiersze][kolumny];
					kalka[0][wiersze][kolumny] = kalka[12][wiersze][kolumny];
				}
				else
				{
					plansza[n + 1][wiersze][kolumny] = plansza[n][wiersze][kolumny];
					kalka[n + 1][wiersze][kolumny] = kalka[n][wiersze][kolumny];
				}
				
				
		}
	}
}

void gra()
{
		generuj_plansze();
		generuj_kalke ();
		atomy();
		
		int x = 1;
		int y = 2;
		int licznik = 0, proby = 0, n = 0, cofki = 0, ruchy = 0, undos = 0;
		bool ciec = false;
		
		while (true)
		{
			
			system("cls");
			
			wypisz_plansze(n, x, y);
				
			cout << endl;
			cout << endl;
			
			cout << "Ilosc atomow w planszy: " << ilosc_atomow << endl;
			cout << "ilosc wykonanych strzalow: " << licznik << endl;
			cout << "ilosc wykorzystanych cofniec ruchow: " << undos << "  " << "Masz jeszcze: " << 10 - undos << endl;
			cout << "Twoj ruch: ";
			
			char znak = cin.get();
			
        	if ((znak == 'a' || znak == 'A') && y > 1) y--;
        	else if ((znak == 'd' || znak == 'D' ) && y < rozmiar +2) y++;
        	else if ((znak == 'w' || znak == 'W') && x > 1) x--; 
            else if ((znak == 's' || znak == 'S') && x < rozmiar + 2) x++;
            
            else if (znak == 'q' || znak == 'Q' ) menu();
			 
            else if (znak == 'H')
			{
            	system("cls");
            	wypisz_cala_plansze(x, y);
            	Sleep(5000);
            	continue;
			}
			 
            else if (znak == 32 && ((x == 1 && (y >= 1 && y <= rozmiar + 2)) || (x == rozmiar + 2 && (y >= 1 && y <= rozmiar + 2)) || (y == 1 && (x >= 1 && x <= rozmiar + 2)) || (y == rozmiar + 2 && (x >= 1 && x <= rozmiar + 2))) )
			{
			    if (ciec == true)
				{
			    	 przepisz_plansze(n);
			    	 ciec = false;
				}
				
				 if (n == 12)
				 {
				 	n++;
            		przepisz_plansze(n);
				 	strzal(0, x, y);
            		n = 0;
            		licznik++;
            		ruchy++;
            		cofki = 0;
            	
				 }
				 else
				 {
				 	przepisz_plansze(n);
				 	strzal(n + 1, x, y);
            		n++;
            		licznik++;
            		ruchy++;
            		cofki = 0;
				 } 

            	
            	
			}
			else if(znak == 'o' && ((x >= 2) && (x <= rozmiar + 1)) && ((y >= 2) && (y <= rozmiar + 1)) && proby < ilosc_atomow )
			{
				 if (ciec == true)
				 {
			    	 przepisz_plansze(n);
			    	 ciec = false;
				 }
				
				if (n == 12)
				{
					kalka[0][x][y] = 'o';
					n++;
					przepisz_plansze(n);
					n = 0;
					ruchy++;
					cofki = 0;
					proby++;
				} 
				else
				{
					przepisz_plansze(n);
					kalka[n + 1][x][y] = 'o';
					n++; 
					ruchy++;
					cofki = 0;
					proby++;
				} 
				
			}
			else if(znak == 'z' && kalka[n][x][y] == 'o')
			{
				 if (ciec == true)
				 {
			    	 przepisz_plansze(n);
			    	 ciec = false;
				 }
				
				if (n == 12)
				{
					kalka[0][x][y] = 255;
					n++;			
					przepisz_plansze(n);
					n = 0;
					ruchy++;					
				} 
				else
				{
					
					przepisz_plansze(n);
					kalka[n + 1][x][y] = 255;
					n++; 
					ruchy++;			
				} 
				 
				if(proby > 0) proby--;
				
				cofki = 0;
				
			}
			else if (znak == 'p')
			{
				koniec_gry();
				wypisz_cala_plansze(x, y);
				cout << endl;
				cout << endl;
				system("PAUSE");
				menu();
			}
			else if (znak == 'k')
			{
				koniec_gry();
				wyniki(n);
				cout << "liczba oddanych strzalow w calej grze: " << licznik << endl;
				cout << "laczna liczba ruchow: " << ruchy << endl;
				cout << endl;
				cout << endl;
				system("PAUSE");
				menu();
			}
			else if ((znak == 'u' || znak == 'U') && undos < 10) 
			{
				ciec = true;
				cofki++;
				undos++;
				if (n == 0) n = 12;
				else n--;
				ruchy--; 
			}
			else if((znak == 'r' || znak == 'R') && cofki > 0)
			{
				cofki --;
				ruchy++;
				if (n == 12) n = 0;
				else n++;
			
			}
				
		}	
}



