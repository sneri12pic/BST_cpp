/*
    Author: Stepan Demianenko 
    Last edit data: 30/04/2023

    The purpose of this program is to perform textual substitution using constants defined in the input file, and output the modified text to a file.

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "BST.h"

using namespace std;

int main(int argc, char* argv[])
{

    // Try to open the input file
    string input_file_name = argv[1];
    ifstream input_file(input_file_name);

    // Check that the input file was opened successfully
    if (!input_file) {
        cout << "Error: Could not open input file " << input_file_name << endl;
        return 1;
    }

    cout << "Input file opened successfully." << endl;

    // Create the output file name based on the input file name
    string output_file_name = input_file_name;
    output_file_name.pop_back();
    output_file_name.push_back('o');
    ofstream output_file(output_file_name);

    // Check that the output file was opened successfully
    if (!output_file) {
        cout << "Error: Could not open output file " << output_file_name << endl;
        return 1;
    }

    cout << "Output file opened successfully." << endl;

    // Create a BST object to store constants
    BST tree;

    // Loop through each line of the input file
    string token;
    string line;
    string name;
    string value;
    bool flag = false;

    while (getline(input_file, line))
    {
        stringstream stream(line);

        // Loop through each token in the line
        while (stream >> token)
        {
            if (token == "#define")
            {
                stream >> name;
                stream >> value;

                // Insert the constant into the BST
                tree.insert_constant(name, value);

                // Set flag to true to skip adding this line to the output file
                flag = true;
                break;
            }

            // Replace the token with its value if it is a constant
            value = tree.get_value(token);
            if (value != "")
            {
                output_file << value << ' ';
                continue;
            }

            // Write the original token to the output file if it is not a constant
            output_file << token << ' ';
        }

        // Skip writing the line to the output file if it contained a constant definition
        if (flag)
        {
            flag = false;
            continue;
        }

        // Write a newline character to the output file
        output_file << '\n'; 
    }

    // Close the input and output files
    input_file.close();
    output_file.close();

    return 0;
}
