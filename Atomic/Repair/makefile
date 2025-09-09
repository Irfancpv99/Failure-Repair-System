OBJS=RepairSAN.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libRepairSAN.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libRepairSAN_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libRepairSAN.a: FORCE
	$(MAKE) lib TARGET=libRepairSAN.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libRepairSAN_debug.a: FORCE
	$(MAKE) lib TARGET=libRepairSAN_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

