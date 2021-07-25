##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lec52_TupleReturn
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/vsevolod/GIT/GitHub/CppLectures
ProjectPath            :=/home/vsevolod/GIT/GitHub/CppLectures/Lec52_TupleReturn
IntermediateDirectory  :=../build-$(ConfigurationName)/Lec52_TupleReturn
OutDir                 :=../build-$(ConfigurationName)/Lec52_TupleReturn
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=vsevolod
Date                   :=25/07/21
CodeLitePath           :=/home/vsevolod/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/Lec52_TupleReturn/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Lec52_TupleReturn/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Lec52_TupleReturn"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Lec52_TupleReturn"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Lec52_TupleReturn/.d:
	@mkdir -p "../build-$(ConfigurationName)/Lec52_TupleReturn"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Lec52_TupleReturn/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Lec52_TupleReturn/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/vsevolod/GIT/GitHub/CppLectures/Lec52_TupleReturn/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lec52_TupleReturn/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lec52_TupleReturn/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lec52_TupleReturn/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Lec52_TupleReturn/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lec52_TupleReturn/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/Lec52_TupleReturn//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


