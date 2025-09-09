#include "RWPVNodes.h"

RWPV0Worker::RWPV0Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Repair);
}

RWPV0Worker::~RWPV0Worker() {
  delete [] TheModelPtr;
}

double RWPV0Worker::Reward_Function(void) {

if(Repair->SystemActive-> Mark()>0) return 1;

return (0);



}

RWPV0::RWPV0(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheRepairSAN);
  double startpts[1]={0.0};
  double stoppts[1]={0.0+1.0};
  Initialize("Availability",(RewardType)3,1, startpts, stoppts, timeindex, 0,1, 1);
  Type = steady_state;
  AddVariableDependency("SystemActive","Repair");
}

RWPV0::~RWPV0() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RWPV0::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RWPV0Worker;
}
RWPV1Worker::RWPV1Worker()
{
  NumModels = 1;
  TheModelPtr = new BaseModelClass**[NumModels];
  TheModelPtr[0] = (BaseModelClass**)(&Repair);
}

RWPV1Worker::~RWPV1Worker() {
  delete [] TheModelPtr;
}

double RWPV1Worker::Reward_Function(void) {

if (1>Repair->Failure->Mark())return 1;

return (0);



}

RWPV1::RWPV1(int timeindex) {
  TheModelPtr = (BaseModelClass**)(&TheRepairSAN);
  double startpts[6]={32, 280, 1200, 2480, 5240, 10520};
  double stoppts[6]={32, 280, 1200, 2480, 5240, 10520};
  Initialize("Relaibility",(RewardType)0,6, startpts, stoppts, timeindex, 0,1, 1);
  AddVariableDependency("Failure","Repair");
}

RWPV1::~RWPV1() {
  for(int i = 0; i < NumberOfWorkers; i++) {
    delete[] WorkerList[i]->Name;
    delete WorkerList[i];
  }
}

void RWPV1::CreateWorkerList(void) {
  for(int i = 0; i < NumberOfWorkers; i++)
    WorkerList[i] = new RWPV1Worker;
}
