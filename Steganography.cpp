/**
 * @file Steganography.cpp
 * @author Script Sages
 * @date 2024-10-17
 * @brief The cpp file for holding the guts of the file. 
 * 
 * 
 */

#include "Steganography.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int Steganography::getNthbit(char cipherChar, int n){

};

//need to read in the file, seperate the header from the thing(nested loop with an if statement?), then establish a system to scan in the ppm data. 
void Steganography::readImage(const std::string& fileName){ 1
    ifstream file;
  string ppmName = "";
  
};

//sends the data to the file
void Steganography::printImage(const std::string& fileName){ 1

};

//some kind of string reader to extract the file data and store it (maybe have something built in to convert the text into the boolean)
void Steganography::readCipherText(string fileName){ 1

}; 

void Steganography::printCipherText(const std::string& fileName){ 1

};

//readies the image for ciphering - will need a string reader that'll run simple math at the end of every 1-3 digit number
void Steganography::cleanImage(){

};

//will add the 1s and 0s to the image data
void Steganography::encipher(){

};

//will extract the data as necesary
void Steganography::decipher(){

};
