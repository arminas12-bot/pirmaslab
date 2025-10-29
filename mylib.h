#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <cctype>
#include <chrono>
#include <list>


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
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;
using std::list;


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
void generuojafailus();
void generuotifaila(string genfail, int iraskiekis);

bool sortinamVardus(Studentas& pirmvard, Studentas& antrvard);
bool sortinamPavardes(Studentas& pirmpavard, Studentas& antrpavard);
bool sortinam_balus_didz(Studentas& pirmbalas, Studentas& antrbalas);
