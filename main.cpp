/*main.cpp*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "header.h"

using namespace std;

int
main ()
{		//Main


  int choice;	//variable for switch case interface

  Hash hashObj;	//Hash class object, creates table and reads in file info

  hashObj.printTable (); //Prints table information out

  hashObj.findMinimum (); //find min and max bucket in table
  hashObj.findMaximum ();

  do
    {		//Loop for switch case interface
      cout << "Would you like to search for a word? (1)yes or (0)no: ";
      cin >> choice;
      string search;

      switch (choice)
	{

	case 0:
	  cout << "Exiting" << endl;
	  break;

	case 1:
	  {
	    string search;
	    cout << "Enter the word you wish to search for: \n";
	    cin >> search;
	    hashObj.searchForWord (search); //Finds word entered by the user
	    break;
	  }
	default:
	  cout << "Try Again." << endl;


	}
    }
  while (choice != 0);


  return 0;
}
