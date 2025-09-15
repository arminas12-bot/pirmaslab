#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


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


struct Studentas {
    string var;
    string pav;
    vector <int> paz;
    int egz;
    double gal;
};


Studentas Stud_iv();

int main() {
    vector<Studentas> Grupe;
    cout<<"Iveskite studentu skaiciu grupeje: ";
    int m;
    cin>>m;
    
    for(auto z=0; z<m; z++)
      Grupe.push_back(Stud_iv());
      
    cout<<setw(18)<<left<<"Pavardė";
    cout<<setw(18)<<left<<"Vardas";
    cout<<setw(22)<<left<<"Galutinis (Vid.)"<<endl;
    cout<<string(52, '-')<<endl;

    for (auto s: Grupe) {
        cout<<setw(16)<<left<<s.pav;
        cout<<setw(16)<<left<<s.var;
        cout<<setw(21)<<left<<fixed<<setprecision(2)<<s.gal<<endl;
    }
}

Studentas Stud_iv() {
    int n, laik_paz, sum=0;
    Studentas Pirmas;
    cout<<"Uzpildykite pasirinkto studento duomenis"<<endl;
    cout<<"Studento vardas: "; cin>>Pirmas.var;
    cout<<"Studento pavarde: "; cin>>Pirmas.pav;
    cout<<"Iveskite studento gautu pazymiu skaiciu"<<endl;
    cout<<"Kiek pazymiu gavo "<<Pirmas.var<<" "<<Pirmas.pav<<"? "; cin>>n; ;
    for(int a=0;a<n;a++) {
        cout<<a+1<<": "; cin>>laik_paz;
        Pirmas.paz.push_back(laik_paz);
        sum+=laik_paz; 
    }
    cout<<"Iveskite gauta studento egzamino pazymi: "; cin>>Pirmas.egz;
    Pirmas.gal=double(sum)/double(n)*0.4+Pirmas.egz*0.6;
    return Pirmas;
}
