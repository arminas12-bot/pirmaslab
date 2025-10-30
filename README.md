Pirmasis lab. darbas (INFORMACIJA ATNAUJINTA PO V0.3 IŠLEIDIMO)

V0.2 versijos trumpas aprašymas.

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


***V0.3 ATNAUJINIMAS:***
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

II) **Duomenų įrašymas į rezultatų failą**
| Įrašų kiekis | Vector | List |
|:--------------|:----------:|-------:|
| 1000 |0.0062 s|0.0736 s|
| 10000 | 0.0491 s| 0.049 s|
| 100000 |0.4679 s| 0.4685 s|
| 1000000 |4.7254 s| 4.8847 s|
| 10000000 |46.7826 s|46.2365 s|

III) **Studentų rūšiavimas į grupes pagal įvertinimus**
| Įrašų kiekis | Vector | List |
|:--------------|:----------:|-------:|
| 1000 | 0.0004 s| 0.0003 s|
| 10000 |0.0034 s|0.0027 s|
| 100000 | 0.0295 s|0.0248 s|
| 1000000 | 0.2895 s|0.2594 s|
| 10000000 |3.1769 s|2.5181 s|

IŠVADA: Rezultatai pateikiami lentelėse yra nurodyti sekundėmis. Galima pastebėti, jog rikiavimas greičiau buvo atliekamas dirbant su list tipo konteineriu, duomenų įrašymas į rezultatų failą didelio laiko skirtumo nedaro, o studentų rūšiavimas į dvi grupes (vargšiukus ir kietekus) buvo greitesnis dirbant su list. Taigi, testavimas parodo, jog bendru atveju, dirbant su vector, darbas trunka ilgiau.
