##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lec6_HowCompilerWorks
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/vsevolod/CodeLight/test1
ProjectPath            :=/home/vsevolod/CodeLight/test1/Lec6_HowCompilerWorks
IntermediateDirectory  :=../build-$(ConfigurationName)/Lec6_HowCompilerWorks
OutDir                 :=../build-$(ConfigurationName)/Lec6_HowCompilerWorks
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=vsevolod
Date                   :=16/07/21
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
Objects0=../build-$(ConfigurationName)/Lec6_HowCompilerWorks/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Lec6_HowCompilerWorks/math.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Lec6_HowCompilerWorks/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Lec6_HowCompilerWorks"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Lec6_HowCompilerWorks"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Lec6_HowCompilerWorks/.d:
	@mkdir -p "../build-$(ConfigurationName)/Lec6_HowCompilerWorks"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Lec6_HowCompilerWorks/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Lec6_HowCompilerWorks/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/vsevolod/CodeLight/test1/Lec6_HowCompilerWorks/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lec6_HowCompilerWorks/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lec6_HowCompilerWorks/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lec6_HowCompilerWorks/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Lec6_HowCompilerWorks/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lec6_HowCompilerWorks/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/Lec6_HowCompilerWorks/math.cpp$(ObjectSuffix): math.cpp ../build-$(ConfigurationName)/Lec6_HowCompilerWorks/math.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/vsevolod/CodeLight/test1/Lec6_HowCompilerWorks/math.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/math.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lec6_HowCompilerWorks/math.cpp$(DependSuffix): math.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lec6_HowCompilerWorks/math.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lec6_HowCompilerWorks/math.cpp$(DependSuffix) -MM math.cpp

../build-$(ConfigurationName)/Lec6_HowCompilerWorks/math.cpp$(PreprocessSuffix): math.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lec6_HowCompilerWorks/math.cpp$(PreprocessSuffix) math.cpp


-include ../build-$(ConfigurationName)/Lec6_HowCompilerWorks//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


