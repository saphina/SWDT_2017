MSALib.a: AnalyseMusic.o FFT.o Freq_Amp.o GetAmplitude.o SearchMusic.o
	ar rv $@ $^
AnalyseMusic.o: 
	g++ -c $^ AnalyseMusic.cpp
FFT.o: 
	g++ -c $^ FFT.cpp
Freq_Amp.o: 
	g++ -c $^ Freq_Amp.cpp
GetAmplitude.o: 
	g++ -c $^ GetAmplitude.cpp
SearchMusic.o: 
	g++ -c $^ SearchMusic.cpp
clean:
	rm -f MSALib.a *.o