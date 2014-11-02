=========================================================================================  README  =============================
================================================================

Team Members:
-JT Davies
-Leopold Eckert
-Andrew Schlosser
-Dillon Mavroulas
-Nat Shapiro



To run GUI portion of the program, open Enigma on a 32bit linux platform machine. The window will open up displaying two tabs; one for strictly encryption labeled "Encrypt File" and one that encrypts and emails the file labeled "Email File". 


-Instructions for Tab 1 "Encrypt File":

input information as follows

	File: The directory in the filesystem where the file to be 		encrypted is located

	Output location: The directory in the filesystem where the 		file encrypted will be placed

	Recipient: Name of the recipient for the encrypted file. 			This correlates to the users stored key 

	[Encrypt]: Encrypt the file using the current settings

	[Decrypt]: Decrypt the file using the current settings



-Instructions for Tab 2 "Email File":

input information as follows

	File: The directory in the filesystem where the file to be 		encrypted is located

	Hostname: The Email host used to email the file

	Username: The users Email address

	Password: The password for the users Email

	Recipient: Target Email of the recipient for the encrypted 		file.

	[Email]: Encrypt and Email the file using the current 			settings


-Intructions for decrypting a received Email file:

	Using the encrypted file received use the first tab and fill in all required fields and click the [decrypt] button. This outputs the decrypted file to the designated location.