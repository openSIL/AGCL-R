#*******************************************************************************
# Copyright (C) 2021-2024 Advanced Micro Devices, Inc. All rights reserved.
#
#*******************************************************************************

import json
import os
import sys
import platform
import shutil
import stat

from enum import Enum
from pathlib import Path
from subprocess import run, PIPE

VERBOSE             = False
CURRENT_DIRECTORY   = Path(__file__).parent
TOOL_DIRECTORY_PATH = CURRENT_DIRECTORY.joinpath("../../../../AgesaModulePkg/AMDTools/ApcbToolV3/Tools").resolve()
TOOL_DIRECTORY      = TOOL_DIRECTORY_PATH if "TOOL_DIR" not in os.environ.keys() else Path(os.environ["TOOL_DIR"]).resolve()

class ToolchainType(Enum):
    TOOLCHAIN_MSVC      = 1
    TOOLCHAIN_GNU       = 2
    TOOLCHAIN_GNU_WIN32 = 3

def GetToolchainType() -> ToolchainType:
    if "Windows" == platform.system():
        return ToolchainType.TOOLCHAIN_MSVC
    else:
        return ToolchainType.TOOLCHAIN_GNU

class Compiler:
    COMPILER_FLAGS = {
        ToolchainType.TOOLCHAIN_MSVC: {
            "tool":       "cl",
            "flags":      ["/nologo"],
            "compile":    "/c",
            "preprocess": "/EP",
            "output":     "/Fo",
            "include":    "/I",
            "define":     "/D",
            "obj_ext":    ".obj"
        },
        ToolchainType.TOOLCHAIN_GNU: {
            "tool":       "gcc",
            "flags":      ["-fno-zero-initialized-in-bss"],
            "compile":    "-c",
            "preprocess": "-E",
            "output":     "-o",
            "include":    "-I",
            "define":     "-D",
            "obj_ext":    ".o"
        },
        ToolchainType.TOOLCHAIN_GNU_WIN32: {
            "tool":       "gcc",
            "flags":      ["-fno-zero-initialized-in-bss"],
            "compile":    "-c",
            "preprocess": "-E",
            "output":     "-o",
            "include":    "-I",
            "define":     "-D",
            "obj_ext":    ".o"
        }
    }

    def __init__(self) -> None:
        self.__toolchain_type      = GetToolchainType()
        self.__include_directories = []
        self.__compile_options     = []
        self.__compile_definitions = {}

    def get_obj_ext(self) -> str:
        return Compiler.COMPILER_FLAGS[self.__toolchain_type]["obj_ext"]

    def add_include_directory(self, include_directory_path: str) -> None:
        self.__include_directories.append(include_directory_path)

    def add_compile_option(self, compile_option: str) -> None:
        if compile_option not in self.__compile_options:
            self.__compile_options.append(compile_option)
        else:
            raise "Duplicate compile option"

    def add_compile_definition(self, compile_definition_name: str, compile_definition_value: any = None) -> None:
        self.__compile_definitions[compile_definition_name] = compile_definition_value

    def __prepare_command(self, input_path: str, output_path: str) -> list:
        command = [Compiler.COMPILER_FLAGS[self.__toolchain_type]["tool"]]

        command.extend(Compiler.COMPILER_FLAGS[self.__toolchain_type]["flags"])
        command.extend(self.__compile_options)

        for compile_definition_name, compile_definition_value in self.__compile_definitions.items():
            if compile_definition_value is None:
                command.append(
                    "{}{}".format(
                        Compiler.COMPILER_FLAGS[self.__toolchain_type]["define"],
                        compile_definition_name))
            else:
                command.append(
                    "{}{}={}".format(
                        Compiler.COMPILER_FLAGS[self.__toolchain_type]["define"],
                        compile_definition_name,
                        compile_definition_value))

        for include_directory in self.__include_directories:
            command.append("{}{}".format(Compiler.COMPILER_FLAGS[self.__toolchain_type]["include"], include_directory))

        command.append("{}{}".format(
            Compiler.COMPILER_FLAGS[self.__toolchain_type]["include"],
            Path(input_path).parent))

        return command

    def preprocess(self, input_path: str, output_path: str) -> None:
        command = self.__prepare_command(input_path, output_path)

        command.append(Compiler.COMPILER_FLAGS[self.__toolchain_type]["preprocess"])
        command.append(input_path)

        if VERBOSE:
            print(command)

        print("[CC-E] {}".format(input_path))

        compilation_result = run(command, stdout=PIPE, stderr=PIPE, universal_newlines=True)

        if 0 != compilation_result.returncode:
            print(compilation_result.stderr)
            exit(compilation_result.returncode)
        else:
            with open(output_path, "w") as output_file:
                output_file.write(compilation_result.stdout)

    def compile(self, input_path: str, output_path: str) -> None:
        command = self.__prepare_command(input_path, output_path)

        command.append(Compiler.COMPILER_FLAGS[self.__toolchain_type]["compile"])
        command.append(input_path)
        command.append("{}{}".format(Compiler.COMPILER_FLAGS[self.__toolchain_type]["output"], output_path))

        if VERBOSE:
            print(command)

        print("[CC]   {}".format(input_path))

        compilation_result = run(command, stdout=PIPE, stderr=PIPE, universal_newlines=True)

        if 0 != compilation_result.returncode:
            print(compilation_result.stdout)
            print(compilation_result.stderr)
            exit(compilation_result.returncode)


