#ifndef INPUT_H
#define INPUT_h

#include <SDL.h>
#include <iostream>
#include <vector>

#include <glm.hpp>

namespace md
{
	namespace input
	{

		enum KeyCode : short
		{
			None = SDL_SCANCODE_UNKNOWN,

			Return = SDL_SCANCODE_RETURN,
			Escape = SDL_SCANCODE_ESCAPE,
			Backspace = SDL_SCANCODE_BACKSPACE,
			Tab = SDL_SCANCODE_TAB,
			Space = SDL_SCANCODE_SPACE,
			Comma = SDL_SCANCODE_COMMA,
			Minus = SDL_SCANCODE_MINUS,
			Period = SDL_SCANCODE_PERIOD,
			Slash = SDL_SCANCODE_SLASH,
			D0 = SDL_SCANCODE_0,
			D1 = SDL_SCANCODE_1,
			D2 = SDL_SCANCODE_2,
			D3 = SDL_SCANCODE_3,
			D4 = SDL_SCANCODE_4,
			D5 = SDL_SCANCODE_5,
			D6 = SDL_SCANCODE_6,
			D7 = SDL_SCANCODE_7,
			D8 = SDL_SCANCODE_8,
			D9 = SDL_SCANCODE_9,
			Semicolon = SDL_SCANCODE_SEMICOLON,
			Apostrophe = SDL_SCANCODE_APOSTROPHE,
			Equals = SDL_SCANCODE_EQUALS,
			LeftBracket = SDL_SCANCODE_LEFTBRACKET,
			Backslash = SDL_SCANCODE_BACKSLASH,
			RightBracket = SDL_SCANCODE_RIGHTBRACKET,
			Grave = SDL_SCANCODE_GRAVE,
			A = SDL_SCANCODE_A,
			B = SDL_SCANCODE_B,
			C = SDL_SCANCODE_C,
			D = SDL_SCANCODE_D,
			E = SDL_SCANCODE_E,
			F = SDL_SCANCODE_F,
			G = SDL_SCANCODE_G,
			H = SDL_SCANCODE_H,
			I = SDL_SCANCODE_I,
			J = SDL_SCANCODE_J,
			K = SDL_SCANCODE_K,
			L = SDL_SCANCODE_L,
			M = SDL_SCANCODE_M,
			N = SDL_SCANCODE_N,
			O = SDL_SCANCODE_O,
			P = SDL_SCANCODE_P,
			Q = SDL_SCANCODE_Q,
			R = SDL_SCANCODE_R,
			S = SDL_SCANCODE_S,
			T = SDL_SCANCODE_T,
			U = SDL_SCANCODE_U,
			V = SDL_SCANCODE_V,
			W = SDL_SCANCODE_W,
			X = SDL_SCANCODE_X,
			Y = SDL_SCANCODE_Y,
			Z = SDL_SCANCODE_Z,

			Capslock = SDL_SCANCODE_CAPSLOCK,

			F1 = SDL_SCANCODE_F1,
			F2 = SDL_SCANCODE_F2,
			F3 = SDL_SCANCODE_F3,
			F4 = SDL_SCANCODE_F4,
			F5 = SDL_SCANCODE_F5,
			F6 = SDL_SCANCODE_F6,
			F7 = SDL_SCANCODE_F7,
			F8 = SDL_SCANCODE_F8,
			F9 = SDL_SCANCODE_F9,
			F10 = SDL_SCANCODE_F10,
			F11 = SDL_SCANCODE_F11,
			F12 = SDL_SCANCODE_F12,

