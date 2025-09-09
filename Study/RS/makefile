OBJS=RSRangeStudy.o 


#include common Makefile for default targets
include ../../Makefile.project
include $(MOBIUSROOT)/Cpp/BaseClasses/Makefile.common

all: normal
opt: $(ROOTDIR)/lib/$(PLATFORM)/libRSRangeStudy.a
normal debug trace: $(ROOTDIR)/lib/$(PLATFORM)/libRSRangeStudy_debug.a

$(ROOTDIR)/lib/$(PLATFORM)/libRSRangeStudy.a: FORCE
	$(MAKE) lib TARGET=libRSRangeStudy.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="" ROOTLIBDIR="."

$(ROOTDIR)/lib/$(PLATFORM)/libRSRangeStudy_debug.a: FORCE
	$(MAKE) lib TARGET=libRSRangeStudy_debug.a OBJS="$(OBJS)" USERINCLUDE="$(USERINCLUDE)" TYPE="_debug" ROOTLIBDIR="."

clean_sub_dirs:

