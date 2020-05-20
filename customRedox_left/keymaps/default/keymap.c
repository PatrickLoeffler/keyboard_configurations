#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _SYMB 1
#define _NAV 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYMB,
  NAV,
  ADJUST,
};

// Fillers to make layering more clear
#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// TAP DANCES
enum {
	TD_MINUS = 0,
	TD_PLUS,
	TD_QUOT,
	TD_SCLN
	//TAPDANCE_BRACES
};

//void td_braces(qk_tap_dance_state_t
void td_minus_finished(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		register_code(KC_MINS); 
	} else {
		register_code(KC_RSFT);
		register_code(KC_MINS);
	}
}


void td_minus_reset(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		unregister_code(KC_MINS); 
	} else {
		unregister_code(KC_RSFT);
		unregister_code(KC_MINS);
	}
}

void td_plus_finished(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		register_code(KC_EQL); 
	} else if (state->count == 2) {
		register_code(KC_RSFT);
		register_code(KC_EQL);
	} else if (state->count == 3) {
		register_code(KC_EQL);
		unregister_code(KC_EQL);
		register_code(KC_EQL);
	} else {
		register_code(KC_RSFT);
		register_code(KC_EQL);
		unregister_code(KC_RSFT);
		unregister_code(KC_EQL);
		register_code(KC_RSFT);
		register_code(KC_EQL);
	}
}


void td_plus_reset(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1 || state->count == 3) {
		unregister_code(KC_EQL); 
	} else {
		unregister_code(KC_RSFT);
		unregister_code(KC_EQL);
	}
}

void td_quote_finished(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		register_code(KC_QUOT); 
	} else {
		register_code(KC_RSFT);
		register_code(KC_QUOT);
	}
}


void td_quote_reset(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		unregister_code(KC_QUOT); 
	} else {
		unregister_code(KC_RSFT);
		unregister_code(KC_QUOT);
	}
}

void td_scln_finished(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		register_code(KC_SCLN); 
	} else {
		register_code(KC_RSFT);
		register_code(KC_SCLN);
	}
}


void td_scln_reset(qk_tap_dance_state_t *state, void *user_data) {
	if(state->count == 1) {
		unregister_code(KC_SCLN); 
	} else {
		unregister_code(KC_RSFT);
		unregister_code(KC_SCLN);
	}
}


