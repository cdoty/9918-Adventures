# Coleco Adam using a Digital Data Pack (DDP)
* The project creates a boot file and program file that are inserted into the DDP. A file system is not used on the DDP.
* The block count is calculated from the size of the resulting program.
* Interrupts, on the VDP, must be disabled when transferring data since the NMI cannot be disabled, and will mess up the address register.
* [ddp](https://github.com/tschak909/ddp) is used to create DDP images.
