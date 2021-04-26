#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "polynomial.hpp"
#include "generator.hpp"
#include "utilsMethod.hpp"
#include "SafeInput.hpp"
#include "pSettings.hpp"
#include "menu.hpp"
#include "interactive.hpp"

void printMainMenu();
void interactiveMode();
void generateMode();

int main()
{
    std::srand(std::time(0));
    int choice;
    while (true)
    {
        menu::mainMenu();
        choice = tsi::getInt("Choice: ");
        switch (choice)
        {
        case 1:
            interactiveMode();
            break;
        case 2:
            generateMode();
            break;
        case 3:
            pSettings::page();
            break;
        case 0:
            std::cout << "GOODBYE JOJO!!!" << std::endl;
            return 0;
        default:
            std::cout << "Unknown Choice!" << std::endl;
        }
    }

    return 0;
}

void interactiveMode()
{
    menu::interactive();

    int choice = tsi::getInt("Your Choice: ");
    switch (choice)
    {
    case 1:
        testMode();
        break;
    case 2:
        endlessMode();
        break;
    case 3:
        timelimitMode();
        break;
    case 0:
        return;
    default:
        std::cout << "Unknown Choice!" << std::endl;
    }
}

void generateMode()
{
    std::string ofile_location = "./generated/";
    std::string keyf_location = ofile_location;
    std::string ofile_name = tsi::getString("Enter Output File Name: ");
    ofile_location += ofile_name;
    ofile_location += ".txt";

    std::string keyf_name = tsi::getString("Enter Key File Name: ");
    keyf_location += keyf_name;
    keyf_location += ".txt";

    if (ofile_name == keyf_name)
    {
        std::cout << "ERROR: Two Files can't be the same!" << std::endl;
        return;
    }

    if (!(ofile_name.size() && keyf_name.size()))
    {
        std::cout << "ERROR: File name can't be blank!" << std::endl;
        return;
    }

    int difficulity = tsi::getInt("Degree of Polynomial: ");
    if (difficulity < 2)
    {
        std::cout << "WARNING: Polynomial degree must be at least 2!" << std::endl;
        return;
    }

    int T = tsi::getInt("Number of polynomial: ");

    std::ofstream OutFile(ofile_location);
    std::ofstream KeyFile(keyf_location);
    for (int i = 1; i <= T; i++)
    {
        Polynomial res = PolyGenerator::random(difficulity);
        OutFile << i << ") Solve " << res.printPoly() << " = 0" << std::endl;
        KeyFile << "Key of #" << i << " : " << rootsToStr(PolyGenerator::getCurrRoots()) << std::endl;
    }

    std::cout << "Successfully generated both files" << std::endl;
    OutFile.close();
}