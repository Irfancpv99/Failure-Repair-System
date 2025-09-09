

// This C++ file was created by SanEditor

#include "Atomic/Repair/RepairSAN.h"

#include <stdlib.h>
#include <iostream>

#include <math.h>


/*****************************************************************
                         RepairSAN Constructor             
******************************************************************/


RepairSAN::RepairSAN(){


  Activity* InitialActionList[9]={
    &FailedB_C, //0
    &RepairSystem, //1
    &failure, //2
    &FailA, //3
    &FailB, //4
    &FailC, //5
    &RepairA, //6
    &RepairB, //7
    &RepairC  // 8
  };

  BaseGroupClass* InitialGroupList[9]={
    (BaseGroupClass*) &(FailA), 
    (BaseGroupClass*) &(FailB), 
    (BaseGroupClass*) &(FailC), 
    (BaseGroupClass*) &(RepairA), 
    (BaseGroupClass*) &(RepairB), 
    (BaseGroupClass*) &(RepairC), 
    (BaseGroupClass*) &(FailedB_C), 
    (BaseGroupClass*) &(RepairSystem), 
    (BaseGroupClass*) &(failure)
  };

  PlaceA = new Place("PlaceA" ,1);
  PlaceB = new Place("PlaceB" ,2);
  PlaceC = new Place("PlaceC" ,3);
  FailedA = new Place("FailedA" ,0);
  FailedB = new Place("FailedB" ,0);
  FailedC = new Place("FailedC" ,0);
  Repair = new Place("Repair" ,0);
  SystemFailure = new Place("SystemFailure" ,0);
  FailedBC = new Place("FailedBC" ,0);
  Failure = new Place("Failure" ,0);
  SystemActive = new Place("SystemActive" ,1);
  BaseStateVariableClass* InitialPlaces[11]={
    PlaceA,  // 0
    PlaceB,  // 1
    PlaceC,  // 2
    FailedA,  // 3
    FailedB,  // 4
    FailedC,  // 5
    Repair,  // 6
    SystemFailure,  // 7
    FailedBC,  // 8
    Failure,  // 9
    SystemActive   // 10
  };
  BaseStateVariableClass* InitialROPlaces[0]={
  };
  initializeSANModelNow("Repair", 11, InitialPlaces, 
                        0, InitialROPlaces, 
                        9, InitialActionList, 9, InitialGroupList);


  assignPlacesToActivitiesInst();
  assignPlacesToActivitiesTimed();

  int AffectArcs[24][2]={ 
    {8,0}, {7,0}, {7,1}, {6,1}, {7,2}, {9,2}, {0,3}, {3,3}, {7,3}, 
    {1,4}, {4,4}, {8,4}, {2,5}, {5,5}, {8,5}, {6,6}, {0,6}, {3,6}, 
    {6,7}, {1,7}, {4,7}, {6,8}, {2,8}, {5,8}
  };
  for(int n=0;n<24;n++) {
    AddAffectArc(InitialPlaces[AffectArcs[n][0]],
                 InitialActionList[AffectArcs[n][1]]);
  }
  int EnableArcs[21][2]={ 
    {8,0}, {7,1}, {9,1}, {3,1}, {8,1}, {7,2}, {0,3}, {10,3}, 
    {1,4}, {10,4}, {2,5}, {10,5}, {6,6}, {3,6}, {6,7}, {0,7}, 
    {4,7}, {6,8}, {0,8}, {1,8}, {5,8}
  };
  for(int n=0;n<21;n++) {
    AddEnableArc(InitialPlaces[EnableArcs[n][0]],
                 InitialActionList[EnableArcs[n][1]]);
  }

  for(int n=0;n<9;n++) {
    InitialActionList[n]->LinkVariables();
  }
  CustomInitialization();

}

void RepairSAN::CustomInitialization() {

}
RepairSAN::~RepairSAN(){
  for (int i = 0; i < NumStateVariables-NumReadOnlyPlaces; i++)
    delete LocalStateVariables[i];
};

