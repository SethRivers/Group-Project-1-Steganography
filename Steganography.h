/*
 * @file Steganography.h
 * @author Script Sages
 * @date 10/10/2024
 * @brief Description: The header of the Steganography class.
 */

#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <iostream>
#include <vector>
#include <string>



/**
 * Steganography class is used to store, modify, and output PPM images.
 * The class supports encoding and decoding hidden messages into the least significant
 * bits of color data in the PPM image format.
 */

class Steganography {
 private:
  std::string magicNumber; // P3 or other PPM format identifier
  int width; // Image width
  int height; // Image height
  int maxColor; // Max color value (e.g, 255)
  std::vector<int> colorData; // Raw color data
  std::string cipherText; // Hidden message

  /** Helper method to retrieve the nth bit of a given character.
   *
   *@param cipherChar The character from which the bit is retrieved
   *@param n The bit position (0-7)
   *@return The nth bit of the character (0 or 1).
   */
 int getNthbit(char cipherChar, int n);

 public:
  /**
   * Reads a PPM image from a file and stores it in the class variables.
   *
   * @param fileName The name of the input PPM file
   */
  void readImage(const std::string& fileName);

  /**
   * Writes the stored image data to a PPM file.
   *
   * @param fileName The name of the output PPM file.
   */
  void printImage(const std::string& fileName);

  /**
   * Reads the cipher text (hidden message) from a plain text file.
   *
   * @param fileName The name of the input plain text file.
   */
  void readCipherText(const std::string& fileName);

  /**
   * Writes the stored cipher text to a plain text file.
   *
   * @param fileName The name of the output plain text file.
   */
  void printCipherText(const std::string& fileName);

  /**
   * Zeros out the least significant bit (LSB) of each color value in the image.
   * This prepares the image for encoding by cleaning it.
   */
  void cleanImage();

   /**
     * Encodes the cipher text (hidden message) into the image data by modifying
     * the least significant bits of the color data.
     */
  void encipher();

    /**
     * Decodes the hidden message from the image data by reading the least significant
     * bits of the color data and reconstructing the original message.
     */
  void decipher();
};

#endif  //STEGANOGRAPHY_H
