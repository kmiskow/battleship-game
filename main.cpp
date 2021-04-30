#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "winbgi2.h"
#include <time.h>
#include <stdlib.h>

struct Coord {
	int kolumna;
	int wiersz;
};
enum Kierunek {
	BRAK,
	PIONOWO,
	POZIOMO,

};
enum Cell {
	STATEK,
	PUSTA,
	OBOK_STATKU,
	STRZELONA
};		
struct Ship						
{								
	int xp;												
	int yp;	
	Kierunek kierunek;
	int num;
};
Cell tabgracz[10][10];
Cell tabcomp[10][10];
Coord kratka(int x, int y) {
	Coord zmienne;
	int zmiennaX = (x - 50) / 50;
	int zmiennaY = (y - 50) / 50;
	zmienne.kolumna = zmiennaX;
	zmienne.wiersz = zmiennaY;
	return(zmienne);
}
void wypisz() {
	for (int i = 0; i < 10; i++)
	{
		for (int n = 0; n < 10; n++)
		{
			printf(" %d\t", tabcomp[n][i]);
		}
		printf("\n");
	}
}

void shootplay();
int check(Cell tab[10][10]) {
	for (int i = 0; i < 10; i++)
	{
		for (int n = 0; n < 10; n++)
		{
			if (tab[i][n] == STATEK)
				return 1;
		}

	}
	return 0;
}
int wynik() {
	if (check(tabgracz)==0)
	{
		outtextxy(50,750,"Przegrales");
		return 0;
	}
	if (check(tabcomp)==0)
	{
		outtextxy(50,750,"Wygrales");
			return 0;
	}

}
int losuj(int min,int max) {
	int x;  
	int L = max - min + 1;

	x = rand() % L + min;
	
	return x;
}



void clearboard(Cell tab[10][10]){
	for (int i = 0; i < 10; i++)
	{
		for (int m = 0;m < 10;m++) {
			tab[i][m] = PUSTA;
		}
	}
}

