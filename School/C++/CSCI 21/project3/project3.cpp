#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std:: endl;
using std::ifstream;
using std::string;
using std::istringstream;

int main(int argc, char *argv[]) {

  if (argc != 2) {
    cout << "Usage: " << argv[0] << " FILENAME" << endl;
  } else {
      ifstream fin(argv[1]);
      if (!fin.is_open()) {
        cout << "Unable to open " << argv[1] << " for input" << endl;
      } else {
          string nextline;
          string name;
          string quantity;
          while(getline(fin, nextline)) {
            istringstream iss(nextline);
            getline(iss, name, ':');
            getline(iss, quantity, ':');
          }
          fin.close();
      }

return 0;
}
