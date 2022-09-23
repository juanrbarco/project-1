#include "Lexer.h"
#include <fstream>
#include <iostream>


int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    std::string fileName = argv[1];
    std::ifstream input(fileName);


    /*if (input.is_open()) {
        std::cout << "it is open!" << std::endl; //check if file is open
    }
    std::cout << fileName << argc << std::endl; //check if it's the right file
*/


    std::string fileStr;
//    char c = '\0';
//    while (EOF != c) {
//        c = input.get();
//        fileStr.push_back(c);
//    }
//     std::cout << fileStr;


    std::istreambuf_iterator<char> inputIt(input), emptyInputIt;
    std::back_insert_iterator<std::string> stringInsert(fileStr);

     copy(inputIt, emptyInputIt, stringInsert);

    lexer->Run(fileStr);

    //std::cout << fileStr << std::endl; //make sure file is being read properly

    lexer->PrintTokens();

    delete lexer;

    return 0;
}