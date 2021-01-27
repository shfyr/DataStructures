//  Created by Liza Prokudina & Victoria Kudryavtseva on 23.11.2020.
//
//System: MacOS
//IDE: XCode 12.2
//
//Set as an ARRAY !!!!!!!!

#include <iostream>
#include <locale.h>
#include <iterator>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;


    const char U[] = {"abcdefghijklmnopqrstuvwxyz"};
    int uSize = sizeof(U) / sizeof(U[0]);

class Timer
{
private:
    // Псевдонимы типов используются для удобного доступа к вложенным типам
    using clock_t = chrono::high_resolution_clock;
    using second_t = chrono::duration<double, std::ratio<1> >;
    
    chrono::time_point<clock_t> m_beg;
    
public:
    Timer() : m_beg(clock_t::now())
    {
    }
    
    void reset()
    {
        m_beg = clock_t::now();
    }
    
    double elapsed() const
    {
        return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};


int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

vector<char> generateSet() {
    int sizeGeneratedSet = getRandomNumber(0, 10);
    vector <char> generatedSet;
    
    for (int i = 0; i < sizeGeneratedSet; i++) {
        int r = rand() % 26;
        char c = 'a' + r;
        if(find(generatedSet.begin(), generatedSet.end(), c) != generatedSet.end()) {
            i--;
            
        } else {
            generatedSet.push_back(c);
        }
        
    }
    return generatedSet;
}


void showVector (vector<char> vector, int size) {
    
    for(int i = 0; i < vector.size(); i++)
    {
        cout << vector[i];
        
    }
    cout << endl;
}

vector<char> insertSet (char setName) {
    int size;
    cout << "Size of " << setName << endl;
    cin >> size;
    char *inputArray = new char[size];
    cout << "Insert " << setName << endl;
    cin >> inputArray;
    vector <char> finalVector (inputArray, inputArray + size);
    return finalVector;
}

void fillArrayWithZeros (char array[26]) {
    for (int i = 0; i < 26; i++) {
        array[i] = '0';
    }
}

int main () {
    
    srand (time(NULL));
    
    vector<char> Av;
    vector<char> Bv;
    vector<char> Cv;
    vector<char> Dv;
    
    cout << "1 - Demo set" << endl;
    cout << "2 - Generate set" << endl;
    cout << "3 - Insert set" << endl;
    
    int choice;
    cin >> choice;
    
    switch(choice)
    {
        case 1:
            Av = {'a', 'b', 'c', 'd', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's'};
            Bv = {'a', 'e', 'c', 'd', 'f', 'g', 'h', 'i', 'j', 'k', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w'};
            Cv = {'a', 'e', 'c', 'd', 'f', 'g', 'h', 'i', 'j', 'k', 'p', 'q', 'r', 's', 't', 'u', 'w', 'z'};
            Dv = {'a', 'e', 'c', 'd', 'f', 'g', 'h', 'i', 'j', 'k', 'p', 'q', 'r', 's', 't', 'u', 'w', 'z'};

            
            cout << "Set A: ";
            showVector(Av, static_cast<int>(Av.size()));
            
            cout << "Set B: ";
            showVector(Bv, static_cast<int>(Bv.size()));
            
            cout << "Set C: ";
            showVector(Cv, static_cast<int>(Cv.size()));
            
            cout << "Set D: ";
            showVector(Dv, static_cast<int>(Dv.size()));
            
            break;
            
        case 2:
            Av = generateSet();
            Bv = generateSet();
            Cv = generateSet();
            Dv = generateSet();
            
            cout << "Set A: ";
            showVector(Av, static_cast<int>(Av.size()));
            
            cout << "Set B: ";
            showVector(Bv, static_cast<int>(Bv.size()));
            
            cout << "Set C: ";
            showVector(Cv, static_cast<int>(Cv.size()));
            
            cout << "Set D: ";
            showVector(Dv, static_cast<int>(Dv.size()));
            
            
            break;
            
        case 3:
            
            Av = insertSet('A');
            Bv= insertSet('B');
            Cv = insertSet('C');
            Dv = insertSet('D');
            
            break;
            
        default:
            cout<<"There is no such option!"<<endl;
    }
    
    char A[26];
    char B[26];
    char C[26];
    char D[26];
    
    fillArrayWithZeros(A);
    fillArrayWithZeros(B);
    fillArrayWithZeros(C);
    fillArrayWithZeros(D);
        
    copy(Av.begin(), Av.end(), A);
    copy(Bv.begin(), Bv.end(), B);
    copy(Cv.begin(), Cv.end(), C);
    copy(Dv.begin(), Dv.end(), D);
    
        int sizeA = 26;
        int sizeC = 26;
        int sizeD = 26;
        int sizeB = 26;
    
    Timer t;
    
    int temp = sizeB + sizeC + sizeD;
    
    char *TEMP = new char [temp];
    
    for (int i = 0; i < temp; i++){
        if (i < sizeB){
            TEMP[i] = B[i];
            
        } else {
            if (i < (sizeB + sizeC)){
                TEMP[i] = C[i - sizeB];
            } else {
                TEMP[i] = D[i - sizeB - sizeC];
            }
        }
    }
    


    for (int i = 0; i < temp; i++) {
        bool exist = find(A, A + sizeA, TEMP[i]) != A + sizeA;
        
        if (!exist) {

            TEMP[i] = '0';
            
        }
    }
    
    for (int i = 0; i < sizeA; i++) {
        for (int j = 0; j < temp; j++) {
            if (TEMP[j] != '0') {
            if (A[i] == TEMP[j]) {
                A[i] = '0';
                break;
            }
            }
        
        }
    }
    

    cout << "Set E: ";
    
    int emptyCounter = 0;
    
    for (int i = 0; i < 26; i++) {
        if (A[i] != '0') {
            cout << A[i];
            emptyCounter++;
        }
    }
    if (emptyCounter == 0) {
        cout << "is empty";
    }
    cout << endl;
    
    cout << "Time taken: " << t.elapsed() << endl;
    return 0;
}

