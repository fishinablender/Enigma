compflags=--std=c++0x
libraries=-lcryptopp -lstdc++

all: ecies_test enigmacli

clean:
	rm -f ecies_test enigmacli *.o

ecies_test: enigma_ecies.o ecies_test.cpp
	gcc -o ecies_test $(compflags) ecies_test.cpp enigma_ecies.o $(libraries)

enigmacli: test.cpp enigma_rsa.o
	gcc -o enigmacli $(compflags) test.cpp enigma_rsa.o $(libraries)

enigma_ecies.o: enigma_ecies.hpp enigma_ecies.cpp
	gcc -c $(compflags) enigma_ecies.cpp

enigma_rsa.o: enigma_rsa.hpp enigma_rsa.cpp
	gcc -c $(compflags) enigma_rsa.cpp
