#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>


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

int main() {
    vector<Studentas> Grupe;
    cout<<"Iveskite studentu skaiciu grupeje: ";
    int m;
    cin>>m;
    if (m<=0) {
        cout<<"Klaidingai ivesti duomenys. Studentu skaicius turi buti rasomas arabiskais skaitmenimis ir turi buti didesnis uz 0."<<endl;
        return 0;
    }
    
    cout<<"Ka norite suskaiciuoti? Tik galutini vidurki - rasykite raide A, jeigu tik mediana - raide B, jeigu abu - raide C. ";
    char abc;
    cin>>abc;
    
    for(int z=0; z<m; z++) {
        Studentas st=Stud_iv();
        if(st.valid)
            Grupe.push_back(st);
    }
    if (!Grupe.empty()) {  
        cout<<setw(18)<<left<<"Pavardė";
        cout<<setw(18)<<left<<"Vardas";
        if (abc=='A')
            cout<<setw(22)<<left<<"Galutinis (Vid.)";
        if (abc=='B')
            cout<<setw(22)<<left<<"Galutinis (Med.)";
        if (abc=='C') {
            cout<<setw(22)<<left<<"Galutinis (Vid.)";
            cout<<setw(22)<<left<<"Galutinis (Med.)";
        }
        cout<<endl;
        cout<<string(65, '-')<<endl;

        for (auto s: Grupe) {
            cout<<setw(18)<<left<<s.pav;
            cout<<setw(18)<<left<<s.var;
            if (abc=='A')
                cout<<setw(22)<<left<<fixed<<setprecision(2)<<s.vidur;
            if (abc=='B')    
                cout<<setw(22)<<left<<fixed<<setprecision(2)<<s.median;
            if (abc=='C') {   
                cout<<setw(22)<<left<<fixed<<setprecision(2)<<s.vidur;
                cout<<setw(22)<<left<<fixed<<setprecision(2)<<s.median;
            }  
            cout<<endl;
        }
    }
}
Studentas Stud_iv() {
    int n, laik_paz, sum=0;
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
    cout<<"Iveskite studento gautu pazymiu skaiciu"<<endl;
    cout<<"Kiek pazymiu gavo "<<Pirmas.var<<" "<<Pirmas.pav<<"? "; cin>>n;
    if (cin.fail()) {
        cout<<"Klaida! Pazymiu skaicius rasomas arabiskais skaitmenimis! "<<endl;
        Pirmas.valid = false;
        return Pirmas;
    }
    
    for(int a=0;a<n;a++) {
        cout<<a+1<<": "; cin>>laik_paz;
        if (cin.fail() || laik_paz<1 || laik_paz>10) {
            cout<<"Klaidingai ivesti duomenys"<<endl;
            Pirmas.valid = false;
            return Pirmas;
        }
        Pirmas.paz.push_back(laik_paz);
        sum+=laik_paz; 
    }
    cout<<"Iveskite gauta studento egzamino pazymi: "; cin>>Pirmas.egz;
    if (cin.fail() || Pirmas.egz<1 || Pirmas.egz>10) {
            cout<<"Klaidingai ivesti duomenys"<<endl;
            Pirmas.valid = false;
            return Pirmas;
        }
        
    if (n>0) {
        double vid=double(sum)/double(n);
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
