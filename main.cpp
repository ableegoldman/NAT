#include "NAT.h"

const string NAT_FILE = "NAT";
const string FLOW_FILE = "FLOW";
const string OUTPUT_FILE = "OUTPUT";

void translate_flow(const string& fname_flow, const string& fname_out, NAT& nat)
{
  ifstream flow(fname_flow);
  if (!flow)
    cerr << "Error: failed to open flow file for reading" << endl;

  ofstream out(fname_out);
  if (!out)
    cerr << "Error: failed to open output file for writing" << endl;

  string addr, new_addr;
  while (getline(flow, addr))
    {
      new_addr = nat.lookup(addr);

      // If lookup returns empty string, there was no match
      if (new_addr == "") {
	out << "No nat match for " << addr << endl;
      } else {
	out << addr << " -> " << new_addr << endl;
      }
    }
  flow.close();
  out.close();
}

int main()
{
  NAT nat;
  nat.init(NAT_FILE);

  translate_flow(FLOW_FILE, OUTPUT_FILE, nat);

  return 0;
}