			Prs32screen = SDL_SCANCODE_PRINTSCREEN,
			Scrolllock = SDL_SCANCODE_SCROLLLOCK,
			Pause = SDL_SCANCODE_PAUSE,
			Insert = SDL_SCANCODE_INSERT,
			Home = SDL_SCANCODE_HOME,
			PageUp = SDL_SCANCODE_PAGEUP,
			Delete = SDL_SCANCODE_DELETE,
			End = SDL_SCANCODE_END,
			PageDown = SDL_SCANCODE_PAGEDOWN,
			Right = SDL_SCANCODE_RIGHT,
			Left = SDL_SCANCODE_LEFT,
			Down = SDL_SCANCODE_DOWN,
			Up = SDL_SCANCODE_UP,

			NumlockClear = SDL_SCANCODE_NUMLOCKCLEAR,
			KeypadDivide = SDL_SCANCODE_KP_DIVIDE,
			KeypadMultiply = SDL_SCANCODE_KP_MULTIPLY,
			KeypadMinus = SDL_SCANCODE_KP_MINUS,
			KeypadPlus = SDL_SCANCODE_KP_PLUS,
			KeypadEnter = SDL_SCANCODE_KP_ENTER,
			Keypad1 = SDL_SCANCODE_KP_1,
			Keypad2 = SDL_SCANCODE_KP_2,
			Keypad3 = SDL_SCANCODE_KP_3,
			Keypad4 = SDL_SCANCODE_KP_4,
			Keypad5 = SDL_SCANCODE_KP_5,
			Keypad6 = SDL_SCANCODE_KP_6,
			Keypad7 = SDL_SCANCODE_KP_7,
			Keypad8 = SDL_SCANCODE_KP_8,
			Keypad9 = SDL_SCANCODE_KP_9,
			Keypad0 = SDL_SCANCODE_KP_0,
			KeypadPeriod = SDL_SCANCODE_KP_PERIOD,

			Application = SDL_SCANCODE_APPLICATION,
			Power = SDL_SCANCODE_POWER,
			KeypadEquals = SDL_SCANCODE_KP_EQUALS,
			F13 = SDL_SCANCODE_F13,
			F14 = SDL_SCANCODE_F14,
			F15 = SDL_SCANCODE_F15,
			F16 = SDL_SCANCODE_F16,
			F17 = SDL_SCANCODE_F17,
			F18 = SDL_SCANCODE_F18,
			F19 = SDL_SCANCODE_F19,
			F20 = SDL_SCANCODE_F20,
			F21 = SDL_SCANCODE_F21,
			F22 = SDL_SCANCODE_F22,
			F23 = SDL_SCANCODE_F23,
			F24 = SDL_SCANCODE_F24,
			Execute = SDL_SCANCODE_EXECUTE,
			Help = SDL_SCANCODE_HELP,
			Menu = SDL_SCANCODE_MENU,
			Select = SDL_SCANCODE_SELECT,
			Stop = SDL_SCANCODE_STOP,
			Again = SDL_SCANCODE_AGAIN,
			Undo = SDL_SCANCODE_UNDO,
			Cut = SDL_SCANCODE_CUT,
			Copy = SDL_SCANCODE_COPY,
			Paste = SDL_SCANCODE_PASTE,
			Find = SDL_SCANCODE_FIND,
			Mute = SDL_SCANCODE_MUTE,
			VolumeUp = SDL_SCANCODE_VOLUMEUP,
			VolumeDown = SDL_SCANCODE_VOLUMEDOWN,
			KeypadComma = SDL_SCANCODE_KP_COMMA,
			KeypadEqualsAS400 = SDL_SCANCODE_KP_EQUALSAS400,

			AltErase = SDL_SCANCODE_ALTERASE,
			SysReq = SDL_SCANCODE_SYSREQ,
			Cancel = SDL_SCANCODE_CANCEL,
			Clear = SDL_SCANCODE_CLEAR,
			Prior = SDL_SCANCODE_PRIOR,
			Return2 = SDL_SCANCODE_RETURN2,
			Separator = SDL_SCANCODE_SEPARATOR,
			Out = SDL_SCANCODE_OUT,
			Oper = SDL_SCANCODE_OPER,
			ClearAgain = SDL_SCANCODE_CLEARAGAIN,
			CrSel = SDL_SCANCODE_CRSEL,
			ExSel = SDL_SCANCODE_EXSEL,

