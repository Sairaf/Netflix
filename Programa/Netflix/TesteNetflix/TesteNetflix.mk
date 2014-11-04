##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=TesteNetflix
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\PROPESPINFO\Documents\GitHub\Netflix\Programa\Netflix"
ProjectPath            := "C:\Users\PROPESPINFO\Documents\GitHub\Netflix\Programa\Netflix\TesteNetflix"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=PROPESPINFO
Date                   :=11/04/14
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=C:/MinGW-4.8.1/bin/g++.exe 
SharedObjectLinkerName :=C:/MinGW-4.8.1/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="TesteNetflix.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW-4.8.1/bin/windres.exe 
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
AR       := C:/MinGW-4.8.1/bin/ar.exe rcu
CXX      := C:/MinGW-4.8.1/bin/g++.exe 
CC       := C:/MinGW-4.8.1/bin/gcc.exe 
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW-4.8.1/bin/as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Netflix_Usuario.cpp$(ObjectSuffix) $(IntermediateDirectory)/Netflix_Netflix.cpp$(ObjectSuffix) $(IntermediateDirectory)/Netflix_Filme.cpp$(ObjectSuffix) $(IntermediateDirectory)/ServicoInternet.cpp$(ObjectSuffix) $(IntermediateDirectory)/Netflix_Data.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/PROPESPINFO/Documents/GitHub/Netflix/Programa/Netflix/TesteNetflix/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Netflix_Usuario.cpp$(ObjectSuffix): ../Netflix/Usuario.cpp $(IntermediateDirectory)/Netflix_Usuario.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/PROPESPINFO/Documents/GitHub/Netflix/Programa/Netflix/Netflix/Usuario.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Netflix_Usuario.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Netflix_Usuario.cpp$(DependSuffix): ../Netflix/Usuario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Netflix_Usuario.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Netflix_Usuario.cpp$(DependSuffix) -MM "../Netflix/Usuario.cpp"

$(IntermediateDirectory)/Netflix_Usuario.cpp$(PreprocessSuffix): ../Netflix/Usuario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Netflix_Usuario.cpp$(PreprocessSuffix) "../Netflix/Usuario.cpp"

$(IntermediateDirectory)/Netflix_Netflix.cpp$(ObjectSuffix): ../Netflix/Netflix.cpp $(IntermediateDirectory)/Netflix_Netflix.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/PROPESPINFO/Documents/GitHub/Netflix/Programa/Netflix/Netflix/Netflix.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Netflix_Netflix.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Netflix_Netflix.cpp$(DependSuffix): ../Netflix/Netflix.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Netflix_Netflix.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Netflix_Netflix.cpp$(DependSuffix) -MM "../Netflix/Netflix.cpp"

$(IntermediateDirectory)/Netflix_Netflix.cpp$(PreprocessSuffix): ../Netflix/Netflix.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Netflix_Netflix.cpp$(PreprocessSuffix) "../Netflix/Netflix.cpp"

$(IntermediateDirectory)/Netflix_Filme.cpp$(ObjectSuffix): ../Netflix/Filme.cpp $(IntermediateDirectory)/Netflix_Filme.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/PROPESPINFO/Documents/GitHub/Netflix/Programa/Netflix/Netflix/Filme.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Netflix_Filme.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Netflix_Filme.cpp$(DependSuffix): ../Netflix/Filme.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Netflix_Filme.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Netflix_Filme.cpp$(DependSuffix) -MM "../Netflix/Filme.cpp"

$(IntermediateDirectory)/Netflix_Filme.cpp$(PreprocessSuffix): ../Netflix/Filme.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Netflix_Filme.cpp$(PreprocessSuffix) "../Netflix/Filme.cpp"

$(IntermediateDirectory)/ServicoInternet.cpp$(ObjectSuffix): ServicoInternet.cpp $(IntermediateDirectory)/ServicoInternet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/PROPESPINFO/Documents/GitHub/Netflix/Programa/Netflix/TesteNetflix/ServicoInternet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ServicoInternet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ServicoInternet.cpp$(DependSuffix): ServicoInternet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ServicoInternet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ServicoInternet.cpp$(DependSuffix) -MM "ServicoInternet.cpp"

$(IntermediateDirectory)/ServicoInternet.cpp$(PreprocessSuffix): ServicoInternet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ServicoInternet.cpp$(PreprocessSuffix) "ServicoInternet.cpp"

$(IntermediateDirectory)/Netflix_Data.cpp$(ObjectSuffix): ../Netflix/Data.cpp $(IntermediateDirectory)/Netflix_Data.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/PROPESPINFO/Documents/GitHub/Netflix/Programa/Netflix/Netflix/Data.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Netflix_Data.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Netflix_Data.cpp$(DependSuffix): ../Netflix/Data.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Netflix_Data.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Netflix_Data.cpp$(DependSuffix) -MM "../Netflix/Data.cpp"

$(IntermediateDirectory)/Netflix_Data.cpp$(PreprocessSuffix): ../Netflix/Data.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Netflix_Data.cpp$(PreprocessSuffix) "../Netflix/Data.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/TesteNetflix"


