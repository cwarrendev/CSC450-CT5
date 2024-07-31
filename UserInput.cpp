#include <iostream> // For cout, cin, cerr
#include <fstream> // For file handling
#include <string> // For string
#include <algorithm> // For reverse

using namespace std; // Using standard namespace

// Function to reverse the contents of a file and write to another file
void reverseFileContents(const string &inputFileName, const string &outputFileName) {
    ifstream inputFile(inputFileName, ios::in);
    if (!inputFile.is_open()) {
        // If file does not exist, return
        cerr << "Error opening input file: " << inputFileName << endl;
        return;
    }

    // Read the contents of the file
    string content((istreambuf_iterator<char>(inputFile)), istreambuf_iterator<char>());
    inputFile.close(); // Close the input file

    // Reverse the content
    reverse(content.begin(), content.end()); // Reverse by swapping characters

    // Open the output file and write the reversed content
    ofstream outputFile(outputFileName, ios::out);
    if (!outputFile.is_open()) {
        cerr << "Error opening output file: " << outputFileName << endl;
        return;
    }

    // Write the reversed content to the output file
    outputFile << content;
    outputFile.close(); // Close the output file
}

int main() {
    // File names
    const string inputFileName = "/mnt/data/CSC450_CT5_mod5.txt";
    const string outputFileName = "/mnt/data/CSC450-mod5-reverse.txt";

    // Obtain input from user and append to the file
    string userInput;
    cout << "Enter text to append to the file: ";
    getline(cin, userInput); // Get the input from the user

    // Append the user input to the file
    ofstream outFile(inputFileName, ios::app);
    if (!outFile.is_open()) {
        cerr << "Error opening file: " << inputFileName << endl;
        return 1;
    }
    outFile << userInput << endl;
    outFile.close();

    // Reverse the contents of the file and store in another file
    reverseFileContents(inputFileName, outputFileName);

    // Output the message
    cout << "Data has been appended to " << inputFileName << " and reversed content has been stored in " << outputFileName << endl;

    return 0; // Return 0 to indicate successful completion
}
