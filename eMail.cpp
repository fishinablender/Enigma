#include <Poco/Net/SMTPClientSession.h>
#include <Poco/Net/MailMessage.h>
#include <Poco/Net/PartSource.h>
#include <Poco/Net/FilePartSource.h>
#include <Poco/Net/MailRecipient.h>
#include <QTCore/QString.h>

using namespace Poco::Net;
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
}

void sendFile(std::string path, QString qRecipient, SMTPClientSession client) {
	FilePartSource attachment(path);
	std::string recipientString = qRecipient.toStdString();
	MailMessage mail;
	mail.addAttachment("Encrypted File", &attachment);
	MailRecipient recipient(MailRecipient::PRIMARY_RECIPIENT, recipientString);
	mail.addRecipient(recipient);
	client.sendMessage(mail);
}