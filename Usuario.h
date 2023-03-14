#ifndef USUARIO
#define USUARIO
#include <string>

using namespace std;

class Usuario
{
private:
    string email;
    string pass;
public:
    Usuario();
    Usuario(string, string);
    string getEmail();
    void setEmail(string);
    string getPass();
    void setPass(string);
    virtual ~Usuario();
};

#endif