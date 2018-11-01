#ifndef NAT_H
#define NAT_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>

using namespace std;

// A class to store the network address translations from a given file
class NAT {
  unordered_map<string, string> nat;  // mapping from one address space to another

 public:
  /* 
   * Lookup and translate a network address
   * Input: address to be translated
   * Output: translated address if there is a match in the NAT table,
   *         empty string otherwise
   */
  string lookup(string addr);

  /*
   * Parses the input file and uses it to populate the NAT table
   * Input: name of the file with NAT entries
   */
  void init(const string& filename);
};

#endif