void RepairSAN::assignPlacesToActivitiesInst(){
  FailedB_C.FailedBC = (Place*) LocalStateVariables[8];
  FailedB_C.SystemFailure = (Place*) LocalStateVariables[7];
  RepairSystem.SystemFailure = (Place*) LocalStateVariables[7];
  RepairSystem.Failure = (Place*) LocalStateVariables[9];
  RepairSystem.FailedA = (Place*) LocalStateVariables[3];
  RepairSystem.FailedBC = (Place*) LocalStateVariables[8];
  RepairSystem.Repair = (Place*) LocalStateVariables[6];
  failure.SystemFailure = (Place*) LocalStateVariables[7];
  failure.Failure = (Place*) LocalStateVariables[9];
}
void RepairSAN::assignPlacesToActivitiesTimed(){
  FailA.PlaceA = (Place*) LocalStateVariables[0];
  FailA.SystemActive = (Place*) LocalStateVariables[10];
  FailA.FailedA = (Place*) LocalStateVariables[3];
  FailA.SystemFailure = (Place*) LocalStateVariables[7];
  FailB.PlaceB = (Place*) LocalStateVariables[1];
  FailB.SystemActive = (Place*) LocalStateVariables[10];
  FailB.FailedB = (Place*) LocalStateVariables[4];
  FailB.FailedBC = (Place*) LocalStateVariables[8];
  FailC.PlaceC = (Place*) LocalStateVariables[2];
  FailC.SystemActive = (Place*) LocalStateVariables[10];
  FailC.FailedC = (Place*) LocalStateVariables[5];
  FailC.FailedBC = (Place*) LocalStateVariables[8];
  RepairA.Repair = (Place*) LocalStateVariables[6];
  RepairA.FailedA = (Place*) LocalStateVariables[3];
  RepairA.PlaceA = (Place*) LocalStateVariables[0];
  RepairB.Repair = (Place*) LocalStateVariables[6];
  RepairB.PlaceA = (Place*) LocalStateVariables[0];
  RepairB.FailedB = (Place*) LocalStateVariables[4];
  RepairB.PlaceB = (Place*) LocalStateVariables[1];
  RepairC.Repair = (Place*) LocalStateVariables[6];
  RepairC.PlaceA = (Place*) LocalStateVariables[0];
  RepairC.PlaceB = (Place*) LocalStateVariables[1];
  RepairC.FailedC = (Place*) LocalStateVariables[5];
  RepairC.PlaceC = (Place*) LocalStateVariables[2];
}
/*****************************************************************/
/*                  Activity Method Definitions                  */
/*****************************************************************/

/*======================FailedB_CActivity========================*/


RepairSAN::FailedB_CActivity::FailedB_CActivity(){
  ActivityInitialize("FailedB_C",6,Instantaneous , RaceEnabled, 2,1, false);
}

void RepairSAN::FailedB_CActivity::LinkVariables(){
  FailedBC->Register(&FailedBC_Mobius_Mark);
  SystemFailure->Register(&SystemFailure_Mobius_Mark);
}

bool RepairSAN::FailedB_CActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(FailedBC_Mobius_Mark)) >=1)&&((FailedBC -> Mark() == 5)));
  return NewEnabled;
}

double RepairSAN::FailedB_CActivity::Weight(){ 
  return 1;
}

bool RepairSAN::FailedB_CActivity::ReactivationPredicate(){ 
  return false;
}

bool RepairSAN::FailedB_CActivity::ReactivationFunction(){ 
  return false;
}

double RepairSAN::FailedB_CActivity::SampleDistribution(){
  return 0;
}

double* RepairSAN::FailedB_CActivity::ReturnDistributionParameters(){
    return NULL;
}

int RepairSAN::FailedB_CActivity::Rank(){
  return 1;
}

BaseActionClass* RepairSAN::FailedB_CActivity::Fire(){
  ;
  (*(FailedBC_Mobius_Mark))--;
  (*(SystemFailure_Mobius_Mark))++;
  return this;
}

/*======================RepairSystemActivity========================*/


RepairSAN::RepairSystemActivity::RepairSystemActivity(){
  ActivityInitialize("RepairSystem",7,Instantaneous , RaceEnabled, 2,4, false);
}

void RepairSAN::RepairSystemActivity::LinkVariables(){
  SystemFailure->Register(&SystemFailure_Mobius_Mark);
  Failure->Register(&Failure_Mobius_Mark);
  FailedA->Register(&FailedA_Mobius_Mark);
  FailedBC->Register(&FailedBC_Mobius_Mark);
  Repair->Register(&Repair_Mobius_Mark);
}

