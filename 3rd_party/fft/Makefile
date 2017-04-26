#Переменная с именем заголовочного файла БПФ
header = fft.h
#Переменная с именем исходного кода функции БПФ
source = FFT.cpp
#Переменная с именем собираемой библиотеки БПФ
library = libFFT.a
#Переменные для удаления файлов
clean_list = *.o *.gch *.a
#Флаги
clean_flags = -rf
compile_flags = -c

all: $(header) $(source)
    g++ $(compile_flags) $^
    ar rc $(library) FFT.o
    ranlib $(library)
clean:
    rm $(clean_flags) $(clean_list)