##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Netflix
ConfigurationName      :=Debug
WorkspacePath          := "G:\Abner\Programacao\Programasfeitos\ProjetosGiteye\Netflix\Programa\Netflix"
ProjectPath            := "G:\Abner\Programacao\Programasfeitos\ProjetosGiteye\Netflix\Programa\Netflix\Netflix"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=ABGerson
Date                   :=10/04/14
CodeLitePath           :="C:\Program Files\CodeLite"
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
ObjectsFileList        :="Netflix.txt"
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
CodeLiteDir:=C:\Program Files\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Data.cpp$(ObjectSuffix) $(IntermediateDirectory)/Filme.cpp$(ObjectSuffix) $(IntermediateDirectory)/Usuario.cpp$(ObjectSuffix) $(IntermediateDirectory)/Netflix.cpp$(ObjectSuffix) 



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
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Abner/Programacao/Programasfeitos/ProjetosGiteye/Netflix/Programa/Netflix/Netflix/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Data.cpp$(ObjectSuffix): Data.cpp $(IntermediateDirectory)/Data.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Abner/Programacao/Programasfeitos/ProjetosGiteye/Netflix/Programa/Netflix/Netflix/Data.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Data.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Data.cpp$(DependSuffix): Data.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Data.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Data.cpp$(DependSuffix) -MM "Data.cpp"

$(IntermediateDirectory)/Data.cpp$(PreprocessSuffix): Data.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Data.cpp$(PreprocessSuffix) "Data.cpp"

$(IntermediateDirectory)/Filme.cpp$(ObjectSuffix): Filme.cpp $(IntermediateDirectory)/Filme.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Abner/Programacao/Programasfeitos/ProjetosGiteye/Netflix/Programa/Netflix/Netflix/Filme.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Filme.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Filme.cpp$(DependSuffix): Filme.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Filme.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Filme.cpp$(DependSuffix) -MM "Filme.cpp"

$(IntermediateDirectory)/Filme.cpp$(PreprocessSuffix): Filme.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Filme.cpp$(PreprocessSuffix) "Filme.cpp"

$(IntermediateDirectory)/Usuario.cpp$(ObjectSuffix): Usuario.cpp $(IntermediateDirectory)/Usuario.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Abner/Programacao/Programasfeitos/ProjetosGiteye/Netflix/Programa/Netflix/Netflix/Usuario.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Usuario.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Usuario.cpp$(DependSuffix): Usuario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Usuario.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Usuario.cpp$(DependSuffix) -MM "Usuario.cpp"

$(IntermediateDirectory)/Usuario.cpp$(PreprocessSuffix): Usuario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Usuario.cpp$(PreprocessSuffix) "Usuario.cpp"

$(IntermediateDirectory)/Netflix.cpp$(ObjectSuffix): Netflix.cpp $(IntermediateDirectory)/Netflix.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "G:/Abner/Programacao/Programasfeitos/ProjetosGiteye/Netflix/Programa/Netflix/Netflix/Netflix.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Netflix.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Netflix.cpp$(DependSuffix): Netflix.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Netflix.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Netflix.cpp$(DependSuffix) -MM "Netflix.cpp"

$(IntermediateDirectory)/Netflix.cpp$(PreprocessSuffix): Netflix.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Netflix.cpp$(PreprocessSuffix) "Netflix.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/Netflix"


