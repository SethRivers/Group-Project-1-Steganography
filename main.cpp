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
    cout << "Steganography Application\n";
    cout << "1. Encode a message into an image\n";
    cout << "2. Decode a message from an image\n";
    cout << "Please enter your choice (1 or 2): ";
    cin >> choice; // Gets the user's choice (1 or 2).
    cin.ignore(); // Clear newline character from the input buffer.

    // If the user chooses to hide a message (option 1).
    if (choice == 1) {
        string inputImage, inputText, outputImage;
        cout << "Enter the PPM image file name to encode into: ";
        getline(cin, inputImage); // Gets the name of the picture file.
        cout << "Enter the text file name containing the message: ";
        getline(cin, inputText); // Gets the name of the text file.
        cout << "Enter the output PPM file name for the encoded image: ";
        getline(cin, outputImage); // Gets the name for the new picture.

        // Read image and cipher text.
        stego.readImage(inputImage);
        stego.readCipherText(inputText);

        // Encipher the message.
        stego.encipher();

        // Print the encoded image to a file.
        stego.printImage(outputImage);
        cout << "Message encoded and image saved to: " << outputImage << endl;

	// If the user chooses to find a hidden message (option 2).
    } else if (choice == 2) {
        string inputImage, outputText;
        cout << "Enter the encoded PPM image file name: ";
        getline(cin, inputImage); // Gets the name of the picture file.
        cout << "Enter the output text file name to save the decoded message: ";
        getline(cin, outputText); // Gets the name for the new text file.

        // Read the encoded image.
        stego.readImage(inputImage);

        // Decipher the message.
        stego.decipher();

        // Print the cipher text to a file.
        stego.printCipherText(outputText);
        cout << "Message decoded and saved to: " << outputText << endl;

    } else { // If the user doesn't choose 1 or 2, print an error message.
        cout << "Invalid choice. Please enter 1 or 2." << endl;
    }

    return 0; // End of the program.
}

