// #include QMK_KEYBOARD_H
#include "ergodox_ez.h"
#include "action_layer.h"
// #include "debug.h"
#include "version.h"
// #include "raw_hid.h"

#define MY_HID_REPORT 0x02
#define MY_HID_CMD 0x01
#define MOD_F13(xkc) (M_F13_BEGIN + xkc)

enum my_hid_commands {
  C_NONE = 0,
  C_TOGGLE_LED,
  C_SET_COLOR_HSV
}; 

enum my_hid_reports {
  R_NONE = 0,
  R_LAYER_CHANGE
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
  PHPSTART,
  PHPEND,
  BACKTICK,
  M_F13_BEGIN,
  M_F13_END = M_F13_BEGIN + 255
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, LGUI(KC_R), MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LGUI, KC_LCTRL, KC_NONUS_BSLASH, KC_LGUI, KC_LALT, MO(3), KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_TRNS, KC_SPACE, OSL(4), KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_LBRACKET, KC_BSPACE, KC_TRNS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NONUS_HASH, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, KC_ENTER, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT, MO(3), KC_RALT, KC_APPLICATION, KC_TRNS, KC_RCTRL, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_TRNS, MO(2), OSL(4), KC_SPACE),
  [1] = LAYOUT_ergodox(KC_TRNS, MOD_F13(KC_1), MOD_F13(KC_2), MOD_F13(KC_3), MOD_F13(KC_4), MOD_F13(KC_5), KC_TRNS, KC_TRANSPARENT, MOD_F13(KC_Q), MOD_F13(KC_W), MOD_F13(KC_E), MOD_F13(KC_R), MOD_F13(KC_T), KC_TRNS, KC_TRNS, KC_TRNS, LALT(LCTL(LSFT(KC_S))), KC_LALT, KC_LSHIFT, KC_TRNS, KC_TRNS, KC_TRNS, MOD_F13(KC_X), MOD_F13(KC_C), MOD_F13(KC_V), MOD_F13(KC_B), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_MOD, RGB_SLD, RGB_VAI, KC_LCTL, RGB_TOG, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DELETE, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_TRNS, KC_ENTER, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN, KC_TRNS, KC_TRNS, KC_BSPACE, KC_TRNS, KC_TRNS, RGB_MODE_GRADIENT, RGB_MODE_XMAS, RGB_MODE_KNIGHT, RGB_MODE_SNAKE, RGB_MODE_SWIRL, RGB_MODE_RAINBOW, RGB_MODE_BREATHE, RGB_MODE_PLAIN, KC_TRNS, KC_SYSTEM_SLEEP, RGB_MODE_RAINBOW, RGB_HUI, KC_TRNS, KC_TRNS),
  [2] = LAYOUT_ergodox(KC_TRNS, KC_NUMLOCK, KC_KP_7, KC_KP_8, KC_KP_9, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_4, KC_KP_5, KC_KP_6, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_1, KC_KP_2, KC_KP_3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EEPROM_RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  [3] = LAYOUT_ergodox(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, LALT(KC_TAB), KC_TRNS, KC_NONUS_HASH, LSFT(KC_3), LSFT(KC_6), KC_TRNS, KC_TRNS, KC_TRNS, LSFT(KC_1), LSFT(KC_2), RALT(KC_2), RALT(KC_4), LSFT(KC_5), MO(5), KC_NONUS_BSLASH, LSFT(KC_NONUS_BSLASH), RALT(KC_NONUS_BSLASH), KC_NONUS_BSLASH, LSFT(KC_NONUS_BSLASH), LSFT(KC_NONUS_BSLASH), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPACE, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, LSFT(KC_RBRACKET), KC_TRNS, BACKTICK, LSFT(KC_7), RALT(KC_8), RALT(KC_9), KC_TRNS, RALT(KC_RBRACKET), LSFT(KC_0), RALT(KC_7), LSFT(KC_8), LSFT(KC_9), RALT(KC_0), KC_NONUS_HASH, KC_ENTER, KC_TRNS, RALT(KC_MINUS), LSFT(KC_MINUS), KC_MINUS, LSFT(KC_NONUS_HASH), MO(5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPACE),
  [4] = LAYOUT_ergodox(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRANSPARENT, KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRNS, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F11, KC_F12, KC_TRANSPARENT, KC_TRANSPARENT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_0, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),
  [5] = LAYOUT_ergodox(KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRNS, KC_TRNS, PHPSTART, PHPEND, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT)
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1) // FN1 - Momentary Layer 1 (Symbols)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  // MOD_F13
  if (M_F13_BEGIN <= keycode && keycode <= M_F13_END) {
      uint16_t realkeycode = keycode - M_F13_BEGIN;
      register_code(KC_F13);
      wait_ms(1);
      
      register_code(realkeycode);
      unregister_code(realkeycode);
      
      wait_ms(1);
      unregister_code(KC_F13);
      
      return false;
  }

  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
        rgblight_mode(1);
        #endif
      }
      return false;
      break;
    case PHPSTART:
      if (record->event.pressed) {
        // <?PHP
        SEND_STRING(SS_TAP(X_NONUS_BSLASH) SS_LSFT("-") "php ");
      }
      return false;
      break;
    case PHPEND:
      if (record->event.pressed) {
        // ?>
        SEND_STRING(SS_DOWN(X_LSHIFT) SS_TAP(X_MINUS) SS_TAP(X_NONUS_BSLASH) SS_UP(X_LSHIFT));
      }
      return false;
      break;
    case BACKTICK:
      if (record->event.pressed) {
        // `
        SEND_STRING(SS_LSFT("=") " ");
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void)
{
  #ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
  #endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void)
{

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state)
{
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);

  // Inform raw hid on layer change
  /*
  uint8_t data[RAW_EPSIZE];
  data[0] = MY_HID_REPORT;
  data[1] = R_LAYER_CHANGE;
  data[2] = layer;
  raw_hid_send(data, RAW_EPSIZE);
  */
  switch (layer) {
    case 0:
      /*
      #ifdef RGBLIGHT_COLOR_LAYER_0
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
      #else
      #ifdef RGBLIGHT_ENABLE
      rgblight_init();
      #endif
      #endif
      */
      break;
    case 1:
      ergodox_right_led_1_on();
      #ifdef RGBLIGHT_COLOR_LAYER_1
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
      #endif
      break;
    case 2:
      ergodox_right_led_2_on();
      #ifdef RGBLIGHT_COLOR_LAYER_2
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
      #endif
      break;
    case 3:
      ergodox_right_led_3_on();
      #ifdef RGBLIGHT_COLOR_LAYER_3
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
      #endif
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      #ifdef RGBLIGHT_COLOR_LAYER_4
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
      #endif
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      #ifdef RGBLIGHT_COLOR_LAYER_5
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
      #endif
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      #ifdef RGBLIGHT_COLOR_LAYER_6
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
      #endif
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      #ifdef RGBLIGHT_COLOR_LAYER_7
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
      #endif
      break;
    default:
      break;
  }

  return state;
};

/** \brief Raw HID Receive
 *
 * FIXME: Needs doc
__attribute__ ((weak))
void raw_hid_receive( uint8_t *data, uint8_t length )
{
  if (data[0] != MY_HID_CMD)
    return;

  uint8_t cmd = data[1];
  switch (cmd) {
    case C_TOGGLE_LED:
      rgblight_toggle();
      break;
    case C_SET_COLOR_HSV:
      rgblight_sethsv_noeeprom(data[2], data[3], data[4]);
      break;
  }
  raw_hid_send( data, length );
}
*/

