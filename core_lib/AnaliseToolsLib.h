/* Данный заголовочный файл определяет функции, которые используются 
в процессе анализа музыкальной композиции */
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

#ifndef ANALISE_TOOL_H_
#define ANALISE_TOOL_H_

typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef short INT16;

const int N = 4; // Field size in bytes.

struct wav_header_t
{
	char rId[N]; //"RIFF" = 0x46464952
	DWORD rLen; /* 28 [+ sizeof(wExtraFormatBytes) + 
				+ wExtraFormatBytes] + sum(sizeof(chunk.id) + 
				+ sizeof(chunk.size) + chunk.size) */
	char wId[N]; //"WAVE" = 0x45564157
	char fId[N]; //"fmt " = 0x20746D66
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
	char id[N]; //"data" = 0x61746164
	DWORD size;
	//Chunk data bytes
};

DWORD *GetAmplitude(char *FPath, int *SamplesCount);
bool SearchMusic(double *frequences, double *amplitudes, char *CompositionName);

#endif
