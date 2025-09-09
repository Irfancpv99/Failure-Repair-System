
#include "Study/RS/RSRangeStudy.h"

//******************************************************
//Global Variables
//******************************************************
Double lambda;
Double mu;

//********************************************************
//RSRangeStudy Constructor
//********************************************************
RSRangeStudy::RSRangeStudy() {

  // define arrays of global variable names and types
  NumGVs = 2;
  NumExps = 16;

  GVNames = new char*[NumGVs];
  GVTypes = new char*[NumGVs];
  GVNames[0]=strdup("lambda");
  GVTypes[0]=strdup("double");
  GVNames[1]=strdup("mu");
  GVTypes[1]=strdup("double");

  // create the arrays to store the values of each gv
  lambdaValues = new double[NumExps];
  muValues = new double[NumExps];

  // call methods to assign values to each gv
  SetValues_lambda();
  SetValues_mu();
  SetDefaultMobiusRoot(MOBIUSROOT);
}


//******************************************************
//RSRangeStudy Destructor
//******************************************************
RSRangeStudy::~RSRangeStudy() {
  delete [] lambdaValues;
  delete [] muValues;
  delete ThePVModel;
}


//******************************************************
// set values for lambda
//******************************************************
void RSRangeStudy::SetValues_lambda() {
  lambdaValues[0] = 0.1;
  lambdaValues[1] = 0.010000000000000002;
  lambdaValues[2] = 0.0010000000000000002;
  lambdaValues[3] = 1.0000000000000003E-4;
  lambdaValues[4] = 0.1;
  lambdaValues[5] = 0.010000000000000002;
  lambdaValues[6] = 0.0010000000000000002;
  lambdaValues[7] = 1.0000000000000003E-4;
  lambdaValues[8] = 0.1;
  lambdaValues[9] = 0.010000000000000002;
  lambdaValues[10] = 0.0010000000000000002;
  lambdaValues[11] = 1.0000000000000003E-4;
  lambdaValues[12] = 0.1;
  lambdaValues[13] = 0.010000000000000002;
  lambdaValues[14] = 0.0010000000000000002;
  lambdaValues[15] = 1.0000000000000003E-4;
}


//******************************************************
// set values for mu
//******************************************************
void RSRangeStudy::SetValues_mu() {
  muValues[0] = 0.1;
  muValues[1] = 0.1;
  muValues[2] = 0.1;
  muValues[3] = 0.1;
  muValues[4] = 0.010000000000000002;
  muValues[5] = 0.010000000000000002;
  muValues[6] = 0.010000000000000002;
  muValues[7] = 0.010000000000000002;
  muValues[8] = 0.0010000000000000002;
  muValues[9] = 0.0010000000000000002;
  muValues[10] = 0.0010000000000000002;
  muValues[11] = 0.0010000000000000002;
  muValues[12] = 1.0000000000000003E-4;
  muValues[13] = 1.0000000000000003E-4;
  muValues[14] = 1.0000000000000003E-4;
  muValues[15] = 1.0000000000000003E-4;
}



//******************************************************
//print values of gv (for debugging)
//******************************************************
void RSRangeStudy::PrintGlobalValues(int expNum) {
  if (NumGVs == 0) {
    cout<<"There are no global variables."<<endl;
    return;
  }

  SetGVs(expNum);

  cout<<"The Global Variable values for experiment "<<
    GetExpName(expNum)<<" are:"<<endl;
  cout << "lambda\tdouble\t" << lambda << endl;
  cout << "mu\tdouble\t" << mu << endl;
}


//******************************************************
//retrieve the value of a global variable
//******************************************************
void *RSRangeStudy::GetGVValue(char *TheGVName) {
  if (strcmp("lambda", TheGVName) == 0)
    return &lambda;
  else if (strcmp("mu", TheGVName) == 0)
    return &mu;
  else 
    cerr<<"!! RSRangeStudy::GetGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
  return NULL;
}


//******************************************************
//override the value of a global variable
//******************************************************
void RSRangeStudy::OverrideGVValue(char *TheGVName,void *TheGVValue) {
  if (strcmp("lambda", TheGVName) == 0)
    SetGvValue(lambda, *(double *)TheGVValue);
  else if (strcmp("mu", TheGVName) == 0)
    SetGvValue(mu, *(double *)TheGVValue);
  else 
    cerr<<"!! RSRangeStudy::OverrideGVValue: Global Variable "<<TheGVName<<" does not exist."<<endl;
}


//******************************************************
//set the value of all global variables to the given exp
//******************************************************
void RSRangeStudy::SetGVs(int expNum) {
  SetGvValue(lambda, lambdaValues[expNum]);
  SetGvValue(mu, muValues[expNum]);
}


//******************************************************
//static class method called by solvers to create study 
//(and thus create all of the model)
//******************************************************
BaseStudyClass* GlobalStudyPtr = NULL;
BaseStudyClass * GenerateStudy() {
  if (GlobalStudyPtr == NULL)
    GlobalStudyPtr = new RSRangeStudy();
  return GlobalStudyPtr;
}

void DestructStudy() {
  delete GlobalStudyPtr;
  GlobalStudyPtr = NULL;
}
//******************************************************
//get and create the PVModel
//******************************************************
PVModel* RSRangeStudy::GetPVModel(bool expandTimeArrays) {
  if (ThePVModel!=NULL)
    delete ThePVModel;
  // create the PV model
  ThePVModel=new RWPVModel(expandTimeArrays);
  return ThePVModel;
}


