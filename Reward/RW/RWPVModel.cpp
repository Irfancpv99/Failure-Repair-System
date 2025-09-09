#include "RWPVModel.h"

RWPVModel::RWPVModel(bool expandTimeArrays) {
  TheModel=new RepairSAN();
  DefineName("RWPVModel");
  CreatePVList(2, expandTimeArrays);
  Initialize();
}



PerformanceVariableNode* RWPVModel::createPVNode(int pvindex, int timeindex) {
  switch(pvindex) {
  case 0:
    return new RWPV0(timeindex);
    break;
  case 1:
    return new RWPV1(timeindex);
    break;
  }
  return NULL;
}
