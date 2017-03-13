// ConsoleApplication17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 1, k = 0, i;
	char s1[20], s2[20];
	FILE *pF1, *pF2;
	fopen_s(&pF1, "C:\\Users\\Валерий\\Documents\\file1.txt", "rt");
	if (pF1 == 0)
	{
		printf("Error. File not found");
		system("pause");
		return 1;
	}
	fprintf(pF1, "\n");
	fseek(pF1, 0, SEEK_SET);
	fopen_s(&pF2, "C:\\Users\\Валерий\\Documents\\file2.txt", "rt");
	if (pF2 == 0)
	{
		printf("Error. File not found");
		system("pause");
		return 2;
	}
	while (!feof(pF1))
	{
		fgets(s1, 20, pF1);
		if (s1[strlen(s1) - 1] == '\n') s1[strlen(s1) - 1] = s1[strlen(s1)];
		while (!feof(pF2))
		{
			fgets(s2, 20, pF2);
			if (s2[strlen(s2) - 1] == '\n') s2[strlen(s2) - 1] = s2[strlen(s2)];
			if (strcmp(s1, s2)==0)  k = 1;
		}
		if (k == 0)
		{
			printf("file1 %d ", n);
			for (i = 0; i <= strlen(s1); ++i)
				printf("%c", s1[i]);
			cout << endl;
		}
		fclose(pF2);
		fopen_s(&pF2, "C:\\Users\\Валерий\\Documents\\file2.txt", "rt");
		k = 0;
		n++;
	}
	fclose(pF1);
	fopen_s(&pF1, "C:\\Users\\Валерий\\Documents\\file1.txt", "rt");
	fclose(pF2);
	fopen_s(&pF2, "C:\\Users\\Валерий\\Documents\\file2.txt", "rt");
	n = 1;
	k = 0;
	while (!feof(pF2))
	{
		fgets(s2, 20, pF2);
		if (s2[strlen(s2) - 1] == '\n') s2[strlen(s2) - 1] = s2[strlen(s2)];
		while (!feof(pF1))
		{
			fgets(s1, 20, pF1);
			if (s1[strlen(s1) - 1] == '\n') s1[strlen(s1) - 1] = s1[strlen(s1)];
			if (strcmp(s1, s2) == 0)  k = 1;
		}
		if (k == 0)
		{
			printf("file2 %d ", n);
			for (i = 0; i <= strlen(s2); ++i)
				printf("%c", s2[i]);
			cout << endl;
		}
		fclose(pF1);
		fopen_s(&pF1, "C:\\Users\\Валерий\\Documents\\file1.txt", "rt");
		k = 0;
		n++;
	}
	fclose(pF1);
	fclose(pF2);
	system("pause");
	return 0;
}

