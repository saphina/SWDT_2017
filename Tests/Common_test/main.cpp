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
	printf("������� ���� � �����: ");
	scanf("%s",fPath);
	if(!AnalyseMusic(fPath, CompositionName))
	{
		printf("������ �� ���������� ������� AnalyseMusic.\n");		
		_getch();
		return 0;
	}
	if(strcmp(CompositionName,"� ���� �������� ������")==0)
	{
		printf("���������� ������ ��������\n", &CompositionName);
		printf("Composition name - \"%s\"\n", &CompositionName);
	}
	else
	{
		printf("���������� ��������� ��������\n", &CompositionName);
		_getch();
		return 0;
	}
	_getch();
	return 0;
}

