#include "enigma_ecies.hpp"

void ecies_public_key::encrypt (const std::string & infile, const std::string & outfile) const;
{
   FileSource(infile.c_str(),
      new PK_EncryptorFilter(rng, privateKey_,
         new FileSink(outfile.c_str())));
}

void ecies_public_key::save (const std::string & filename) const;
{
   // Create sink object to stream data into
   FileSink sink (filename.c_str());
   // Save key
   publicKey_.GetPublicKey().Save(sink);
}

void ecies_public_key::load (const std::string & filename)
{
   FileSource source (filename.c_str());
   publicKey_.AccessPublic().Load(source);
}

void ecies_private_key::decrypt (const std::string & infile, const std::string & outfile) const
{
   FileSource(infile.c_str(),
      new PK_DecryptorFilter(rng, privateKey_,
         new FileSink(outfile.c_str())));
}

void ecies_private_key::save (const std::string & filename) const
{
   // Create sink object to stream data into
   FileSink sink (filename.c_str());
   // Save key
   privateKey_.GetPrivateKey().Save(sink);
}

void ecies_private_key::load (const std::string & filename)
{
   FileSource source (filename.c_str());
   privateKey_.AccessPrivateKey().Load(source);
}