void Statekcomp(Ship nazwa, Cell tab[10][10]) {
	
	Coord xy = kratka(nazwa.xp - 550, nazwa.yp);
	int zmiennaX = xy.kolumna;
	int zmiennaY = xy.wiersz;
	
	
	if (nazwa.kierunek == PIONOWO) {
		for (int i = 0; i < nazwa.num; i++)
		{
			if (zmiennaX - 1 >= 0)tab[zmiennaX - 1][zmiennaY + i] = OBOK_STATKU;
			if (zmiennaY - 1 >= 0)tab[zmiennaX][zmiennaY - 1 + i] = OBOK_STATKU;
			if (zmiennaY + 1 <= 10)tab[zmiennaX][zmiennaY + 1 + i] = OBOK_STATKU;
			if (zmiennaX + 1 <= 10)tab[zmiennaX + 1][zmiennaY + i] = OBOK_STATKU;
			if (zmiennaX + 1 <= 10)if (zmiennaY + 1 <= 10)tab[zmiennaX + 1][zmiennaY + 1 + i] = OBOK_STATKU;
			if (zmiennaX - 1 >= 0)if (zmiennaY - 1 >= 0)tab[zmiennaX - 1][zmiennaY - 1 + i] = OBOK_STATKU;
			if (zmiennaX + 1 <= 10)if (zmiennaY - 1 >= 0)tab[zmiennaX + 1][zmiennaY - 1 + i] = OBOK_STATKU;
			if (zmiennaX - 1 >= 0)if (zmiennaY + 1 <= 10)tab[zmiennaX - 1][zmiennaY + 1 + i] = OBOK_STATKU;


		}
		for (int i = 0; i < nazwa.num; i++)
		{
			tab[zmiennaX][zmiennaY + i] = STATEK;
		}
	}
	if (nazwa.kierunek == POZIOMO) {
		for (int i = 0; i < nazwa.num; i++)
		{
			
			
			if (zmiennaX - 1 >= 0)tab[zmiennaX - 1 + i][zmiennaY] = OBOK_STATKU;
			if (zmiennaY - 1 >= 0)tab[zmiennaX + i][zmiennaY - 1] = OBOK_STATKU;
			if (zmiennaY + 1 <= 10)tab[zmiennaX + i][zmiennaY + 1] = OBOK_STATKU;
			if (zmiennaX + 1 <= 10)tab[zmiennaX + 1 + i][zmiennaY] = OBOK_STATKU;
			if (zmiennaX + 1 <= 10)if (zmiennaY + 1 <= 10)tab[zmiennaX + 1 + i][zmiennaY + 1] = OBOK_STATKU;
			if (zmiennaX - 1 >= 0)if (zmiennaY - 1 >= 0)tab[zmiennaX - 1 + i][zmiennaY - 1] = OBOK_STATKU;
			if (zmiennaX + 1 <= 10)if (zmiennaY - 1 >= 0)tab[zmiennaX + 1 + i][zmiennaY - 1] = OBOK_STATKU;
			if (zmiennaX - 1 >= 0)if (zmiennaY + 1 <= 10)tab[zmiennaX - 1 + i][zmiennaY + 1] = OBOK_STATKU;

		}
		for (int i = 0; i < nazwa.num; i++)
		{
			tab[zmiennaX + i][zmiennaY] = STATEK;
		}
	}
	if (nazwa.kierunek == BRAK) {

		
		if (zmiennaX - 1 >= 0)tab[zmiennaX - 1][zmiennaY] = OBOK_STATKU;
		if (zmiennaY - 1 >= 0)tab[zmiennaX][zmiennaY - 1] = OBOK_STATKU;
		if (zmiennaY + 1 <= 10)tab[zmiennaX][zmiennaY + 1] = OBOK_STATKU;
		if (zmiennaX + 1 <= 10)tab[zmiennaX + 1][zmiennaY] = OBOK_STATKU;
		if (zmiennaX + 1 <= 10)if (zmiennaY + 1 <= 10)tab[zmiennaX + 1][zmiennaY + 1] = OBOK_STATKU;
		if (zmiennaX - 1 >= 0)if (zmiennaY - 1 >= 0)tab[zmiennaX - 1][zmiennaY - 1] = OBOK_STATKU;
		if (zmiennaX + 1 <= 10)if (zmiennaY - 1 >= 0)tab[zmiennaX + 1][zmiennaY - 1] = OBOK_STATKU;
		if (zmiennaX - 1 >= 0)if (zmiennaY + 1 <= 10)tab[zmiennaX - 1][zmiennaY + 1] = OBOK_STATKU;
		tab[zmiennaX][zmiennaY] = STATEK;

	}
}
void Statek(Ship nazwa, Cell tab[10][10]) {
	int zmiennaX = (nazwa.xp - 50) / 50;
	int zmiennaY = (nazwa.yp - 50) / 50;

	setfillstyle(1, 1);
	if (nazwa.kierunek==PIONOWO) {
		for (int i = 0; i < nazwa.num; i++)
		{
			int zmienna1 = i * 50;
			floodfill(nazwa.xp , nazwa.yp+ zmienna1, 15);
			if (zmiennaX - 1 >= 0)tab[zmiennaX - 1][zmiennaY + i] = OBOK_STATKU;
			if (zmiennaY - 1 >= 0)tab[zmiennaX][zmiennaY-1 + i] = OBOK_STATKU;
			if (zmiennaY + 1 <= 10)tab[zmiennaX][zmiennaY+1 + i] = OBOK_STATKU;
			if (zmiennaX +1 <= 10)tab[zmiennaX+1][zmiennaY + i] = OBOK_STATKU;
			if (zmiennaX + 1 <= 10)if (zmiennaY + 1 <= 10)tab[zmiennaX + 1][zmiennaY+1 + i] = OBOK_STATKU;
			if (zmiennaX - 1 >= 0)if (zmiennaY - 1 >= 0)tab[zmiennaX - 1][zmiennaY - 1 + i] = OBOK_STATKU;
			if (zmiennaX + 1 <= 10)if (zmiennaY - 1 >= 0)tab[zmiennaX + 1 ][zmiennaY - 1+i] = OBOK_STATKU;
			if (zmiennaX - 1 >= 0)if (zmiennaY + 1 <= 10)tab[zmiennaX - 1 ][zmiennaY + 1+i] = OBOK_STATKU;
		}
		for (int i = 0; i < nazwa.num; i++)
		{
			tab[zmiennaX][zmiennaY + i] = STATEK;
		}
	}
	if (nazwa.kierunek==POZIOMO) {
		for (int i = 0; i < nazwa.num; i++)
		{
			int zmienna1 = i * 50;
			floodfill(nazwa.xp+ zmienna1, nazwa.yp , 15);
			if (zmiennaX - 1 >= 0)tab[zmiennaX - 1+i][zmiennaY ] = OBOK_STATKU;
			if (zmiennaY - 1 >= 0)tab[zmiennaX + i][zmiennaY - 1 ] = OBOK_STATKU;
			if (zmiennaY + 1 <= 10)tab[zmiennaX + i][zmiennaY + 1 ] = OBOK_STATKU;
			if (zmiennaX + 1 <= 10)tab[zmiennaX + 1 + i][zmiennaY ] = OBOK_STATKU;
			if (zmiennaX + 1 <= 10)if (zmiennaY + 1 <= 10)tab[zmiennaX + 1 + i][zmiennaY + 1 ] = OBOK_STATKU;
			if (zmiennaX - 1 >= 0)if (zmiennaY - 1 >= 0)tab[zmiennaX - 1 + i][zmiennaY - 1 ] = OBOK_STATKU;
			if (zmiennaX + 1 <= 10)if (zmiennaY - 1 >= 0)tab[zmiennaX + 1 + i][zmiennaY - 1] = OBOK_STATKU;
			if (zmiennaX - 1 >= 0)if (zmiennaY + 1 <= 10)tab[zmiennaX - 1 + i][zmiennaY + 1] = OBOK_STATKU;
			
		}
		for (int i = 0; i < nazwa.num; i++)
		{
			tab[zmiennaX+i][zmiennaY] = STATEK;
		}
	}
	if (nazwa.kierunek == BRAK) {
		
			floodfill(nazwa.xp , nazwa.yp, 15);
			if(zmiennaX - 1 >= 0)tab[zmiennaX - 1][zmiennaY ] = OBOK_STATKU;
			if (zmiennaY - 1 >= 0)tab[zmiennaX][zmiennaY - 1] = OBOK_STATKU;
			if (zmiennaY + 1 <= 10)tab[zmiennaX][zmiennaY + 1] = OBOK_STATKU;
			if (zmiennaX + 1 <= 10)tab[zmiennaX + 1][zmiennaY] = OBOK_STATKU;
			if (zmiennaX + 1 <= 10)if (zmiennaY + 1 <= 10)tab[zmiennaX + 1][zmiennaY + 1] = OBOK_STATKU;
			if (zmiennaX - 1 >= 0)if (zmiennaY - 1 >= 0)tab[zmiennaX - 1][zmiennaY - 1 ] = OBOK_STATKU;
			if (zmiennaX + 1 <= 10)if (zmiennaY - 1 >= 0)tab[zmiennaX + 1 ][zmiennaY - 1] = OBOK_STATKU;
			if (zmiennaX - 1 >= 0)if (zmiennaY + 1 <= 10)tab[zmiennaX - 1 ][zmiennaY + 1] = OBOK_STATKU;
			tab[zmiennaX][zmiennaY] = STATEK;
		
	}
}
void boardplay() {
	
	for (int i = 1; i < 12; i++)
	{
		int zmienna1 = i * 50;
		line(zmienna1, 50, zmienna1, 550);
		line(50, zmienna1, 550, zmienna1);	
		
	}
	char znak[2] = { 0, 0 };
	for (int i = 0; i < 10; i++)
	{
		znak[0] = 'A' + i;
	outtextxy(70+i*50, 35, znak);
	znak[0] = '0' + i;
	outtextxy(35, 70 + i * 50, znak);
	}

	outtextxy(50, 600, "LPM-POZIOMO");
	outtextxy(50, 625, "PPM-PIONOWO");
	outtextxy(50, 650, "Ustawienie statków:");
	outtextxy(50, 675, "Jeden tatek wielkosci 4");
	outtextxy(50, 700, "Trzy statki wielkosci 2");
	outtextxy(50, 725, "Cztery statki wielkosci 1");
}	
void boardcomp() {

	for (int i = 1; i < 12; i++)
	{
		int zmienna1 = i * 50 +550;
		int zmienna2 = i*50;
		line(zmienna1, 50, zmienna1, 550);
		line(600, zmienna2, 1100, zmienna2);
	}

	char znak[2] = { 0, 0 };
	for (int i = 0; i < 10; i++)
	{
		znak[0] = 'A' + i;
		outtextxy(620 + i * 50, 35, znak);
		znak[0] = '0' + i;
		outtextxy(585, 70 + i * 50, znak);
	}

}



