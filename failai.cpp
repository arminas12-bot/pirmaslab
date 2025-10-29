#include "failai.h"

bool failiukasvektorius(vector <Studentas>& Grupe, string failassupavadinimu) {
    ifstream skaitymui(failassupavadinimu);
    if (!skaitymui.is_open()) {
        return false;
    }

    string visaeil;
    while (getline(skaitymui, visaeil)) {
        if (visaeil.empty()) continue;

        istringstream kintam(visaeil);
        Studentas studencioks;
        kintam >> studencioks.pav >> studencioks.var;

        vector <int> paz;
        int j;

        while (kintam >> j) {
            paz.push_back(j);
        }

        if (paz.empty()) continue;

        studencioks.egz = paz.back();
        paz.pop_back();
        studencioks.paz = paz;

        double sum = 0;
        for (int q : paz)
            sum = sum + q;

        if (!paz.empty()) {
            studencioks.vidur = (sum / paz.size()) * 0.4 + studencioks.egz * 0.6;
            studencioks.median = ieskommediana(paz) * 0.4 + studencioks.egz * 0.6;
        }
        else {
            studencioks.vidur = 0.6 * studencioks.egz;
            studencioks.median = 0.6 * studencioks.egz;
        }
        Grupe.push_back(studencioks);
    }
    skaitymui.close();
    return true;
}

void atvaizdvektorius(vector <Studentas>& Grupe) {
    if (!Grupe.empty()) {
        cout << "Kaip norite atlikti rusiavimas? Pagal vardus - 1, pagal pavardes - 2, pagal vidurkius - 3. " << endl;
        int prad;
        cin >> prad;

        auto rikiavimopradzia = high_resolution_clock::now();

        if (prad == 1) { sort(Grupe.begin(), Grupe.end(), sortinamVardus); }
        else if (prad == 2) sort(Grupe.begin(), Grupe.end(), sortinamPavardes);
        else if (prad == 3) sort(Grupe.begin(), Grupe.end(), sortinam_balus_didz);

        auto rikiavimopabaiga = high_resolution_clock::now();
        auto rikiavimasuztruko = duration_cast<milliseconds>(rikiavimopabaiga- rikiavimopradzia);
        cout << "Pasirinktas studentu isrikiavimas is viso uztruko: " << rikiavimasuztruko.count() <<" ms." << endl;

        cout << "Ka norite suskaiciuoti? Tik galutini vidurki - rasykite raide A, jeigu tik mediana - raide B, jeigu abu - raide C: ";
        char abc;
        cin >> abc;

        auto pradedam = high_resolution_clock::now();

        ofstream rezultatai("rezultatufailas.txt");

        rezultatai << setw(18) << left << "Pavardė";
        rezultatai << setw(18) << left << "Vardas";
        if (abc == 'A' || abc == 'a')
            rezultatai << setw(22) << left << "Galutinis (Vid.)";
        if (abc == 'B' || abc == 'b')
            rezultatai << setw(22) << left << "Galutinis (Med.)";
        if (abc == 'C' || abc == 'c') {
            rezultatai << setw(22) << left << "Galutinis (Vid.)";
            rezultatai << setw(22) << left << "Galutinis (Med.)";
        }
        rezultatai << endl;
        rezultatai << string(65, '-') << endl;

        for (auto s : Grupe) {
            rezultatai << setw(18) << left << s.pav;
            rezultatai << setw(18) << left << s.var;
            if (abc == 'A' || abc == 'a')
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.vidur;
            if (abc == 'B' || abc == 'b')
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.median;
            if (abc == 'C' || abc == 'c') {
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.vidur;
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.median;
            }
            rezultatai << endl;
        }
        vector<Studentas>vargseliai;
        vector<Studentas>kietiakai;

        auto pradz = high_resolution_clock::now();
        for (auto s : Grupe) {
            double gal = (abc == 'B' || abc == 'b') ? s.median : s.vidur;
            if (gal < 5) {
                vargseliai.push_back(s);
            }
            else {
                kietiakai.push_back(s);
            }
        }
        auto pab = high_resolution_clock::now();

        ofstream vargsiukai("vargsiukai.txt");
        ofstream kietekai("kietekai.txt");
        if (!vargsiukai.is_open() || !kietekai.is_open()) {
            cout << "Nepavyko sukurti vargsiuku, kieteku failo";
        }
        else {
            vargsiukai << setw(17) << left << "Pavarde";
            vargsiukai << setw(17) << left << "Vardas";
            vargsiukai << setw(21) << left << "Galutinis" << endl;
            vargsiukai << string(65, '-') << endl;

            kietekai << setw(17) << left << "Pavarde";
            kietekai << setw(17) << left << "Vardas";
            kietekai << setw(21) << left << "Galutinis" << endl;
            kietekai << string(65, '-') << endl;
            auto ipradz = high_resolution_clock::now();
            for (const Studentas& s : Grupe) {
                double gal;
                if (abc == 'B' || abc == 'b') {
                    gal = s.median;
                }
                else
                    gal = s.vidur;

                if (gal < 5) {
                    vargsiukai << setw(17) << left << s.pav;
                    vargsiukai << setw(17) << left << s.var;
                    vargsiukai << setw(21) << left << fixed << setprecision(2) << gal << endl;
                }
                else {
                    kietekai << setw(17) << left << s.pav;
                    kietekai << setw(17) << left << s.var;
                    kietekai << setw(21) << left << fixed << setprecision(2) << gal << endl;
                }
            }
            vargsiukai.close();
            kietekai.close();

            auto ipab = high_resolution_clock::now();
            auto w1 = duration_cast<milliseconds>(pab - pradz);
            auto w2 = duration_cast<milliseconds>(ipab - ipradz);
            cout << "Studentu rusiavimas i dvi grupes uztruko: " << w1.count() << " ms." << endl;
            cout << "Studentu surusiuotu isvedimas i du naujus failus uztruko: " << w2.count() << " ms." << endl;
        }
        double kursovidurkis = 0;
        int islaik = 0;
        int neislaik = 0;

        for (auto& nez : Grupe) {
            kursovidurkis = kursovidurkis + nez.vidur;
            if (nez.vidur >= 4.5) islaik++;
            else neislaik++;
        }
        kursovidurkis = kursovidurkis / Grupe.size();
        rezultatai << "Bendras viso kurso studentu vidurkis: " << fixed << setprecision(2) << kursovidurkis << endl;
        rezultatai << "Teigiama bendra iverti gavo: " << islaik << " studentai." << endl;
        rezultatai << "Neigiama bendra iverti gavo ir kursa kartos: " << neislaik << " studentai." << endl;


        rezultatai.close();

        auto pabaigiam = high_resolution_clock::now();
        auto bendraslaikas = duration_cast<milliseconds>(pabaigiam - pradedam);
        cout << "Irasymas i rezultatu faila uztruko: " << bendraslaikas.count() << " ms." << endl;
        cout << "Rezultatai sekmingai issaugoti" << endl;
    }
}

