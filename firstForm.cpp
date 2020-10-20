#include "finalLab.h"

void firstForm()
{
    std::string uname, pword, result, name, amtString, priceString, offer, album;
    parseInput(uname, pword, name, amtString, priceString, offer, album);
    int amt;
    double price;

    auth(uname, pword, result);
    
    amt = atoi(amtString.c_str());
    price = atof(priceString.c_str());
    
    if (offer == "1")
        offer = "BUY";
    else if (offer == "2")
        offer = "SELL";
        
    if (album == "1")
        album = "Yellow Submarine";
    else if (album == "2")
        album = "The Dark Side of the Moon";
    else if (album == "3")
        album = "The Life of Pablo";
    
        
    std::ofstream ofs("../groupLab/offerList.txt", std::ios::app);
    if (ofs)
    {
        ofs << name << " " << amtString << " " << priceString << " " << offer << " " << album << std::endl;
        ofs.close();
    }

    std::string page = formatPage(uname, pword, name, amtString, priceString, offer, album, result);
    std::cout << page << std::endl;

}
