#include "enigma_ecies.hpp"
#include <iostream>

using namespace std;

int main ()
{
   cout << "Creation test!" << endl;
   ICryptosystem * testKey = newECIESPrivateKey();
   if ( testKey == 0 ) { cout << "Failed!" << endl; return 1; }
   
   cout << "Encryption test!" << endl;
   cout << "Filler!" << endl;
   testKey->encrypt("testIn","testEnc");
   cout << "Save/load test!" << endl;
   testKey->save("testKey");
   testKey->destroy();
   
   testKey = newECIESPrivateKey();
   testKey->load("testKey");
   cout << "Decryption test!" << endl;
   testKey->decrypt("testEnc","testOut");
   cout << "Destruction test!" << endl;
   testKey->destroy();

   return 0;
}
