//  Created by Liza Prokudina & Victoria Kudryavtseva on 23.11.2020.
//
//System: MacOS
//IDE: XCode 12.2
//
//Set as a Array Of Bits!!!!!!!!

#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <cstdlib>
#include <array>
#include <algorithm>
#include <chrono>


using namespace std;

class Timer
{
private:
    
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


const char U[] = {"abcdefghijklmnopqrstuvwxyz"};
int uSize = sizeof(U) / sizeof(U[0]);

bitset<26> arrayToBit (vector <char> array, int arraySize) {
    bitset<26> bitsArray;
    for (int i = 0; i < arraySize; i++) {
        for (int j = 0; j < uSize; j++) {
            if (array[i] == U[j]) {
                bitsArray.set(j);
                break;
            }
        }
    }
    return bitsArray;
}

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

vector<char> generateSet() {
    int sizeGeneratedSet = getRandomNumber(5, 20);
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
    cout << "Insert A" << endl;
    cin >> inputArray;
    vector <char> finalVector (inputArray, inputArray + size);
    return finalVector;
}



int main() {
    
    srand (time(NULL));
    
    vector<char> A;
    vector<char> B;
    vector<char> C;
    vector<char> D;
    
    cout << "1 - Demo set" << endl;
    cout << "2 - Generate set" << endl;
    cout << "3 - Insert set" << endl;
    
    int choice;
    cin >> choice;
    
    switch(choice)
    {
        case 1:
            A = {'a', 'b', 'c', 'd', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's'};
            B = {'a', 'e', 'c', 'd', 'f', 'g', 'h', 'i', 'j', 'k', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w'};
            C = {'a', 'e', 'c', 'd', 'f', 'g', 'h', 'i', 'j', 'k', 'p', 'q', 'r', 's', 't', 'u', 'w', 'z'};
            D = {'a', 'e', 'c', 'd', 'g', 'h', 'i', 'j', 'k', 'p', 'q', 'r', 's', 't', 'u', 'w', 'z'};
            
            cout << "Set A: ";
            showVector(A, static_cast<int>(A.size()));
            
            cout << "Set B: ";
            showVector(B, static_cast<int>(B.size()));
            
            cout << "Set C: ";
            showVector(C, static_cast<int>(C.size()));
            
            cout << "Set D: ";
            showVector(D, static_cast<int>(D.size()));
            
            break;
            
        case 2:
            A = generateSet();
            B = generateSet();
            C = generateSet();
            D = generateSet();
            
            cout << "Set A: ";
            showVector(A, static_cast<int>(A.size()));
            
            cout << "Set B: ";
            showVector(B, static_cast<int>(B.size()));
            
            cout << "Set C: ";
            showVector(C, static_cast<int>(C.size()));
            
            cout << "Set D: ";
            showVector(D, static_cast<int>(D.size()));
            
        
            break;
            
        case 3:
            
            A = insertSet('A');
            B = insertSet('B');
            C = insertSet('C');
            D = insertSet('D');
            
            break;
            
        default:
            cout<<"Такого пункта не существует, повторите ввод!"<<endl;
    }
   
    
    
    int sizeA = static_cast<int>(A.size());
    int sizeB = static_cast<int>(B.size());
    int sizeC = static_cast<int>(C.size());
    int sizeD = static_cast<int>(D.size());
    
    Timer t;
    
    bitset<26> bitsB = arrayToBit(B, sizeB);
    bitset<26> bitsC = arrayToBit(C, sizeC);
    bitset<26> bitsD = arrayToBit(D, sizeD);
    
    cout << bitsB << " bits B" << endl;
    cout << bitsC << " bits C" << endl;
    cout << bitsD << " bits D" << endl;
    
 
    bitset<26> bitsBCD = bitsB | bitsC | bitsD;
    
    bitsBCD = ~bitsBCD;

    vector <char> E;
    
    for (int i = 0; i < sizeA; i++) {
        bitset<26> bitsA;
        for (int j = 0; j < uSize; j++) {
            if (A[i] == U[j]) {
                bitsA.set(j);
                bitsA &= bitsBCD;
                for (int k = 0; k < uSize; k++) {
                    if (bitsA[k] == 1) {
                        E.push_back(U[k]);
                        break;
                    }
                }
                break;
            }
        }
    }
    
    if (E.empty()) {
        cout << "E is empty!" << endl;
    } else {
        
        cout << "Result set E: ";
        for(int i = 0; i < E.size(); i++)
        {
            cout << E[i];
            
        }
    }
    cout << endl;
    cout << "Time taken: " << t.elapsed() << endl;
    return 0;
}