void ustawstatek(Ship statek, Cell tab[10][10]) {
	int z = 0;

	while (z == 0) {
		if (mousedown() == 1) {
			if (whichmousebutton() == 0)
			{
				statek.kierunek = POZIOMO;
				Coord xy = kratka(mouseclickx(), mouseclicky());
				if (tab[xy.kolumna][xy.wiersz] == PUSTA) {
					if (statek.num == 1) {
						if (mouseclickx() >= 50 && mouseclickx() <= 550 && mouseclicky() >= 50 && mouseclicky() <= 550)
						{

							statek.xp = mouseclickx();
							statek.yp = mouseclicky();
							z = 1;
						}
					}
					if (statek.num == 2) {


						if (tab[xy.kolumna+1][xy.wiersz] == PUSTA &&
							mouseclickx() >= 50 && mouseclickx() <= 500 && mouseclicky() >= 50 && mouseclicky() <= 550)
						{

							statek.xp = mouseclickx();
							statek.yp = mouseclicky();
							z = 1;
						}
					}
					if (statek.num == 3) {


						if (tab[xy.kolumna + 1][xy.wiersz] == PUSTA && tab[xy.kolumna+ 2][xy.wiersz ] == PUSTA &&
							mouseclickx() >= 50 && mouseclickx() <= 450 && mouseclicky() >= 50 && mouseclicky() <=550 )
						{

							statek.xp = mouseclickx();
							statek.yp = mouseclicky();
							z = 1;
						}
					}
					if (statek.num == 4) {


						if (tab[xy.kolumna+ 1][xy.wiersz ] == PUSTA && tab[xy.kolumna+ 2][xy.wiersz ] == PUSTA && tab[xy.kolumna+ 3][xy.wiersz ] == PUSTA &&
							mouseclickx() >= 50 && mouseclickx() <= 400 && mouseclicky() >= 50 && mouseclicky() <=550 )
						{

							statek.xp = mouseclickx();
							statek.yp = mouseclicky();
							z = 1;
						}
					}
				}
			}
			if (whichmousebutton() == 1) {
				Coord xy = kratka(mouseclickx(), mouseclicky());
				statek.kierunek = PIONOWO;
				if (tab[xy.kolumna][xy.wiersz] == PUSTA) {
					if (statek.num == 1) {
						if (
							mouseclickx() >= 50 && mouseclickx() <= 550 && mouseclicky() >= 50 && mouseclicky() <= 550)
						{

							statek.xp = mouseclickx();
							statek.yp = mouseclicky();
							z = 1;
						}
					}
					if (statek.num == 2) {


						if (tab[xy.kolumna][xy.wiersz+1] == PUSTA &&
							mouseclickx() >= 50 && mouseclickx() <= 550 && mouseclicky() >= 50 && mouseclicky() <= 500)
						{

							statek.xp = mouseclickx();
							statek.yp = mouseclicky();
							z = 1;
						}
					}
					if (statek.num == 3) {


						if (tab[xy.kolumna][xy.wiersz + 1] == PUSTA && tab[xy.kolumna][xy.wiersz + 2] == PUSTA &&
							mouseclickx() >= 50 && mouseclickx() <= 550 && mouseclicky() >= 50 && mouseclicky() <= 450)
						{

							statek.xp = mouseclickx();
							statek.yp = mouseclicky();
							z = 1;
						}
					}
					if (statek.num == 4) {


						if (tab[xy.kolumna][xy.wiersz + 1] == PUSTA && tab[xy.kolumna][xy.wiersz + 2] == PUSTA && tab[xy.kolumna][xy.wiersz + 3] == PUSTA &&
							mouseclickx() >= 50 && mouseclickx() <= 550 && mouseclicky() >= 50 && mouseclicky() <= 400)
						{

							statek.xp = mouseclickx();
							statek.yp = mouseclicky();
							z = 1;
						}
					}
				}


			}
		}
	}
	Statek(statek, tab);
}
int ustawstatekkomp(Ship statek, Cell tab[10][10],int Wx, int Wy) {
	
		int z = 0;

			Coord xy = kratka(Wx - 550, Wy);
			

			if (tab[xy.kolumna][xy.wiersz] == PUSTA) {




				if (statek.kierunek == PIONOWO)
				{
					if (statek.num == 1) {
						if (Wx >= 600 && Wx <= 1100 && Wy >= 50 && Wy <= 550)
						{

							statek.xp = Wx;
							statek.yp = Wy;
							z = 1;
						}
					}
					if (statek.num == 2) {


						if (tab[xy.kolumna][xy.wiersz + 1] == PUSTA &&
							Wx >= 600 && Wx <= 1050 && Wy >= 50 && Wy <= 500)
						{

							statek.xp = Wx;
							statek.yp = Wy;
							z = 1;
						}
					}
					if (statek.num == 3) {


						if (tab[xy.kolumna][xy.wiersz + 1] == PUSTA && tab[xy.kolumna][xy.wiersz + 2] == PUSTA &&
							Wx >= 600 && Wx <= 1100 && Wy >= 50 && Wy <= 450)
						{

							statek.xp = Wx;
							statek.yp = Wy;
							z = 1;
						}
					}
					if (statek.num == 4) {


						if (tab[xy.kolumna][xy.wiersz + 1] == PUSTA && tab[xy.kolumna][xy.wiersz + 2] == PUSTA && tab[xy.kolumna][xy.wiersz + 3] == PUSTA &&
							Wx >= 600 && Wx <= 1100 && Wy >= 50 && Wy <= 400)
						{

							statek.xp = Wx;
							statek.yp = Wy;
							z = 1;
						}
					}



				}

				if (statek.kierunek == POZIOMO)
				{
					if (statek.num == 1) {
						if (Wx >= 600 && Wx <= 1100 && Wy >= 50 && Wy <= 550)
						{

							statek.xp = Wx;
							statek.yp = Wy;
							z = 1;
						}
					}
					if (statek.num == 2) {

						if (tab[xy.kolumna + 1][xy.wiersz] == PUSTA
							&& Wx >= 600 && Wx <= 1050 && Wy >= 50 && Wy <= 550)
						{

							statek.xp = Wx;
							statek.yp = Wy;
							z = 1;
						}
					}
					if (statek.num == 3) {


						if (tab[xy.kolumna + 1][xy.wiersz] == PUSTA && tab[xy.kolumna + 2][xy.wiersz] == PUSTA &&
							Wx >= 600 && Wx <= 1000 && Wy >= 50 && Wy <= 550)
						{

							statek.xp = Wx;
							statek.yp = Wy;
							z = 1;
						}
					}
					if (statek.num == 4) {


						if (tab[xy.kolumna + 1][xy.wiersz] == PUSTA && tab[xy.kolumna + 2][xy.wiersz] == PUSTA && tab[xy.kolumna + 3][xy.wiersz] == PUSTA &&
							Wx >= 600 && Wx <= 950 && Wy >= 50 && Wy <= 550)
						{

							statek.xp = Wx;
							statek.yp = Wy;
							z = 1;
						}
					}




				}



			}
		
			
			if (z == 1) {
				Statekcomp(statek, tab);
			}
			return z;
	}
