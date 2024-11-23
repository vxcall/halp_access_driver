# halp_access_driver

A simple driver to retrieve HalpInterruptController.
Just for my future use. Not useful at all as is

# HalpInterruptController

I access HAL's private subroutines through HalpInterruptController.
This is an interesting structure that holds function pointers of various HAL's private subroutiines.
You can get its pointer by `x nt!HalpInterruptController`, in WinDbg also `dq poi(nt!HalpInterruptController) L18` will show you the list of pointers it has.

# build

```Shell
cmake -B build; cmake --build build
```
