#include <iostream>
#include <string>
#include <fstream>

bool isLoggedIn()
{
    std::string login;
    std::string password;
    std::string compareLogin;
    std::string comparePassword;

    std::cout << "Enter User Login: "; std::cin >> login;
    std::cout << "Enter User Password: "; std::cin >> password;

    std::ifstream read("C:\\" + login + ".txt");
    getline(read, compareLogin);
    getline(read, comparePassword);   

    if(compareLogin == login && comparePassword == password)
    {
        return true;
    } else return false;
}

int main() 
{
    int choice;

    std::cout << "1.Register\n2.Login\nPut your choice: "; std::cin >> choice;

    if(choice == 1)
    {
    std::string login;
    std::string password;

      std::cout << "Select User Login: "; std::cin >> login;
      std::cout << "Select User password: "; std::cin >> password;

      std::ofstream file;
      file.open("c:\\" + login + ".txt");
      file << login << std::endl << password;
      file.close();
      main();  
    } else if (choice == 2) 
    {
    
    bool status {isLoggedIn()};
    
    if(status)
    {
        std::cout << "Succesfully logged in!" << std::endl;
        system("PAUSE");
        
        return 1;
    } else
    {
        std::cout << "False!" << std::endl;
        system("PAUSE");
        
        return 0;
    }
    
    }
    return 0;
}