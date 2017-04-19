/*
Comsci.h											         		
Standard header to be included with programs created in Computer Science related classes
Version	:1.2b
Created	:April		25th 2015
Modified:January	31th 2017
*/
#ifndef Comsci_H
#define Comsci_H
//#include "stdafx.h"
#include <iostream>
#include "windows.h"
#include <conio.h>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <tchar.h>
#include <cmath>
#include <fstream>
#define spacer "|------------------------------------------------------------------------------|"
#define newline "\n"
#define newlineS "\n "
std::string splashwrap(std::string input)// need to fix drift issue
{
	int c = 22;
	if (input.length() < 62)
	{
		return input;
	}
	if (input.length() > 62 && input.length()<141)
	{

		input.insert(61, newlineS);
		return input;
	}
	else
	{
		input.insert(61, newlineS);
		int instancecnt = 0;
		int size22 = input.length() - 61;
		int ctr2234 = size22 / 80;
		while (ctr2234>0)
		{
			int spot = (61 + (80 * ctr2234));
			input.insert(spot, newlineS);
			ctr2234--;
			instancecnt++;
		}
	}
	return input;
}
int splash(std::string title = "Untitled", std::string purpose = "N/A",bool usings = true) //splash screen for programs
{
	
	//std::cout << "********************************************************************\n";
	std::cout << spacer;
	if (usings) { std::cout << std::endl<< " Using Comsci.h"; }
	std::cout <<std::endl<< " Program Name	: "<< title << std::endl;
	std::cout << " Description	: " << splashwrap(purpose) << std::endl;;
	std::cout << spacer<<std::endl;
	//std::cout << "********************************************************************\n";
		return 0;
}

void pause(std::string word = "Press any key to continue\n") //easy pause command
{
	std::cout << std::endl<< word;
	std::cin.get();
}
int color(std::string doscolor) //Simple color handler
{
	std::string syscolor; // green, default, blue
	{
		if (doscolor == "green")
			doscolor = "0A";
		if (doscolor == "default")
			doscolor = "07";
		if (doscolor == "blue")
			doscolor = "9E";
		syscolor = "color " + doscolor;
		system(syscolor.c_str());
		return 3;
	}
}
std::string centertext(std::string imput)
{
	std::string z2;
	int math;
	int screenwidth = 78;
	math = (78 - imput.length()) / 2;
	if (imput.length() > 80)
		goto exit;
	int counter = 0;
	while (math > counter)
	{
		z2 = z2 + " ";
		counter++;
	}
	z2 = z2 + imput;
	exit:
	return z2;

}
//EOF
#endif