#ifndef _RW_PVS_
#define _RW_PVS_
#include <math.h>
#include "Cpp/Performance_Variables/PerformanceVariableNode.hpp"
#include "Atomic/Repair/RepairSAN.h"
#include "Cpp/Performance_Variables/SteadyState.hpp"
#include "Cpp/Performance_Variables/InstantOfTime.hpp"


class RWPV0Worker:public SteadyState
{
 public:
  RepairSAN *Repair;
  
  RWPV0Worker();
  ~RWPV0Worker();
  double Reward_Function();
};

class RWPV0:public PerformanceVariableNode
{
 public:
  RepairSAN *TheRepairSAN;

  RWPV0Worker *RWPV0WorkerList;

  RWPV0(int timeindex=0);
  ~RWPV0();
  void CreateWorkerList(void);
};

class RWPV1Worker:public InstantOfTime
{
 public:
  RepairSAN *Repair;
  
  RWPV1Worker();
  ~RWPV1Worker();
  double Reward_Function();
};

class RWPV1:public PerformanceVariableNode
{
 public:
  RepairSAN *TheRepairSAN;

  RWPV1Worker *RWPV1WorkerList;

  RWPV1(int timeindex=0);
  ~RWPV1();
  void CreateWorkerList(void);
};

#endif
