#include "stdlib.h"

#include "AnaliseToolsLib.h"
#include "CoreLib.h"
#include "fft.h"

#define Mem_alloc_Comp(Pointer, Num) Pointer = (ShortComplex*)malloc(Num*sizeof(ShortComplex))
#define Mem_alloc_Double(Pointer, Num) Pointer = (double*)malloc(((Num+1)/2)*sizeof(double));

/* ������ ������� ���������� ���������� ������ ��� �������� � ������� ���. */
ShortComplex *FFTDataPreparetion(int SamplesCount, uint32_t *Amp)
{
    //ShortComplex *NAmp = (ShortComplex*)malloc(SamplesCount*sizeof(ShortComplex));
    ShortComplex *NAmp;
    Mem_alloc_Comp(NAmp, SamplesCount);
    //������ �������� �������� � ������������ ����� ������� ����������� �����.
    for(int i = 0; i < SamplesCount; ++i)
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
    int SamplesCount;
    //���������� ��������
    Amp = GetAmplitude(FPath, &SamplesCount);
    if(Amp == NULL)
    {
        return false;
    }
    //���������� ������ � �������������� �����
    ShortComplex *NAmp = FFTDataPreparetion(SamplesCount, Amp);
    if(NAmp == NULL)
    {
        return false;
    }
    //�������������� �����
    universal_fft(NAmp,SamplesCount,false);
    //��������� ������ � �������� �� ������ ���
    //double *Frequences = (double*)malloc(((SamplesCount+1)/2)*sizeof(double));
    double *Frequences, *Amplitudes;
    Mem_alloc_Double(Frequences, SamplesCount);
    Mem_alloc_Double(Amplitudes, SamplesCount);
    //double *Amplitudes = (double*)malloc(((SamplesCount+1)/2)*sizeof(double));
    if(!Get_Freq_Amp(NAmp, Frequences, Amplitudes, SamplesCount))
    {
        return false;
    }
    //�������� ������� ��������� �����
    *PeaksCount = SamplesCount/2;
    return true;
}
