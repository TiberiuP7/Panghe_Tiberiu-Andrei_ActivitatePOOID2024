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

Barca operator+ (double valoare, Barca barca) {
    Barca aux= barca;
    double cai= aux.getcaiPutere();
    double suma= cai + valoare;
    aux.setcaiPutere(suma);
    return aux;
}

Barca operator- (double valoare, Barca barca) {
    Barca aux= barca;
    double cai= aux.getcaiPutere();
    double diferenta= cai - valoare;
    aux.setcaiPutere(diferenta);
    return aux;
}

ostream& operator<< (ostream& oStream, Barca barca) {
    string etaj;
    if(barca.getetaj()==1)
        etaj= " Cu etaj ";
    else
        etaj= " Fara etaj ";
    oStream << barca.getcaiPutere() << etaj.c_str() << barca.getnume() <<endl;
    oStream << "cu pretul de:" << barca.getpret()<< endl;
}

ostream& operator<< (ostream& oStream, Vapor vapor) {
    string cargo;
    if(vapor.getcargo()==1)
        cargo= " Cu marfa ";
    else
        cargo= " Fara marfa ";
    oStream << vapor.getniveluri() << " "<< vapor.getmarime() << " "<< cargo.c_str() <<endl;
    oStream << "cu pretul de:" << vapor.getpret() << " si numele: "<< vapor.ceNume()<< "\n";
}

ostream& operator<< (ostream& oStream, Skijet skijet) {
    oStream << skijet.getcaiPutere() << " "<< skijet.getproprietar() << " "<< skijet.getlocuri() <<endl;
    oStream << "cu pretul de:" << skijet.getpret()<< endl;
}

istream& operator>> (istream& iStream, Vapor& vapor) {
    int n;
    cout<< "Vapor: ";
    iStream >>n;
    vapor.setniveluri(n);
    bool c;
    iStream >> c;
    if(c==0 || c==1)
    vapor.setcargo(c);
    int m;
    iStream>>m;
    vapor.setmarime(m);
    float p;
    iStream>> p;
    vapor.setpret(&p);
}

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

Skijet operator* (int valoare, Skijet skj) {
        Skijet aux= skj;
        aux.locuri= aux.locuri * skj.locuri;
        return aux;
}

bool locuriPare(Skijet skj) {
    bool aux;
    if(skj.locuri % 2 ==0)
        aux= true;
    else
        aux= false;

    return aux;
} 

bool incapPeSkijet(int valoare, Skijet skj) {
    bool aux;
    if(valoare < skj.locuri)
        aux= true;
    else
        aux= false;

    return aux;
}

int main()
{
    Barca barca;
    Barca *p_barca= new Barca();
    Barca *v_barca= new Barca[3];
    v_barca[2]= Barca();
    
    for(int i=0; i<3; i++)
    {
        v_barca[i]= Barca();
    }

    Vapor *v_vapor= new Vapor[3];
    for(int i=0; i<3; i++)
    {
        v_vapor[i]= Vapor();
    }
    for(int i=0; i<3; i++)
    {
        operator>>(cin, v_vapor[i]);
    }
    for(int i=0; i<3; i++)
    {
        operator<<(cout, v_vapor[i]);
    }

    Skijet *v_skijet= new Skijet[3];
      for(int i=0; i<3; i++)
    {
        v_skijet[i]= Skijet();
    }
    for(int i=0; i<3; i++)
    {
        operator>>(cin, v_skijet[i]);
    }

    for(int i=0; i<3; i++)
    {
        operator<<(cout, v_skijet[i]);
    }
    
    Barca **pp_barca= new Barca*[3];
    for(int i=0; i<3; i++)
    {
        pp_barca[i]= new Barca[3];
        for(int j=0; j<3; j++)
        {
            pp_barca[i][j]= Barca();
        }
    }

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            operator>>(cin, pp_barca[i][j]);
        }

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            operator<<(cout, pp_barca[i][j]);
        }
}