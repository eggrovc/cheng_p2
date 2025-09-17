#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;


class Cheng_p2{

    public: 


        void setStates(const string& arg1, const string& arg2);
        void execute(const string& arg2);



    private:

        // Each gate direction, true = left, false = right
        vector<bool> states;
        // vector<char> output;
        char lastLetter;
        int inputs;

};

void Cheng_p2::setStates(const string& arg1, const string& argv2) {
    for (char ch : arg1) {
        if (ch == 'L') {
            states.push_back(true);

        } else if (ch == 'R') {
            states.push_back(false);
        }
    }

    for ([[maybe_unused]] char num : argv2) {
        this->inputs++;
    }
}


// arg1 = gate direction arg2 = input string
void Cheng_p2::execute(const string& arg2) {
    for (int l = 0; l < (int)states.size(); l++) {
        if (states[l] == true) {
            cout << "L";
        }

        if (states[l] == false) {
            cout << "R";
        }
    }

    cout << "->";
    int counter = 0; 

    
    for (char ch : arg2) {
        // A(0): 2 4 5 (1, 3, 4)
        if (ch == '1') {
            if (states[1]) {
                switch(states[3]) {
                    case true:
                        lastLetter = 'D';
                        states[3] = false;
                        break;
                    case false:
                        lastLetter = 'E';
                        states[3] = true;
                        break;
                }
                states[1] = false;
            } else {
                switch(states[4]) {
                    case true:
                        lastLetter = 'E';
                        states[4] = false;
                        break;
                    case false:
                        lastLetter = 'F';
                        states[4] = true;
                        break;

                }
                states[1] = true;
            }  
        }

        // B(1): 1 3 4 (0, 2, 3)
        if (ch == '0') {
            if (states[0]) {
                switch(states[2]) {
                    case true:
                        lastLetter = 'C';
                        states[2] = false;
                        break;
                    case false:
                        lastLetter = 'D';
                        states[2] = true;
                        break;
                }
                states[0] = false;
            } else {
                switch(states[3]) {
                    case true:
                        lastLetter = 'D';
                        states[3] = false;
                        break;
                    case false:
                        lastLetter = 'E';
                        states[3] = true;
                        break;
                }
                states[0] = true;
            }
        }
    
        for (int l = 0; l < (int)states.size(); l++) {
            if (states[l] == true) {
                cout << "L";
            }

            if (states[l] == false) {
                cout << "R";
            }
        }
        
        if (counter < this->inputs - 1) {
            cout << "->";
            counter++;
        }
    }

    cout << " " << lastLetter << endl;
}


int main(int argc, char* argv[]) {

    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }

    Cheng_p2 dfa;

    dfa.setStates(argv[1], argv[2]);

    dfa.execute(argv[2]);

    return 0;
}

