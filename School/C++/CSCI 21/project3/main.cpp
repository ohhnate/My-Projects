#include "project.hpp"

int main(int argc, char *argv[]) {
  
  bool created = false;
  string command = "";
  DList<unsigned int> *list = nullptr;
  vector<string> lines;

  if(argc != 2) {
    cout << "Usage: " << argv[0] << " FILENAME\n";
  } else {
    ifstream fin(argv[1]);
    if(!fin.is_open()){
      cout << "Unable to open " << argv[1] << " for input\n";
    } else {
      string nextline;
      while(getline(fin, nextline)) {
        lines.push_back(nextline);
      }
      fin.close();
    }
  }


  for(vector<string>::iterator i=lines.begin(); i<lines.end(); i++){
    string line = *i;
    unsigned int value = 0;
    command = "";

    command = line[0];
    if(command != "#"){
      if(line.size() > 1){
        int pos = line.find(" ");
        int end = line.size();
        value = stoul(line.substr(pos, end));
      }
    }
    if(command == "C"){
      if(created){
        list->clear();
        delete list;
        list = nullptr;
      }
      list = new DList<unsigned int>;
      created = true;
      cout << "LIST CREATED";
    }

    if(command == "X"){
      if(!created){
        cout << "MUST CREATE LIST INSTANCE";
      } else {
        list->clear();
        cout << "LIST CLEARED";
      }
    }

    if(command == "D"){
      if(list !=nullptr){
        cout << "MUST CREATE LIST INSTANCE";
      } else {
        list->clear();
        delete list;
        list = nullptr;
        created = false;
        cout << "LIST DELETED";
      }
    }

    if(command == "I"){
      if(!created){
        cout << "MUST CREATE LIST INSTANCE";
      } else {
        list->insert(value);
        cout << "VALUE " << value << " INSERTED";
      }
    }
    if(command == "F"){
      if(!created){
        cout << "MUST CREATE LIST INSTANCE";
      } else {
        list->pushFront(value);
        cout << "VALUE " << value << " ADDED TO HEAD";
      }
    }
    if(command == "B"){
      if(!created){
        cout << "MUST CREATE LIST INSTANCE";
      } else {
        list->pushBack(value);
        cout << "VALUE " << value << " ADDED TO TAIL";
      }
    }
    if(command == "E"){
      bool elim = false;
      if(!created){
        cout << "MUST CREATE LIST INSTANCE";
      } else {
        elim = list->elimAll(value);
      }
      if(elim)
        cout << "VALUE " << value << " ELIMINATED";
      if(!elim)
        cout << "VALUE " << value << " NOT FOUND";
    }
    if(command == "R"){
      bool elim = false;
      if(!created){
        cout << "MUST CREATE LIST INSTANCE";
      } else {
        elim = list->elimFirst(value);
      }
      if(elim)
        cout << "VALUE " << value << " REMOVED";
      if(!elim)
        cout << "VALUE " << value << " NOT FOUND";
    }
    if(command == "G"){
      if(!created){
        cout << "MUST CREATE LIST INSTANCE";
      } else {
        list->findValue(value);
      }
    }
    if(command == "A"){
      if(!created){
        cout << "MUST CREATE LIST INSTANCE";
      } else {
        list->getFront();
      }
    }
    if(command == "Z"){
      if(!created){
        cout << "MUST CREATE LIST INSTANCE";
      } else {
        list->getBack();
      }
    }
    if(command == "T"){
      bool popped = false;
      if(!created){
        cout << "MUST CREATE LIST INSTANCE";
      } else {
        popped = list->popFront();
      }
      if(popped)
        cout << "HEAD REMOVED";
      if(!popped)
        cout << "LIST EMPTY";
    }
    if(command == "K"){
      bool popped = false;
      if(!created){
        cout << "MUST CREATE LIST INSTANCE";
      } else {
        popped = list->popBack();
      }
      if(popped)
        cout << "TAIL REMOVED";
      if(!popped)
        cout << "LIST EMPTY";
    }
    if(command == "N"){
      if(!created){
        cout << "MUST CREATE LIST INSTANCE";
      } else {
        cout << "LIST SIZE IS " << list->getSize(); 
      }
    } 
    if(command == "P"){
      if(!created){
        cout << "MUST CREATE LIST INSTANCE";
      } else {
        list->printList();
      }
    }
    if(command != "#")
      cout << endl;
  }

return 0;
}
