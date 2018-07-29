#ifndef DEFINE_H
#define DEFINE_H

#define Byte unsigned char

#define WindowsW 500
#define WindowsH 300
#define WindowsX 500
#define WindowsY 500

#define MenuBarW WindowsW
#define MenuBarH 25
#define MenuBarX 0
#define MenuBarY 0

#define OpenFileEditW WindowsW
#define OpenFileEditH 25
#define OpenFileEditX 0
#define OpenFileEditY 26

#define OpenFilePushButtonW 100
#define OpenFilePushButtonH 40
#define OpenFilePushButtonX 30
#define OpenFilePushButtonY 30

#define FRAMEW WindowsW
#define FRAMEH WindowsH-MenuBarH-OpenFileEditH
#define FRAMEX 0
#define FRAMEY MenuBarH+OpenFileEditH


#define PEMACHINELBW 100
#define PEMACHINELBH 20
#define PEMACHINELBX 0
#define PEMACHINELBY 10

#define PEMACHINELEW 100
#define PEMACHINELEH 20
#define PEMACHINELEX 110
#define PEMACHINELEY 10

#define SIGNATURE_MOVE 0         // 4
#define MACHINE_MOVE 4           // 2
#define NUMBEROFSESSIONS_MOVE 6  // 2
#define TIMEDATESTAMP_MOVE 8     // 4

#endif // DEFINE_H

