all: CreateLib
	g++ -c main.cpp
	g++ main.o -L. -static -lMSA -o common_test
CreateLib: Compile_o
	ar rc libMSA.a AnalyseMusic.o FFT.o Freq_Amp.o GetAmplitude.o SearchMusic.o
	ranlib libMSA.a
Compile_o:
	g++ -c AnalyseMusic.cpp FFT.cpp Freq_Amp.cpp GetAmplitude.cpp SearchMusic.cpp
clean:
	rm -rf *.o CreateLib