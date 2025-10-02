#include "mylib.h"
#include "failai.h"

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
