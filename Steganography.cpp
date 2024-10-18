/**
 * @file Steganography.cpp
 * @author Script Sages
 * @date 2024-10-17
 * @brief The cpp file for the Steganography class implementation.
 */

#include "Steganography.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Helper method to retrieve the nth bit of a given character.
int Steganography::getNthbit(char cipherChar, int n) {
    return (cipherChar >> (7 - n)) & 1; // Get the nth bit (0-7)
}

// Reads a PPM image from a file and stores it in the class variables.
void Steganography::readImage(const std::string& fileName) {
  (void)fileName;

}

// Writes the stored image data to a PPM file.
void Steganography::printImage(const std::string& fileName) {
  ofstream file(fileName); //Tries to open file with the name given by fileName
  if (!file.is_open()) { //Checks to see if the file opened correctly
    cerr << "Error: Could not open file " << fileName << endl;
    return;
  }
  
  file << magicNumber << endl; //Special identifier for the file format
  file << width << " " << height << endl; //The dimensions of the image (width and height)
  file << maxColor << endl; // The maximum color value
  for (int value : colorData) { //Goes through all the color values stored in colorData and writes them to the file
    file << value << " "; //Each value represents the color intensity for a pixel in the image. Written one after the other, spaced.
  }
  file.close(); //Closes the file
}

// Reads the cipher text (hidden message) from a plain text file.
void Steganography::readCipherText(const std::string& fileName) {
  (void)fileName;

}

// Writes the stored cipher text to a plain text file.
void Steganography::printCipherText(const std::string& fileName) {
  (void)fileName;

}

// Zeros out the least significant bit (LSB) of each color value in the image.
void Steganography::cleanImage() {
    for (size_t i = 0; i < colorData.size(); ++i) {
        colorData[i] &= ~1; // Zero out the least significant bit
    }
}

// Encodes the cipher text into the image data by modifying the least significant bits of the color data.
void Steganography::encipher() {
    cleanImage(); // Clean the image before encoding

    for (size_t i = 0; i < cipherText.size(); ++i) {
        for (int bit = 0; bit < 8; ++bit) {
            if (i * 8 + bit < colorData.size()) {
                int bitValue = getNthbit(cipherText[i], bit); // Get the bit from the character
                colorData[i * 8 + bit] |= bitValue; // Set the LSB to the bit value
            }
        }
    }
}

// Decodes the hidden message from the image data.
void Steganography::decipher() {
    cipherText.clear(); // Clear any existing cipher text
    for (size_t i = 0; i < colorData.size() / 8; ++i) {
        char cipherChar = 0; // Initialize the character
        for (int bit = 0; bit < 8; ++bit) {
            if (i * 8 + bit < colorData.size()) {
                int bitValue = colorData[i * 8 + bit] & 1; // Get the LSB
                cipherChar |= (bitValue << (7 - bit)); // Set the corresponding bit in the character
            }
        }
        cipherText += cipherChar; // Add the character to the cipher text
    }
}