void shoot(Cell tab[10][10],int Wx,int Wy) {
		Coord zmienne=kratka(Wx-550,Wy);
		switch (tab[zmienne.kolumna][zmienne.wiersz])
		{
		case STATEK:
			setfillstyle(RED, 4);
			floodfill(Wx, Wy, 15);
			tab[zmienne.kolumna][zmienne.wiersz] = STRZELONA;
			break;
		case PUSTA:
			setfillstyle(1, 8);
			floodfill(Wx, Wy, 15);
			tab[zmienne.kolumna][zmienne.wiersz] = STRZELONA;
			break;
		case OBOK_STATKU:
			setfillstyle(1, 8);
			floodfill(Wx, Wy, 15);
			tab[zmienne.kolumna][zmienne.wiersz] = STRZELONA;
			break;
		case STRZELONA:
			shootplay();
			break;
		default:
			break;
		}
}
void shootcomp(int Wx, int Wy) {
Coord zmienne = kratka(Wx, Wy);
	switch (tabgracz[zmienne.kolumna][zmienne.wiersz])
	{
		
	case STATEK:
		setfillstyle(RED, 4);
		floodfill(Wx, Wy, 15);
		tabgracz[zmienne.kolumna][zmienne.wiersz] = STRZELONA;
		break;
		
	case PUSTA:
		setfillstyle(1, 8);
		floodfill(Wx, Wy, 15);
		tabgracz[zmienne.kolumna][zmienne.wiersz] = STRZELONA;
		break;

	case OBOK_STATKU:
		setfillstyle(1, 8);
		floodfill(Wx, Wy, 15);
		tabgracz[zmienne.kolumna][zmienne.wiersz] = STRZELONA;
		break;

	case STRZELONA:	
	default:
		printf("Strzelona: %d %d", zmienne.kolumna, zmienne.wiersz);
		shootcomp(losuj(50, 550), losuj(50, 550));
		break;
	}
}

