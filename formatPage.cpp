#include "finalLab.h"
std::string formatPage(std::string un, std::string pw, std::string name, std::string amt, 
                        std::string price, std::string offer, std::string album, std::string result)
{
    std::string button;
    std::string confirm;
    
    if (result == "Username found. You are logged in!")
    {
        button = "";
        confirm = "<br>Offer has been made by "; 
        confirm += name; confirm += " for "; 
        confirm += amt; confirm += " of \"";  
        confirm += album; confirm += "\" CDs "; 
        confirm += " for $"; confirm += price;
        confirm += ". Offer is to "; confirm += offer;
        confirm += ".";
    }
    else 
    {
        button = "<br><input type=\"button\" value=\"Try Again\" onclick=\"history.back()\"></input>";
        confirm = "<br>Please try again.";
    }
    
    std::ifstream ifs("../finalLab/resultInput.html");
    if(!ifs) std::cout << "file not found" << std::endl;
    std::string page; std::string s;
    while(getline(ifs,s))
    {
        if (s.find("Authentication:") != std::string::npos)
        {
            std::ostringstream oss; 
            oss << result << confirm << button;
            size_t posm1 = s.find("string");
            s.replace(posm1,6, oss.str());
        }
    page += s + "\n";
    }
    return page;
}
