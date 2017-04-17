#include "AnaliseToolsLib.h"

/* Данная функция производит считывания .WAV файла с 
последующей записью данных в массив амплитуд. В качестве
аргументов функция принимает путь к файлу и указатель на
переменную количества отсчетов (samples). */
uint32_t *GetAmplitude(char *fPath,int *SampCount){
	
	FILE *f = fopen(fPath, "rb");
	if(f==NULL)
	{
		printf("\nError! Can't open the file");
		return NULL;
	}
	wav_header_t header;

	fread(&header, sizeof(header), 1, f);

	//printf("wFormatTag=%i\n", header.wFormatTag);
	//printf("nChannels=%i\n", header.nChannels);
	//printf("nSamplesPerSec=%li\n", header.nSamplesPerSec);
	//printf("wBitsPerSample=%i\n", header.wBitsPerSample);
	//skip wExtraFormatBytes & extra format bytes
	fseek(f, header.fLen - 16, SEEK_CUR); 

	chunk_t chunk;
	//printf("id\t" "size\n");
	while (true) //go to data chunk
	{
		fread(&chunk, sizeof(chunk), 1, f);
		/*printf("%c%c%c%c\t" "%li\n", 
			chunk.id[0], chunk.id[1], chunk.id[2], chunk.id[3], chunk.size);*/
		if (*(uint32_t *)&chunk.id == 0x61746164) break;
		fseek(f, chunk.size, SEEK_CUR); //skip chunk data bytes
	}

	int sample_size = header.wBitsPerSample / 8;
	int samples_count = chunk.size  *8 / header.wBitsPerSample;

	//printf("samples_count=%i\n", samples_count);

	uint32_t *value = new uint32_t[samples_count];
	//memset(value, 0, sizeof(uint32_t)  *samples_count);

	for (int i = 0; i < samples_count; i++)
	{
		fread(&value[i], sample_size, 1, f);
	}

	fclose(f);
	*SampCount = samples_count;
	return value;
}