bool RepairSAN::RepairSystemActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(SystemFailure_Mobius_Mark)) >=1)&&((FailedA ->Mark()==1) && (FailedBC-> Mark()==5) && (Failure->Mark()==1)	
));
  return NewEnabled;
}

double RepairSAN::RepairSystemActivity::Weight(){ 
  return 1;
}

bool RepairSAN::RepairSystemActivity::ReactivationPredicate(){ 
  return false;
}

bool RepairSAN::RepairSystemActivity::ReactivationFunction(){ 
  return false;
}

double RepairSAN::RepairSystemActivity::SampleDistribution(){
  return 0;
}

double* RepairSAN::RepairSystemActivity::ReturnDistributionParameters(){
    return NULL;
}

int RepairSAN::RepairSystemActivity::Rank(){
  return 1;
}

BaseActionClass* RepairSAN::RepairSystemActivity::Fire(){
  ;
  (*(SystemFailure_Mobius_Mark))--;
  (*(Repair_Mobius_Mark))++;
  return this;
}

/*======================failureActivity========================*/


RepairSAN::failureActivity::failureActivity(){
  ActivityInitialize("failure",8,Instantaneous , RaceEnabled, 2,1, false);
}

void RepairSAN::failureActivity::LinkVariables(){
  SystemFailure->Register(&SystemFailure_Mobius_Mark);
  Failure->Register(&Failure_Mobius_Mark);
}

bool RepairSAN::failureActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(SystemFailure_Mobius_Mark)) >=1));
  return NewEnabled;
}

double RepairSAN::failureActivity::Weight(){ 
  return 1;
}

bool RepairSAN::failureActivity::ReactivationPredicate(){ 
  return false;
}

bool RepairSAN::failureActivity::ReactivationFunction(){ 
  return false;
}

double RepairSAN::failureActivity::SampleDistribution(){
  return 0;
}

double* RepairSAN::failureActivity::ReturnDistributionParameters(){
    return NULL;
}

int RepairSAN::failureActivity::Rank(){
  return 1;
}

BaseActionClass* RepairSAN::failureActivity::Fire(){
  (*(SystemFailure_Mobius_Mark))--;
  (*(Failure_Mobius_Mark))++;
  return this;
}

/*======================FailAActivity========================*/

RepairSAN::FailAActivity::FailAActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("FailA",0,Exponential, RaceEnabled, 3,2, false);
}

RepairSAN::FailAActivity::~FailAActivity(){
  delete[] TheDistributionParameters;
}

void RepairSAN::FailAActivity::LinkVariables(){
  PlaceA->Register(&PlaceA_Mobius_Mark);
  SystemActive->Register(&SystemActive_Mobius_Mark);
  FailedA->Register(&FailedA_Mobius_Mark);
  SystemFailure->Register(&SystemFailure_Mobius_Mark);
}

bool RepairSAN::FailAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PlaceA_Mobius_Mark)) >=1)&&(SystemActive -> Mark() == 1));
  return NewEnabled;
}

double RepairSAN::FailAActivity::Rate(){
  return lambda*(PlaceA->Mark())/4.0 ;
  return 1.0;  // default rate if none is specified
}

double RepairSAN::FailAActivity::Weight(){ 
  return 1;
}

bool RepairSAN::FailAActivity::ReactivationPredicate(){ 
  return false;
}

bool RepairSAN::FailAActivity::ReactivationFunction(){ 
  return false;
}

double RepairSAN::FailAActivity::SampleDistribution(){
  return TheDistribution->Exponential(lambda*(PlaceA->Mark())/4.0 );
}

double* RepairSAN::FailAActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int RepairSAN::FailAActivity::Rank(){
  return 1;
}

BaseActionClass* RepairSAN::FailAActivity::Fire(){
  ;
  (*(PlaceA_Mobius_Mark))--;
  (*(FailedA_Mobius_Mark))++;
  (*(SystemFailure_Mobius_Mark))++;
  return this;
}

/*======================FailBActivity========================*/

RepairSAN::FailBActivity::FailBActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("FailB",1,Exponential, RaceEnabled, 3,2, false);
}

RepairSAN::FailBActivity::~FailBActivity(){
  delete[] TheDistributionParameters;
}

