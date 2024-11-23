# vxdrv

my research kernel driver to investigate HAL's private APIC functionality.

# HalpInterruptController

I access HAL's private subroutines through HalpInterruptController.
This is an interesting structure that holds function pointers of various HAL's private subroutiines.
You can get its pointer by `x nt!HalpInterruptController`, in WinDbg also `dq poi(nt!HalpInterruptController) L18` will show you the list of pointers it has.
