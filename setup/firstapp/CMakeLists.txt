add_executable(firstapp firstapp.c)
set_module_type(firstapp win32gui UNICODE)
add_importlibs(firstapp gdi32 user32 shell32 msvcrt kernel32 ntdll)
add_cd_file(TARGET firstapp DESTINATION reactos NO_CAB FOR bootcd)