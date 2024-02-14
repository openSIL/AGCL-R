#;*****************************************************************************
#; Copyright (C) 2008-2022 Advanced Micro Devices, Inc. All rights reserved.
#;
#;*****************************************************************************

[LibraryClasses]
  AmdDirectoryBaseLib|AgesaModulePkg/Library/AmdDirectoryBaseLib/AmdDirectoryBaseLib.inf
  FchEspiLib|AgesaModulePkg/Library/FchEspiGenoaLib/FchEspiGenoaLib.inf

[Components.IA32]
  AgesaModulePkg/Mem/AmdMemoryHobInfoPeimGenoa/AmdMemoryHobInfoPeimGenoa.inf
  AgesaModulePkg/Library/FabricResourceManagerGenoaLib/FabricResourceManagerLib.inf

[Components.X64]
  AgesaModulePkg/Fch/9004/Fch9004SmmDispatcher/FchSmmDispatcher.inf

