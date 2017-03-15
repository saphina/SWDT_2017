/*������ ������� �������������� ������ ���������� � ������� .WAV � ����������� ����� �� � ���� ������ � ����� ����������� �� ��������.
� �������� ���������� ������� ��������� ���� � ����� FPath � ��������� �� �������� ���������� CompositionName, ������� �� ����� ������� ������ 
������ �������� NULL. � ������ ��������� ����������� �������� ���������� ������� AnalyseMusic ���������� �������� true, ����� false.
*/

#include "AnaliseToolsLib.h"
#include "CoreLib.h"

bool AnalyseMusic(char* FPath, char* CompositionName){
	DWORD* Amplitudes=NULL;//������ ��������
	int SamplesCount=NULL;//������� �������
	float* Rdat=NULL;//������������ ����� ������������ ����� ��� �������������� �����
	//���������� ��������
	Amplitudes=GetAmplitude(FPath,&SamplesCount);
	if(Amplitudes==NULL){printf("GetAmplitude error.\n");return false;}
	//�������������� �����
	if(!FFT(Amplitudes,SamplesCount,Rdat)){ printf("FFT error.\n");return false;}
	//����� ���������� � ���� ������
	if(!SearchMusic(Rdat,CompositionName)){printf("Search error.\n");return false;}
	return true;
}