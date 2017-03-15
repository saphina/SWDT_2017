/*Данная функция осущнаествляет анализ композиции в формате .WAV и последующий поиск ее в базе данных с целью определения ее названия.
В качестве аргументов функция принимает путь к файлу FPath и указатель на название композиции CompositionName, который на входе функции должен 
имееть значение NULL. В случае успешного определения названия композиции функция AnalyseMusic возвращает значение true, иначе false.
*/

#include "AnaliseToolsLib.h"
#include "CoreLib.h"

bool AnalyseMusic(char* FPath, char* CompositionName){
	DWORD* Amplitudes=NULL;//Массив амплитуд
	int SamplesCount=NULL;//Счетчик сэмплов
	float* Rdat=NULL;//Вещественная часть комплексного числа для преобразования фурье
	//Вычисление амплитуд
	Amplitudes=GetAmplitude(FPath,&SamplesCount);
	if(Amplitudes==NULL){printf("GetAmplitude error.\n");return false;}
	//Преобразование Фурье
	if(!FFT(Amplitudes,SamplesCount,Rdat)){ printf("FFT error.\n");return false;}
	//Поиск композиции в базе данных
	if(!SearchMusic(Rdat,CompositionName)){printf("Search error.\n");return false;}
	return true;
}