bool failiukassarasas(list <Studentas>& Grupe, string failassupavadinimu) {
    ifstream skaitymui(failassupavadinimu);
    if (!skaitymui.is_open()) {
        return false;
    }

    string visaeil;
    while (getline(skaitymui, visaeil)) {
        if (visaeil.empty()) continue;

        istringstream kintam(visaeil);
        Studentas studencioks;
        kintam >> studencioks.pav >> studencioks.var;

        vector <int> paz;
        int j;

        while (kintam >> j) {
            paz.push_back(j);
        }

        if (paz.empty()) continue;

        studencioks.egz = paz.back();
        paz.pop_back();
        studencioks.paz = paz;

        double sum = 0;
        for (int q : paz)
            sum = sum + q;

        if (!paz.empty()) {
            studencioks.vidur = (sum / paz.size()) * 0.4 + studencioks.egz * 0.6;
            studencioks.median = ieskommediana(paz) * 0.4 + studencioks.egz * 0.6;
        }
        else {
            studencioks.vidur = 0.6 * studencioks.egz;
            studencioks.median = 0.6 * studencioks.egz;
        }
        Grupe.push_back(studencioks);
    }
    skaitymui.close();
    return true;
}

void atvaizdsarasas(list <Studentas>& Grupe) {
    if (!Grupe.empty()) {
        cout << "Kaip norite atlikti rusiavimas? Pagal vardus - 1, pagal pavardes - 2, pagal vidurkius - 3. " << endl;
        int prad;
        cin >> prad;

        auto rikiavimopradzia = high_resolution_clock::now();

        if (prad == 1) Grupe.sort(sortinamVardus);
        else if (prad == 2) Grupe.sort(sortinamPavardes);
        else if (prad == 3) Grupe.sort(sortinam_balus_didz);

        auto rikiavimopabaiga = high_resolution_clock::now();
        auto rikiavimasuztruko = duration_cast<milliseconds>(rikiavimopabaiga - rikiavimopradzia);
        cout << "Pasirinktas studentu isrikiavimas is viso uztruko: " << rikiavimasuztruko.count() << " ms." << endl;

        cout << "Ka norite suskaiciuoti? Tik galutini vidurki - rasykite raide A, jeigu tik mediana - raide B, jeigu abu - raide C: ";
        char abc;
        cin >> abc;

        ofstream rezultatai("rezultatufailas.txt");

        rezultatai << setw(18) << left << "Pavardė";
        rezultatai << setw(18) << left << "Vardas";
        if (abc == 'A' || abc == 'a')
            rezultatai << setw(22) << left << "Galutinis (Vid.)";
        if (abc == 'B' || abc == 'b')
            rezultatai << setw(22) << left << "Galutinis (Med.)";
        if (abc == 'C' || abc == 'c') {
            rezultatai << setw(22) << left << "Galutinis (Vid.)";
            rezultatai << setw(22) << left << "Galutinis (Med.)";
        }
        rezultatai << endl;
        rezultatai << string(65, '-') << endl;

        for (auto s : Grupe) {
            rezultatai << setw(18) << left << s.pav;
            rezultatai << setw(18) << left << s.var;
            if (abc == 'A' || abc == 'a')
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.vidur;
            if (abc == 'B' || abc == 'b')
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.median;
            if (abc == 'C' || abc == 'c') {
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.vidur;
                rezultatai << setw(22) << left << fixed << setprecision(2) << s.median;
            }
            rezultatai << endl;
        }
        list<Studentas>vargseliai;
        list<Studentas>kietiakai;

        auto pradz = high_resolution_clock::now();
        for (auto s : Grupe) {
            double gal = (abc == 'B' || abc == 'b') ? s.median : s.vidur;
            if (gal < 5) {
                vargseliai.push_back(s);
            }
            else {
                kietiakai.push_back(s);
            }
        }
        auto pab = high_resolution_clock::now();

        ofstream vargsiukai("vargsiukai.txt");
        ofstream kietekai("kietekai.txt");
        if (!vargsiukai.is_open() || !kietekai.is_open()) {
            cout << "Nepavyko sukurti vargsiuku, kieteku failo";
        }
        else {
            vargsiukai << setw(17) << left << "Pavarde";
            vargsiukai << setw(17) << left << "Vardas";
            vargsiukai << setw(21) << left << "Galutinis" << endl;
            vargsiukai << string(65, '-') << endl;

            kietekai << setw(17) << left << "Pavarde";
            kietekai << setw(17) << left << "Vardas";
            kietekai << setw(21) << left << "Galutinis" << endl;
            kietekai << string(65, '-') << endl;
            auto ipradz = high_resolution_clock::now();
            for (const Studentas& s : Grupe) {
                double gal;
                if (abc == 'B' || abc == 'b') {
                    gal = s.median;
                }
                else
                    gal = s.vidur;

                if (gal < 5) {
                    vargsiukai << setw(17) << left << s.pav;
                    vargsiukai << setw(17) << left << s.var;
                    vargsiukai << setw(21) << left << fixed << setprecision(2) << gal << endl;
                }
                else {
                    kietekai << setw(17) << left << s.pav;
                    kietekai << setw(17) << left << s.var;
                    kietekai << setw(21) << left << fixed << setprecision(2) << gal << endl;
                }
            }
            vargsiukai.close();
            kietekai.close();

            auto ipab = high_resolution_clock::now();
            auto w1 = duration_cast<milliseconds>(pab - pradz);
            auto w2 = duration_cast<milliseconds>(ipab - ipradz);
            cout << "Studentu rusiavimas i dvi grupes uztruko: " << w1.count() << " ms." << endl;
            cout << "Studentu surusiuotu isvedimas i du naujus failus uztruko: " << w2.count() << " ms." << endl;
        }
        double kursovidurkis = 0;
        int islaik = 0;
        int neislaik = 0;

        for (auto& nez : Grupe) {
            kursovidurkis = kursovidurkis + nez.vidur;
            if (nez.vidur >= 4.5) islaik++;
            else neislaik++;
        }
        kursovidurkis = kursovidurkis / Grupe.size();
        rezultatai << "Bendras viso kurso studentu vidurkis: " << fixed << setprecision(2) << kursovidurkis << endl;
        rezultatai << "Teigiama bendra iverti gavo: " << islaik << " studentai." << endl;
        rezultatai << "Neigiama bendra iverti gavo ir kursa kartos: " << neislaik << " studentai." << endl;


        rezultatai.close();
        cout << "Rezultatai sekmingai issaugoti" << endl;
    }
}
