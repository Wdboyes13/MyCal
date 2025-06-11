# MyCal
__A Planner & Calendar app__  
__I'm doing this for a school project__  
__You can contact me at [willdev2025@outlook.com](mailto:willdev2025@outlook.com)__   
__Info about info can be found at [other/info.md](other/info.md)__  
## Dependencies
Raylib  
LibXML2  

## Notes  
idea.txt is the idea  
Currently only planner is mostly done    
Schedules are in XML  

The <sub>Launcher password is 2398</sub> files ending in ~ are emacs saves (I clean these regularly)  
  
The Makefile is just a wrapper around CMake and others to make my life easier  

## Notice  
-- Font --  
The 'Roboto' Font is licensed under the SIL Open Font License Version 1.1  
More details about this font are available at https://fonts.google.com/specimen/Roboto  
The full license text is available at [other/OFL.txt](other/OFL.txt)  
  
-- Background Music --  
Pixel Peeker Polka - faster Kevin MacLeod (incompetech.com)  
Licensed under Creative Commons: By Attribution 3.0 License  
http://creativecommons.org/licenses/by/3.0/  
  
-- Project --  
This project is released under The GNU General Public License version 3.0  
You can view the full License text at [LICENSE](LICENSE)  
As well as the License's File Header at [other/LicenseBlob.txt](other/LicenseBlob.txt)     
  
## Compatibility    

| Windows | macOS | Linux | AArch64 | x86_64 |
|---------|-------|-------|---------|--------|
| NO      | YES   | YES   | YES     | YES    |

- __Windows__ is incompatible due to `unistd.h` & `strings.h` being needed as well as MSVC being wierd with .S files
- App icon will not load on macOS due to reasons (Unless someone wants to deal with .app bundles)
