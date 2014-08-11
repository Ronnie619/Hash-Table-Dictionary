/*hash.cpp*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "header.h"

using namespace std;



Hash::Hash ()
{		//Constructor creates initial table and reads in file info
  for (int i = 0; i < tableSize; i++)
    {
      HashTable[i] = new item;
      HashTable[i]->word = "empty";
      HashTable[i]->def = "empty";
      HashTable[i]->next = NULL;
    }

  ifstream inFile ("dictionary.txt");
  string word;
  string def = "def";

  while (!inFile.eof ())
    {
      inFile >> word;
      addItem (word, def);
    }

}

int
Hash::hash (string key)
{		//Hash function decides which bucket to place item 
  int hash = 0;
  int index;

  for (int i = 0; i < key.length (); i++)
    {
      hash = hash + ((int) key[i]) * 5;
    }
  cout << endl;

  index = hash % tableSize;

  return index;

}

void
Hash::addItem (string word, string def)
{		//Function manually adds item to the tree
  int index = hash (word);

  if (HashTable[index]->word == "empty")
    {		// if table is empty
      HashTable[index]->word = word;
      HashTable[index]->def = def;
    }
  else
    {
      itemPtr n = HashTable[index];
      itemPtr p = new item;
      p->word = word;
      p->def = def;
      p->next = NULL;

      while (n->next != NULL)
	{
	  n = n->next;
	}
      n->next = p;
    }

}

int
Hash::numberOfItemsInIndex (int index)
{		//returns # of items in a bucket
  int count = 0;

  if (HashTable[index]->word == "empty")
    {
      return count;
    }
  else
    {
      count++;
      itemPtr p = HashTable[index];
      while (p->next != NULL)
	{
	  count++;
	  p = p->next;
	}
    }
  return count;


}

void
Hash::findMinimum ()
{		//Finds bucket with least amount of items in table
  int minimum = 2000;

  for (int i = 0; i < tableSize; i++)
    {
      if (numberOfItemsInIndex (i) < minimum)
	{
	  minimum = numberOfItemsInIndex (i);
	}

    }

  cout << "Bucket with the least amount of items contains " << minimum <<
    " items." << endl;

}

void
Hash::findMaximum ()
{		//Finds bucket with most items in table
  int maximum = 0;

  for (int i = 0; i < tableSize; i++)
    {
      if (numberOfItemsInIndex (i) > maximum)
	{
	  maximum = numberOfItemsInIndex (i);
	}
    }

  cout << "Bucket with the greatest amount of items contains " << maximum <<
    " items." << endl;

}



void
Hash::printTable ()
{		//Prints hash table info
  int number;

  for (int i = 0; i < tableSize; i++)
    {
      number = numberOfItemsInIndex (i);
      cout << "-----------------\n";
      cout << "index = " << i << endl;
      cout << HashTable[i]->word << endl;
      cout << HashTable[i]->def << endl;
      cout << "# of words in bucket = " << number << endl;
      cout << "-----------------\n";
    }
}

void
Hash::searchForWord (string word)
{		//Finds user-entered word in hash table

  for (int i = 0; i < tableSize; i++)
    {
      itemPtr p = HashTable[i];
      while (p != NULL)
	{
	  if (p->word == word)
	    {
	      cout << "Word was found!" << endl;
	      break;
	    }
	  else
	    {
	      p = p->next;
	    }

	}


    }


}

void
Hash::printItemsInIndex (int index)
{		//prints all contents of a bucket
  itemPtr p = HashTable[index];

  if (p->word == "empty")
    {
      cout << "Index = " << index << " is empty\n";
    }
  else
    {
      cout << "Index " << index << " contains the following items: \n";

      while (p != NULL)
	{
	  cout << "--------------------\n";
	  cout << p->word << endl;
	  cout << p->def << endl;
	  cout << "--------------------\n";
	  p = p->next;
	}
    }
}


void
Hash::printIndex (int index)
{		//Prints a specific index
  itemPtr p = HashTable[index];
  int number = numberOfItemsInIndex (index);

  if (p->word == "empty")
    {
      cout << "Index = " << index << " is empty\n";
    }
  else
    {
      cout << "Index " << index << " contains the following items: \n";
      cout << "--------------------\n";
      cout << p->word << endl;
      cout << p->def << endl;
      cout << "Number of items in bucket: " << number << endl;
      cout << "--------------------\n";
    }
}
