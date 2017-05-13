# Conversion Program
Program that takes an input mp4 video, and outputs the same format but with one of the following conversions:
* Black and White 
* Sepia
* Audio only
* Video only
- [Video of Program being used][In Use]
- [Example videos converted][Converted video]
## Dependencies
* Mac OS to use the already compiled .app found in the project folder. Otherwise could compile on your system. 
* [Static ffmpeg executable.][ffmpeg download] Would need to download the correct static build for your system. 

## How to use 
- If your are on Mac OSX El Capitan:
    1.  You can use the ConversionProgram.app directly, no need to change anything
    2.  If you are on a different version of OSX, best to compile the program
- If you are on a different version of Mac OS or are on Linux or Windows
    1. Make sure that you have the correct **static executable** of [ffmpeg][ffmpeg download]
    2. Compile program through QT to ensure that it works on your platform
    3. Make sure that ffmpeg is place in the same folder as your ConversionProgram executable. For mac, this is place within the .app bundle so you will need to place in ConversionProgram.app/Contents/MacOS 
## What works
1. Currently, can only input mp4 files and recieve mp4 files. This can be easily changed due to ffmpeg's felxibility 
2. Progress bar to indicate current status and notification of which file is being converted
3. Full output from ffmpeg (what would normally appear if you were using it from the command line

## What can be improved
1. A pause feature. Often times video conversion takes time and uses alot of computing power. Adding a [pause feature][pause feature] would be helpful.
2. Allowing user to pick their output format.
3. Allowing more options for input format
4. Allowing user to input commands to the running ffmpeg process (in case it prompts user for input).
5. UI could be greatly improved by using QT's "QML" libraries 
6. Adding option to convert multiple videos
7. Adding error handling to let user know if ffmpeg is being located properly
8. Error handling in case user is using the wrong ffmpeg static build

## Helpful resources when doing this project 
- [FFMPEG official website][ffmpeg website]
- [Helpful thread on the basics of ffmpeg and video conversion][basics of ffmpeg]
- [Helpful tutorial on how to use ffmpeg on command line (good for prototyping)][ffmpeg on command line]
- [Creating Gray or Sepia using colormatrix command for ffmpeg][colormatrix explanation]
- [Useful UI/UX methods for making command line parameters for GUI's][parameters and GUI's]
- [Getting progress of currently converting video][progress]
- [Using QT's regular expressions to parse the output from ffmpeg][regex and QT]
- [If adding a pause function for currently converted video][pause]


[In Use]: https://www.dropbox.com/s/k5qsjp5nt40cirq/Conversion%20Program%20In%20Use.mp4?dl=0
[Converted video]: https://www.dropbox.com/s/5jsztc24joxcgpg/Examples.zip?dl=0
[ffmpeg download]: https://ffmpeg.org/download.html
[pause feature]: https://video.stackexchange.com/questions/17061/is-there-a-way-to-pause-and-resume-ffmpeg-encoding
[ffmpeg website]: https://ffmpeg.org/
[basics of ffmpeg]: https://superuser.com/questions/373018/resources-to-use-ffmpeg-effectively/373024#373024
[ffmpeg on command line]: http://blog.superuser.com/2012/02/24/ffmpeg-the-ultimate-video-and-audio-manipulation-tool/
[colormatrix explanation]: https://superuser.com/questions/926617/ffmpeg-applying-effects-to-a-video
[parameters and GUI's]: https://softwareengineering.stackexchange.com/questions/204225/what-are-some-standard-design-methods-to-add-gui-to-a-command-line-app
[progress]: http://stackoverflow.com/questions/11441517/ffmpeg-progress-bar-encoding-percentage-in-php
[regex and QT]: http://doc.qt.io/qt-5/qregexp.html#details
[pause]: https://video.stackexchange.com/questions/17061/is-there-a-way-to-pause-and-resume-ffmpeg-encoding
