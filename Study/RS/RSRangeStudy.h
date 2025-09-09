
#ifndef RSRangeSTUDY_H_
#define RSRangeSTUDY_H_

#include "Reward/RW/RWPVNodes.h"
#include "Reward/RW/RWPVModel.h"
#include "Cpp/BaseClasses/GlobalVariables.h"
#include "Cpp/Study/BaseStudyClass.hpp"

extern Double lambda;
extern Double mu;

class RSRangeStudy : public BaseStudyClass {
public:

RSRangeStudy();
~RSRangeStudy();

private:

double *lambdaValues;
double *muValues;

void SetValues_lambda();
void SetValues_mu();

void PrintGlobalValues(int);
void *GetGVValue(char *TheGVName);
void OverrideGVValue(char *TheGVName, void *TheGVValue);
void SetGVs(int expnum);
PVModel *GetPVModel(bool expandTimeArrays);
};

#endif

