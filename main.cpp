#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::string;
using std::fixed;
using std::setprecision;
using std::sort;
using std::uniform_int_distribution;
using std::random_device;
using std::mt19937;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::stringstream;


struct Studentas {
    string var;
    string pav;
    vector <int> paz;
    int egz;
    double vidur;
    double median;
    bool valid = true;
};


Studentas Stud_iv();
double ieskommediana(vector <int> paz);
bool failiukas(vector <Studentas> & Grupe, string failassupavadinimu);
void atvaizd(vector <Studentas> & Grupe);

void generuojafailus();
void generuotifaila(string genfail, int iraskiekis);

bool sortinamVardus(Studentas & pirmvard, Studentas & antrvard) {
    return pirmvard.var<antrvard.var;}

bool sortinamPavardes(Studentas & pirmpavard, Studentas & antrpavard) {
    return pirmpavard.pav<antrpavard.pav;}
    
bool sortinam_balus_didz(Studentas & pirmbalas, Studentas & antrbalas) {
    return pirmbalas.vidur>antrbalas.vidur;}

int main() {
    vector<Studentas> Grupe;
    
    cout<<"Ar duomenis norite vesti pats, ar nuskaityti is failo kursiokai.txt? Jei pats, rasykite raide p(P), jei is failo, tuomet f(F), o jei generuoti failus - rasykite g(G)."<<endl;
    char pasirinkta;
    cin>>pasirinkta;
    
    if (pasirinkta=='p'||pasirinkta=='P') {
        cout<<"Iveskite studentu skaiciu grupeje: ";
        int m;
        cin>>m;
        if (m<=0) {
            cout<<"Klaidingai ivesti duomenys. Studentu skaicius turi buti rasomas arabiskais skaitmenimis ir turi buti didesnis uz 0."<<endl;
            return 0;
        }
    
        for(int z=0; z<m; z++) {
            Studentas st=Stud_iv();
            if(st.valid)
                Grupe.push_back(st);
        }
        atvaizd(Grupe);
    }
    
    else if (pasirinkta=='f'||pasirinkta=='F') {
        string norimfail;
        cout<<"Iveskite norimo failo pavadinimas (gale nepamirskite prideti .txt): ";
        cin>>norimfail;
        
        if (failiukas(Grupe, norimfail)) {
            cout<<"Sekmingai pavyko nuskaityti duomenis is failo. "<<endl;
            atvaizd(Grupe);
        }
        else {
            cout<<"Nesekmingas failo nuskaitymas"<<endl;
        }
    }
    
    else if (pasirinkta=='g'||pasirinkta=='G') {
        generuojafailus();
        cout<<"Jei norite toliau dirbti su sugeneruotu failu, iveskite jo pavadinima, jei norite baigti, rasykite raide b(B): ";
        string failas;
        cin>>failas;
        
        if (failas!="b"&&failas!="B") {
            Grupe.clear();
            if (failiukas(Grupe, failas)) {
                cout<<"Nuskaitymas sekmingas"<<endl;
                atvaizd(Grupe);
            }
            else {
                cout<<"Nesekmingas nuskaitymas fialo"<<failas<<endl;
            }
        }
        else {
            cout<<"Viskas baigta, failai sekmingai sukurti"<<endl;
        }
    }
}

