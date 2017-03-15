/*������ ������������ ���� ���������� �������, ������� ������������ � �������� ������� ����������� ����������.
*/
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "stdafx.h"
#include <conio.h>

typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef short INT16;

struct wav_header_t
{
	char rId[4]; //"RIFF" = 0x46464952
	DWORD rLen; //28 [+ sizeof(wExtraFormatBytes) + wExtraFormatBytes] + sum(sizeof(chunk.id) + sizeof(chunk.size) + chunk.size)
	char wId[4]; //"WAVE" = 0x45564157
	char fId[4]; //"fmt " = 0x20746D66
	DWORD fLen; //16 [+ sizeof(wExtraFormatBytes) + wExtraFormatBytes]
	WORD wFormatTag;
	WORD nChannels;
	DWORD nSamplesPerSec;
	DWORD nAvgBytesPerSec;
	WORD nBlockAlign;
	WORD wBitsPerSample;
	//[WORD wExtraFormatBytes;]
	//[Extra format bytes]
};

struct chunk_t
{
	char id[4]; //"data" = 0x61746164
	DWORD size;
	//Chunk data bytes
};

DWORD* GetAmplitude(char* ,int*);
bool FFT(DWORD*,int,float*);
bool SearchMusic(float*,char*);