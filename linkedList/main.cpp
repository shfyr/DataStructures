//  Created by Liza Prokudina & Victoria Kudryavtseva on 23.11.2020.
//
//System: MacOS
//IDE: XCode 12.2
//Set as a Liner List !!!!!!!!

#include <iostream>
#include <locale.h>
#include <iterator>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;

struct Node {
    char data;
    Node* next;
};


// Function to insert node
void insert(Node** root, char item)
{
    Node* temp = new Node;
    Node* ptr;
    temp->data = item;
    temp->next = NULL;
    
    if (*root == NULL)
        *root = temp;
    else {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void display(Node* root)
{
    while (root != NULL) {
        cout << root->data << " ";
        root = root->next;
    }
}

int getCount(Node* head)
{
    int count = 0; // Initialize count
    Node* current = head; // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void insertList(struct Node* head1, struct Node* head2)
{
    
    struct Node* curr = head1;
    
    int amountOfNodes = getCount(head1);
    int count = 1;
    
    while (count < amountOfNodes) {
        curr = curr->next;
        count++;
    };
    
    
    // backup next node of the k-th point
    struct Node* temp = curr->next;
    
    // join second linked list at the kth point
    curr->next = head2;
    
    // traverse the second linked list till end
    while (head2->next != NULL)
        head2 = head2->next;
    
    // join the second part of the linked list
    // to the end
    head2->next = temp;
}


Node *vectorToList(vector <char> arr, size_t n)
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    insert(&root, arr[i]);
    return root;
}

void deleteNode(struct Node **head_ref, size_t position)
{

    if (*head_ref == NULL)
        return;
 
    struct Node* temp = *head_ref;
    
    if (position == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    
    for (int i=0; temp!=NULL && i<position-1; i++)
    temp = temp->next;
    
    if (temp == NULL || temp->next == NULL)
        return;

    struct Node *next = temp->next->next;

    free(temp->next);
    
    temp->next = next;
}



bool search(Node* head, char x)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

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


int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

vector<char> generateSet() {
    int sizeGeneratedSet = getRandomNumber(3, 10);
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
    cout << "Insert "<< setName << endl;
    cin >> inputArray;
    vector <char> finalVector (inputArray, inputArray + size);
    return finalVector;
}


int main () {
    
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
            A = {'b', 'c', 'd', 'e', 'f', 'g', 'z', 'y', 'x'};
            B = {'a', 'b'};
            C = {'c', 'd', 'e'};
            D = {'z'};
            
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
            cout<<"There is no such option!"<<endl;
    }
        
    int sizeA = static_cast<int>(A.size());
    int sizeB = static_cast<int>(B.size());
    int sizeC = static_cast<int>(C.size());
    int sizeD = static_cast<int>(D.size());
    
    
        Node* listA = vectorToList(A, sizeA);
        Node* listB = vectorToList(B, sizeB);
        Node* listC = vectorToList(C, sizeC);
        Node* listD = vectorToList(D, sizeD);
    
        insertList(listB, listC);
        insertList(listB, listD);
    
    Timer t;
    
    while (listB != NULL) {
        
        Node* current = listA;
        int counter = 0;
        vector <int> itemsToDel;
        
        while (current != NULL) /
        {
            
            if (current->data == listB->data) {
                
                itemsToDel.push_back(counter);
            }
            
            current = current->next;
            counter++;
        }
        
        int vectorSize = itemsToDel.size() - 1;
        
        for (int i = vectorSize;  i >= 0; i--) {
            deleteNode(&listA, itemsToDel[i]);
        }
        
        listB = listB->next;
        
    }
    
    if (listA  == NULL) {
        cout << "E is empty!" << endl;
    } else {
        
        cout << "Set E: ";
    display(listA);
        cout << endl;
    }
    
    cout << "Time taken: " << t.elapsed() << endl;
    return 0;
}


