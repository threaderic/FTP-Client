#include "FTPClient.h"

FTPClient::FTPClient() {}

FTPClient::~FTPClient() {}

int FTPClient::start()
{
    std::cout << "FTP Client" << std::endl;
    std::cout << "By JTKreates" << std::endl;

    do
    {
        std::cout << "FTP Address: ";
        std::cin >> serverAddress;
        std::cout << "\n";
    } while(!connect(serverAddress));

    std::cout << "Successfully connected to " << serverAddress << std::endl;

    do
    {
        std::cout << "Enter the username: ";
        std::cin >> username;
        std::cout << "\n";
        std::cout << "Enter the password: ";
        std::cin >> password;
        std::cout << "\n";
    } while(!login(username, password));

    std::cout << "Successfully logged in" << std::endl;

    do
    {
        std::cout << "\n";
        std::cout << "Choose an action:"                      << std::endl;
        std::cout << "1. Print working directory"             << std::endl;
        std::cout << "2. Print contents of working directory" << std::endl;
        std::cout << "3. Change directory"                    << std::endl;
        std::cout << "4. Create directory"                    << std::endl;
        std::cout << "5. Delete directory"                    << std::endl;
        std::cout << "6. Rename file"                         << std::endl;
        std::cout << "7. Remove file"                         << std::endl;
        std::cout << "8. Download file"                       << std::endl;
        std::cout << "9. Upload file"                         << std::endl;
        std::cout << "0. Disconnect"                          << std::endl;
        std::cout << "\n";

        std::cin >> choice;

        switch(choice)
        {
        default:
            {
                std::cout << "Bad Choice..." << std::endl;
                std::cin.clear();
                std::cin.ignore();
                break;
            }
        case 1:
            {
                directoryResponse = ftp.getWorkingDirectory();
                std::cout << directoryResponse.getDirectory() << std::endl;
                break;
            }
        }
    }
}

bool FTPClient::connect(sf::IpAddress serverAddress)
{
    response = ftp.connect(serverAddress);
    if(response.isOk())
        return true;
    else
        return false;
}

bool FTPClient::login(std::string username, std::string password)
{
    response = ftp.login(username, password);
    if(response.isOk())
        return true;
    else
        return false;
}

void FTPClient::close()
{
    response = ftp.disconnect();
    if(response.isOk())
        std::cout << "Successfully closed the connection to " << serverAddress << std::endl;
}
