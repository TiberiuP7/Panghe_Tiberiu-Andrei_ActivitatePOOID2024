#include<iostream>
#include<string>

using namespace std;

//Domeniul ales este: Panghe Tiberiu-Andrei - Ambarcatiuni
class Barca {
    public:
    static int locuri;
    double caiPutere;
    string nume;
    const int nrelice;
    const string marca;
    bool etaj;
    float* pret;

    Barca() : marca("SeaDoo"), nrelice(4) {
        this->caiPutere= 3000;
        this->nume= "Ana";
        this->etaj= 1;
        this->pret= nullptr;
    }

    Barca(double caiPutere, string nume, bool etaj, float pret) : marca("Aqua"), nrelice(4){
        this->caiPutere= 4000;
        this->nume= "Maria";
        this->etaj= 1;
        this->pret= new float();
    }

    Barca(double caiPutere, bool etaj): marca("CanAm"), nrelice(3){
        this->nume= "Rechinul";
        this->caiPutere= caiPutere;
        this->etaj= etaj;
        this->pret= nullptr;
    }


    static int cateLocuri(){
        return locuri;
    }
};

    int Barca::locuri = 8;

class Vapor {
    public:
    static int nrVapoare;
    const string nume;
    int niveluri;
    double marime;
    bool cargo;
    float* pret;

    Vapor() : nume("SSEnterprise") {
        this->niveluri= 4;
        this->marime= 5000;
        this->cargo= 1;
        this->pret= new float();
    }

    Vapor(int niveluri, double marime, bool cargo, float pret) : nume("Arca") {
        this->niveluri= 5;
        this->marime= 10000;
        this->cargo= 1;
        this->pret= nullptr;
    }

    Vapor(int niveluri, double marime) : nume("Maria") {
        this->niveluri= niveluri;
        this->marime= marime;
        this->cargo= 0;
        this->pret= nullptr;
    }

    int static cateVapoare() {
        return nrVapoare;
    }
};

int Vapor::nrVapoare= 0; 

class Skijet {
    public:
    static int nrSkijeturi;
    const string marca;
    int caiPutere;
    int locuri;
    float pret;
    string* proprietar;

    Skijet() : marca("CanAm") {
        this->caiPutere= 300;
        this->locuri= 3;
        this->pret= 30000;
        this->proprietar= nullptr;
    }

    Skijet(int caiPutere, int locuri, float pret, string proprietar) : marca("SeaDoo") {
        this->caiPutere= 350;
        this->locuri= 4;
        this->pret= 35000.50;
        this->proprietar= new string();
    }

    Skijet(int caiPutere, float pret) : marca("Kawasaki") {
        this->caiPutere= caiPutere;
        this->pret= pret;
        this->locuri= 4;
        this->proprietar= new string();
    }

    static double numarSkijeturi() {
        return nrSkijeturi + 1;
    }
};

int Skijet::nrSkijeturi= 0;

int main() 
{
    Barca barca1(400, "Ana", true, 50000);
    Barca barca2;
    Barca barca3(300, true);
    float* pret= new float(30000);
    cout << "Barca cu numele: " << barca1.nume << " este marca " << barca1.marca << endl;
    cout << "are " << barca1.caiPutere << " cai putere si ";
    if(barca1.etaj == true)
    {
        cout << "are etaj." << endl;
    }
    else
    {
        cout << "nu are etaj." << endl;
    }
    cout << "Pretul este de: " << barca1.pret << " lei." << endl << endl;

    cout << "Barca cu numele: " << barca2.nume  << " este marca " << barca2.marca << endl;
    cout << "are " << barca2.caiPutere << " cai putere si ";
    if(barca2.etaj == true)
    {
        cout << "are etaj." << endl;
    }
    else
    {
        cout << "nu are etaj." << endl;
    }
    cout << "Pretul este de: " << barca2.pret << " lei." << endl << endl;

    cout << "Barca cu numele: " << barca3.nume << " este marca " << barca3.marca << endl;
    cout << "are " << barca3.caiPutere << " cai putere si ";
    if(barca3.etaj == true)
    {
        cout << "are etaj." << endl;
    }
    else
    {
        cout << "nu are etaj." << endl;
    }
    cout << "Pretul este de: " << barca3.pret << " lei." << endl << endl;
    Vapor v1;
    Vapor v2(5, 50000);
    Vapor v3(5, 20000, true, 1000000);
    string* nume= new string[3] {"v1", "v2", "v3"};
    cout << "Vaporul cu numele: " << v1.nume << " are " << v1.niveluri << " niveluri inaltime si " << endl;
    if(v1.cargo == true)
    {
        cout << "este transportator de marfuri." << endl << endl;
    }
    else
    {
        cout << "este vapor de croaziera, transportator de persoane." << endl << endl;
    }

    cout << "Vaporul cu numele: " << v2.nume << " are " << v2.niveluri << " niveluri inaltime si " << endl;
    if(v2.cargo == true)
    {
        cout << "este transportator de marfuri." << endl << endl;
    }
    else
    {
        cout << "este vapor de croaziera, transportator de persoane" << endl << endl;
    }

    cout << "Vaporul cu numele: " << v3.nume << " are " << v3.niveluri << " niveluri inaltime si " << endl;
    if(v3.cargo == true)
    {
        cout << "este transportator de marfuri." << endl << endl;
    }
    else
    {
        cout << "este vapor de croaziera, transportator de persoane" << endl << endl;
    }


    Skijet sk1;
    Skijet sk2(300, 4, 30000, "Andrei");
    Skijet sk3(350, 55000);

    cout << "Skijetul cu marca: " << sk1.marca << " are " << sk1.caiPutere << " cai putere " << " si o capacitate de " << sk1. locuri << " locuri." << endl;
    cout << "Proprietarul acestuia este: " << sk1.proprietar << " si a platit pe acesta o suma de " << sk1.pret << "euro." << endl << endl;

    cout << "Skijetul cu marca: " << sk2.marca << " are " << sk2.caiPutere << " cai putere " << " si o capacitate de " << sk2. locuri << " locuri." << endl;
    cout << "Proprietarul acestuia este: " << sk2.proprietar << " si a platit pe acesta o suma de " << sk2.pret << "euro." << endl << endl;

    cout << "Skijetul cu marca: " << sk3.marca << " are " << sk3.caiPutere << " cai putere " << " si o capacitate de " << sk3. locuri << " locuri." << endl;
    cout << "Proprietarul acestuia este: " << sk3.proprietar << " si a platit pe acesta o suma de " << sk3.pret << "euro." << endl << endl;

}
