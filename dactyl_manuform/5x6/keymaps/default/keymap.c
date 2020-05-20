/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _SYMBOL 1
#define _NAVI 2

#define SYMBOL MO(_SYMBOL)

#define _______ KC_TRNS

#define SFT_SPC SFT_T(KC_SPC)
#define SFT_BSPC SFT_T(KC_BSPC)
#define CTL_ENT CTL_T(KC_ENT)
#define ALT_ESC ALT_T(KC_ESC)
#define LOWER_HOME LT(_SYMBOL KC_HOME)
#define LOWER_END LT(_SYMBOL, KC_END)

#define NAVI_BSP LT(_NAVI, KC_BSPC)
#define SYMBOL_SPC LT(_SYMBOL, KC_SPC)
#define CTL_ESC CTL_T(KC_ESC)

// mouse
#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1 


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_F12 , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9   , KC_F10   , KC_F11  ,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O   , KC_P   , KC_QUOT  ,
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L   , KC_SCLN, KC_RSFT  ,
     KC_LGUI, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM, KC_DOT , KC_SLSH, KC_BSLASH,
                      KC_LBRC,KC_RBRC,                                                       KC_HOME, KC_END ,
                                 NAVI_BSP,CTL_ESC,                         CTL_ENT, SYMBOL_SPC,
                                      KC_DEL,KC_LALT,                         KC_RALT, KC_INS,
                         LGUI(LCTL(KC_LEFT)),_______,                         _______, LGUI(LCTL(KC_RIGHT))
  ),

  [_SYMBOL] = LAYOUT_5x6(

     _______,KC_EXLM,KC_AT ,KC_HASH,KC_DLR,KC_PERC,                           KC_CIRC,KC_AMPR,KC_ASTR ,KC_LPRN  ,KC_RPRN,KC_DEL ,
     _______,KC_1   ,KC_2  ,KC_3   ,KC_4  ,KC_5   ,                           KC_6   ,KC_7   ,KC_8    ,KC_9     ,KC_0   ,KC_GRV,
     KC_TILD,KC_EXLM,KC_AT ,KC_HASH,KC_DLR,KC_PERC,                           KC_CIRC,KC_AMPR,KC_ASTR ,KC_MINUS ,KC_PLUS,KC_EQUAL,
     KC_F1  ,KC_F2  ,KC_F3 ,KC_F4  ,KC_F5 , KC_F6 ,                           KC_F7  ,KC_F8  ,KC_F9   ,KC_F10   ,KC_F11 ,KC_F12,
                    KC_LPRN,KC_RPRN,                                                           KC_UNDS,KC_PIPE,
                                             _______,_______,            _______,KC_PLUS,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),

  [_NAVI] = LAYOUT_5x6(
       KC_F12 ,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                      KC_F6  ,KC_F7  ,KC_F8    ,KC_F9   ,KC_F10   ,KC_F11 ,
       _______,_______,_______,KC_MU  ,_______,_______,                      KC_VOLU,_______,KC_UP    ,KC_INS  ,KC_PGUP  ,KC_MUTE,
       _______,_______,KC_ML  ,KC_MD  ,KC_MR  ,_______,                      KC_MUTE,KC_LEFT,KC_DOWN  ,KC_RIGHT,KC_PGDOWN,KC_VOLU,
       _______,_______,_______,_______,_______,_______,                      KC_VOLD,_______,KC_PGDOWN,KC_PGUP ,KC_UP    ,KC_RIGHT,
                                               _______,_______,                              KC_LEFT  ,KC_DOWN ,
                                               _______,_______,            KC_MB1,KC_MB2,
                                               _______,_______,            _______,_______,
                                   LGUI(LALT(KC_LEFT)),_______,            _______,LGUI(LALT(KC_RIGHT))
  ),
};