void RepairSAN::FailBActivity::LinkVariables(){
  PlaceB->Register(&PlaceB_Mobius_Mark);
  SystemActive->Register(&SystemActive_Mobius_Mark);
  FailedB->Register(&FailedB_Mobius_Mark);
  FailedBC->Register(&FailedBC_Mobius_Mark);
}

bool RepairSAN::FailBActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PlaceB_Mobius_Mark)) >=1)&&(SystemActive -> Mark() == 1));
  return NewEnabled;
}

double RepairSAN::FailBActivity::Rate(){
  return lambda*(PlaceB->Mark())/2.0;
  return 1.0;  // default rate if none is specified
}

double RepairSAN::FailBActivity::Weight(){ 
  return 1;
}

bool RepairSAN::FailBActivity::ReactivationPredicate(){ 
  return false;
}

bool RepairSAN::FailBActivity::ReactivationFunction(){ 
  return false;
}

double RepairSAN::FailBActivity::SampleDistribution(){
  return TheDistribution->Exponential(lambda*(PlaceB->Mark())/2.0);
}

double* RepairSAN::FailBActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int RepairSAN::FailBActivity::Rank(){
  return 1;
}

BaseActionClass* RepairSAN::FailBActivity::Fire(){
  ;
  (*(PlaceB_Mobius_Mark))--;
  (*(FailedB_Mobius_Mark))++;
  (*(FailedBC_Mobius_Mark))++;
  return this;
}

/*======================FailCActivity========================*/

RepairSAN::FailCActivity::FailCActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("FailC",2,Exponential, RaceEnabled, 3,2, false);
}

RepairSAN::FailCActivity::~FailCActivity(){
  delete[] TheDistributionParameters;
}

void RepairSAN::FailCActivity::LinkVariables(){
  PlaceC->Register(&PlaceC_Mobius_Mark);
  SystemActive->Register(&SystemActive_Mobius_Mark);
  FailedC->Register(&FailedC_Mobius_Mark);
  FailedBC->Register(&FailedBC_Mobius_Mark);
}

bool RepairSAN::FailCActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(PlaceC_Mobius_Mark)) >=1)&&(SystemActive -> Mark() == 1));
  return NewEnabled;
}

double RepairSAN::FailCActivity::Rate(){
  return lambda*(PlaceC->Mark());
  return 1.0;  // default rate if none is specified
}

double RepairSAN::FailCActivity::Weight(){ 
  return 1;
}

bool RepairSAN::FailCActivity::ReactivationPredicate(){ 
  return false;
}

bool RepairSAN::FailCActivity::ReactivationFunction(){ 
  return false;
}

double RepairSAN::FailCActivity::SampleDistribution(){
  return TheDistribution->Exponential(lambda*(PlaceC->Mark()));
}

double* RepairSAN::FailCActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int RepairSAN::FailCActivity::Rank(){
  return 1;
}

BaseActionClass* RepairSAN::FailCActivity::Fire(){
  ;
  (*(PlaceC_Mobius_Mark))--;
  (*(FailedC_Mobius_Mark))++;
  (*(FailedBC_Mobius_Mark))++;
  return this;
}

/*======================RepairAActivity========================*/

RepairSAN::RepairAActivity::RepairAActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("RepairA",3,Exponential, RaceEnabled, 3,2, false);
}

RepairSAN::RepairAActivity::~RepairAActivity(){
  delete[] TheDistributionParameters;
}

void RepairSAN::RepairAActivity::LinkVariables(){
  Repair->Register(&Repair_Mobius_Mark);
  FailedA->Register(&FailedA_Mobius_Mark);
  PlaceA->Register(&PlaceA_Mobius_Mark);
}

bool RepairSAN::RepairAActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(Repair_Mobius_Mark)) >=1)&&((FailedA -> Mark() == 1)));
  return NewEnabled;
}

double RepairSAN::RepairAActivity::Rate(){
  return mu/4;
  return 1.0;  // default rate if none is specified
}

double RepairSAN::RepairAActivity::Weight(){ 
  return 1;
}

bool RepairSAN::RepairAActivity::ReactivationPredicate(){ 
  return false;
}

bool RepairSAN::RepairAActivity::ReactivationFunction(){ 
  return false;
}

