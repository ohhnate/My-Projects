class Thing {
public:
  Thing(int number): number(number) {}

  friend bool operator>(const Thing& leftThing, const Thing& rightThing);
  bool operator<(const Thing& otherThing);

  friend ostream& operator<<(ostream& outs, const Thing& thing);

  private:
    int number;
};

ostream& operator<<(ostream& outs, const Thing& thing) {
  outs << thing.number;
  return outs;
}

bool operator>(const Thing& leftThing, const Thing& rightThing) {
  return leftThing.number < rightThing.number;
}

bool Thing::operator<(const Thing& otherThing) {
  this->number < otherThing.number;
}