			Keypad00 = SDL_SCANCODE_KP_00,
			Keypad000 = SDL_SCANCODE_KP_000,
			ThousandsSeparator = SDL_SCANCODE_THOUSANDSSEPARATOR,
			DecimalSeparator = SDL_SCANCODE_DECIMALSEPARATOR,
			CurrencyUnit = SDL_SCANCODE_CURRENCYUNIT,
			CurrencySubunit = SDL_SCANCODE_CURRENCYSUBUNIT,
			KeypadLeftParen = SDL_SCANCODE_KP_LEFTPAREN,
			KeypadRightParen = SDL_SCANCODE_KP_RIGHTPAREN,
			KeypadLeftBrace = SDL_SCANCODE_KP_LEFTBRACE,
			KeypadRightBrace = SDL_SCANCODE_KP_RIGHTBRACE,
			KeypadTab = SDL_SCANCODE_KP_TAB,
			KeypadBackspace = SDL_SCANCODE_KP_BACKSPACE,
			KeypadA = SDL_SCANCODE_KP_A,
			KeypadB = SDL_SCANCODE_KP_B,
			KeypadC = SDL_SCANCODE_KP_C,
			KeypadD = SDL_SCANCODE_KP_D,
			KeypadE = SDL_SCANCODE_KP_E,
			KeypadF = SDL_SCANCODE_KP_F,
			KeypadXor = SDL_SCANCODE_KP_XOR,
			KeypadPower = SDL_SCANCODE_KP_POWER,
			KeypadPercent = SDL_SCANCODE_KP_PERCENT,
			KeypadLess = SDL_SCANCODE_KP_LESS,
			KeypadGreater = SDL_SCANCODE_KP_GREATER,
			KeypadAmpersand = SDL_SCANCODE_KP_AMPERSAND,
			KeypadDblAmpersand = SDL_SCANCODE_KP_DBLAMPERSAND,
			KeypadVerticalBar = SDL_SCANCODE_KP_VERTICALBAR,
			KeypadDblVerticalBar = SDL_SCANCODE_KP_DBLVERTICALBAR,
			KeypadColon = SDL_SCANCODE_KP_COLON,
			KeypadHash = SDL_SCANCODE_KP_HASH,
			KeypadSpace = SDL_SCANCODE_KP_SPACE,
			KeypadAt = SDL_SCANCODE_KP_AT,
			KeypadExclam = SDL_SCANCODE_KP_EXCLAM,
			KeypadMemStore = SDL_SCANCODE_KP_MEMSTORE,
			KeypadMemRecall = SDL_SCANCODE_KP_MEMRECALL,
			KeypadMemClear = SDL_SCANCODE_KP_MEMCLEAR,
			KeypadMemAdd = SDL_SCANCODE_KP_MEMADD,
			KeypadMemSubtract = SDL_SCANCODE_KP_MEMSUBTRACT,
			KeypadMemMultiply = SDL_SCANCODE_KP_MEMMULTIPLY,
			KeypadMemDivide = SDL_SCANCODE_KP_MEMDIVIDE,
			KeypadPlusMinus = SDL_SCANCODE_KP_PLUSMINUS,
			KeypadClear = SDL_SCANCODE_KP_CLEAR,
			KeypadClearEntry = SDL_SCANCODE_KP_CLEARENTRY,
			KeypadBinary = SDL_SCANCODE_KP_BINARY,
			KeypadOctal = SDL_SCANCODE_KP_OCTAL,
			KeypadDecimal = SDL_SCANCODE_KP_DECIMAL,
			KeypadHexadecimal = SDL_SCANCODE_KP_HEXADECIMAL,

