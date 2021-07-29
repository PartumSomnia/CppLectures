##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Lec72_PrecompHeaders
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/vsevolod/GIT/GitHub/CppLectures
ProjectPath            :=/home/vsevolod/GIT/GitHub/CppLectures/Lec72_PrecompHeaders
IntermediateDirectory  :=../build-$(ConfigurationName)/Lec72_PrecompHeaders
OutDir                 :=../build-$(ConfigurationName)/Lec72_PrecompHeaders
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=vsevolod
Date                   :=29/07/21
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
IncludePCH             :=  -include /home/vsevolod/GIT/GitHub/CppLectures/Lec72_PrecompHeaders/pch.h 
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
Objects0=../build-$(ConfigurationName)/Lec72_PrecompHeaders/pch.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/Lec72_PrecompHeaders/main.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Lec72_PrecompHeaders/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Lec72_PrecompHeaders"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Lec72_PrecompHeaders"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Lec72_PrecompHeaders/.d:
	@mkdir -p "../build-$(ConfigurationName)/Lec72_PrecompHeaders"

PreBuild:

# PreCompiled Header
/home/vsevolod/GIT/GitHub/CppLectures/Lec72_PrecompHeaders/pch.h.gch: /home/vsevolod/GIT/GitHub/CppLectures/Lec72_PrecompHeaders/pch.h
	$(CXX) $(SourceSwitch) /home/vsevolod/GIT/GitHub/CppLectures/Lec72_PrecompHeaders/pch.h $(PCHCompileFlags) $(CXXFLAGS) $(IncludePath)



##
## Objects
##
../build-$(ConfigurationName)/Lec72_PrecompHeaders/pch.cpp$(ObjectSuffix): pch.cpp ../build-$(ConfigurationName)/Lec72_PrecompHeaders/pch.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/vsevolod/GIT/GitHub/CppLectures/Lec72_PrecompHeaders/pch.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pch.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lec72_PrecompHeaders/pch.cpp$(DependSuffix): pch.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lec72_PrecompHeaders/pch.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lec72_PrecompHeaders/pch.cpp$(DependSuffix) -MM pch.cpp

../build-$(ConfigurationName)/Lec72_PrecompHeaders/pch.cpp$(PreprocessSuffix): pch.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lec72_PrecompHeaders/pch.cpp$(PreprocessSuffix) pch.cpp

../build-$(ConfigurationName)/Lec72_PrecompHeaders/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/Lec72_PrecompHeaders/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/vsevolod/GIT/GitHub/CppLectures/Lec72_PrecompHeaders/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Lec72_PrecompHeaders/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Lec72_PrecompHeaders/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/Lec72_PrecompHeaders/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/Lec72_PrecompHeaders/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Lec72_PrecompHeaders/main.cpp$(PreprocessSuffix) main.cpp


-include ../build-$(ConfigurationName)/Lec72_PrecompHeaders//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)
	$(RM) /home/vsevolod/GIT/GitHub/CppLectures/Lec72_PrecompHeaders/pch.h.gch


