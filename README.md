              Building a custom File hierarchy by modifying the git kernel
https://www.youtube.com/watch?v=v04KbT0dh2E
AIM:
To develop an Operating system by taking the source code of Windows-clone ReactOS and build a new looking and with drivers that to support Windows Os.
TOOLS:
1. ReactOS Build Environment for Windows NT-compatible OS Version 2.1.1
2. Subversion is a version control system used by ReactOS to manage the source code of the project.
3. Emulator - Qemu Emulator on which ReactOS runs.
4. Editor – Sublime Text2
STEPS:
1 https://www.reactos.org/download 
2 http://sourceforge.net/projects/reactos/files/ReactOS/0.3.17/ReactOS-0.3.17-REL-QEMU.zip/download 
3 ReactOS Preinstalled on a QEMU Virtual Machine
This package contains a preinstalled ReactOS version on a QEMU virtual machine. For Windows users, it also contains the QEMU application, so you can easily start the virtual machine and run ReactOS.
Windows users--To start the preinstalled ReactOS version, just execute the "boot.bat" file. If you want to access files of the virtual hard disk, download and install VDK from http://chitchat.at.infoseek.co.jp/vmware/vdk.html this tool allows you to mount the virtual hard disk in your Windows system.
Users of Unix-based Operating Systems--If you use a Unix-based Operating System such as Linux, install the appropriate QEMU package for your OS. Then open a Terminal, change the current directory to the directory containing the "ReactOS.vmdk" file and execute the following command:
   qemu -m 128 -hda ReactOS.vmdk
If you want to access and modify files of the virtual hard disk, you have to convert it to the "raw" format. To convert it, execute the following commands in the directory containing the "ReactOS.vmdk" file:
   Qemu-img convert ReactOS.vmdk -O raw ReactOS.hd
Beware that this takes 2 GB of hard disk space, since a raw hard disk image is not grow able. Now you can easily mount the image with the following command:
   Mount -oloop,offset=32256 -t vfat ReactOS.hd /mnt/vhd
In this case, I assume that you want to mount the hard disk image to /mnt/vhd. Otherwise modify the command line accordingly. After you unmounted the changed hard disk, you can boot it by executing the following command:
   qemu -m 128 -hda ReactOS.hd
4, Open the .bat file
5, Now the ReactOS starts within Qemu
Started learning about Qemu from its official website Installed Qemu and tried basic commands
Installed subversion SVN
 
This is just like git where all the repository is maintained and the connection to the main source code of the project.Now from this site download the stated link and this is the build environment from which we can Develop the react os, where we can install new features and drivers.  

after installing these files are installing.Now read the instructions given in Readme.
Now just DoubleClick the RosBE PS – PostInstall .After this this command prompt will setup now type the “ssnv create” .This will install the source code of the react os.
 
After installing the tree structure of the source code can we viewed in above screenshot. Now jump to the folder. 





After loading ReactOS in Virtual Box it somewhat looked like our most lovable evergreen WINDOWS XP with slightly different look perhaps. Let’s see how our traditional Command Prompt looks ….

Changing the source:
I'm going to explain how to build your own ReactOS application using ROSBE  
the examples works without changes, if source code was located in c:\ReactOS-SRC and ROSBE is installed correctly. All the examples are named : firstapp.exe, and can builded by a simple: MAKE FIRSTAPP from ROSBE CONSOLE we edit the c-code using the standard NOTEPAD... and it can be compiled using only ReactOS 
first, create a directory called FIRSTAPP located in C:\ReactOS-src\base\setup
we used Setup-directory because it contains WELCOME application.. That can be a good source of example code...
 

now... Edit the setup. rbuild located in SETUP directory and ADD then new FIRSTAPP entry.

Open FIRSTAPP directory and create a new rbuild file named: firstapp.rbuild
copy this code on it:
<?xml version="1.0"?>
<!DOCTYPE module SYSTEM "../../../tools/rbuild/project.dtd">
<module name="firstapp" type="win32gui" installbase="system32" installname="firstapp.exe" unicode="yes">
   <bootstrap installbase="$(CDOUTPUT)" />
   <include base="firstapp">.</include>
   <library>kernel32</library>
   <library>gdi32</library>
   <library>user32</library>
   <file>firstapp.c</file>
