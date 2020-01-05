#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int stateDiagram[9][2] =
    {
        //0b876543210, 0b876543210
        {0b000010010, 0b000110111},     // State 0*
        {0b000000010, 0b000010111},     // State 1*
        {0b000011010, 0b000100111},     // State 2*
        {0b000010111, 0b000001000},     // State 3*
        {0b000010000, 0b000100000},     // State 4*
        {0b001010011, 0b010000000},     // State 5*
        {0b100010010, 0b000110111},     // State 6*
        {0b000100000, 0b001010011},     // State 7*
        {0b010000000, 0b100000000}      // State 8*
    };

    int startStates = 0b000010011;
    int acceptingStates = 0b001000100;
    string inputString = "not empty";
    int currentStates, nextStates;

    while (inputString.length() != 0)
    {
        cout << "Enter a binary string: ";
        getline(cin, inputString);

        currentStates = startStates;
        for (unsigned int i = 0; i < inputString.length(); i++)
        {
            nextStates = 0;
            if (inputString.at(i) == '0')
            {
                for (int stateCounter = 0; currentStates != 0; stateCounter++, currentStates = currentStates >> 1)
                {
                    if ((currentStates & 1) == 1)
                    {
                        nextStates = nextStates | stateDiagram[stateCounter][0];
                    }
                }
            }
            else if (inputString.at(i) == '1')
            {
                for (int stateCounter = 0; currentStates != 0; stateCounter++, currentStates = currentStates >> 1)
                {
                    if ((currentStates & 1) == 1)
                    {
                        nextStates = nextStates | stateDiagram[stateCounter][1];
                    }
                }
            }
            currentStates = nextStates;
        }
        if ((currentStates & acceptingStates) == 0)
        {
            cout << "The string was rejected." << endl;
        }
        else
        {
            cout << "The string was accepted." << endl;
        }
    }

    return 0;
}
