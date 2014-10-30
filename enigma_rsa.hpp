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
   /// Copy assignment.
   const enigma_rsa_public & operator= (const enigma_rsa_public & other) { publicKey_ = other.publicKey_; }
   /// Move assignment.
   const enigma_rsa_public & operator= (enigma_rsa_public && other) { publicKey_ = std::move(other.publicKey_); }
   
   /**
    * Constructs a [projectname] public key type from a Crypto++ public key.
    * 
    * \param key Public key provided by Crypto++.
    */
   enigma_rsa_public (const CryptoPP::RSA::PublicKey & key) : publicKey_(key) {}
   
   virtual enigma_rsa_public * clone () const { return new enigma_rsa_public(*this); } 
   virtual void destroy () { delete this; }
   
   virtual void encrypt (const std::string & infile, const std::string & outfile) const;
   virtual void decrypt (const std::string & infile, const std::string & outfile) const
   {
      // throw an exception rather than do nothing
   }
   
   virtual void save (const std::string & filename) const;
   virtual void load (const std::string & filename);
private:
   /// RSA public key object from Crypto++.
   CryptoPP::RSA::PublicKey publicKey_;
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
   /// Copy assignment.
   const enigma_rsa_private & operator= (const enigma_rsa_private & other) { *((enigma_rsa_public *)(this)) = other; privateKey_ = other.privateKey_; return *this; }
   /// Move assignment.
   const enigma_rsa_private & operator= (enigma_rsa_private && other) { *((enigma_rsa_public *)(this)) = std::move(other); privateKey_ = std::move(other.privateKey_); return *this; }

   virtual enigma_rsa_private * clone () const { return new enigma_rsa_private(*this); }
   virtual void destroy () { delete this; }
   
   /**
    * Constructs a private key container from a Crypto++ key.
    * 
    * \param public_key Public key provided by Crypto++.
    * \param private_key Private key provided by Crypto++.
    */
   enigma_rsa_private (const CryptoPP::RSA::PrivateKey & privateKey) : enigma_rsa_public(privateKey), privateKey_(privateKey) {}
   
   
   // encrypt a file 
   virtual void decrypt (const std::string & infile, const std::string & outfile) const;
   virtual bool has_private () const noexcept { return true; }
   virtual void save (const std::string & filename) const;
   virtual void load (const std::string & filename);
private:
   /// RSA private key object from Crypto++.
   CryptoPP::RSA::PrivateKey privateKey_;
};

enigma_rsa_private generateRSAPrivateKey ();

#endif
