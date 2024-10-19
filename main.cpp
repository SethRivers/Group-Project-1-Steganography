/**
 * @file main.cpp
 * @author Script Sages
 * @date 2024-10-17
 * @brief Main driver for the Steganography application.
 *
 * This program allows users to encode a hidden message into a PPM image
 * or decode a hidden message from a PPM image.
 */

#include <iostream>
#include "Steganography.h"

using namespace std;

int main() {
  Steganography stego; // Creates an object to handle hiding or finding messages.
    int choice;

    // Print options for the user.
    cout << "======Script Sages Steganography Application: Open======\n";
    cout << ">Good Morning/Afternoon/Evening! With this simple program, you will be able to: \n"; 
    cout << "1. Encode a message into an image\n";
    cout << "2. Decode a message from an image\n";
    cout << ">Please select which you would like to do, now (1 or 2): "; 
    cin >> choice; // Gets the user's choice (1 or 2).
    cin.ignore(); // Clear newline character from the input buffer.

    // If the user chooses to hide a message (option 1).
    if (choice == 1) {
        string inputImage, inputText, outputImage;
        cout << ">Please enter the PPM image file name to encode into: ";
        getline(cin, inputImage); // Gets the name of the picture file.
	stego.readImage(inputImage); // Reads the image file
	
        cout << ">Please enter the text file name containing the message: ";
        getline(cin, inputText); // Gets the name of the text file.
	stego.readCipherText(inputText); // Reads the image file. 
	
	cout << ">Please enter the output PPM file name for the encoded image (Do not include '.ppm' in the name, as the code will do it for you): ";
        getline(cin, outputImage); // Gets the name for the new picture.
	outputImage += ".ppm"; // adds the ppm to the end of your filename. 
        // Encipher the message.
	stego.encipher();

        // Print the encoded image to a file.
        stego.printImage(outputImage);
        cout << ">Your message was encoded, and image was saved to: " << outputImage << endl;

	// If the user chooses to find a hidden message (option 2).
    } else if (choice == 2) {
        string inputImage, outputText;
        cout << ">Please enter the encoded PPM image file name: ";
        getline(cin, inputImage); // Gets the name of the picture file.
	
        stego.readImage(inputImage); // Reads the encoded image. 
        stego.decipher(); // Decipher the message.
	
        cout << ">Please enter the output text file name to save the decoded message (Do not include '.txt' in the name, as the code will do it for you): ";
        getline(cin, outputText); // Gets the name for the new text file.
	outputText += ".txt"; // Adds the .txt to the end of your filename. 
	
        stego.printCipherText(outputText);// Print the cipher text to a file. 
        cout << ">Your message decoded and saved to: " << outputText << endl;

    } else { // If the user doesn't choose 1 or 2, print an error message.
        cout << "[Invalid selection! Please enter 1 or 2]" << endl;
    }

    return 0; // End of the program.
}

