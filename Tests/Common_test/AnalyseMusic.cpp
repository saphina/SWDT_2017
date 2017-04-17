#include "stdlib.h"
#include "AnaliseToolsLib.h"
#include "CoreLib.h"
#include "fft.h"

/* Данная функция осущнаествляет анализ композиции в формате .WAV и 
последующий поиск ее в базе данных с целью определения ее названия.
В качестве аргументов функция принимает путь к файлу FPath и указатель 
на название композиции CompositionName, который на входе функции должен 
имееть значение NULL. В случае успешного определения названия 
композиции функция AnalyseMusic возвращает значение true, иначе false. */
bool AnalyseMusic(char *FPath, char *CompositionName){
	//Массив амплитуд
	DWORD *Amp = NULL;
	//Счетчик сэмплов
	int SamplesCount = NULL;
	//Вычисление амплитуд
	Amp = GetAmplitude(FPath, &SamplesCount);
	if(Amp==NULL)
	{
		printf("GetAmplitude error.\n");
		return false;
	}
	//Подготовка данных к преобразованию Фурье
	ShortComplex *NAmp = 
		(ShortComplex*)malloc(SamplesCount*sizeof(ShortComplex));
	for(int i = 0; i<SamplesCount; i++)
	{
		NAmp[i].re = (double)Amp[i];
		NAmp[i].im = 0.0;
	}
	//Преобразование Фурье
	universal_fft(NAmp,SamplesCount,false);
	//Получение частот и амплитуд из данных БПФ
	double *frequences = (double*)malloc(((SamplesCount+1)/2)*sizeof(double));
	double *amplitudes = (double*)malloc(((SamplesCount+1)/2)*sizeof(double));
	if(!Get_Freq_Amp(NAmp, frequences, amplitudes, SamplesCount))
	{
		printf("Get_Freq_Amp error\n");
	}
	//Поиск композиции в базе данных
	if(!SearchMusic(frequences, amplitudes, CompositionName))
	{
		printf("Search error.\n");
		return false;
	}
	return true;
}
