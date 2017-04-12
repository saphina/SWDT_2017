#include "stdlib.h"
#include "AnaliseToolsLib.h"
#include "CoreLib.h"
#include "fft.h"

/* ������ ������� �������������� ������ ���������� � ������� .WAV � 
����������� ����� �� � ���� ������ � ����� ����������� �� ��������.
� �������� ���������� ������� ��������� ���� � ����� FPath � ��������� 
�� �������� ���������� CompositionName, ������� �� ����� ������� ������ 
������ �������� NULL. � ������ ��������� ����������� �������� 
���������� ������� AnalyseMusic ���������� �������� true, ����� false. */
bool AnalyseMusic(char *FPath, char *CompositionName){
	//������ ��������
	DWORD *Amp = NULL;
	//������� �������
	int SamplesCount = NULL;
	//���������� ��������
	Amp = GetAmplitude(FPath, &SamplesCount);
	if(Amp==NULL)
	{
		printf("GetAmplitude error.\n");
		return false;
	}
	//���������� ������ � �������������� �����
	ShortComplex *NAmp = 
		(ShortComplex*)malloc(SamplesCount*sizeof(ShortComplex));
	for(int i = 0; i<SamplesCount; i++)
	{
		NAmp[i].re = (double)Amp[i];
		NAmp[i].im = 0.0;
	}
	//�������������� �����
	universal_fft(NAmp,SamplesCount,false);
	//��������� ������ � �������� �� ������ ���
	double *frequences = (double*)malloc(((SamplesCount+1)/2)*sizeof(double));
	double *amplitudes = (double*)malloc(((SamplesCount+1)/2)*sizeof(double));
	if(!Get_Freq_Amp(NAmp, frequences, amplitudes, SamplesCount))
	{
		printf("Get_Freq_Amp error\n");
	}
	//����� ���������� � ���� ������
	if(!SearchMusic(frequences, amplitudes, CompositionName))
	{
		printf("Search error.\n");
		return false;
	}
	return true;
}
