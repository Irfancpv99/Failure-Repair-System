OBJS=RWPVNodes.o RWPVModel.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libRWPV.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libRWPV_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libRWPV.a: FORCE
	$(MAKE) lib TARGET=libRWPV.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libRWPV_debug.a: FORCE
	$(MAKE) lib TARGET=libRWPV_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

