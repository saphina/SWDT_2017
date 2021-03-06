#include <math.h>

#include "fft.h"
#define nSamplesPerSec 44100.0

/* ������ ������� ���������� ��������� ����������� ���������� �������
���. ������� � �������� ���������� ��������� ��������� �� ������
������ �� ���, ��������� �� ������ ������, ��������� �� ������ ��������
� ���������� �������� (samples). */
bool Get_Freq_Amp(ShortComplex *arr, double *freq, double *amp, int N)
{
    //��� ����������� �����, ��������� ������� ����������� �������������� �����
    //ShortComplex - ��� ��������� � ������: double re, im;
    //��� ������ ������������ ����� � ������� arr
    int i = N - 1;
    //��� ������� �������������
    //double nSamplesPerSec = 44100.0;
    //������� ���������� ������, ������ ���������� ������ ��������
    int Nmax = (N + 1) / 2; 
    //�� ����� �������� ������ ��������.
    //��� ������ ��������, ������ ������ � ������ ��� ��� ������ ���������
    //freq= new double[Nmax];
    //amp= new double[Nmax];
    
    //��� ������ ���������. � ����� ��������� �� ����� ����� ���������� 
    //��������� ��������
    int j = 0;
    
    //��� ������ ������ ��������� ���������. ��� ����� ���� ����� ������ ����
    //� ����������� �� ����, ����� ��������� �� ������� �������� ������.
    double limit = 0.001;
    
    //��������������� ���������� ��� �����������
    double abs2min = pow(limit, 2) * N * N;
    
    //�������� ���������� ������������
    if (arr[i].re >= limit)
    {
        amp[j] = arr[i].re / N;
        freq[j] = 0.0;
        ++j;
    }
    //�������� ��������� ���������
    for(i = 1; i < Nmax; ++i)
    {
        double re = arr[i].re;
        double im = arr[i].im;
        //��� ������� ������ ������������ ����� arr[i]
        double abs2 = re  *re + im  *im;
        //����������� ������� ������ ���������
        if (abs2 < abs2min)
            continue;
        //��������� ���������. 2.0 - ��� ���������� ����������� �������
        amp[j] = 2.0  *sqrt(abs2) / N;
        //�������� �������
        freq[j] = (nSamplesPerSec  *i) / N;
        ++j;
    }
    return true;
}
