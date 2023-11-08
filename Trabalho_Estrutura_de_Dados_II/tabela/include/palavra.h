#include <cstring>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Palavra
{
    public:
        Palavra();
        Palavra(string chave, int contador);
        string getChave();
        int getCont();
        void setChave(string chave);
        void setCont(int cont);
        ~Palavra();

    private:
        string chave;
        int contador;
};