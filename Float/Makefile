# Makefile for BP codes Created by Mark Van der Merwe based on Makefile shown here: https://gist.github.com/yzhwang/5120437

CC			=	g++
LD			=	g++
EXE			:= 	${SRC:.cpp=.out}
CU_SRCS			:= 	Representation/pgm.cpp Representation/graph.cpp Inference/serial_inference_helpers.cpp Tests/test_helpers.cpp Tests/time_tests_helpers.cpp $(SRC)
CU_OBJS			:=	Representation/pgm.o Representation/graph.o Inference/serial_inference_helpers.o Tests/test_helpers.o Tests/time_tests_helpers.o ${SRC:.cpp=.o}

ifeq ($(INFER), loopy)
CU_SRCS			+= 	Inference/serial_loopy_belief_propagation.cpp
CU_OBJS			+=	Inference/serial_loopy_belief_propagation.o
endif
ifeq ($(INFER), rbp)
CU_SRCS			+=	Inference/serial_residual_belief_propagation.cpp
CU_OBJS			+=	Inference/serial_residual_belief_propagation.o
endif
ifeq ($(INFER), ve)
CU_SRCS			+= 	Inference/variable_elimination.cpp
CU_OBJS			+=	Inference/variable_elimination.o
endif

OBJS			:=	$(CU_OBJS)

# include directories
INC_DIRS	:=	$(BOOST_INC)

# library directories
LIB_DIRS	:= 	$(BOOST_LIB)

# libraries
LIBS		:=	

CCFLAGS		+=	--std=c++14 -g -Wall $(foreach includedir, $(INC_DIRS), -I $(includedir))
LDFLAGS         +=      -lboost_system -lboost_filesystem -ldl -g $(foreach includedir, $(INC_DIRS), -I $(includedir))
LDFLAGS		+=	$(foreach librarydir, $(LIB_DIRS), -L $(librarydir))
LDFLAGS		+=	$(foreach library, $(LIBS), -l$(library))

.PHONY:		all clean distclean

$(EXE): $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXE)

.cpp.o:
	$(CC) $(CCFLAGS) $< -o $@

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	rm -vf $(EXE) $(OBJS)
	rm *.out *.o
	rm Inference/*.o

