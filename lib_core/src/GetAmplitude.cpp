#include "AnaliseToolsLib.h"

/* Данная функция производит считывания .WAV файла
с последующей записью данных в массив амплитуд. В качестве
аргументов функция принимает путь к файлу и указатель на
переменную количества отсчетов (samples). */
uint32_t *GetAmplitude(char *fPath, int *SampCount){
	
    FILE *f = fopen(fPath, "rb");
    if(f == NULL)
    {
        return NULL;
    }
    WavHeader header;

    fread(&header, sizeof(header), 1, f);

    //skip wExtraFormatBytes & extra format bytes
    fseek(f, header.fLen - 16, SEEK_CUR); 

    ChunkT chunk;
    while (true) //go to data chunk
    {
        fread(&chunk, sizeof(chunk), 1, f);
        if (*(uint32_t *)&chunk.id == 0x61746164)
        {
            break;
        }
        fseek(f, chunk.size, SEEK_CUR); //skip chunk data bytes
    }
    
    int SampleSize = header.wBitsPerSample / BiB;
    int SamplesCount = chunk.size  *8 / header.wBitsPerSample;

    uint32_t *value = new uint32_t[SamplesCount];

    for (int i = 0; i < SamplesCount; ++i)
    {
        fread(&value[i], SampleSize, 1, f);
    }

    fclose(f);
    *SampCount = SamplesCount;
    return value;
}
