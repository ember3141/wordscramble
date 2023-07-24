#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<string> getPermutations(const string& arr) {
    if (arr.length() == 1) {
        return {arr};
    }

    vector<string> result;

    for (size_t i = 0; i < arr.length(); i++) {
        char currentElement = arr[i];
        string remainingElements = arr.substr(0, i) + arr.substr(i + 1);
        vector<string> permutationsOfRemaining = getPermutations(remainingElements);

        for (const string& perm : permutationsOfRemaining) {
            result.push_back(currentElement + perm);
        }
    }

    return result;
}

vector<string> getOrderedCombinations(const string& arr) {
    vector<string> permutations = getPermutations(arr);
    vector<string> orderedCombinations;

    for (const string& perm : permutations) {
        if (perm.length() == arr.length()) {
            orderedCombinations.push_back(perm);
        }
    }

    return orderedCombinations;
}

void printOutput(const vector<string>& combinations, bool saveToFile, const string& filename) {
    if (saveToFile) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const string& combination : combinations) {
                outFile << combination << endl;
            }
            outFile.close();
            cout << "Output saved to " << filename << endl;
        } else {
            cout << "Error: Unable to open file." << endl;
        }
    } else {
        for (const string& combination : combinations) {
            cout << combination << endl;
        }
    }
}

int main() {
    string userInput;
    cout << "Enter a string: ";
    cin >> userInput;

    vector<string> out = getOrderedCombinations(userInput);

    cout << "Do you want to save the output to a text file? (1 for yes, 0 for no): ";
    bool saveToFile;
    cin >> saveToFile;

    if (saveToFile) {
        string filename;
        cout << "Enter the filename to save the output: ";
        cin >> filename;
        printOutput(out, true, filename);
    } else {
        printOutput(out, false, "");
    }

    cout << "Number of combinations: " << out.size() << endl;

    return 0;
}
