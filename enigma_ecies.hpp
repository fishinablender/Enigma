#ifndef ENIGMA_ECIES_HPP
#define ENIGMA_ECIES_HPP

#include "icryptosystem.hpp"

class ecies_public_key: public ICryptosystem
{
   /// Default constructor.
   enigma_ecies_public () {};
   /// Copy constructor.
   enigma_ecies_public (const enigma_ecies_public & other) : publicKey_(other.publicKey_) {}
   /// Move constructor.
   enigma_ecies_public (enigma_ecies_public && other) : publicKey_(std::move(other.publicKey_)) {}
   /// Copy assignment.
   const enigma_ecies_public & operator= (const enigma_ecies_public & other) { publicKey_ = other.publicKey_; }
   /// Move assignment.
   const enigma_ecies_public & operator= (enigma_ecies_public && other) { publicKey_ = std::move(other.publicKey_); }
   
   /// Deletes this object.
   virtual void destroy () { delete this; }
   
   /// Returns a copy of this object owned by the caller.
   virtual ecies_public_key * clone () const { return new ecies_public_key(*this); }
   
   virtual void encrypt (const std::string & infile, const std::string & outfile) const;
   
   virtual void decrypt (const std::string & infile, const std::string & outfile) const
   {
      // throw an exception here
   }
   
   virtual void save (const std::string & filename) const;
   virtual void load (const std::string & filename);
protected:
   CryptoPP::ECIES<ECP>::Encryptor publicKey_;
};

class ecies_private_key: public ecies_public_key
{
public:
   /// Default constructor.
   enigma_ecies_private ();
   /// Copy constructor.
   enigma_ecies_private (const enigma_ecies_private & other) : enigma_ecies_public(other), privateKey_(other.privateKey_) {}
   /// Move constructor.
   enigma_ecies_private (enigma_ecies_private && other) : enigma_ecies_public(std::move(other)), privateKey_(std::move(other.privateKey_)) {}
   /// Copy assignment.
   const enigma_ecies_private & operator= (const enigma_ecies_private & other)
   {
      *((enigma_ecies_public *)(this)) = other;
      privateKey_ = other.privateKey_;
      return *this;
   }
   /// Move assignment.
   const enigma_ecies_private & operator= (enigma_ecies_private && other)
   {
      *((enigma_ecies_public *)(this)) = std::move(other);
      privateKey_ = std::move(other.privateKey_);
      return *this;
   }
   /// Key assignment.
   const enigma_ecies_private & operator= (const CryptoPP::ECIES<ECP>::Decryptor & key) { privateKey_ = key; }
   /// Key move assignment.
   const enigma_ecies_private & operator= (CryptoPP::ECIES<ECP>::Decryptor && key) { privateKey_ = std::move(key); }
   
   /// Deletes this object.
   virtual void destroy () { delete this; }
   
   /// Returns a copy of this object owned by the caller.
   virtual ecies_private_key * clone () const { return new ecies_private_key(*this); }
   
   virtual void decrypt (const std::string & infile, const std::string & outfile) const;
   virtual void save (const std::string & filename) const;
   virtual void load (const std::string & filename);
   
   virtual bool has_private () const noexcept { return true; }
private:
   CryptoPP::ECIES<ECP>::Decryptor privateKey_;
};

/// Generates and returns a private key owned by the caller.
ecies_private_key * newECIESPrivateKey ();

#endif