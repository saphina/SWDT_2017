#include "stdlib.h"
#include "AnaliseToolsLib.h"
#include "CoreLib.h"
#include "fft.h"

/* Данная функция производит подготовку данных для передачи в функция БПФ. */
ShortComplex *FFTDataPreparetion(int SamplesCount, uint32_t *Amp)
{
	ShortComplex *NAmp = (ShortComplex*)malloc(SamplesCount*sizeof(ShortComplex));
	//Запись значений амплитуд в вещественную часть массива комплексных чисел.
	for(int i = 0; i<SamplesCount; i++)
	{
		NAmp[i].re = (double)Amp[i];
		NAmp[i].im = 0.0;
	}
	return NAmp;
}

/* Данная функция производит анализ композиции. В качестве аргументов
функция принимает путь к файлу .WAV, пустой указатель на массив пиков
частот, пустой указатель на массив пиков амплитуд и указатель на 
количество пиков. */
bool AnalyseMusic(char *FPath, double *&FrequencesPeaks, double *&AmplitudesPeaks, int *PeaksCount){
	//Массив амплитуд
	uint32_t *Amp = NULL;
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
	ShortComplex *NAmp = FFTDataPreparetion(SamplesCount, Amp);
	if(NAmp == NULL)
	{
		printf("FFTDatapreparetion error.\n");
		return false;
	}
	//Преобразование Фурье
	universal_fft(NAmp,SamplesCount,false);
	//Получение частот и амплитуд из данных БПФ
	double *Frequences = (double*)malloc(((SamplesCount+1)/2)*sizeof(double));
	double *Amplitudes = (double*)malloc(((SamplesCount+1)/2)*sizeof(double));
	if(!Get_Freq_Amp(NAmp, Frequences, Amplitudes, SamplesCount))
	{
		printf("Get_Freq_Amp error\n");
	}
	//ДОБАВИТЬ ФУНКЦИЮ ВЫДЕЛЕНИЯ ПИКОВ
	*PeaksCount = SamplesCount/2;
	return true;
}