void wypelnij(Ship statek) {
	
	while (1) {
		switch (losuj(0, 1))
		{
		case 0:
			statek.kierunek = POZIOMO;
			break;
		case 1:
			statek.kierunek = PIONOWO;
			break;

		default:
			break;
		}
		if (ustawstatekkomp(statek, tabcomp, losuj(600, 1100), losuj(50, 550)) == 1) {
			break;
		}
	}
}
void compustawiaj(Ship cz, Ship t, Ship d, Ship j) {
	wypelnij(cz);
	wypelnij(t);
	wypelnij(t);
	wypelnij(j);
	wypelnij(j);
	wypelnij(j);
	wypelnij(j);
	wypelnij(d);
	wypelnij(d);
	wypelnij(d);
}
void ustawiaj(Ship cztery,Ship trzy,Ship dwa,Ship jeden) {
	ustawstatek(cztery, tabgracz);
	ustawstatek(trzy, tabgracz);
	ustawstatek(trzy, tabgracz);
	ustawstatek(dwa, tabgracz);
	ustawstatek(dwa, tabgracz);
	ustawstatek(dwa, tabgracz);
	ustawstatek(jeden, tabgracz);
	ustawstatek(jeden, tabgracz);
	ustawstatek(jeden, tabgracz);
	ustawstatek(jeden, tabgracz);
}
void shootplay() {
	while(1){
	if (mousedown() == 1) {
		int zmiennaX = mouseclickx();
		int zmiennaY = mouseclicky();
		if (zmiennaX >= 600 && zmiennaX <= 1100 && zmiennaY >= 50 && zmiennaY <= 550) {
			shoot(tabcomp, zmiennaX, zmiennaY);
			break;
		}
	}
	}
}
void main() {
	srand(time(NULL));
	graphics(1020, 2020);


	Ship cztery = { 75, 75, POZIOMO,4 };
	Ship jeden = { 225,225,BRAK,1 };

	Ship trzy = { 225,225,PIONOWO,3 };

	Ship dwa = { 225,225,PIONOWO,2 };

	boardplay();
	boardcomp();


	clearboard(tabgracz);
	clearboard(tabcomp);

	
	compustawiaj(cztery, trzy, dwa, jeden);
	ustawiaj(cztery, trzy, dwa, jeden);
	
	
	while (check(tabgracz) != 0 && check(tabcomp) != 0) {
		shootplay();
		shootcomp(losuj(50,550),losuj(50,550));
		//wypisz();
	}
	wynik();


	wait();
}