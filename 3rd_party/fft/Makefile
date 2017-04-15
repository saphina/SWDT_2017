#Переменная с именем заголовочного файла БПФ
header = fft.h
#Переменная с именем исходного кода функции БПФ
source = FFT.cpp
#Переменная с именем собираемой библиотеки БПФ
library = libFFT.a
#Переменные для удаления файлов
clean_list = $(clean_obj) $(clean_lib) $(clean_gch)
clean_obj = *.o
clean_lib = *.a
clean_gch = *.gch
#Флаги
clean_flags = -rf
compile_flags = -c

all: $(header) $(source)
	g++ $(compile_flags) $^
	ar rc $(library) FFT.o
	ranlib $(library)
clean:
	rm $(clean_flags) $(clean_list)
clean_obj:
	rm $(clean_flags) $(clean_obj)
clean_lib:
	rm $(clean_flags) $(clean_lib)
clean_gch:
	rm $(clean_flags) $(clean_gch)
