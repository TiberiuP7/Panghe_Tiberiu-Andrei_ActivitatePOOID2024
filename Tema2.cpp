#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Barca {
    private:
        static int locuri;
        double caiPutere;
        string nume;
        const int nrelice;
        const string marca;
        bool etaj;
        float* pret;
    public:

    Barca() : marca("SeaDoo"), nrelice(4) {
        this->caiPutere= 3000;
        this->nume= "Ana";
        this->etaj= 1;
        this->pret= nullptr;
    }

    Barca(double caiPutere, string nume, bool etaj, float pret) : marca("Aqua"), nrelice(4) {
        this->caiPutere= caiPutere;
        this->nume= nume;
        this->etaj= etaj;
        this->pret=nullptr;
    }


    Barca(double caiPutere, bool etaj): marca("CanAm"), nrelice(3){
        this->nume= "Rechinul";
        this->caiPutere= caiPutere;
        this->etaj= etaj;
        this->pret= nullptr;
    }

    ~Barca(){
        if(this->pret != nullptr)
		delete[] this->pret;
    }

    Barca(double caiPutere, string nume, bool etaj, float* pret) : marca("Aqua"), nrelice(4) {
        this->caiPutere= caiPutere;
        this->nume= nume;
        this->etaj= etaj;

        this->pret= new float();
        this->pret=pret;
        delete[] pret;
    }

    static int cateLocuri(){
        return locuri;
    }

    double getcaiPutere() {
        return caiPutere;
    }
    void setcaiPutere(int caiPutere) {
        if(caiPutere>0)
            this->caiPutere=caiPutere;
    }

    string getnume() {
        return nume;
    }
    void setnume(string nume) {
        if(nume.length() != 0)
            this->nume=nume;
    }

    bool getetaj() {
        return etaj;
    }
    void setetaj(bool etaj) {
        this->etaj=etaj;
    }

    float* getpret() {
        return pret;
    }
    void setpret(float* noulpret) {
        if(this->pret != nullptr)
        {  
            delete this->pret;
        }

        this->pret= new float();
        this->pret=noulpret;
        delete[] noulpret;
    }

    friend bool areEtaj(Barca b);
};

    int Barca::locuri = 8;

class Vapor {
    private:
    static int nrVapoare;
    const string nume;
    int niveluri;
    double marime;
    bool cargo;
    float* pret;

    public:
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

    ~Vapor() {
        if(this->pret != nullptr)
            delete[] this->pret;
    }

    Vapor(int niveluri, double marime, bool cargo, float* pret) : nume("Arca") {
        this->niveluri=niveluri;
        this->marime=marime;
        this->cargo=cargo;

        this->pret= new float();
        this->pret=pret;
        delete[] pret;
    }

    int static cateVapoare() {
        return nrVapoare;
    }

    int getniveluri() {
        return niveluri;
    }
    void setniveluri(int niveluri) {
        if(niveluri>0)
        this->niveluri=niveluri;
    }

    double getmarime() {
        return marime;
    }
    void setmarime(double marime) {
        if(marime>0)
        this->marime=marime;
    }

    bool getcargo() {
        return cargo;
    }
    void setcargo(bool cargo) {
        this->cargo=cargo;
    }

    float* getpret() {
        return pret;
    }
    void setpret(float* noulpret) {
        if(this->pret != nullptr)
        {  
            delete this->pret;
        }

        this->pret= new float();
        this->pret=noulpret;
        delete[] noulpret;
    }
};

int Vapor::nrVapoare= 0; 

class Skijet {
    private:
    static int nrSkijeturi;
    const string marca;
    int caiPutere;
    int locuri;
    float pret;
    string* proprietar;

    public:
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

    ~Skijet() {
        if(this->proprietar != nullptr)
            delete[] this->proprietar;
    }

    Skijet(int caiPutere, int locuri, float pret, string* proprietar) : marca("Kawasaki") {
        this->caiPutere=caiPutere;
        this->locuri=locuri;
        this->pret=pret;
       
        this->proprietar= new string();
        this->proprietar=proprietar;
        delete[] proprietar;
    }
    
    float getpret() {
    return pret;
    }

    int getcaiPutere() {
        return caiPutere;
    }

    static double numarSkijeturi() {
        return nrSkijeturi + 1;
    }

    friend int catiCaiPutere(Skijet ski);
    friend float crestePretul(Skijet ski);
};



int Skijet::nrSkijeturi= 0;

bool areEtaj(Barca b) {
    return b.etaj;
} 

int catiCaiPutere(Skijet ski) {
    if(ski.caiPutere>0)
    return ski.caiPutere;
}

float crestePretul(Skijet ski) {
    float pret= ski.pret;
    ski.pret = pret + 1000;
    return ski.pret;
}

int main() 
{
    Barca b;
    Skijet sk(300, 30000);
    if(areEtaj(b)==true)
    cout<< b.getnume()<< " Are etaj."<<endl;
    else
    cout<< b.getnume()<< " Nu are etaj."<<endl<< " si are" <<b.getcaiPutere() << " si costa "<< b.getpret()<<endl;

    cout<< crestePretul(sk)<<endl;
    cout<< sk.getpret();
    cout<< catiCaiPutere(sk)<<endl<< sk.getcaiPutere()<<endl;
}