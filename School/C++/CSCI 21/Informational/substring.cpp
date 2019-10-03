// Substring method
//example 1 (1 delimiter)
string c = "mauve ^ 224 ^ 176 ^ 255";

string color, token;
int r,g,b;
int pos; // position

pos = c.find("^", 0);
color = c.substr(0, pos);
c = c.substr(pos +1);
pos = c.find("^");
token = c.substr(0, pos);
r = stoi(token);

//example 2 (more than 1 delimeter)
string c = "mauve -> 224 -> 176 -> 255";

string color, token;
int r,g,b;
int pos; // position
string delim = "->";

pos = c.find(delim);
color = c.substr(0, pos);
c = c.substr(pos + delim.size());
token = c.substr(0, pos);
r = stoi(token);
