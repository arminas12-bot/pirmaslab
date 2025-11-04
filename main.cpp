#include "mylib.h"
#include "failai.h"

int main() {

    char konteineris;
    cout << "Su kokiu konteineriu norite dirbti? Jei su sarasu rasykite raide S, jei su vektoriumi - V" << endl;
    cin >> konteineris;

    vector<Studentas> GrupeV;
    list<Studentas> GrupeS;

    cout << "Ar duomenis norite vesti pats, ar nuskaityti is failo kursiokai.txt? Jei pats, rasykite raide p(P), jei is failo, tuomet f(F), o jei generuoti failus - rasykite g(G)." << endl;
    char pasirinkta;
    cin >> pasirinkta;

    if (pasirinkta == 'p' || pasirinkta == 'P') {
        cout << "Iveskite studentu skaiciu grupeje: ";
        int m;
        cin >> m;
        if (m <= 0) {
            cout << "Klaidingai ivesti duomenys. Studentu skaicius turi buti rasomas arabiskais skaitmenimis ir turi buti didesnis uz 0." << endl;
            return 0;
        }

        if (konteineris == 'V' || konteineris == 'v') {
            for (int z = 0; z < m; z++) {
                Studentas st = Stud_iv();
                if (st.valid) {
                    GrupeV.push_back(st);
                    cout << "Studento ( " << st.var << " " << st.pav << " ) atminties adresas: " <<static_cast<void*>(& GrupeV.back()) << endl;
                }
            }
            atvaizdvektorius(GrupeV);
        }
        else {
            for (int z = 0; z < m; z++) {
                Studentas st = Stud_iv();
                if (st.valid) {
                    GrupeS.push_back(st);
                    cout << "Studento ( " << st.var << " " << st.pav << " ) atminties adresas: " << static_cast<void*>(& GrupeS.back()) << endl;
                }
            }
            atvaizdsarasas(GrupeS);
        }
    }

    else if (pasirinkta == 'f' || pasirinkta == 'F') {
        string norimfail;
        cout << "Iveskite norimo failo pavadinimas (gale nepamirskite prideti .txt): ";
        cin >> norimfail;

        auto startas = high_resolution_clock::now();
        bool sekmingas = false;

        if (konteineris == 'V' || konteineris == 'v') {
            sekmingas = failiukasvektorius(GrupeV, norimfail);
        }
        else
            sekmingas = failiukassarasas(GrupeS, norimfail);

        auto uztrukimas = duration_cast<seconds>(high_resolution_clock::now() - startas);

        if (sekmingas) {
          
            cout << "Sekmingai pavyko nuskaityti duomenis is failo. ";
            cout << "Nuskaityti faila uztruko: " << uztrukimas.count() << " s." << endl;
            if (konteineris=='V'||konteineris=='v')
                atvaizdvektorius(GrupeV);
            else
                atvaizdsarasas(GrupeS);
        }
        else {
            cout << "Nesekmingas failo nuskaitymas" << endl;
        }
    }

    else if (pasirinkta == 'g' || pasirinkta == 'G') {
        generuojafailus();
        cout << "Jei norite toliau dirbti su sugeneruotu failu, iveskite jo pavadinima, jei norite baigti, rasykite raide b(B): ";
        string failas;
        cin >> failas;

        if (failas != "b" && failas != "B") {
            auto startas = (high_resolution_clock::now());
            bool sekmingas = false;

            if (konteineris == 'V' || konteineris == 'v')
                sekmingas = failiukasvektorius(GrupeV, failas);
            else
                sekmingas = failiukassarasas(GrupeS, failas);

                auto uztrukimas = duration_cast<seconds>(high_resolution_clock::now() - startas);

                if (sekmingas) {

                cout << "Nuskaitymas sekmingas" << endl;
                cout << "Nuskaityti faila uztruko: " << uztrukimas.count() << " s." << endl;
                if (konteineris=='V'||konteineris=='v')
                    atvaizdvektorius(GrupeV);
                else
                    atvaizdsarasas(GrupeS);
            }
            else {
                cout << "Nesekmingas nuskaitymas failo" << failas << endl;
            }
        }
        else {
            cout << "Viskas baigta, failai sekmingai sukurti" << endl;
        }
    }
    return 0;
}
