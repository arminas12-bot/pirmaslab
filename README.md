# PAGRINDINIAI NAUDOJIMOSI ŽINGSNIAI
1. Paleidę programą vartotojai pasirenka, ar nori dirbti su list, ar su vector tipo konteineriu.
   
<img width="813" height="25" alt="image" src="https://github.com/user-attachments/assets/5cac5314-474a-4a72-9f5a-2814bdb96c52" />

2. Tuomet naudotojas turi teisę pasirinkti, ar duomenis nori nuskaityti is failo, ar vesti ranka pats, o galbūt generuoti atsitiktinius pažymius su įvairiais kiekiais įrašų.
   
<img width="1092" height="50" alt="image" src="https://github.com/user-attachments/assets/ee30582c-6144-4ad4-9b0d-713b2447ea40" />

3. Tuomet atlikęs pasirinkimą, turi nuspręsti, kokį atlikti rūšiavimą. Galimi trys pasirinkimo variantai.
   
<img width="812" height="26" alt="image" src="https://github.com/user-attachments/assets/a10db75a-ab5d-4171-93d5-126c0eecfa98" />

4. Tuomet yra apskaičiuojamas ir išvedamas laikas (kiek užtruko rūšiavimas). Tada vartotojas renkasi - ar skaičiuoti vidurkį, ar medianą, ar abu.
   
<img width="1032" height="41" alt="image" src="https://github.com/user-attachments/assets/1131a2b3-a95c-44cc-8790-1665e8790bd7" />

5. Tada vartotojui yra išvedamas rezultatų įrašymo į failą laikas bei liepiama pasirinkti norimą strategiją iš trijų variantų.
   
<img width="855" height="112" alt="image" src="https://github.com/user-attachments/assets/4bce0811-1908-4b2c-993d-62b6a6c60a13" />

6. Galiausiai informuojama apie pasirinktos strategijos ir konteinerio (list arba vector) studentų skaidymo į du naujus kont. trukmę bei pranešama, kiek užtruko surūšiuotų studentų išvedimas.
    
<img width="611" height="49" alt="image" src="https://github.com/user-attachments/assets/6e63b56d-2ccc-44e0-b6bb-842c3d627cf5" />

7. Programa baigiama, o visi rezultatai išsaugomi keliuose rezultatų failuose.
 


## V0.1 + V.0.2 versijos trumpas aprašymas.

Nuo šiol programa veikia ne vien tik V0.1 principu, bet ir V0.2, todėl papildomai gali:

-generuoti atsitiktinius studentų sąrašų failus su skirtingais įrašų kiekiais;

-rūšiuoti studentus į kategorijas pagal galutinį įvertinimą;

-apskaičiuoti ir išvesti, per kiek laiko sukuriamas failas, per kiek laiko nuskaitomi duomenys iš tam tikrų failų, taip pat apskaičiuojamas rūšiavimo veikimo greitis.

Pavyzdys: -1000 įrašų – failas sukuriamas per 2 ms, paskutinį kartą nuskaitytas per 3 ms. Failo sugeneravimo vidurkis - 2,2 ms.

-10000 įrašų – failas sukuriamas per 22 ms, paskutinį kartą nuskaitytas per 31 ms. Failo sugeneravimo vidurkis - 27,2 ms.

-100000 įrašų – failas sukuriamas per 226 ms, paskutinį kartą nuskaitytas per 339 ms. Failo sugeneravimo vidurkis - 277,4 ms.

-1000000 įrašų – failas sukuriamas per 1127 ms, paskutinį kartą nuskaitytas per 1690 ms. Failo sugeneravimo vidurkis - 1643 ms.

-10000000 įrašų – failas sukuriamas per 8964 ms, paskutinį kartą nuskaitytas per 13441 ms. Failo sugeneravimo vidurkis - 13487,8 ms.

Tikslas - sukurti programą, kuri gebėtų ne tik leisti naudotojui įvesti duomenis, bet ir nuskaitytų duomenis iš pateiktų failų.

Ši programa sukurta taip, kad galėtų:

-įvesti norimus studentų duomenis, t.y. vardą, pavardę, gautus pažymius bei egzamino įvertinimą;

-skaityti failus, kur namų darbų vertinimų arba studentų skaičius skirtingas;

-nuskaityti studentų sąrašus iš įvairaus tipo .txt formatų;

-pranešti apie naudotoją padarytą kokią nors (pvz.: loginę) klaidą;

-leisti naudotojui vesti pažymius pačiam arba generuoti automatiškai;

-skaičiuoti ne tik studentų vidurkius, bet ir rasti įvertinimų medianas;

-sortinti studentus ir pagal vardus, ir pagal pavardes, ir pagal vidurkius (naudotojo teisė rinktis);

-išvesti visų studentų bendrąjį kurso vidurkį, parodyti, kiek studentų kursą išlaikė (bendras įvertinimas >=4.5), o kiek neišlaikė (bendras įvertinimas <4.5);

-rezultatus atvaizduoti paprastoje, suformatuotoje, naudotojui suprantamoje lentelėje.


## ***V0.3 ATNAUJINIMAS:***
- Pridėta galimybė naudotojui pasirinkti, ar dirbti su vector, ar su list tipo konteineriu.
- Atliekama programos spartos analizė. Nuo šiol programa matuoja studentų rūšiavimo į dvi grupes laiką, pasirinkto studentų rikiavimo laiką bei įrašymo į rezultatų failą trukmę.

- Buvo atliekamas patikrinimas (testavimas) su 2 tipų konteineriais: vector, list. Testavimas atliktas su kompiuteriu, kurio parametrai: CPU - 2.8GHz, RAM - 24GB, SSD - 223GB. Gauti rezultatai pateikiami žemiau lentelėse:


