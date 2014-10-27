#include <Poco/Net/SMTPClientSession.h>
#include <Poco/Net/MailMessage.h>
#include <Poco/Net/PartSource.h>
#include <Poco/Net/FilePartSource.h>
#include <Poco/Net/MailRecipient.h>
#include <QTCore/QString.h>

/**
 * Author: Leopold Eckert
 * Filename: Email.cpp
 * Contains methods for connecting to SMTP servers and sending email.
 */

using namespace Poco::Net;

/**
 * Name: openConnection
 * Connects to and logins to an SMTP host
 * Params:
 *   hostname: the name of the SMTP host to connect to
 *   user: the username used in login
 *   pass: password for login
 * Returns: A Client session that can be used to send emails.
 */
SMTPClientSession openConnection(QString hostname, QString user, QString pass) {
	//Convert QStrings to std strings
	std::string hostnameString = hostname.toStdString();
	std::string userString = user.toStdString();
	std::string passwordString = user.toStdString();
	// Connect
	SMTPClientSession result(hostnameString, SMTPClientSession::SMTP_PORT);
	// Login
	result.login(SMTPClientSession::AUTH_LOGIN, userString, passwordString);
	
	return result;
}// End of method: openConnection

/**
 * Name: sendFile
 * Sends a file over email as an attachment
 * Params:
 *    path: the path to the file to attach
 *    qRecipient: the email address of the recipient of the file
 *    client: an client session used to send the file.
 * 
 */
void sendFile(std::string path, QString qRecipient, SMTPClientSession client) {
	//Get the attachment
	FilePartSource attachment(path);
	std::string recipientString = qRecipient.toStdString();
	//Prepare and send the message
	MailMessage mail;
	mail.addAttachment("Encrypted File", &attachment);
	MailRecipient recipient(MailRecipient::PRIMARY_RECIPIENT, recipientString);
	mail.addRecipient(recipient);
	client.sendMessage(mail);
}// End of method: sendFile
// End of file: Email.cpp
