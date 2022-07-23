# en/deCryption

This is my final project for first semester. Documentation is in "Doc/*.pdf".

## Details

In this project I focused on creating console program which allows you to encrypt or decrypt .txt files using [Vigenere cipher](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)
Program is really simple to handle, you only need few commands.

## How it works?
<sub>This is simplified description, for more look into documentation</sub>

### Cipher

Vigenere cipher used in this project uses series of interwoven Caesar ciphers, based on the letters of a keyword. It employs a form of polyalphabetic substitution.
For example if your key is "jan" and text given in .txt file is "pierogi", the encoded text will be "yiraotr".
In order to understand it better, look into the documentation.

### Commands
In order to endrypt or decrypt .txt files you need to pass particular command into console window of a project.
* To encrypt: `-sz -nin input_name.txt -nk key_name -nout output_name`
* To decrypt: `-od -nin input_name.txt -nk key_name -nout output_name`

## How to setup?

To setup the program on your device you just need to clone this repository and compile the project.
