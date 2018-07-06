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

        std::vector<std::string> listing;

        sf::IpAddress serverAddress;

        int choice;

        std::string username;
        std::string password;
        std::string directory;
        std::string file;
        std::string renamedFile;
        std::string filePath;
};

#endif // FTPCLIENT_H
