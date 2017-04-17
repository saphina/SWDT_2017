#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include "CoreLib.h"

int main()
{
	setlocale( LC_ALL,"Russian" );
	char fPath[250];
	char CompositionName[100];
	printf("Введите путь к файлу: ");
	scanf("%s",fPath);
	if(!AnalyseMusic(fPath, CompositionName))
	{
		printf("Ошибка по исполнении функции AnalyseMusic.\n");		
		_getch();
		return 0;
	}
	if(strcmp(CompositionName,"В лесу родилась елочка")==0)
	{
		printf("Возвращено верное значение\n", &CompositionName);
		printf("Composition name - \"%s\"\n", &CompositionName);
	}
	else
	{
		printf("Возвращено ошибочное значение\n", &CompositionName);
		_getch();
		return 0;
	}
	_getch();
	return 0;
}

