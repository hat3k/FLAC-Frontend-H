<p align="center"><img src="https://ptpimg.me/25gayf.png"></p>

<b>Changes made compared to original FLAC Fronted 2.1:</b>

<b>Added:</b>
* Latest flac.exe and metaflac.exe
    * This builds may have some bugs
    * You may use any build you want, but be aware that multithreading was implemented for latest v.1.4.3 builds (not for 1.4.3 release)
    * To use your builds copy flac.exe and metaflac.exe to "tools" foder
    * FLAC build version is shown in "About" form
* Additional compression options
* Multithreading option
* Ability to autosave some settings
    * Settings like "-p", "-e" or command line options are autosaved on app close
    * They are stored in a "settings.txt"  
* Ability to overwright existing files (useful for re-encoding purposes)

<b>Removed/Moved:</b>
* Advanced options window
    * These options are moved to main window
    * CL options are now saved, so it's better to have them in sight

<b>Other:</b>
* Updated toolset
* Project is build at VS2022



---------------------------------------------------------------------------
------                          COPYRIGHT                            ------
---------------------------------------------------------------------------

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

The source of this project and the FLAC project can be found on 
http://sourceforge.net/project/flacfrontend and http://xiph.org/flac
respectively.

---------------------------------------------------------------------------
------                             FAQ                               ------
---------------------------------------------------------------------------

1) Why is this command line thing popping up?
FLAC frontend is a very simple program that just calls the 'real' FLAC
encoder, which is command line based. This has been done to keep
development of FLAC frontend easy and accessible and makes it possible to
change the encoder without having to change anything in the FLAC frontend

2) Is there drag and drop support?
Yes, there is. Just drag any files or directories to the list box in the
top left of the FLAC frontend window. Any directories will automatically be
searched (recursively) for .flac, .ogg, .oga and .wav files.

3) Where is FLAC tester?
FLAC tester has been replaced by the frontend, because the frontend now has
drag-and-drop support too. Just drag the files you want to test to the FLAC
Frontend and click the test button.

4) How does the portable version of FLAC Frontend work?
Just unzip the zip-file somewhere convenient and run the executable, either
FLAC frontend-NET20.exe or FLAC frontend-NET40.exe, depending on which
version of the .NET framework you have installed. If you have .NET 2.0, 3.0
or 3.5 you should use NET20, if you have .NET 4.0 or 4.5 use NET40. If you
are not sure, just try both. You can just delete the other file if you
don't want to have to remember which one is the right one.