class Linker:
    LINKER_FLAGS = {
        ToolchainType.TOOLCHAIN_MSVC: {
            "tool":    "link",
            "flags":   ["/nologo"],
            "map":     "/MAP:",
            "output":  "/OUT:",
            "exe_ext": ".exe"
        },
        ToolchainType.TOOLCHAIN_GNU: {
            "tool":   "gcc",
            "flags":  [],
            "map":    "-Wl,-Map=",
            "output": "-o",
            "exe_ext": ".elf"
        },
        ToolchainType.TOOLCHAIN_GNU_WIN32: {
            "tool":   "gcc",
            "flags":  [],
            "map":    "-Wl,-Map=",
            "output": "-o",
            "exe_ext": ".exe"
        }
    }

    def __init__(self) -> None:
        self.__toolchain_type = GetToolchainType()

    def get_exe_ext(self) -> str:
        return Linker.LINKER_FLAGS[self.__toolchain_type]["exe_ext"]

    def link(self, input_paths: list, output_path: str, map_file_path: str = None) -> None:
        command = [Linker.LINKER_FLAGS[self.__toolchain_type]["tool"]]

        command.extend(Linker.LINKER_FLAGS[self.__toolchain_type]["flags"])
        command.extend(input_paths)

        if type(map_file_path) is str:
            command.append("{}{}".format(Linker.LINKER_FLAGS[self.__toolchain_type]["map"], map_file_path))

        command.append("{}{}".format(Linker.LINKER_FLAGS[self.__toolchain_type]["output"], output_path))

        if VERBOSE:
            print(command)

        print("[LINK] {}".format(output_path))

        link_result = run(command, stdout=PIPE, stderr=PIPE, universal_newlines=True)

        if 0 != link_result.returncode:
            print(link_result.stdout)
            print(link_result.stderr)
            exit(link_result.returncode)


def clean() -> None:
    shutil.rmtree(CURRENT_DIRECTORY.joinpath("Release"), True)
    shutil.rmtree(CURRENT_DIRECTORY.joinpath("Log"), True)
    shutil.rmtree(CURRENT_DIRECTORY.joinpath("Build"), True)


