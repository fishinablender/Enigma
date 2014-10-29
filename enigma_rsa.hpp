#ifndef ENIGMA_RSA_HPP
#define ENIGMA_RSA_HPP

#include "icryptosystem.hpp"
#include <cryptopp/rsa.h>
#include <string>

/**
 * \class enigma_rsa_public
 * \brief Handles public key information.
 * 
 * \author J.T. Davies
 * 
 * This class acts as an abstraction layer between the main program and the underlying cryptography library.
 */
class enigma_rsa_public: public ICryptosystem
{
public:
   /// Default constructor.
   enigma_rsa_public () {}
   /// Copy constructor.
   enigma_rsa_public (const enigma_rsa_public & other) : publicKey_(other.publicKey_) {}
   /// Move constructor.
   enigma_rsa_public (enigma_rsa_public && other) : publicKey_(std::move(other.publicKey_)) {}
   
   /**
    * Constructs a [projectname] public key type from a Crypto++ public key.
    * 
    * \param key Public key provided by Crypto++.
    */
   enigma_rsa_public (const RSA::PublicKey & key) : publicKey_(key) {}
   
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

class enigma_rsa_private: public enigma_rsa_public
{
public:
   /// Default constructor.
   enigma_rsa_private () {}
   /// Copy constructor.
   enigma_rsa_private (const enigma_rsa_private & other) : enigma_rsa_public(other), privateKey_(other.privateKey_) {}
   /// Move constructor.
   enigma_rsa_private (enigma_rsa_private && other) : enigma_rsa_public(std::move(other)), privateKey_(std::move(other.privateKey_)) {}
   
   /**
    * Constructs a private key container from a Crypto++ key.
    * 
    * \param public_key Public key provided by Crypto++.
    * \param private_key Private key provided by Crypto++.
    */
   enigma_rsa_private (const RSA::PrivateKey & privateKey) : enigma_rsa_public(publicKey(private_key)), privateKey_(privateKey) {}
   
   
   // 
   virtual void decrypt (const std::string & infile, const std::string & outfile) const;
   virtual bool has_private () const noexcept { return true; }
   virtual void save (const std::string & filename) const;
   virtual void load (const std::string & filename);
private:
   /// RSA private key object from Crypto++.
   RSA::PrivateKey privateKey_;
};

#endifz