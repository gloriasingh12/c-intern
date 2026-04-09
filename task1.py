/* =================================================================
PROJECT: C++ File Management Tool
DESCRIPTION: Demonstrating Read, Write, and Append using fstream.
DELIVERABLE: A C++ program showcasing modern file-handling techniques.
=================================================================
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileTool {
public:
    // 1. Function to WRITE to a file (Overwrites existing content)
    void writeFile(string filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << "Task 29: C++ File Management System" << endl;
            outFile << "Status: Initialized via ofstream." << endl;
            outFile.close();
            cout << "✅ Step 1: File created and written successfully." << endl;
        } else {
            cout << "❌ Error: Unable to open file for writing." << endl;
        }
    }

    // 2. Function to APPEND data (Adds to the end of the file)
    void appendFile(string filename) {
        ofstream outFile(filename, ios::app); // ios::app is the append flag
        if (outFile.is_open()) {
            outFile << "Append: Adding a new log entry in C++." << endl;
            outFile.close();
            cout << "✅ Step 2: Data appended successfully." << endl;
        } else {
            cout << "❌ Error: Unable to open file for appending." << endl;
        }
    }

    // 3. Function to READ data from the file
    void readFile(string filename) {
        string line;
        ifstream inFile(filename);
        if (inFile.is_open()) {
            cout << "\n--- 📄 READING FILE CONTENT (C++) ---" << endl;
            while (getline(inFile, line)) {
                cout << line << endl;
            }
            cout << "-------------------------------------" << endl;
            inFile.close();
            cout << "✅ Step 3: File read operation complete." << endl;
        } else {
            cout << "❌ Error: Unable to open file for reading." << endl;
        }
    }
};

int main() {
    FileTool tool;
    string myFile = "cpp_internship_log.txt";

    cout << "🚀 Starting C++ File Management Tool..." << endl;

    // Execution sequence
    tool.writeFile(myFile);
    tool.appendFile(myFile);
    tool.readFile(myFile);

    cout << "\n✅ Task 29 Complete: C++ fstream operations verified." << endl;

    return 0;
}