double RepairSAN::RepairAActivity::SampleDistribution(){
  return TheDistribution->Exponential(mu/4);
}

double* RepairSAN::RepairAActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int RepairSAN::RepairAActivity::Rank(){
  return 1;
}

BaseActionClass* RepairSAN::RepairAActivity::Fire(){
  FailedA-> Mark()-- && PlaceA -> Mark()==1;
  (*(Repair_Mobius_Mark))--;
  (*(PlaceA_Mobius_Mark))++;
  return this;
}

/*======================RepairBActivity========================*/

RepairSAN::RepairBActivity::RepairBActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("RepairB",4,Exponential, RaceEnabled, 3,3, false);
}

RepairSAN::RepairBActivity::~RepairBActivity(){
  delete[] TheDistributionParameters;
}

void RepairSAN::RepairBActivity::LinkVariables(){
  Repair->Register(&Repair_Mobius_Mark);
  PlaceA->Register(&PlaceA_Mobius_Mark);
  FailedB->Register(&FailedB_Mobius_Mark);
  PlaceB->Register(&PlaceB_Mobius_Mark);
}

bool RepairSAN::RepairBActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(Repair_Mobius_Mark)) >=1)&&((FailedB -> Mark() == 1) && (PlaceA -> Mark()== 1)));
  return NewEnabled;
}

double RepairSAN::RepairBActivity::Rate(){
  return mu/2;
  return 1.0;  // default rate if none is specified
}

double RepairSAN::RepairBActivity::Weight(){ 
  return 1;
}

bool RepairSAN::RepairBActivity::ReactivationPredicate(){ 
  return false;
}

bool RepairSAN::RepairBActivity::ReactivationFunction(){ 
  return false;
}

double RepairSAN::RepairBActivity::SampleDistribution(){
  return TheDistribution->Exponential(mu/2);
}

double* RepairSAN::RepairBActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int RepairSAN::RepairBActivity::Rank(){
  return 1;
}

BaseActionClass* RepairSAN::RepairBActivity::Fire(){
  FailedB-> Mark()-- && PlaceB -> Mark()==2;
  (*(Repair_Mobius_Mark))--;
  (*(PlaceB_Mobius_Mark))++;
  return this;
}

/*======================RepairCActivity========================*/

RepairSAN::RepairCActivity::RepairCActivity(){
  TheDistributionParameters = new double[1];
  ActivityInitialize("RepairC",5,Exponential, RaceEnabled, 3,4, false);
}

RepairSAN::RepairCActivity::~RepairCActivity(){
  delete[] TheDistributionParameters;
}

void RepairSAN::RepairCActivity::LinkVariables(){
  Repair->Register(&Repair_Mobius_Mark);
  PlaceA->Register(&PlaceA_Mobius_Mark);
  PlaceB->Register(&PlaceB_Mobius_Mark);
  FailedC->Register(&FailedC_Mobius_Mark);
  PlaceC->Register(&PlaceC_Mobius_Mark);
}

bool RepairSAN::RepairCActivity::Enabled(){
  OldEnabled=NewEnabled;
  NewEnabled=(((*(Repair_Mobius_Mark)) >=1)&&((FailedC -> Mark() == 1) && (PlaceA -> Mark()== 1) && (PlaceB -> Mark()== 2)));
  return NewEnabled;
}

double RepairSAN::RepairCActivity::Rate(){
  return mu;
  return 1.0;  // default rate if none is specified
}

double RepairSAN::RepairCActivity::Weight(){ 
  return 1;
}

bool RepairSAN::RepairCActivity::ReactivationPredicate(){ 
  return false;
}

bool RepairSAN::RepairCActivity::ReactivationFunction(){ 
  return false;
}

double RepairSAN::RepairCActivity::SampleDistribution(){
  return TheDistribution->Exponential(mu);
}

double* RepairSAN::RepairCActivity::ReturnDistributionParameters(){
  TheDistributionParameters[0] = Rate();
  return TheDistributionParameters;
}

int RepairSAN::RepairCActivity::Rank(){
  return 1;
}

BaseActionClass* RepairSAN::RepairCActivity::Fire(){
  FailedC-> Mark()-- && PlaceC -> Mark()==3;
  (*(Repair_Mobius_Mark))--;
  (*(PlaceC_Mobius_Mark))++;
  return this;
}

