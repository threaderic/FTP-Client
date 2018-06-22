#ifndef FTPCLIENT_H
#define FTPCLIENT_H

#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>

class FTPClient
{
    public:
        FTPClient();
        ~FTPClient();

        int start();

        bool connect(sf::IpAddress serverAddress);
        bool login(std::string username, std::string password);

        void close();

    protected:

    private:
        sf::Ftp ftp;
        sf::Ftp::Response response;
        sf::Ftp::DirectoryResponse directoryResponse;
        sf::Ftp::ListingResponse listingResponse;

        std::vector<std::string> listing;

        sf::IpAddress serverAddress;

        int choice;

        std::string username;
        std::string password;
};

#endif // FTPCLIENT_H
