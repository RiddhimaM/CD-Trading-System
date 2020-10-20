#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>

enum STATUS {OK, FAILED};

template <class SOMETYPE> 
class HEAP 
{ 
    private: 
        int size;       
        int nNodes;   
        SOMETYPE *buf;  
    public: 
        HEAP (int a_size); 
        ~HEAP(); 
        bool IsEmpty() {return bool(nNodes == 0);} 
        bool IsFull() {return bool(nNodes == size);} 
        STATUS Insert(SOMETYPE x); 
        STATUS Remove(SOMETYPE &x);
        SOMETYPE Peek ()
        {
            std::cout << "PEEKING " << std::endl;
            std::cout << buf[1].name;
            SOMETYPE x = buf[1];
            return x;
        } 
}; 

//**********************************************************************
struct Transaction
{
    std::string name;
    int amount;
    double price;
    double per;
};
//**********************************************************************
struct Album
{
    Album() : maxH(100), minH(100) {}
    HEAP<Transaction> maxH;
    HEAP<Transaction> minH;
};
//**********************************************************************
template <class SOMETYPE> 
HEAP<SOMETYPE>::HEAP(int a_size) 
{ 
    nNodes = 0; 
    buf = new SOMETYPE[a_size+1];
    if (buf) size = a_size; 
    else size = 0; 
} 
//**********************************************************************
template <class SOMETYPE> 
HEAP<SOMETYPE>::~HEAP() 
{ 
    delete [] buf; 
} 
//**********************************************************************
template <class SOMETYPE> 
STATUS HEAP<SOMETYPE>::Insert(SOMETYPE x) 
{ 
    if (IsFull()) return FAILED; 
    nNodes++;  
    int i = nNodes; 
    int iParent; 
    while (i > 1) 
    { 
        iParent = i/2; 
        if (x <= buf[iParent]) break; 
        buf[i] = buf[iParent];        
        i = iParent;                   
    } 

    buf[i] = x; 
    return OK; 
} 
//**********************************************************************
template <class SOMETYPE> 
STATUS HEAP<SOMETYPE>::Remove(SOMETYPE &x) 
{ 
    if (IsEmpty()) return FAILED; 
    x = buf[1];              
    int iParent = 1;       
    int i = 2;            
    while (i <= nNodes) 
    { 
        if (i < nNodes && buf[i] < buf[i+1]) i++; 
        if (buf[i] <= buf[nNodes]) break; 
        buf[iParent] = buf[i];    
        iParent = i;            
        i *= 2;                  
    } 
    if (nNodes > 1) buf[iParent] = buf[nNodes]; 
    nNodes--; 
    return OK; 
} 

extern Album albums[3];

bool auth (std::string uname, std::string pass, std::string &result);
void parseInput(std::string &un, std::string &pw, 
                std::string &name, std::string &amt, 
                std::string &price, std::string &offer, std::string &album);
std::string formatPage(std::string un, std::string pw, 
                        std::string name, std::string amt, 
                        std::string price, std::string offer, 
                        std::string album, std::string result);
void firstForm();
void readToHeap();
void quote();
