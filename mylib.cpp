#include "mylib.h"

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
bool sortinamVardus(Studentas & pirmvard, Studentas & antrvard) {
    return pirmvard.var<antrvard.var;}

bool sortinamPavardes(Studentas & pirmpavard, Studentas & antrpavard) {
    return pirmpavard.pav<antrpavard.pav;}
    
bool sortinam_balus_didz(Studentas & pirmbalas, Studentas & antrbalas) {
    return pirmbalas.vidur>antrbalas.vidur;}
