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
        std::cout << "1) Print directory" << std::endl;
        std::cout << "2) Print directory contents" << std::endl;
        std::cout << "3) Change directory" << std::endl;
        std::cout << "4) Create directory" << std::endl;
        std::cout << "5) Delete directory" << std::endl;
        std::cout << "6) Rename file" << std::endl;
        std::cout << "7) Delete file" << std::endl;
        std::cout << "8) Download file" << std::endl;
        std::cout << "9) Upload file" << std::endl;
        std::cout << "0) Close Connection" << std::endl;
        std::cout << "\n";

        std::cout << "Choice: ";
        std::cin >> choice;
        std::cout << "\n";

        switch(choice)
        {
        default:
            {
                std::cout << "Bad Choice..." << std::endl;
                std::cin.clear();
                std::cin.ignore();
                break;
            }
        case 0:
            {
                close();
                break;
            }
        case 1:
            {
                sf::Ftp::DirectoryResponse directoryResponse = ftp.getWorkingDirectory();
                std::cout << "Current Directory is " << directoryResponse.getDirectory() << std::endl;
                break;
            }
        case 2:
            {
                sf::Ftp::ListingResponse listingResponse = ftp.getDirectoryListing();
                listing = listingResponse.getListing();
                for(std::vector<std::string>::const_iterator i = listing.begin(); i != listing.end(); ++i)
                    std::cout << *i << std::endl;
                break;
            }
        case 3:
            {
                std::cout << "Directory: ";
                std::cin >> directory;
                std::cout << "\n";
                sf::Ftp::Response directoryResponse = ftp.changeDirectory(directory);
                if(directoryResponse.isOk())
                    std::cout << "Successfully changed the directory" << std::endl;
                else
                    std::cout << "Failed to change the directory" << std::endl;
                break;
            }
        case 4:
            {
                std::cout << "New Directory Name: ";
                std::cin >> directory;
                std::cout << "\n";
                sf::Ftp::Response newDirectoryResponse = ftp.createDirectory(directory);
                if(newDirectoryResponse.isOk())
                    std::cout << "Successfully created a new directory" << std::endl;
                else
                    std::cout << "Failed to create a new directory" << std::endl;
                break;
            }
        case 5:
            {
                std::cout << "Directory to Delete: ";
                std::cin >> directory;
                std::cout << "\n";
                sf::Ftp::Response removeDirectoryResponse = ftp.deleteDirectory(directory);
                if(removeDirectoryResponse.isOk())
                    std::cout << "Successfully deleted the directory" << std::endl;
                else
                    std::cout << "Failed to delete the directory" << std::endl;
                break;
            }
        case 6:
            {
                std::cout << "File to rename: ";
                std::cin >> file;
                std::cout << "\n";
                std::cout << "New name: ";
                std::cin >> renamedFile;
                std::cout << "\n";
                sf::Ftp::Response renameResponse = ftp.renameFile(file, renamedFile);
                if(renameResponse.isOk())
                    std::cout << "Successfully renamed the file" << std::endl;
                else
                    std::cout << "Failed to rename the file" << std::endl;
                break;
            }
        case 7:
            {
                std::cout << "File to delete: ";
                std::cin >> file;
                std::cout << "\n";
                sf::Ftp::Response deleteResponse = ftp.deleteFile(file);
                if(deleteResponse.isOk())
                    std::cout << "Successfully deleted the file" << std::endl;
                else
                    std::cout << "Failed to delete the file" << std::endl;
                    break;
            }
        case 8:
            {
                std::cout << "File to download: ";
                std::cin >> file;
                std::cout << "\n";
                std::cout << "File path: ";
                std::cin >> filePath;
                std::cout << "\n";
                sf::Ftp::Response downloadResponse = ftp.download(file, filePath);
                if(downloadResponse.isOk())
                    std::cout << "Successfully downloaded the file" << std::endl;
                else
                    std::cout << "Failed to download the file" << std::endl;
                break;
            }
        case 9:
            {
                std::cout << "File to upload: ";
                std::cin >> file;
                std::cout << "\n";
                std::cout << "File path: ";
                std::cin >> filePath;
                std::cout << "\n";
                sf::Ftp::Response uploadResponse = ftp.upload(file, filePath);
                if(uploadResponse.isOk())
                    std::cout << "Successfully uploaded the file" << std::endl;
                else
                    std::cout << "Failed to upload the file" << std::endl;
                break;
            }
        }
    } while(choice != 0);

    return 0;
}

bool FTPClient::connect(sf::IpAddress serverAddress)
{
    sf::Ftp::Response connectionResponse = ftp.connect(serverAddress);
    if(connectionResponse.isOk())
        return true;
    else
        return false;
}

bool FTPClient::login(std::string username, std::string password)
{
    sf::Ftp::Response loginResponse = ftp.login(username, password);
    if(loginResponse.isOk())
        return true;
    else
        return false;
}

void FTPClient::close()
{
    sf::Ftp::Response closeResponse = ftp.disconnect();
    if(closeResponse.isOk())
        std::cout << "Successfully closed the connection to " << serverAddress << std::endl;
}
