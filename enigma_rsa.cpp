#include "enigma_rsa.hpp"

#include <cryptopp/files.h>
#include <cryptopp/osrng.h>

using namespace CryptoPP;

AutoSeededRandomPool rng;

void enigma_rsa_public::encrypt (const std::string & infile, const std::string & outfile) const
{
   RSAES_OAEP_SHA_Encryptor encryptor (publicKey_);
   FileSource pipeline (infile.c_str(), true,
      new PK_EncryptorFilter(rng, encryptor,
         new FileSink(outfile.c_str())));
}

void enigma_rsa_public::save (const std::string & filename) const
{
   ByteQueue queue;
   publicKey_.DEREncodePublicKey(queue);
   FileSink file(filename.c_str());
   queue.CopyTo(file);
   file.MessageEnd();
}

void enigma_rsa_public::load (const std::string & filename)
{
   ByteQueue queue;
   FileSource file(filename.c_str(), true);
   file.TransferTo(queue);
   queue.MessageEnd();
   publicKey_.BERDecodePublicKey(queue, false, queue.MaxRetrievable());
}

void enigma_rsa_private::decrypt (const std::string & infile, const std::string & outfile) const
{
   RSAES_OAEP_SHA_Decryptor decryptor (privateKey_);
   FileSource pipeline (infile.c_str(), true,
      new PK_DecryptorFilter(rng, decryptor,
         new FileSink(outfile.c_str())));
}

enigma_rsa_public enigma_rsa_private::getPublicKey () const
{
   RSAFunction publicKey(privateKey_);
   return enigma_rsa_public(publicKey);
}

void enigma_rsa_private::save (const std::string & filename) const
{
   ByteQueue queue;
   privateKey_.DEREncodePrivateKey(queue);
   FileSink file(filename.c_str());
   queue.CopyTo(file);
   file.MessageEnd();
}

void enigma_rsa_private::load (const std::string & filename)
{
   ByteQueue queue;
   FileSource file(filename.c_str(), true);
   file.TransferTo(queue);
   queue.MessageEnd();
   privateKey_.BERDecodePrivateKey(queue, false, queue.MaxRetrievable());
}

enigma_rsa_private generateNewPrivateKey ()
{ 
   // InvertibleRSAFunction is used because private key would not
   // be able to do anything by itself.
   CryptoPP::AutoSeededRandomPool randomNumberGenerator;
   CryptoPP::InvertibleRSAFunction privateKey;
   privateKey.Initialize(randomNumberGenerator, 1024);
   return enigma_rsa_private(privateKey);
}
