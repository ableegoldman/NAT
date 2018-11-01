#include "NAT.h"

string NAT::lookup(string addr)
{
  // Look for the address in our NAT table
  auto it = nat.find(addr);
  if (it != nat.end())
    return it->second;

  // Look for a match on the ip (ie a NAT entry with port = *)
  // by looking up ip.*
  string addr_ip = addr.substr(0, 1 + addr.find(':')) + '*';
  it = nat.find(addr_ip);
  if (it != nat.end())
    return it->second;

  // Look for a match on the port (ie a NAT entry with ip = *)
  // by looking up *:port
  string addr_port = '*' + addr.substr(addr.find(':'));
  it = nat.find(addr_port);
  if (it != nat.end())
    return it->second;

  return "";
}

void NAT::init(const string& fname)
{
  ifstream natfile(fname);
  if (!natfile)
    cerr << "Error: failed to open nat file for reading" << endl;

  string entry, addr, new_addr;
  while (getline(natfile, entry))
    {
      addr = entry.substr(0, entry.find(','));
      new_addr = entry.substr(1 + entry.find(','));

      nat[addr] = new_addr;
    }

  natfile.close();
}