def build() -> None:
    compiler = Compiler()
    linker   = Linker()

    compiler.add_include_directory("Include")
    compiler.add_include_directory("../Inc/Genoa")
    compiler.add_include_directory("../Inc/Common")

    compiler.add_compile_definition("BUILD_APCB_SIG", 1)

    if "1" == os.environ.get("APCB_EXTERNAL_BUILD", "0"):
        compiler.add_compile_definition("APCB_EXTERNAL_BUILD", "1")

    if "APCB_PLAT_C_FLAGS" in os.environ.keys():
        for option in os.environ["APCB_PLAT_C_FLAGS"].split(" "):
            compiler.add_compile_option(option)

    with open(CURRENT_DIRECTORY.joinpath("ApcbCreate.json"), "r") as configuration_file:
        configuration = json.loads(configuration_file.read())

        if "APCB_DATA_BOARD_DIR_LIST" in os.environ.keys():
            board_list = os.environ["APCB_DATA_BOARD_DIR_LIST"].split(" ")
        else:
            board_list = ["GenoaCommon", "Onyx"]

        release_path = CURRENT_DIRECTORY.joinpath("Release")
        log_path     = CURRENT_DIRECTORY.joinpath("Log")

        release_path.mkdir(parents=True, exist_ok=True)
        log_path.mkdir(parents=True, exist_ok=True)

        for target_name, target_configuration in configuration.items():
            print("Building {}...".format(target_name))
            print()

            log_file = log_path.joinpath(target_name).with_suffix(".log")

            command_path = TOOL_DIRECTORY.joinpath("ApcbToolV3").with_suffix(linker.get_exe_ext())
            command_exe_stats = os.stat(command_path)
            os.chmod(command_path, command_exe_stats.st_mode | stat.S_IEXEC | stat.S_IXGRP | stat.S_IXOTH)

            command = [
                str(command_path),
                "--outputfile",
                str(release_path.joinpath(target_configuration["binary"]))
                ]

            build_path = CURRENT_DIRECTORY.joinpath("Build")
            sources    = []

            if "ApcbDataDefaultRecovery" == target_name:
                for board_name, board_sources in target_configuration["sources"].items():
                    if board_name in board_list:
                        sources.extend(board_sources["common"])

                        if ("1" == os.environ.get("APCB_MULTI_BOARD_SUPPORT", "0") and
                           ("multiboard" in board_sources.keys())):
                            sources.extend(board_sources["multiboard"])
            else:
                sources.extend(target_configuration["sources"])

            if len(sources) > 0:
                for source in sources:
                    source_path = CURRENT_DIRECTORY.joinpath(source)
                    output_path = build_path.joinpath(target_name).joinpath(Path(source).parent.name)
                    output_path = output_path.joinpath(Path(source).name).with_suffix(compiler.get_obj_ext())

                    output_path.parent.mkdir(parents=True, exist_ok=True)

                    compiler.preprocess(str(source_path), str(output_path.with_suffix(".cod")))
                    compiler.compile(str(source_path), str(output_path))

                    linker.link([str(output_path)],
                                str(output_path.with_suffix(linker.get_exe_ext())),
                                str(output_path.with_suffix(".map")))

                    command.append("-I")
                    command.append(str(output_path.with_suffix(linker.get_exe_ext())))

                if VERBOSE:
                    print(command)
                    print("Logging to {}".format(log_file))

                print("[APCB] {}".format(command[2]))

                tool_result = run(command, stdout=PIPE, stderr=PIPE, universal_newlines=True)

                with open(log_file, "w") as output_file:
                    output_file.write(tool_result.stdout)

                if 0 != tool_result.returncode:
                    print(tool_result.stdout)
                    print(tool_result.stderr)
                    exit(tool_result.returncode)

                print()


if __name__ == "__main__":
    if (2 == len(sys.argv)) and (("--help" == sys.argv[1].lower()) or ("-h" == sys.argv[1].lower())):
        print()
        print("{} help info".format(Path(__file__).name))
        print()
        print("USAGE:")
        print("      For clean up output directories (Release, Build and Log directoies)")
        print("  {} CLEAN".format(Path(__file__).name))
        print()
        print("      For build APCB data and tool")
        print("  {} BUILD".format(Path(__file__).name))
        print()
        print("      You may combine both")
        print("  {} CLEAN BUILD".format(Path(__file__).name))
        print()
    elif (2 == len(sys.argv)) and ("clean" == sys.argv[1].lower()):
        clean()
    elif (2 == len(sys.argv)) and ("build" == sys.argv[1].lower()):
        build()
    elif (3 == len(sys.argv)) and ("clean" == sys.argv[1].lower()) and ("build" == sys.argv[2].lower()):
        clean()
        build()
