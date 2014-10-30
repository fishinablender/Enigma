#include "enigma_rsa.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int handleArgs (int argc, const char * argv[])
{
   std::string command(argv[1]);
   if ( command == "generate" )
   {
      if ( argc < 3 )
      {
         cout << "Not enough arguments: enigmacli generate <keyfile>";
         return 1;
      }
      enigma_rsa_private key = generateRSAPrivateKey();
      key.save(std::string(argv[2]));
   }
   else if ( command == "encrypt" )
   {
      if ( argc < 5 )
      {
         cout << "Not enough arguments: enigmacli encrypt <keyfile> <infile> <outfile>" << endl;
         return 1;
      }
      enigma_rsa_private key; key.load(std::string(argv[2]));
      key.encrypt(std::string(argv[3]),std::string(argv[4]));
   }
   else if ( command == "decrypt" )
   {
      if ( argc < 5 )
      {
         cout << "Not enough arguments: enigmacli decrypt <keyfile> <infile> <outfile>" << endl;
         return 1;
      }
      enigma_rsa_private key; key.load(std::string(argv[2]));
      key.decrypt(std::string(argv[3]),std::string(argv[4]));
   }
   return 0;
}

int main (int argc, const char * argv[])
{
   enigma_rsa_private key;
   
   if ( argc > 1 ) { return handleArgs(argc, argv); }
   
   while (true)
   {
      std::string command, infile, outfile;
      cout << "enigmacli> ";
      cin >> command;
      
      if ( command == "generate" ) { key = generateRSAPrivateKey(); }
      else if ( command == "save" )
      {
         cout << "Enter file name: ";
         cin >> outfile;
         key.save(outfile);
      }
      else if ( command == "load" )
      {
         cout << "Enter file name: ";
         cin >> infile;
         key.load(infile);
      }
      else if ( command == "encrypt" )
      {
         cout << "Enter name of file to encrypt: ";
         cin >> infile;
         cout << "Enter name of destination file: ";
         cin >> outfile;
         key.encrypt(infile,outfile);
      }
      else if ( command == "decrypt" )
      {
         cout << "Enter name of file to decrypt: ";
         cin >> infile;
         cout << "Enter name of destination file: ";
         cin >> outfile;
         key.decrypt(infile,outfile);
      }
      else if ( command == "quit" || command == "exit" ) { break; }
      else if ( command == "help" )
      {
         cout << "Commands: generate, save, load, encrypt, decrypt, quit" << endl;
      }
      else
      {
         cout << "Invalid command. Type 'help' for command listing." << endl;
      }
   }
   return 0;
};
