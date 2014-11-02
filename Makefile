compflags=--std=c++0x
libraries=-lcryptopp -lstdc++

all: enigmacli

clean:
	rm -f enigmacli *.o

enigmacli: test.cpp enigma_rsa.o
	gcc -o enigmacli $(compflags) test.cpp enigma_rsa.o $(libraries)

enigma_ecies.o: enigma_ecies.hpp enigma_ecies.cpp
	gcc -c $(compflags) enigma_ecies.cpp

enigma_rsa.o: enigma_rsa.hpp enigma_rsa.cpp
	gcc -c $(compflags) enigma_rsa.cpp