Studentas Stud_iv() {
    int laik_paz, sum=0;
    Studentas Pirmas;
    cout<<"Uzpildykite pasirinkto studento duomenis"<<endl;
    cout<<"Studento vardas: "; cin>>Pirmas.var;
    for (char raid: Pirmas.var) {
        if (isdigit(raid)) {
            cout<<"Varde turi buti rasomos TIK raides."<<endl;
            Pirmas.valid = false;
            return Pirmas;
        }
    }
    
    cout<<"Studento pavarde: "; cin>>Pirmas.pav;
    for (char raid: Pirmas.pav) {
        if (isdigit(raid)) {
            cout<<"Pavardeje turi buti rasomos TIK raides."<<endl;
            Pirmas.valid = false;
            return Pirmas;
        }
    }
    
    cout<<"Jeigu pazymius norite generuoti automatiskai, rasykite TAIP, jeigu norite vesti ranka, tuomet rasykite NE."<<endl;
    cout<<"Jusu atsakymas (TAIP/NE) : ";
    string atsitik;
    cin>>atsitik;
    if (atsitik=="Taip"||atsitik=="taip"||atsitik=="TAIP") {
        random_device rando;
    
        mt19937 mt(rando());
    
        uniform_int_distribution <int> dydis(1,10);
    
        uniform_int_distribution <int> generuoja(5,15);
        int pazymiu_skaicius=generuoja(mt);
    
        for (int i=0; i<pazymiu_skaicius; i++) {
            int paz=dydis(mt);
            Pirmas.paz.push_back(paz);
            sum=sum+paz;
        }
        cout<<"Sugeneruoti atsitiktiniai iverciai: ";
        for (int ivert: Pirmas.paz) {
            cout<<ivert<<" ";
        }
        cout<<endl;
        
        
        Pirmas.egz=dydis(mt);
        cout<<"Atsitiktinis egzaminos balas: "<<Pirmas.egz<<endl;
        cout<<"Automatiskai atsitiktiniu budu sugeneruotas buvo 1 egzamino ivertinimas ir "<<pazymiu_skaicius<<" pazymiai."<<endl;
    }
    else {
    cout<<"Iveskite studento gautus pazymius. Baige vesti norimus pazymius iveskite 0."<<endl;
    
    int numeris=1;
    
    while (true) {
        cout<<numeris<<" pazymys: ";
        cin>>laik_paz;
        
        if (cin.fail()) {
            cout<<"Klaidingai ivestas pazymys."<<endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        if (laik_paz==0) break;
        if(laik_paz<1||laik_paz>10) {
            cout<<"Pazymiai turi buti vedami nuo 1 iki 10."<<endl;
            continue;
        }
        
        Pirmas.paz.push_back(laik_paz);
        sum+=laik_paz;
        numeris++;
    }

    cout<<"Iveskite gauta studento egzamino pazymi: "; cin>>Pirmas.egz;
    if (cin.fail() || Pirmas.egz<1 || Pirmas.egz>10) {
            cout<<"Klaidingai ivesti duomenys"<<endl;
            Pirmas.valid = false;
            return Pirmas;
        }
    }    
    if (!Pirmas.paz.empty()) {
        double vid=double(sum)/double(Pirmas.paz.size());
        Pirmas.vidur=vid*0.4+Pirmas.egz*0.6;
        double medi=ieskommediana(Pirmas.paz);
        Pirmas.median=medi*0.4+Pirmas.egz*0.6;
    }
    else {
        Pirmas.vidur=0.6*Pirmas.egz;
        Pirmas.median=0.6*Pirmas.egz;
    }
    
    return Pirmas;
}

double ieskommediana (vector<int> paz) {
    double h;
    sort(paz.begin(), paz.end());
    int n=paz.size();
    if (n%2==1) {
        h=paz[n/2];
    }
    else {
        h=(paz[n/2-1]+paz[n/2])/2.0;
    }
    return h;
}

bool failiukas(vector <Studentas> & Grupe, string failassupavadinimu) {
    ifstream skaitymui(failassupavadinimu);
    if (!skaitymui.is_open()) {
        return false;
    }
    
    string visaeil;
    while (getline(skaitymui, visaeil)) {
        if(visaeil.empty()) continue;
        
        istringstream kintam(visaeil);
        Studentas studencioks;
        kintam>>studencioks.pav>>studencioks.var;
        
        vector <int> paz;
        int j;
        
        while (kintam>>j) {
            paz.push_back(j);
        }
        
        if (paz.empty()) continue;
        
        studencioks.egz=paz.back();
        paz.pop_back();
        studencioks.paz=paz;
        
        double sum=0;
        for (int q: paz)
        sum=sum+q;
        
        if (!paz.empty()) {
            studencioks.vidur=(sum/paz.size())*0.4+studencioks.egz*0.6;
            studencioks.median=ieskommediana(paz)*0.4+studencioks.egz*0.6;
        }
        else {
            studencioks.vidur=0.6*studencioks.egz;
            studencioks.median=0.6*studencioks.egz;
        }
        Grupe.push_back(studencioks);
    }
    skaitymui.close();
    return true;
}

void atvaizd (vector <Studentas> & Grupe) {
    if (!Grupe.empty()) {
        cout<<"Kaip norite atlikti rusiavimas? Pagal vardus - 1, pagal pavardes - 2, pagal vidurkius - 3. "<<endl;
        int prad;
        cin>>prad;
        if (prad==1) {sort (Grupe.begin(), Grupe.end(), sortinamVardus);}
        else if (prad==2) sort (Grupe.begin(), Grupe.end(), sortinamPavardes);
        else if (prad==3) sort (Grupe.begin(), Grupe.end(), sortinam_balus_didz);
        cout<<"Ka norite suskaiciuoti? Tik galutini vidurki - rasykite raide A, jeigu tik mediana - raide B, jeigu abu - raide C: ";
        char abc;
        cin>>abc;
        
        ofstream rezultatai("rezultatufailas.txt");
        
        rezultatai<<setw(18)<<left<<"Pavardė";
        rezultatai<<setw(18)<<left<<"Vardas";
        if (abc=='A'||abc=='a')
            rezultatai<<setw(22)<<left<<"Galutinis (Vid.)";
        if (abc=='B'||abc=='b')
            rezultatai<<setw(22)<<left<<"Galutinis (Med.)";
        if (abc=='C'||abc=='c') {
            rezultatai<<setw(22)<<left<<"Galutinis (Vid.)";
            rezultatai<<setw(22)<<left<<"Galutinis (Med.)";
        }
        rezultatai<<endl;
        rezultatai<<string(65, '-')<<endl;

        for (auto s: Grupe) {
            rezultatai<<setw(18)<<left<<s.pav;
            rezultatai<<setw(18)<<left<<s.var;
            if (abc=='A'||abc=='a')
                rezultatai<<setw(22)<<left<<fixed<<setprecision(2)<<s.vidur;
            if (abc=='B'||abc=='b')    
                rezultatai<<setw(22)<<left<<fixed<<setprecision(2)<<s.median;
            if (abc=='C'||abc=='c') {   
                rezultatai<<setw(22)<<left<<fixed<<setprecision(2)<<s.vidur;
                rezultatai<<setw(22)<<left<<fixed<<setprecision(2)<<s.median;
            }  
            rezultatai<<endl;
        }
        double kursovidurkis=0;
        int islaik=0;
        int neislaik=0;
        
        for (auto & nez : Grupe) {
            kursovidurkis=kursovidurkis+nez.vidur;
            if (nez.vidur>=4.5) islaik++;
            else neislaik++;
        }
        kursovidurkis=kursovidurkis/Grupe.size();
        rezultatai<<"Bendras viso kurso studentu vidurkis: "<<fixed<<setprecision(2)<<kursovidurkis<<endl;
        rezultatai<<"Teigiama bendra iverti gavo: "<<islaik<<" studentai."<<endl;
        rezultatai<<"Neigiama bendra iverti gavo ir kursa kartos: "<<neislaik<<" studentai."<<endl;
        
        ofstream vargsiukai("vargsiukai.txt");
        ofstream kietekai("kietekai.txt");
        if (!vargsiukai.is_open()||!kietekai.is_open()) {
            cout<<"Nepavyko sukurti vargsiuku, kieteku failo";
        }
        else {
            vargsiukai<<setw(17)<<left<<"Pavarde";
            vargsiukai<<setw(17)<<left<<"Vardas";
            vargsiukai<<setw(21)<<left<<"Galutinis"<<endl;
            vargsiukai<<string(65, '-')<<endl;
            
            kietekai<<setw(17)<<left<<"Pavarde";
            kietekai<<setw(17)<<left<<"Vardas";
            kietekai<<setw(21)<<left<<"Galutinis"<<endl;
            kietekai<<string(65, '-')<<endl;
            
            for (const Studentas & s: Grupe) {
                double gal;
                if (abc=='B'||abc=='b') {
                    gal= s.median;
                }
                else 
                    gal=s.vidur;
                    
                if (gal < 5) {
                    vargsiukai<<setw(17)<<left<<s.pav;
                    vargsiukai<<setw(17)<<left<<s.var;
                    vargsiukai<<setw(21)<<left<<fixed<<setprecision(2)<<gal<<endl;
                } 
                else {
                    kietekai<<setw(17)<<left<<s.pav;
                    kietekai<<setw(17)<<left<<s.var;
                    kietekai<<setw(21)<<left<<fixed<<setprecision(2)<<gal<<endl;
                }
            }
            vargsiukai.close();
            kietekai.close();
        }
        rezultatai.close();
        cout<<"Rezultatai sekmingai issaugoti"<<endl;
    }
}

void generuojafailus() {
    cout<<"Generuojami failai, prasome palaukti"<<endl;
    generuotifaila("1000stud.txt", 1000);
    generuotifaila("10000stud.txt", 10000);
    generuotifaila("100000stud.txt", 100000);
    generuotifaila("1000000stud.txt", 1000000);
    generuotifaila("10000000stud.txt", 10000000);
    cout<<"5 skirtingo dydzio failai sekmingai sugeneruoti"<<endl;
}

void generuotifaila(string genfail, int iraskiekis) {
    ofstream failas(genfail);
    if (!failas.is_open()) {
        cout<<"Nesekmingas "<<genfail<<" failo sukurimas"<<endl;
        return;
    }
    
    failas<<left<<setw(20)<<"Pavarde";
    failas<<left<<setw(20)<<"Vardas";
    for (int y=1; y<8; y++) {
        stringstream sstreamas;
        sstreamas<<"Nd"<<y;
        failas<<left<<setw(9)<<sstreamas.str();
    }
    failas<<left<<setw(9)<<"Egz"<<endl;
    
    random_device rando;
    mt19937 mt(rando());
    uniform_int_distribution <int> paz(1,10);
    
    for (int h=1; h<=iraskiekis; h++) {
        stringstream stringpav, stringvar;
        stringpav<<"Pavarde"<<h;
        stringvar<<"Vardas"<<h;
        failas<<left<<setw(20)<<stringpav.str();
        failas<<left<<setw(20)<<stringvar.str();
        for (int l=0; l<7; l++) {
            failas<<left<<setw(9)<<paz(mt);
        }
        failas<<left<<setw(9)<<paz(mt)<<endl;
    }
}
