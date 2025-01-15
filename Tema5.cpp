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

    Barca operator= (const Barca &barca) {
        if(this->pret != NULL)
        delete[]this->pret;

        this->pret= new float();
        this->pret= barca.pret;
        this->caiPutere= barca.caiPutere;
        this->nume= barca.nume;
        this->etaj= barca.etaj;
        return *this;
    }


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
        this->pret= pret;
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
    string const ceNume() {
        return nume;
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

    Vapor operator= (const Vapor &vapor) {
        if(this->pret != NULL)
        delete[]this->pret;

        this->pret= new float();
        this->pret= vapor.pret;
        this->niveluri= vapor.niveluri;
        this->marime=vapor.marime;
        this->cargo=  vapor.cargo;
        return *this;
    }

    Vapor operator++(int) {
        Vapor copie= *this;
        this->niveluri++;
        return copie;
    }
    // Polimorfism al operatorului unar ++
    Vapor operator++ () {
        this->niveluri++;
        return *this;
    }

    operator int() {
        return niveluri;
    }

    
    Vapor operator--(int) {
        Vapor copie= *this;
        this->niveluri--;
        return copie;
    }
    // Polimorfism al operatorului unar --
    Vapor operator-- () {
        this->niveluri--;
        return *this;
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

    int getlocuri() {
        return locuri;
    }

    string* getproprietar() {
        return proprietar;
    }

    void setproprietar(string* noulproprietar) {
        if(this->proprietar != nullptr)
        {  
            delete this->proprietar;
        }

        this->proprietar= new string();
        this->proprietar= noulproprietar;
        delete[] noulproprietar;
    }

    void setpret(float pret) {
        if(pret > 0)
            this->pret= pret;
    }

    void setcaiPutere( int caiPutere) {
        if(caiPutere>0)
            this->caiPutere= caiPutere;
    }

    void setlocuri(int locuri) {
        if(locuri>0)
            this->locuri= locuri;
    }

    static double numarSkijeturi() {
        return nrSkijeturi + 1;
    }

    friend int catiCaiPutere(Skijet ski);
    friend float crestePretul(Skijet ski);

    Skijet operator= (const Skijet&skj) {
        if(this->proprietar != NULL)
        delete[]this->proprietar;

        this->proprietar= new string[1000];
        this->proprietar=skj.proprietar;
        this->caiPutere=skj.caiPutere;
        this->locuri=skj.locuri;
        this->pret=skj.pret;
        return *this;
    }

    Skijet* operator-> () {
        this->pret= 300000;
        return this;
    }

    operator float() {
        return pret;
    }

    friend Skijet operator* (int, Skijet);
    friend bool locuriPare(Skijet);
    friend bool incapPeSkijet(int, Skijet);
};

class Port {
    private:
    Skijet skijet;
    Barca* v_barca;
    int capacitate;
    double marime;

    public:
    Port() {
        this->capacitate= 1000;
        this->marime= 20000;
        this->skijet->setcaiPutere(300);
        this->skijet->setlocuri(5);
        this->skijet->setpret(10000);
        string p= "Mircea";
        this->skijet->setproprietar(&p);
        this->v_barca= new Barca[3];
        for(int i=0; i<3; i++)
            this->v_barca[i]= Barca();
    }

    int getcapacitate() {
        return capacitate;
    }

    void setcapacitate(int capacitate) {
        if(capacitate>0)
            this->capacitate= capacitate;
    }

    double getmarime() {
        return marime;
    }

    void setmarime(double marime) {
        if(marime>0)
            this->marime= marime;
    }

    Skijet getskijet() {
        return skijet;
    }

    Barca* getv_barca(int n) {
        for(int i=0; i<n; i++)
            return &v_barca[i];
    }

    void setv_barca(Barca &barca, int n) {
        for(int i=0; i<n; i++)
            this->v_barca[i]= barca;
    }

    void setskijet(Skijet skijet) {
        this->skijet= skijet;
    }

    ~Port() {
        if(this->v_barca != nullptr)
            delete[] this->v_barca;
    }
};

istream& operator>> (istream& iStream, Skijet& skijet) {
    int n;
    cout<<"Skijet: "<< "Cai Putere: ";
    iStream >>n;
    skijet.setcaiPutere(n);
    int c;
    cout<<"Locuri: ";
    iStream >> c;
    skijet.setlocuri(c);
    float p;
    cout<<"Pret:";
    iStream >> p;
    skijet.setpret(p);
}

istream& operator>> (istream& iStream, Barca& barca) {
    double n;
    cout<<"Barca: "<< "Cai Putere: ";
    iStream >>n;
    barca.setcaiPutere(n);
    bool e;
    cout<<"Are etaj: ";
    iStream >> e;
    barca.setetaj(e);
    float p;
    cout<<"Pret:";
    iStream >> p;
    barca.setpret(&p);
    string pr;
    cout<<"Nume: ";
    iStream >> pr;
    barca.setnume(pr);
}

istream& operator>> (istream& iStream, Port& port) {
    Skijet skijet;
    cout<<"Port: "<< "Skijet ";
    iStream >>skijet;
    port.setskijet(skijet);
    Barca v_barca;
    int n;
    cout<<"Barca: ";
    iStream >> n;
    iStream >> v_barca;
    port.setv_barca(v_barca, n);
    int c;
    cout<<"Capacitate:";
    iStream >> c;
    port.setcapacitate(c);
    double m;
    cout<<"Marime: ";
    iStream >> m;
    port.setmarime(m);
}

Port operator+ (double valoare, Port port) {
    Port aux= port;
    double marime= aux.getmarime();
    double suma= marime + valoare;
    aux.setmarime(suma);
    return aux;
}

Port operator* (int valoare, Port port) {
        Port aux= port;
        int capacitate= port.getcapacitate();
        int produs= capacitate * valoare;
        aux.setcapacitate(produs);
        return aux;
}