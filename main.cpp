#include <iostream>
using namespace std;

class Subject{
  protected:
    double totalMarks;
    double obtainedMarks;
};
class Physics:protected Subject{
  private:
    
};

int main() {
  cout << endl << endl <<  "------------------------------";
  cout << endl << "Final Statement";
}