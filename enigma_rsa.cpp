#include "enigma_rsa.hpp"

#include <cryptopp/files.h>

rsa_key_public::encrypt (const std::string & infile, const std::string & outfile) const
{
   RSAES_OAEP_SHA_Encryptor encryptor (publicKey_);
   FileSource (infile.c_str(), true,
      new PK_EncryptorFilter(encryptor,
         new FileSink(outfile.c_str())));
}

rsa_key_public::save (const std::string & filename) const
{
   ByteQueue queue;
   key.DEREncodePublicKey(queue);
   FileSink file(filename.c_str());
   queue.CopyTo(file);
   file.MessageEnd();
}

rsa_key_public::load (const std::string & filename)
{
   ByteQueue queue;
   FileSource file(filename.c_str(), true);
   file.TransferTo(queue);
   queue.MessageEnd();
   key.BERDecodePublicKey(queue, false, queue.MaxRetrievable());
}

rsa_key_private::decrypt (const std::string & infile, const std::string & outfile)
{
   RSAES_OAEP_SHA_Decryptor decryptor (privateKey_);
   FileSource (infile.c_str(), true,
      new PK_DecryptorFilter(decryptor,
         new FileSink(outfile.c_str())));
}

rsa_key_private::save (const std::string & filename) const
{
   ByteQueue queue;
   key.DEREncodePrivateKey(queue);
   FileSink file(filename.c_str());
   queue.CopyTo(file);
   file.MessageEnd();
}

rsa_key_private::load (const std::string & filename)
{
   ByteQueue queue;
   FileSource file(filename.c_str(), true);
   file.TransferTo(queue);
   queue.MessageEnd();
   key.BERDecodePrivateKey(queue, false, queue.MaxRetrievable());
}
