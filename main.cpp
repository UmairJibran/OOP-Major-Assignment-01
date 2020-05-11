#include <iostream>
using namespace std;

class Subject{
  protected:
    double totalMarks;
    double obtainedMarks;
  public:
    Subject(){
      this->totalMarks = 100.0;
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
      double percentageObtainedMarksWithoutPracticle = 0.0;
      double percentageObtainedMarksWithPracticle = 0.0;
      percentageObtainedMarksWithoutPracticle = (this->Urdu::obtainedMarks + this->Physics::obtainedMarks + this->ComputerScience::obtainedMarks) / (this->Urdu::totalMarks + this->Physics::totalMarks + this->ComputerScience::totalMarks) * 100;
      percentageObtainedMarksWithPracticle = (this->Urdu::obtainedMarks + this->Physics::obtainedMarks + this->ComputerScience::obtainedMarks + this-> ComputerScience::pracitcalObtainedMarks + this->Physics::pracitcalObtainedMarks) / (this->Urdu::totalMarks + this->Physics::totalMarks + this->ComputerScience::totalMarks + this-> ComputerScience::practicalTotalMarks + this->Physics::practicalTotalMarks) * 100;
      cout << endl << "Percentage of all subjects excluding Practicle: " << percentageObtainedMarksWithoutPracticle << "%";
      cout << endl << "Percentage of all subjects including the ones with Practicle: " << percentageObtainedMarksWithPracticle << "%";
    }
};

int main() {
  Student awais;
  awais.getTheoryMakrs(91,68,72);
  awais.getPracticalMarks(7,83);
  awais.getAveragePercentMarks();
}