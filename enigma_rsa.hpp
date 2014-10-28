#ifndef ENIGMA_RSA_HPP
#define ENIGMA_RSA_HPP

#include "icryptosystem.hpp"
#include <cryptopp/rsa.h>
#include <string>

/**
 * \class rsa_key_public
 * \brief Handles public key information.
 * 
 * \author J.T. Davies
 * 
 * This class acts as an abstraction layer between the main program and the underlying cryptography library.
 */
class rsa_key_public: public ICryptosystem
{
public:
   /// Default constructor.
   rsa_key_public () {}
   /// Copy constructor.
   rsa_key_public (const rsa_key_public & other) : publicKey_(other.publicKey_) {}
   /// Move constructor.
   rsa_key_public (rsa_key_public && other) : publicKey_(std::move(other.publicKey_)) {}
   
   /**
    * Constructs a [projectname] public key type from a Crypto++ public key.
    * 
    * \param key Public key provided by Crypto++.
    */
   rsa_key_public (const RSA::PublicKey & key) : publicKey_(key) {}
   
   virtual void encrypt (const std::string & infile, const std::string & outfile) const;
   virtual void decrypt (const std::string & infile, const std::string & infile) const
   {
      // throw an exception rather than do nothing
   }
   
   virtual void save (const std::string & filename) const;
   virtual void load (const std::string & filename);
private:
   /// RSA public key object from Crypto++.
   RSA::PublicKey publicKey_;
};

class rsa_key_private: public rsa_key_public
{
public:
   /// Default constructor.
   rsa_key_private () {}
   /// Copy constructor.
   rsa_key_private (const rsa_key_private & other) : rsa_key_public(other), privateKey_(other.privateKey_) {}
   /// Move constructor.
   rsa_key_private (rsa_key_private && other) : rsa_key_public(std::move(other)), privateKey_(std::move(other.privateKey_)) {}
   
   /**
    * Constructs a private key container from a Crypto++ key.
    * 
    * \param public_key Public key provided by Crypto++.
    * \param private_key Private key provided by Crypto++.
    */
   rsa_key_private (const RSA::PrivateKey & privateKey) : rsa_key_public(publicKey(private_key)), privateKey_(privateKey) {}
   
   
   // 
   virtual void decrypt (const std::string & infile, const std::string & outfile) const;
   virtual bool has_private () const noexcept { return true; }
   virtual void save (const std::string & filename) const;
   virtual void load (const std::string & filename);
private:
   /// RSA private key object from Crypto++.
   RSA::PrivateKey privateKey_;
};

#endif