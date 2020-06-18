#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _FLOAT 1

bool recording = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: Main layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │<- │-> │Esc│1 !│2 "│3 £│4 $│5 %│6 ^│7 &│8 *│9 (│0 )│- _│= +│Bksp   │RGB│
   * ├───┼───┼───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │F13│F14│Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │[ {│] }│\ |  │ ` │
   * ├───┼───┼─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │F15│F16│CapsLk│ A │ S │ D │ F │ G │ H │ J │ K │ L │; :│' "│Enter   │ ~ │
   * ├───┼───┼──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │F17│F18│Shift   │ Z │ X │ C │ V │ B │ N │ M │, <│. >│/ ?│Shift │Up │<3 │
   * ├───┼───┼────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │MP1│MP2│Ctrl│GUI │Alt │Space                   │Alt│Fn │Ctl│Lft│Dwn│Rgt│
   * └───┴───┴────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  /* 0: ANSI qwerty */
  [_QWERTY] = LAYOUT_ansi(
    LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RIGHT)), KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, RGB_TOG,
    KC_F13, KC_F14, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
    KC_F15, KC_F16, MO(_FLOAT), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENTER, LSFT(KC_GRV),
    KC_F17, KC_F18, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, UC(0x2661) /* ♡ */,
    DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),


  /* 1: LED layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │RST│   │GRV│ F1│ F2│ F3│F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ DEL   │BSt│
   * ├───┼───┼───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │   │   │     │   │   │   │   │   │   │   │   │Up │   │   │   │     │VL+│
   * ├───┼───┼─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │CPS│IME│      │   │   │   │   │   │   │Lft│Dn │Rht│INS│   │    END │VL-│
   * ├───┼───┼──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │   │   │        │Rm+│Rm-│Rh+│RH-│Rs+│RS-│RV+│RV-│   │   │      │VUp│STP│
   * ├───┼───┼────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │MR1│MR2│ MCS│    │    │          File          │   │   │   │Prv│VDn│Nxt│
   * └───┴───┴────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  [_FLOAT] = LAYOUT_ansi(
    RESET, KC_TRANSPARENT, KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, UNICODE_MODE_WINC, KC_UP, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_VOLU,
    KC_CAPSLOCK, LALT(KC_GRV), KC_TRNS, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT, KC_DOWN, KC_RGHT, KC_INS, KC_TRANSPARENT, KC_END, KC_VOLD,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_MODE_FORWARD, RGB_MODE_REVERSE, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_STOP,
    DYN_REC_START1, DYN_REC_START2, DYN_REC_STOP, KC_TRANSPARENT, KC_TRANSPARENT, KC_MYCM, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  )
};

void dynamic_macro_record_start_user(void) {
    recording = true;
}

void dynamic_macro_record_end_user(int8_t direction) {
    recording = false;
    layer_state_set_user(layer_state);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // set lighting effect based on what layer i'm in
    if(recording) {
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD);
        return state;
    }
    if(layer_state_cmp(state, _QWERTY)) { // if default
        rgblight_mode(RGBLIGHT_MODE_TWINKLE + 5);
    }
    if(layer_state_cmp(state, _DEFAULT)) { // if fn
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 5);
    }
    return state;
}

bool led_update_user(led_t led_state) {
    if(led_state.caps_lock) { //if capslock
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 4);
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {
    rgblight_mode(RGBLIGHT_MODE_TWINKLE + 5);
}
