#ifndef RepairSAN_H_
#define RepairSAN_H_

#include "Cpp/BaseClasses/EmptyGroup.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/BaseClasses/PreselectGroup.h"
#include "Cpp/BaseClasses/PostselectGroup.h"
#include "Cpp/BaseClasses/state/StructStateVariable.h"
#include "Cpp/BaseClasses/state/ArrayStateVariable.h"
#include "Cpp/BaseClasses/SAN/SANModel.h" 
#include "Cpp/BaseClasses/SAN/Place.h"
#include "Cpp/BaseClasses/SAN/ExtendedPlace.h"
extern Double lambda;
extern Double mu;
extern UserDistributions* TheDistribution;

void MemoryError();


/*********************************************************************
               RepairSAN Submodel Definition                   
*********************************************************************/

class RepairSAN:public SANModel{
public:

class FailedB_CActivity:public Activity {
public:

  Place* FailedBC;
  short* FailedBC_Mobius_Mark;
  Place* SystemFailure;
  short* SystemFailure_Mobius_Mark;

  double* TheDistributionParameters;
  FailedB_CActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // FailedB_CActivityActivity

class RepairSystemActivity:public Activity {
public:

  Place* SystemFailure;
  short* SystemFailure_Mobius_Mark;
  Place* Failure;
  short* Failure_Mobius_Mark;
  Place* FailedA;
  short* FailedA_Mobius_Mark;
  Place* FailedBC;
  short* FailedBC_Mobius_Mark;
  Place* Repair;
  short* Repair_Mobius_Mark;

  double* TheDistributionParameters;
  RepairSystemActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // RepairSystemActivityActivity

class failureActivity:public Activity {
public:

  Place* SystemFailure;
  short* SystemFailure_Mobius_Mark;
  Place* Failure;
  short* Failure_Mobius_Mark;

  double* TheDistributionParameters;
  failureActivity();
  double Rate(){return 0;}
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
}; // failureActivityActivity

class FailAActivity:public Activity {
public:

  Place* PlaceA;
  short* PlaceA_Mobius_Mark;
  Place* SystemActive;
  short* SystemActive_Mobius_Mark;
  Place* FailedA;
  short* FailedA_Mobius_Mark;
  Place* SystemFailure;
  short* SystemFailure_Mobius_Mark;

  double* TheDistributionParameters;
  FailAActivity();
  ~FailAActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // FailAActivityActivity

class FailBActivity:public Activity {
public:

  Place* PlaceB;
  short* PlaceB_Mobius_Mark;
  Place* SystemActive;
  short* SystemActive_Mobius_Mark;
  Place* FailedB;
  short* FailedB_Mobius_Mark;
  Place* FailedBC;
  short* FailedBC_Mobius_Mark;

  double* TheDistributionParameters;
  FailBActivity();
  ~FailBActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // FailBActivityActivity

class FailCActivity:public Activity {
public:

  Place* PlaceC;
  short* PlaceC_Mobius_Mark;
  Place* SystemActive;
  short* SystemActive_Mobius_Mark;
  Place* FailedC;
  short* FailedC_Mobius_Mark;
  Place* FailedBC;
  short* FailedBC_Mobius_Mark;

  double* TheDistributionParameters;
  FailCActivity();
  ~FailCActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // FailCActivityActivity

class RepairAActivity:public Activity {
public:

  Place* Repair;
  short* Repair_Mobius_Mark;
  Place* FailedA;
  short* FailedA_Mobius_Mark;
  Place* PlaceA;
  short* PlaceA_Mobius_Mark;

  double* TheDistributionParameters;
  RepairAActivity();
  ~RepairAActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // RepairAActivityActivity

class RepairBActivity:public Activity {
public:

  Place* Repair;
  short* Repair_Mobius_Mark;
  Place* PlaceA;
  short* PlaceA_Mobius_Mark;
  Place* FailedB;
  short* FailedB_Mobius_Mark;
  Place* PlaceB;
  short* PlaceB_Mobius_Mark;

  double* TheDistributionParameters;
  RepairBActivity();
  ~RepairBActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // RepairBActivityActivity

class RepairCActivity:public Activity {
public:

  Place* Repair;
  short* Repair_Mobius_Mark;
  Place* PlaceA;
  short* PlaceA_Mobius_Mark;
  Place* PlaceB;
  short* PlaceB_Mobius_Mark;
  Place* FailedC;
  short* FailedC_Mobius_Mark;
  Place* PlaceC;
  short* PlaceC_Mobius_Mark;

  double* TheDistributionParameters;
  RepairCActivity();
  ~RepairCActivity();
  bool Enabled();
  void LinkVariables();
  double Weight();
  bool ReactivationPredicate();
  bool ReactivationFunction();
  double SampleDistribution();
  double* ReturnDistributionParameters();
  int Rank();
  BaseActionClass* Fire();
  double Rate();
}; // RepairCActivityActivity

  //List of user-specified place names
  Place* PlaceA;
  Place* PlaceB;
  Place* PlaceC;
  Place* FailedA;
  Place* FailedB;
  Place* FailedC;
  Place* Repair;
  Place* SystemFailure;
  Place* FailedBC;
  Place* Failure;
  Place* SystemActive;

  // Create instances of all actvities
  FailedB_CActivity FailedB_C;
  RepairSystemActivity RepairSystem;
  failureActivity failure;
  FailAActivity FailA;
  FailBActivity FailB;
  FailCActivity FailC;
  RepairAActivity RepairA;
  RepairBActivity RepairB;
  RepairCActivity RepairC;
  //Create instances of all groups 
  PreselectGroup ImmediateGroup;
  PostselectGroup FailedB_CGroup;
  PostselectGroup RepairSystemGroup;
  PostselectGroup failureGroup;

  RepairSAN();
  ~RepairSAN();
  void CustomInitialization();

  void assignPlacesToActivitiesInst();
  void assignPlacesToActivitiesTimed();
}; // end RepairSAN

#endif // RepairSAN_H_
