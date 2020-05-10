#include <iostream>
using namespace std;

class Subject{
  protected:
    double totalMarks;
    double obtainedMarks;
  public:
    Subject(){
      this->totalMarks = 0.0;
      this->obtainedMarks = 0.0;
    }
};

class Physics:protected Subject{
  public:
    Physics(){
      practicalTotalMarks = 100.0;
      pracitcalObtainedMarks = 0.0;
    }
  protected:
    double practicalTotalMarks;
    double pracitcalObtainedMarks;
};

class ComputerScience:protected Subject{
  public:
    ComputerScience(){
      practicalTotalMarks = 100.0;
      pracitcalObtainedMarks = 0.0;
    }
  protected:
    double practicalTotalMarks;
    double pracitcalObtainedMarks;
};

class Urdu:protected Subject{

};

class Student: protected Physics,protected Urdu,protected ComputerScience{
  public:
    void getTheoryMakrs(double urduMarks,double physicsMarks,double cSMarks){
      this->Urdu::obtainedMarks = urduMarks;
      this->Physics::obtainedMarks = physicsMarks;
      this->ComputerScience::obtainedMarks = cSMarks;
    }
    void getPracticalMarks(double cSPMarks, double physicsPMarks){
      this->ComputerScience::pracitcalObtainedMarks = cSPMarks;
      this->Physics::pracitcalObtainedMarks = physicsPMarks;
    }
    void getAveragePercentMarks(){
      double averageObtainedMarksWithoutPracticle = 0.0;
      double averageObtainedMarksWithPracticle = 0.0;
      double percentageObtainedMarksWithoutPracticle = 0.0;
      double percentageObtainedMarksWithPracticle = 0.0;
      averageObtainedMarksWithoutPracticle = this->Urdu::obtainedMarks + this->Physics::obtainedMarks + this->ComputerScience::obtainedMarks / 3;
      averageObtainedMarksWithPracticle = this->Urdu::obtainedMarks + this->Physics::obtainedMarks + this-> Physics::pracitcalObtainedMarks + this-> ComputerScience::pracitcalObtainedMarks + this->ComputerScience::obtainedMarks / 5;
      percentageObtainedMarksWithoutPracticle = (this->Urdu::obtainedMarks + this->Physics::obtainedMarks + this->ComputerScience::obtainedMarks) / 300 * 100;
      percentageObtainedMarksWithPracticle = (this->Urdu::obtainedMarks + this->Physics::obtainedMarks + this->ComputerScience::obtainedMarks + this-> ComputerScience::pracitcalObtainedMarks + this->Physics::pracitcalObtainedMarks) / 500 * 100;
      cout << endl << "Average Marks of all subjects excluding Practicle: " << averageObtainedMarksWithoutPracticle;
      cout << endl << "Average Marks of all subjects including the ones with Practicle: " << averageObtainedMarksWithPracticle;
      cout << endl << "Percentage of all subjects excluding Practicle: " << percentageObtainedMarksWithoutPracticle << "%";
      cout << endl << "Percentage of all subjects including the ones with Practicle: " << percentageObtainedMarksWithPracticle << "%";
    }
};

int main() {
  Student awais;
  awais.getTheoryMakrs(90,80,85);
  awais.getPracticalMarks(75,83);
  awais.getAveragePercentMarks();
  cout << endl << endl <<  "------------------------------";
  cout << endl << "Final Statement";
}