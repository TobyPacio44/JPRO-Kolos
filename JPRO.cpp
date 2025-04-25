#include <iostream>
#include <cstdlib>
#include <time.h>

void FreeMatrix(int** tab, int n) {
	for (int i = 0; i < n; i++)
	{
		free(tab[i]);
	}
	free(tab);
}

void WriteMatrix(int** tab, int n) {

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << tab[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

}

float suma(float** tablica, int n, int m) {
	float sum = 0;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum += tablica[i][j];
		}
	}
	return sum;
}

void referencja(int& times, float& liczba) {
	if (times == 0) {
		liczba = (float)(rand()) / (float)(RAND_MAX);
	}

	std::cout << liczba << std::endl;
	liczba = 1 - (liczba * liczba);

	times++;
}

int maksind(float* t, int n, float& average) {
	int max = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (t[i] > t[max]) {
			max = i;
			sum += t[i];
		}
	}	
	average = (float)sum / n;
	return max;
}

void multiply(unsigned int n, int** tab1, int** tab2, int& suma) {
	int** tab3 = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		tab3[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++)
	{		
		for (int j = 0; j < n; j++)
		{		
			int ram = 0;
			for (int k = 0; k < n; k++)
			{
				ram += tab1[i][k] * tab2[k][j];
			}
			tab3[i][j] = ram;
		}
	}

	for (int i = 0; i < n; i++)
	{
		suma += tab3[i][i];
	}

	WriteMatrix(tab3, n);

	FreeMatrix(tab3, 2);
}

int convert1(double value) {
	return (int)value;
}

int convert2(double value) {
	return (int)(value + 0.5);
}

int choice() {
	int choice = 0;
	std::cout << "Wybierz opcje konwersji" << std::endl;
	std::cout << "1. Obciecie czesci ulamkowej" << std::endl;
	std::cout << "2. Zaokraglenie czesci ulamkowej" << std::endl;
	std::cin >> choice;

	return choice;
}

int main()
{
	//-----------------Zad1-------------------
	/*float** tablica = (float**)malloc(100 * sizeof(float*));		
	srand(time(NULL));

	for(int i = 0; i < 100; i++)
	{
		tablica[i] = (float*)malloc(200 * sizeof(float));

		for (int j = 0; j < 200; j++)
		{
			int x = rand() % 3000001 - 1000000;
			tablica[i][j] = x;
		}
	}

	std::cout << suma(tablica, 100, 200) << std::endl;

	for (int i = 0; i < 100; i++)
	{
		free(tablica[i]);
	}
	free(tablica);*/

	//-----------------Zad2-------------------
	/*srand(time(NULL));
	int times = 0;
	float liczba = 0;
	int n = 1 + rand() % 100000;

	for (int i = 0; i < 10; i++)
	{
		referencja(times, liczba);
	}

	std::cout << times << std::endl;
	std::cout << liczba << std::endl;*/

	//-----------------Zad3-------------------
	/*srand(time(NULL));

	float average = 0;
	int n = rand() % 100;
	float* t = (float*)malloc(n * sizeof(float));

	for (int i = 0; i < n; i++)
	{
		t[i] = (float)(rand() % 2062 - 1028);
	}

	std::cout << n << std::endl;
	std::cout << "Index max: " << maksind(t, n, average) << std::endl;
	std::cout << "Average: " << average <<std::endl;*/

	//-----------------Zad4-------------------

	/*int** tab1 = (int**)malloc(3 * sizeof(int*));
	int** tab2 = (int**)malloc(3 * sizeof(int*));
	int suma = 0;


	srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		tab1[i] = (int*)malloc(3 * sizeof(int));
		tab2[i] = (int*)malloc(3 * sizeof(int));
		for (int j = 0; j < 3; j++)
		{
			tab1[i][j] = rand() % 10;
			tab2[i][j] = rand() % 10;
		}
	}

	WriteMatrix(tab1, 3);
	WriteMatrix(tab2, 3);

	std::cout << std::endl;

	multiply(3, tab1, tab2, suma);
	std::cout << "Suma" << suma << std::endl;

	FreeMatrix(tab1, 2);
	FreeMatrix(tab2, 2);

	tab1 = nullptr;
	tab2 = nullptr; */

	//-----------------Zad5-------------------

	/*double number = 5.5;
	int value = choice();


	if (value == 1) {
		std::cout << convert1(number) << std::endl;
	}
	else if (value == 2) {
		std::cout << convert2(number) << std::endl;
	}
	else {
		std::cout << "Nie ma takiej opcji" << std::endl;
	}*/

	return 0;
}


