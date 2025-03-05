# NT API Process Injector
**FOR EDUCATIONAL PURPOSES ONLY!**


**This C++ code, will inject the specified process, create a new malicious thread, that will connect to a reverse listener with the IP 192.168.68.101**

**This uses the NTAPI (ntdll.dll) undocumented API functions by microsoft. Those are basically Win32 API's (console ones), but ones that go straight to the Kernel, those are still very much detectable,
since AV's and EDR's place hooks on those functions, view the Indirect Syscalls github page to somehow bypass this restriction**

**Steps to build**

Open Visual Studio 2022

Open the .sln file (Solution)

Build.