I) **Studentų rikiavimas (pagal vardus)**
| Įrašų kiekis | Vector | List |
|:--------------|:----------:|-------:|
| 1000 |0.0004 s| 0.0001 s|
| 10000 |0.0039 s|0.001 s|
| 100000 |0.0375 s|0.0127 s|
| 1000000 | 0.453 s|0.1881 s|
| 10000000 |5.4857 s|2.2341 s|

**Studentų rikiavimo (pagal vardus) vidutinis laikas (testas atliktas 5 kartus), dirbant su 1000000 įrašų failu: vector - 0.431 s, list - 0.193 s.**

II) **Duomenų įrašymas į rezultatų failą**
| Įrašų kiekis | Vector | List |
|:--------------|:----------:|-------:|
| 1000 |0.0062 s|0.0736 s|
| 10000 | 0.0491 s| 0.049 s|
| 100000 |0.4679 s| 0.4685 s|
| 1000000 |4.7254 s| 4.8847 s|
| 10000000 |46.7826 s|46.2365 s|

**Studentų duomenų įrašymo į rezultatų failą vidutinis laikas (testas atliktas 5 kartus), dirbant su 1000000 įrašų failu: vector - 4.712 s, list - 4.8985 s.**

III) **Studentų rūšiavimas į grupes pagal įvertinimus**
| Įrašų kiekis | Vector | List |
|:--------------|:----------:|-------:|
| 1000 | 0.0004 s| 0.0003 s|
| 10000 |0.0034 s|0.0027 s|
| 100000 | 0.0295 s|0.0248 s|
| 1000000 | 0.2895 s|0.2594 s|
| 10000000 |3.1769 s|2.5181 s|

**Studentų rūšiavimo į grupes (pagal įvertinimus) vidutinis laikas (testas atliktas 5 kartus), dirbant su 1000000 įrašų failu: vector - 0.2911 s, list - 0.26 s.**


IŠVADA: Rezultatai pateikiami lentelėse yra nurodyti sekundėmis. Galima pastebėti, jog rikiavimas greičiau buvo atliekamas dirbant su list tipo konteineriu, duomenų įrašymas į rezultatų failą didelio laiko skirtumo nedaro, o studentų rūšiavimas į dvi grupes (vargšiukus ir kietekus) buvo greitesnis dirbant su list. Taigi, testavimas parodo, jog bendru atveju, dirbant su vector, darbas trunka ilgiau.


## **V1.0 GALUTINĖ VERSIJA**

Nuo šiol programa gali įgyvendinti 3 skirtingas strategijas (priklausomai nuo vartotojo pasirinkimo).
Pasirinkus pirmą - studentų skaidymui yra naudojami du konteineriai (vargšiukai ir kietiakai).
Pasirinkus antrą - studentų skaidymui yra panaudojamas tik vienas vargšiukų konteineris, o iš jo ištrinami studentai, kurie netenkina tam tikrų sąlygų.
Pasirinkus trečiąjį - studentu skaidymui yra naudojamas labiausiai optimizuotas (efektyvus) studentų rūšiavimas, todėl visas veikimo principas yra labai greitas.

***STUDENTŲ SKAIDYMAS PAGAL STRATEGIJAS***

Buvo atliekamas kiekvienos strategijos tyrimas. Kiekviena strategija su vector arba list tipo konteineriu buvo ištestuota tris kartus. Žemiau esančiose lentelėse yra pateikiami gauti rezultatai.

**1 strategija**

| Įrašų kiekis | Vector | List |
|:--------------|:----------:|-------:|
| 1000 | 0.0002 s| 0.0003 s|
| 10000 |0.0015 s| 0.0024 s|
| 100000 |0.0124 s| 0.0194 s|
| 1000000 | 0.124 s| 0.1889 s|
| 10000000 |1.2913 s|1.9058 s|

1000000 įrašų vidurkis (atliekant testavimą 10 kartų) vector konteineryje 0.122 s, list - 1.91 s.

**2 strategija**

| Įrašų kiekis | Vector | List |
|:--------------|:----------:|-------:|
| 1000 |0.0002 s| 0.0001 s|
| 10000 |0.002 s| 0.0014 s|
| 100000 | 0.0145 s|0.0152 s|
| 1000000 |0.1383 s|0.1626 s|
| 10000000 |1.4815 s| 1.6431 s|

1000000 įrašų vidurkis (atliekant testavimą 10 kartų) vector konteineryje 0.141 s, list - 0.1697 s.

**3 strategija**

| Įrašų kiekis | Vector | List |
|:--------------|:----------:|-------:|
| 1000 | 0.0001 s|0.0001 s|
| 10000 | 0.0006 s| 0.0001 s|
| 100000 |0.0047 s|0.004 s|
| 1000000 |0.0472 s| 0.0251 s|
| 10000000 |0.5178 s|0.2609 s|

1000000 įrašų vidurkis (atliekant testavimą 10 kartų) vector konteineryje 0.0455 s, list - 0.029 s.

Išvada: naudojant pirmos strategijos skaidymą list konteineris buvo apytiksliai 1.5 karto lėtesnis nei vector; naudojant antros strategijos rūšiavimą pranašesnis buvo taip pat vector konteineris, tačiau labai nežymiai - apie 15% kiekvienu atveju; naudojant trečios strategijos skaidymą rezultatai pasikeitė - buvo taikomi nauji algoritmai, kurie gerokai pagreitino procesą ir pranašumą įgijo list konteineris, kuris vidutiniškai buvo greitesnis du kartus nei vector.
