#ifndef _RW_PVMODEL_
#define _RW_PVMODEL_
#include "RWPVNodes.h"
#include "Cpp/Performance_Variables/PVModel.hpp"
#include "Atomic/Repair/RepairSAN.h"
class RWPVModel:public PVModel {
 protected:
  PerformanceVariableNode *createPVNode(int pvindex, int timeindex);
 public:
  RWPVModel(bool expandtimepoints);
};

#endif
