class aType;
class bType;
class cType;

class aType {
  public:
    bType *b;
    cType *c;
};

class bType {
  public:
    aType *a;
    cType *c;
};

class cType {
  public:
    aType *a;
    bType *b;
};


int main() {
  aType a;
  bType b;
  cType c;
  return 0;
}