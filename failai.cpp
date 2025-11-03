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
        auto rikiavimasuztruko = duration<double>(rikiavimopabaiga- rikiavimopradzia).count();
        cout << "Pasirinktas studentu isrikiavimas is viso uztruko: " <<fixed<<setprecision(4)<< rikiavimasuztruko<<" s." << endl;

        cout << "Ka norite suskaiciuoti? Tik galutini vidurki - rasykite raide A, jeigu tik mediana - raide B, jeigu abu - raide C: ";
        char abc;
        cin >> abc;
        const bool imed = (abc == 'b' || abc == 'B');

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

        for (const auto & s : Grupe) {
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
        auto bendraslaikas = duration<double>(pabaigiam - pradedam).count();
        cout << "Irasymas i rezultatu faila uztruko: " << fixed << setprecision(4)<< bendraslaikas << " s." << endl;

        vector<Studentas>vargseliai;
        vector<Studentas>kietiakai;


        auto pradedamskaidyma = high_resolution_clock::now();
        pirmastr_vector(Grupe, vargseliai, kietiakai, imed);
        auto baigiamskaidyma= high_resolution_clock::now();
        double skaid = duration<double>(baigiamskaidyma - pradedamskaidyma).count();

        cout << "Pirmos strategijos vector skaidymas i 2 kont. uztruko: " << fixed << setprecision(4) << skaid << " s" << endl;
        ofstream vargsiukaiisv("vargsiukai.txt");
        ofstream kietekaiisv("kietekai.txt");
        if (!vargsiukaiisv.is_open() || !kietekaiisv.is_open()) {
            cout << "Nepavyko sukurti vargsiuku, kieteku failo" << endl;
            return;
        }
        vargsiukaiisv << setw(17) << left << "Pavarde";
        vargsiukaiisv << setw(17) << left << "Vardas";
        vargsiukaiisv << setw(21) << left << "Galutinis" << endl;
        vargsiukaiisv << string(65, '-') << endl;

        kietekaiisv << setw(17) << left << "Pavarde";
        kietekaiisv << setw(17) << left << "Vardas";
        kietekaiisv << setw(21) << left << "Galutinis" << endl;
        kietekaiisv << string(65, '-') << endl;

        auto startass = high_resolution_clock::now();

        for (const auto& s : vargseliai) {
            const double gal = imed ? s.median : s.vidur;
            vargsiukaiisv << setw(17) << left << s.pav;
            vargsiukaiisv << setw(17) << left << s.var;
            vargsiukaiisv << setw(21) << left << fixed << setprecision(2) << gal << endl;
        }

        for (const auto& s : kietiakai) {
            const double gal = imed ? s.median : s.vidur;
            kietekaiisv << setw(17) << left << s.pav;
            kietekaiisv << setw(17) << left << s.var;
            kietekaiisv << setw(21) << left << fixed << setprecision(2) << gal << endl;
        }
        auto endas = high_resolution_clock::now();
        cout<<  "Studentu surusiuotu isvedimas i du naujus failus uztruko: " << fixed << setprecision(4) << duration<double>(endas-startass).count() << " s." << endl;


        vargsiukaiisv.close();
        kietekaiisv.close();
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
        auto rikiavimasuztruko = duration<double>(rikiavimopabaiga - rikiavimopradzia).count();
        cout << "Pasirinktas studentu isrikiavimas is viso uztruko: " << fixed << setprecision(4) << rikiavimasuztruko << " s." << endl;

        cout << "Ka norite suskaiciuoti? Tik galutini vidurki - rasykite raide A, jeigu tik mediana - raide B, jeigu abu - raide C: ";
        char abc;
        cin >> abc;
        const bool imed = (abc == 'b' || abc == 'B');

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

        for (const auto & s : Grupe) {
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
        auto bendraslaikas = duration<double>(pabaigiam - pradedam).count();
        cout << "Irasymas i rezultatu faila uztruko: " << fixed << setprecision(4) << bendraslaikas << " s." << endl;
        cout << "Rezultatai sekmingai issaugoti" << endl;

        list<Studentas>vargseliai;
        list<Studentas>kietiakai;

        auto pradedamskaidyma = high_resolution_clock::now();
        pirmastr_list(Grupe, vargseliai, kietiakai, imed);
        auto baigiamskaidyma = high_resolution_clock::now();
        double skaid = duration<double>(baigiamskaidyma - pradedamskaidyma).count();


        cout << "Pirmos strategijos list skaidymas i 2 kont. uztruko: " << fixed << setprecision(4) << skaid << " s" << endl;
        ofstream vargsiukaiisv("vargsiukai.txt");
        ofstream kietekaiisv("kietekai.txt");
        if (!vargsiukaiisv.is_open() || !kietekaiisv.is_open()) {
            cout << "Nepavyko sukurti vargsiuku, kieteku failo";
            return;
        }
        vargsiukaiisv << setw(17) << left << "Pavarde";
        vargsiukaiisv << setw(17) << left << "Vardas";
        vargsiukaiisv << setw(21) << left << "Galutinis" << endl;
        vargsiukaiisv << string(65, '-') << endl;

        kietekaiisv << setw(17) << left << "Pavarde";
        kietekaiisv << setw(17) << left << "Vardas";
        kietekaiisv << setw(21) << left << "Galutinis" << endl;
        kietekaiisv << string(65, '-') << endl;

        auto startass = high_resolution_clock::now();

        for (const auto& s : vargseliai) {
            const double gal = imed ? s.median : s.vidur;
            vargsiukaiisv << setw(17) << left << s.pav;
            vargsiukaiisv << setw(17) << left << s.var;
            vargsiukaiisv << setw(21) << left << fixed << setprecision(2) << gal << endl;
        }

        for (const auto& s : kietiakai) {
            const double gal = imed ? s.median : s.vidur;
            kietekaiisv << setw(17) << left << s.pav;
            kietekaiisv << setw(17) << left << s.var;
            kietekaiisv << setw(21) << left << fixed << setprecision(2) << gal << endl;
        }

        auto endas = high_resolution_clock::now();
        cout << "Studentu surusiuotu isvedimas i du naujus failus uztruko: " << fixed << setprecision(4) << duration<double>(endas-startass).count() << " s." << endl;
        vargsiukaiisv.close();
        kietekaiisv.close();



        cout << "Rezultatai sekmingai issaugoti" << endl;
    }
}

double galutinis(const Studentas& s, bool imammediana) {
    return imammediana ? s.median : s.vidur;
}

void pirmastr_vector(const vector <Studentas>& in, vector<Studentas>& varg, vector <Studentas>& kiet, bool imammediana) {
    varg.clear(); kiet.clear();
    varg.reserve(in.size() / 2);
    kiet.reserve(in.size() / 2);

    partition_copy(in.begin(), in.end(), back_inserter(varg), back_inserter(kiet), [imammediana](const Studentas& s) {
        return galutinis(s, imammediana) < 5.0;
        });
}

void pirmastr_list(const list <Studentas>& in, list<Studentas>& varg, list <Studentas>& kiet, bool imammediana) {
    varg.clear(); kiet.clear();
    for (const Studentas& s : in) {
        if (galutinis(s, imammediana)<5.0) varg.push_back(s);
        else
            kiet.push_back(s);
        }

}