			LCtrl = SDL_SCANCODE_LCTRL,
			LShift = SDL_SCANCODE_LSHIFT,
			LAlt = SDL_SCANCODE_LALT,
			LGui = SDL_SCANCODE_LGUI,
			RCtrl = SDL_SCANCODE_RCTRL,
			RShift = SDL_SCANCODE_RSHIFT,
			RAlt = SDL_SCANCODE_RALT,
			RGui = SDL_SCANCODE_RGUI,

			MouseLeft,
			MouseRight,
			MouseMiddle,

			MouseWheelUp,
			MouseWheelDown,


			/*Mode = SDL_SCANCODE_MODE,

			AudioNext = SDL_SCANCODE_AUDIONEXT,
			AudioPrev = SDL_SCANCODE_AUDIOPREV,
			AudioStop = SDL_SCANCODE_AUDIOSTOP,
			AudioPlay = SDL_SCANCODE_AUDIOPLAY,
			AudioMute = SDL_SCANCODE_AUDIOMUTE,
			MediaSelect = SDL_SCANCODE_MEDIASELECT,
			Www = SDL_SCANCODE_WWW,
			Mail = SDL_SCANCODE_MAIL,
			Calculator = SDL_SCANCODE_CALCULATOR,
			Computer = SDL_SCANCODE_COMPUTER,
			ACSearch = SDL_SCANCODE_AC_SEARCH,
			ACHome = SDL_SCANCODE_AC_HOME,
			ACBack = SDL_SCANCODE_AC_BACK,
			ACForward = SDL_SCANCODE_AC_FORWARD,
			ACStop = SDL_SCANCODE_AC_STOP,
			ACRefresh = SDL_SCANCODE_AC_REFRESH,
			ACBookmarks = SDL_SCANCODE_AC_BOOKMARKS,

			BrightnessDown = SDL_SCANCODE_BRIGHTNESSDOWN,
			BrightnessUp = SDL_SCANCODE_BRIGHTNESSUP,
			DisplaySwitch = SDL_SCANCODE_DISPLAYSWITCH,
			KbDillumToggle = SDL_SCANCODE_KBDILLUMTOGGLE,
			KbDillumDown = SDL_SCANCODE_KBDILLUMDOWN,
			KbDillumUp = SDL_SCANCODE_KBDILLUMUP,
			Eject = SDL_SCANCODE_EJECT,
			Sleep = SDL_SCANCODE_SLEEP,
				,*/

			count,
		};

		struct axis_t
		{
			axis_t();
			std::string mName;
			KeyCode mNegativeButton;
			KeyCode mPositiveButton;
			float mGravity;
			float mDead;
			float mSensitivity;
		};


		bool IsKeyPressed(const KeyCode& key);
		bool IsKeyReleased(const KeyCode& key);
		bool IsKeyDown(const KeyCode& key);
		bool IsMouseActive();
		bool IsScrollForwardActive();
		bool IsScrollBackwardActive();
		bool IsScrollActive();

		float GetAxis(std::string const &axis);
		void AddAxis(const axis_t &axis);
		axis_t *FindAxis(std::string const &axis);

		glm::vec2 GetMousePosition();
		void GetMousePosition(int *x, int *y);
		glm::vec2 GetGlobalMousePosition();
		void GetGlobalMousePosition(int *x, int *y);
		glm::vec2 GetRelativeMousePosition();
		void GetRelativeMousePosition(int *x, int *y);

	}

	namespace inputconf
	{
		void Init();
		void OnPressKey(const input::KeyCode& key);
		void OnReleaseKey(const input::KeyCode& key);
		void StartNewFrame(void);
		void UpdateRelativeMousePosition();
		void UpdateMousePosition(int mouseX, int mouseY);
		void UpdateScrollPosition(int scrollX, int scrollY);
		void UpdateKeyState(const uint8_t* state);
		void UpdateMouseState(const uint8_t state);
	}
}

#endif // !INPUT_H
