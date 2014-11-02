=========================================================================================  README  =============================
================================================================

Team Members:
-JT Davies
-Leopold Eckert
-Andrew Schlosser
-Dillon Mavroulas



To run GUI portion of the program, open Enigma on a 32bit linux platform machine. The encryption window will open up for the user to input information as follows

	File: The directory in the filesystem where the file to be 		encrypted is located

	Output location: The directory in the filesystem where the 		file encrypted will be placed

	Recipient: Name of the recipient for the encrypted file. 			This correlates to the users stored key 

	Encryption Type: Select between "RSA" and "ECC" encryption 		methods

	[Encrypt]: Encrypt the file using the current settings

	[Decrypt]: Decrypt the file using the current settings


In its current state the GUI does not interface with the backend encryption libraries so no encryption/decryption takes place when pressing Encrypt/Decrypt buttons. These features will be implemented in future sprints.