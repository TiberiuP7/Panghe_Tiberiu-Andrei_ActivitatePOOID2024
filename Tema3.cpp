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
    oStream << barca.getcaiPutere() << " "<< barca.getetaj() << " "<< barca.getnume() <<endl;
    oStream << "cu pretul de:" << barca.getpret();
}

istream& operator>> (istream& iStream, Vapor& vapor) {
    int n;
    iStream >>n;
    vapor.setniveluri(n);
    bool c;
    iStream >> c;
    vapor.setcargo(c);
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
    int n;
    Skijet skj;
    cout<<"Nr. de persoane: ";
    cin>> n;
    bool incap= incapPeSkijet(n, skj);
    bool pare= locuriPare(skj);
    cout<<incap<<pare;

    if(pare ==1)
        cout<< "Skj are un numar de locuri pare si ";
    else
        cout<< "Skj are un numar de locuri impare si ";

    if(incap==1)
        cout<< "incap "<<n<< " persoane"<< endl;
    else
        cout<<"Nu incap "<<n<<" persoane"<<endl; 

    Skijet sk1= skj;
    Skijet sk2= operator*(50, skj);
    float valoarepret= skj;
    cout<< "Vechiul pret este de "<< skj.getpret()<<endl;
    cout<< "Pretul este de "<< skj->getpret()<<endl;

    Barca b1, b2;
    Barca b3= b1;
    operator<<(cout, b1);
    cout<<endl;
    b2= operator+(100, b3);
    b1= operator-(100, b1);
    operator<<(cout, b1);

    Vapor v1, v2;
    Vapor v3= v1;
    operator>>(cin, v2);
    v1++;
    v2--;

    int niveluri= v3;
    cout<<" Nr.de niveluri este: "<<niveluri;
}