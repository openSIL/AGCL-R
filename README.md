# README

## Beta Release of UEFI Host Firmware for Genoa openSIL POC (AGCL-R)

Thank you for your interest in the testing of this beta firmware. This firmware is provided to you as-is and is under the terms of the [beta license agreement](https://github.com/openSIL/AGCL-R/blob/main/2023.10.9%20Beta%20Firmware%20License%20(source%20code)%20v.2.pdf) that is available in this repository.

### Disclaimer

Please note that the content available in [this](https://github.com/openSIL/AGCL-R) repository is a beta version of the AGCL-R (a component of a sample UEFI EDK2-based Host Firmware for Genoa openSIL POC), which means it is still in a development and testing phase. While we have done our best to ensure the stability of this set of firmware, it may still contain bugs, incomplete features, or other issues.

### License

By using this beta firmware, you agree to the terms and conditions of the [Beta Firmware license agreement](https://github.com/openSIL/EDKII-Platform/blob/main/2023.10.9%20Beta%20Firmware%20License%20(source%20code)%20v.2.pdf).


### Intended usage

- The beta release of the AGCL-R is intended to integrate with an EDKII Host FW for the AMD openSIL Genoa Proof-Of-Concept (POC), which is available at https://github.com/openSIL/openSIL.
- Aims to enable those who are interested in AMD openSIL to evaluate an EDKII Host FW based on AMD openSIL.
- For additional details, please reference the [EDKII Platform README](https://github.com/openSIL/EDKII-Platform/blob/main/README.md).

### About AGCL-R (AGESA Compatibility Layer - Reduced)

AGCL-R:
- The code in this repository is based on a production version of the AGESA Platform Initialization (PI) Package for AMD Genoa CPUs.
- This code utilizes opensil-uefi-interface protocols in order to interface with openSIL.
- Based on externally released (under NDA) AGESA PI code.