</module>
 
#include <windows.h> // managing windows...
#include <tchar.h>   // for TEXT function ( unicode strings )

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
     //this is the first Message BOX...
     MessageBox(
      0,
      TEXT("This is my first Reactos-Application"),
      TEXT("This is a MESSAGEBOX"),
       MB_OK
      );

     //and this is the second... the code is the same, but on a single-line.
     MessageBox(0,TEXT("This is another MESSAGEBOX"),TEXT("Press OK..."), MB_OK);

return(0);
}

 


Complete Code:

#include <windows.h> // managing windows...
#include <tchar.h>   // for TEXT function ( unicode strings )

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
     //this is the first Message BOX...
     MessageBox(
      0,
      TEXT("This is my first Reactos-Application"),
      TEXT("This is a MESSAGEBOX"),
       MB_OK
      );

     //and this is the second... the code is the same, but on a single-line.
     MessageBox(0,TEXT("This is another MESSAGEBOX"),TEXT("Press OK..."), MB_OK);

return(0);
}
Now... JUST go on ROSBE shell... and type: MAKE FIRSTAPP
 

the compiled program are created on directory: C:\ReactOS-src\output-i386\base\setup\firstapp
 
now, copy FIRSTAPP.EXE on ReactOS desktop... and double-click it!
(in Q-EMU just MOUNT the c-drive image using ROSTE, and copy firstapp.exe on UNIT:\Documents and Settings\Administrator\Desktop )
( in win.. just doubleclick the program )
 

now, we can introduce a simple DEBUG output...
this is the code:
OutputDebugStringW(L"Example Debug-line : Started first example <firstapp.exe>\n");

Place it before the first MessageBox 
 
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
     OutputDebugStringW(L"Example Debug-line : Started first example <firstapp.exe>\n");
     //this is the first Message BOX...
     MessageBox(
      0,

Now... Start ROS (debug version) in QEMU and the debug-output will appear in the debug window

New Update for present Cmake File System
rbuild files are now obsolete you should use cmake files: 

from [now... edit the setup.rbuild located in SETUP directory and ADD then new FIRSTAPP entry.]
To [now... is time to write the c-code... is a good idea to write some REM, something like that:]
is now done by as follows….
now.. Edit the CMakeLists.txt located in SETUP directory and ADD then new FIRSTAPP entry.

add_subdirectory(reactos)
add_subdirectory(setup)
add_subdirectory(usetup)
add_subdirectory(vmwinst)
add_subdirectory(welcome)
add_subdirectory(firstapp)

open FIRSTAPP directory and create a new Cmake file named: CMakeLists.txt copy this code on it:
add_executable(firstapp firstapp.c)
7set_module_type(firstapp win32gui UNICODE)
add_importlibs(firstapp gdi32 user32 shell32 msvcrt kernel32 ntdll)
add_cd_file(TARGET firstapp DESTINATION reactos NO_CAB FOR bootcd)


[now... JUST go on ROSBE shell... and type: MAKE FIRSTAPP]
shuold be substituted [now... JUST go on ROSBE shell, output directory, reactos ... and type: ninja firstapp]


[edit firstapp.rbuild and add this entry: firstapp.rc] to [now.. create resource.h]
be substituted with:

edit CMakeLists.txt and add this entry: firstapp.rc
like this:

add_executable(firstapp firstapp.c firstapp.rc)
set_module_type(firstapp gdi32 user32 shell32 msvcrt kernel32 ntdll)
add_importlibs(firstapp kernel32 gdi32 user32 )
add_cd_file(TARGET firstapp DESTINATION reactos NO_CAB FOR bootcd)
Suggestion by group Members:
	1. Improvisation of the graphical approach rather than command interface	
	2. Not only just editing trying to develop a small os with just command line not much GUI

References:
https://www.reactos.org/forum/ucp.php?mode=login
https://www.reactos.org/development/build-environment
https://www.reactos.org/
https://www.reactos.org/installation
https://www.reactos.org/forum/viewtopic.php?f=22&t=6366
https://www.reactos.org/forum/viewtopic.php?f=2&t=14089
https://www.reactos.org/forum/viewtopic.php?f=2&t=14084