qk_tap_dance_action_t tap_dance_actions[] = {
	//TAPDANCE_BRACES = ACTION_TAP_DANCE_FN()
	[TD_MINUS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_minus_finished, td_minus_reset),
	[TD_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_plus_finished, td_plus_reset),
	[TD_QUOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_quote_finished, td_quote_reset),
	[TD_SCLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_scln_finished, td_scln_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,------------------------------------------------.            ,------------------------------------------------.
 * |`-Lyr2|   1  |   2  |   3  |   4  |   5  | Lyr1 |            | Lyr1 |   6  |   7  |   8  |   9  |   0  |--Lyr2|
 * |------+------+------+------+------+------+------|            |------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  [   |            |   ]  |   Y  |   U  |   I  |   O  |   P  |   =  |
 * |------+------+------+------+------+------+------|            |------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  | PgUp |            | End  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+------|            |------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  | PgDn |            | Home |   N  |   M  |   ,  |   .  |   \  |Shift |
 * |------+------+------+------+------+------+------|            |------+------+------+------+------+------+------|
 * |  Gui |   +  |   -  |*(Alt)|/(Ctr)|Bcksp | Del  |            |Enter |Space |  Alt | Left | Down |  Up  | Right|
 * `------------------------------------------------'            `------------------------------------------------'
 */
/*  [_QWERTY] = LAYOUT(
  //,----+----+----+----+----+----+----.                                                         ,----+----+----+----+----+----+----.
     LT(_NAV, KC_GRV) , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,MO(_SYMB),                           MO(_SYMB), KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,LT(_NAV, KC_MINS),
  //|----+----+----+----+----+----+----|                                                         |----+----+----+----+----+----+----|
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,KC_LBRC,                                       KC_RBRC , KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_EQL,
  //|----+----+----+----+----+----+----|                                                         |----+----+----+----+----+----+----|
     KC_ESC , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  , LT(_ADJUST, KC_PGUP),                         LT( _ADJUST, KC_END) , KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
  //|----+----+----+----+----+----+----|                                                         |----+----+----+----+----+----+----|
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_PGDN,                                      KC_HOME , KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_BSLASH, KC_RSFT,
  //|----+----+----+----+----+----+----|                                                         |----+----+----+----+----+----+----|
     KC_LGUI,KC_PPLS,KC_PMNS,LALT_T(KC_PAST),LCTL_T(KC_PSLS),KC_BSPC,KC_ENT,                     KC_ENT , KC_SPC, KC_RALT,KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT
  //`----+----+----+----+----+----+----'                                                         `----+----+----+----+----+----+----'
  ),
  */
  
  [_QWERTY] = LAYOUT(
  //,----+----+----+----+----+----+----.                                                         ,----+----+----+----+----+----+----.
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,LT(_SYMB, KC_BSPC),                           LT(_SYMB, KC_BSPC), KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , TD(TD_MINUS),
  //|----+----+----+----+----+----+----|                                                         |----+----+----+----+----+----+----|
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,KC_LBRC,                                       KC_RBRC , KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,TD(TD_PLUS),
  //|----+----+----+----+----+----+----|                                                         |----+----+----+----+----+----+----|
     LT(_NAV, KC_PIPE) , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  , LT(_ADJUST, KC_PGUP),                         LT( _ADJUST, KC_HOME) , KC_H  , KC_J  , KC_K  , KC_L  ,TD(TD_SCLN),TD(TD_QUOT),
  //|----+----+----+----+----+----+----|                                                         |----+----+----+----+----+----+----|
     KC_LSPO, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_PGDN,                                      KC_END , KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLASH, KC_RSPC,
  //|----+----+----+----+----+----+----|                                                         |----+----+----+----+----+----+----|
     KC_LGUI,LT(_ADJUST,KC_GRV),KC_DEL,KC_INS,LALT_T(KC_SLASH),KC_SPC,LCTL_T(KC_ENT) ,                     RCTL_T(KC_ENT) , KC_SPC, RALT_T(KC_BSLASH),KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT
  //`----+----+----+----+----+----+----'                                                         `----+----+----+----+----+----+----'
  ),  

/* Symbols
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |      |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |   !  |   @  |   {  |   }  |   |  |      |      |      |      |   7  |   8  |   9  |      | F12  |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |   #  |   $  |   [  |   ]  |   ~  |      |      |      |      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |   %  |   ^  |   (  |   )  |   `  |      |      |      |   0  |   1  |   2  |   3  |   .  |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  WNL |  WML |  WMR | WNR  |
 * `------------------------------------------------'      `------------------------------------------------'
 */

  [_SYMB] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                             _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, 
    _______, KC_EXLM, KC_AT ,  KC_LCBR, KC_RCBR, KC_PIPE, _______,                             _______, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, XXXXXXX, KC_F12, 
    _______, KC_HASH, KC_DLR , KC_LBRC, KC_RBRC, KC_GRV,  _______,                             _______, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX, XXXXXXX, 
    _______, KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN, KC_TILD, _______,                             _______, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, XXXXXXX, 
    _______, _______, _______, _______, _______, _______, _______,                             _______, _______, _______, LGUI(LCTL(KC_LEFT)), LGUI(LALT(KC_LEFT)), LGUI(LALT(KC_RIGHT)), LGUI(LCTL(KC_RIGHT)) 
  ),



/* Navigation
 * ,------------------------------------------------.      ,------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |MOUS_U|      |WHEL_U|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |MOUS_L|MOUS_D|MOUS_R|WHEL_D|      |      |      |      | LEFT | DOWN |  UP  |RIGHT |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------|      |------+------+------+------+------+------+------|
 * |      |      |      |      |MOUS_1|MOUS_2|      |      |      |      |      |      |      |      |      |
 * `------------------------------------------------'      `------------------------------------------------'
 */
  [_NAV] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, _______,
    XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, KC_WH_U, LCTL(KC_T), _______,                            _______, XXXXXXX, XXXXXXX, LCTL(LSFT(LALT(KC_B))), XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, LCTL(LSFT(KC_A)), KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX, _______,                            _______, KC_LEFT, KC_DOWN, LCTL(LSFT(LALT(KC_B))), KC_RIGHT,XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LSFT(LCTL(KC_B)), _______,                            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, _______,                            _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [_ADJUST] = LAYOUT(
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_VOLD,
    XXXXXXX, RESET  , RGB_M_P, RGB_TOG, RGB_MOD, RGB_HUD, LCTL(KC_T),                            RGB_SAD, RGB_SAI, RGB_VAD, LCTL(LSFT(LALT(KC_B))), XXXXXXX, KC_DEL,  KC_VOLU,
    XXXXXXX, LCTL(LSFT(KC_A)), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LSFT(LCTL(KC_B)), XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

