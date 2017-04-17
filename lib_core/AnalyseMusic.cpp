#include "stdlib.h"
#include "AnaliseToolsLib.h"
#include "CoreLib.h"
#include "fft.h"

/* ������ ������� ���������� ���������� ������ ��� �������� � ������� ���. */
ShortComplex *FFTDataPreparetion(int SamplesCount, uint32_t *Amp)
{
	ShortComplex *NAmp = (ShortComplex*)malloc(SamplesCount*sizeof(ShortComplex));
	//������ �������� �������� � ������������ ����� ������� ����������� �����.
	for(int i = 0; i<SamplesCount; i++)
	{
		NAmp[i].re = (double)Amp[i];
		NAmp[i].im = 0.0;
	}
	return NAmp;
}

/* ������ ������� ���������� ������ ����������. � �������� ����������
������� ��������� ���� � ����� .WAV, ������ ��������� �� ������ �����
������, ������ ��������� �� ������ ����� �������� � ��������� �� 
���������� �����. */
bool AnalyseMusic(char *FPath, double *&FrequencesPeaks, double *&AmplitudesPeaks, int *PeaksCount){
	//������ ��������
	uint32_t *Amp = NULL;
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
	ShortComplex *NAmp = FFTDataPreparetion(SamplesCount, Amp);
	if(NAmp == NULL)
	{
		printf("FFTDatapreparetion error.\n");
		return false;
	}
	//�������������� �����
	universal_fft(NAmp,SamplesCount,false);
	//��������� ������ � �������� �� ������ ���
	double *Frequences = (double*)malloc(((SamplesCount+1)/2)*sizeof(double));
	double *Amplitudes = (double*)malloc(((SamplesCount+1)/2)*sizeof(double));
	if(!Get_Freq_Amp(NAmp, Frequences, Amplitudes, SamplesCount))
	{
		printf("Get_Freq_Amp error\n");
	}
	//�������� ������� ��������� �����
	*PeaksCount = SamplesCount/2;
	return true;
}
