/* Данный заголовочный файл определяет функции, которые используются 
в процессе анализа музыкальной композиции */
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdint.h>
#include "fft.h"

#ifndef ANALISE_TOOL_H_
#define ANALISE_TOOL_H_

const int N = 4; // Field size in bytes.

struct wav_header_t
{
	char rId[N]; //"RIFF" = 0x46464952
	uint32_t rLen; /* 28 [+ sizeof(wExtraFormatBytes) + 
				+ wExtraFormatBytes] + sum(sizeof(chunk.id) + 
				+ sizeof(chunk.size) + chunk.size) */
	char wId[N]; //"WAVE" = 0x45564157
	char fId[N]; //"fmt " = 0x20746D66
	uint32_t fLen; //16 [+ sizeof(wExtraFormatBytes) + wExtraFormatBytes]
	uint16_t wFormatTag;
	uint16_t nChannels;
	uint32_t nSamplesPerSec;
	uint32_t nAvgBytesPerSec;
	uint16_t nBlockAlign;
	uint16_t wBitsPerSample;
	//[WORD wExtraFormatBytes;]
	//[Extra format bytes]
};

struct chunk_t
{
	char id[N]; //"data" = 0x61746164
	uint32_t size;
	//Chunk data bytes
};

uint32_t *GetAmplitude(char *FPath, int *SamplesCount);
bool Get_Freq_Amp(ShortComplex *arr, double *freq, double *amp, int N);
#endif
