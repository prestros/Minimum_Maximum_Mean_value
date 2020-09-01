// Programm zum Berechnen des Mittelwertes, Ermitteln des Maximums und des Minimums und Sortieren von Zahlen
// Autor: Fabian Prestros
// Datum: 01.09.2020
#include <stdio.h>
#include <float.h>										// Enthält Maximum und Minimum des Double

double einlesen(char koef[31])
{
	int chk;
	double zahl;

	do													// In einer Schleife einlesen, bis eine korrekte Zahl eingelesen wurde
	{
		printf("%s = ", koef);
		chk = scanf_s("%lf", &zahl);
		while (getchar() != '\n');						// Tastaturpuffer leeren.
		if (chk == 0)									// Fehlermeldung, wenn scanf_s meldet, dass keine Ganze Zahl eingegeben wurde
			printf("Bite geben Sie eine Zahl ein!\n");
	} while (chk == 0);									// Schleifendurchlauf, bis kein Fehler mehr vorliegt.

	return zahl;
}

int eingeben(double a[10000], int n)
// Einlesen der vorgegebenen Anzahl an Zahlen
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d. ",  i + 1);
		a[i] = einlesen("Zahl");
	}
}

int schaetzer(double a[10000], int n)
// Berechnen des Mittelwertes und Ermitteln des Maximums und des Minimums
{
	int i;
	double min = DBL_MAX_EXP, max = DBL_MIN_EXP, summe = 0, mittelwert;

	for (i = 0; i < n; i++)
	{
		summe = summe + a[i];
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			 min = a[i];
	}
	mittelwert = summe / n;

	printf("Minimum = %lf\n", min);
	printf("Maximum = %lf\n", max);
	printf("Mittelwert = %lf\n", mittelwert);
}

void bubbelsort(double a[10000], int n)
// Beispiel bubbleSort2 entsprechend https://de.wikipedia.org/wiki/Bubblesort
{
	int i, getauscht;
	double temp;

	do
	{
		getauscht = 0;
		for (i = 0; i < n - 1; i++)
			if (a[i] > a[i + 1])
			{
				temp = a[i + 1];
				a[i + 1] = a[i];
				a[i] = temp;
				getauscht = 1;
			}
	} while (getauscht != 0);
}

void ausgabe(double a[10000], int n)
// Ausgabe der Zahlen in Arrays a
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d. Zahl = ", i + 1);
		printf("%lf\n", a[i]);
	}
		
}

int main()
{
	int n;
	double a[10000];
	
	n = einlesen("Anzahl der einzulesenden Zahlen");
	if (n > 10000)
		n = 10000;
	eingeben(a, n);
	schaetzer(a, n);
	bubbelsort(a, n);
	ausgabe(a, n);
}