#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

class Carro{
    private:
        string marca;
        int ano;
        string cor;
    public:
        void setMarca(string marca){
            this->marca = marca;
        }
        string getMarca(){
            return marca;
        }
};

int main(int argc, char** argv)
{
    Carro c1;
    c1.setMarca("FIAT");
    cout << c1.getMarca() << endl;
    return 0;
}
