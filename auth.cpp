#include "finalLab.h"

bool auth (std::string uname, std::string pass, std::string &result)
{
    std::string username[] = {"Maya", "Megan", "Jim", "Atwood", "Marcus", 
                                "Julie", "Zoey", "Ed", "Ruby", "Trevor"};
    std::string password[] = {"pink18", "1purple2" , "37blue" , "green29" , "7823yellow" ,
                            "5white8" , "black21", "44brown" , "cyan2810" , "magenta0"};
    int index = -1;
    
    for (int i = 0; i < 10; i++)
    {
        if (uname == username[i])
        {
            index = i;
            result = "Username found.";
        }
    }
    if (index == -1)
    {
        result = "Wrong username!";
        return false;
    }
    
    if (pass == password[index])
    {
        result += " You are logged in!";
        return true;
    }
    else
    {
        result += " Wrong password!";
        return false;
    }
}

