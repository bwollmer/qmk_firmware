#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define I3 3 // i3 navigation
#define PSB 4 // i3 navigation
#define PSN 5 // i3 navigation

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | ~PSB |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
 * |--------+------+------+------+------+------| ESC  |           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  | B/I3 |      |           |      | N/I3 |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~L1  |  '   |      | LALT | CTRL |                                       | RAlt | Win  |  W_D |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | PgUP | Win  |       |      |PgDwn |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Print |       | Ins  |        |      |
 *                                 | Space|Backsp|------|       |------|  ~L1   |Enter |
 *                                 |      |ace   |Hme/I3|       |End/I3|        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_GRAVE,       KC_1,         KC_2,     KC_3,    KC_4,     KC_5,           TG(PSB),
        KC_DELT,        KC_Q,         KC_W,     KC_E,    KC_R,     KC_T,           KC_TRNS,
        KC_TAB,         KC_A,         KC_S,     KC_D,    KC_F,     KC_G,
        KC_LSFT,        KC_Z,         KC_X,     KC_C,    KC_V,     LT(I3,KC_B),    KC_ESC,
        KC_FN1,         KC_QUOT,      KC_TRNS,  KC_LALT, KC_LCTRL,
                                                             KC_PGUP,       KC_RGUI,
                                                                            KC_PSCR,
                                                     KC_SPC, KC_BSPC, LT(I3,KC_HOME),
        // right hand
             KC_TRNS,             KC_6,   KC_7,    KC_8,    KC_9,       KC_0,              KC_MINS,
             KC_TRNS,             KC_Y,   KC_U,    KC_I,    KC_O,       KC_P,              KC_EQL,
                                  KC_H,   KC_J,    KC_K,    KC_L,       LT(MDIA, KC_SCLN), KC_QUOT,
             MEH_T(KC_NO), LT(I3,KC_N),   KC_M,    KC_COMM, KC_DOT,     CTL_T(KC_SLSH),    RSFT_T(KC_BSLS),
                                   KC_RALT, KC_RGUI, RGUI(KC_D), KC_TRNS,           KC_TRNS,
             KC_TRNS,       KC_PGDN,
             KC_INS,
             LT(I3,KC_END), KC_FN1, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |     |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                               KC_TRNS,KC_TRNS,
                                                       KC_TRNS,
                                       KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |WheelD| MsUp |WheelU|      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| Left | Down |  UP  | Right|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |Brwser|Brwser|
 *                                 |      |      |------|       |------|Back  |Fwd   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WH_U, KC_MS_U, KC_WH_D, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                                    KC_TRNS, KC_TRNS,
                                                             KC_TRNS,
                                           KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_WBAK, KC_WFWD
),
/* Keymap 3: i3 navigation
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |  W_4 |      |  W_3 |      |           |      |W_S_H |W_S_J |W_S_K |W_S_L |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  W_0 |      |  W_D | W_F  |  W_9 |------|           |------| W_H  | W_J  | W_K  | W_L  |      |        |
 * |--------+------+------+------+------+------|W_S_Q |           |  W_A |------+------+------+------+------+--------|
 * |        |      |      |  W_2 |      |  W_1 |      |           |      |W_C_H |W_C_J |W_C_K |W_C_L |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      | W_5  | W_6  | W_7  | W_8  |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |   W_`|      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |  W_' |  W_  |
 *                                 |      |      |------|       |------|      |Enter |
 *                                 |      |      |      |       | W_-  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// I3
[I3] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS,       KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
       KC_TRNS, RGUI(S(KC_Q)), KC_TRNS,    RGUI(KC_4), KC_TRNS,     RGUI(KC_3), KC_TRNS,
       KC_TRNS, RGUI(KC_0),    KC_TRNS,    RGUI(KC_D), RGUI(KC_F),  RGUI(KC_9),
       KC_TRNS, KC_TRNS,       KC_TRNS,    RGUI(KC_2), KC_TRNS,     RGUI(KC_1), RGUI(S(KC_Q)),
       KC_TRNS, RGUI(KC_5),    RGUI(KC_6), RGUI(KC_7), RGUI(KC_8),
                                                                 RGUI(KC_GRAVE), KC_TRNS,
                                                                                 KC_TRNS,
                                                        KC_TRNS, KC_TRNS,        KC_TRNS,
    // right hand
       KC_TRNS,    KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,
       KC_TRNS,    RGUI(S(KC_H)),    RGUI(S(KC_J)),    RGUI(S(KC_K)),    RGUI(S(KC_L)),    KC_TRNS, KC_TRNS,
                   RGUI(KC_H),       RGUI(KC_J),       RGUI(KC_K),       RGUI(KC_L),       KC_TRNS, KC_TRNS,
       RGUI(KC_A), RGUI(LCTL(KC_H)), RGUI(LCTL(KC_J)), RGUI(LCTL(KC_K)), RGUI(LCTL(KC_L)), KC_TRNS, KC_TRNS,
                                   KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS,
       KC_TRNS,       KC_TRNS,
       KC_TRNS,
       RGUI(KC_MINS), RGUI(KC_QUOT), RGUI(KC_ENT)
),
/* Photoshop
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  | ~PSN |           |      |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|   '    |
 * |--------+------+------+------+------+------| ESC  |           | Meh  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~L1  |  I   |   H  | LALT | CTRL |                                       | RAlt | Win  |  W_D |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |C+S(N)| Win  |       |      |PgDwn |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Alt+] |       | Ins  |        |      |
 *                                 | Space|Backsp|------|       |------|  ~L1   |Enter |
 *                                 |      |ace   |Alt+[ |       |End/I3|        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[PSB] = LAYOUT_ergodox(
        // left hand
        KC_GRAVE,       KC_1,         KC_2,     KC_3,    KC_4,     KC_5,            KC_TRNS,
        KC_DELT,        KC_Q,         KC_W,     KC_E,    KC_R,     KC_T,            KC_TRNS,
        KC_TAB,         KC_A,         KC_S,     KC_D,    KC_F,     KC_G,
        KC_LSFT,        KC_Z,         KC_X,     KC_C,    KC_V,     LT(PSN,KC_B),    KC_ESC,
        KC_FN1,         KC_I,         KC_H,     KC_LALT, KC_LCTRL,
                                                    LCTL(LSFT(KC_N)),           KC_RGUI,
                                                                      LALT(KC_RBRACKET),
                                                     KC_SPC, KC_BSPC, LALT(KC_LBRACKET),
        // right hand
        KC_TRNS,      KC_6,   KC_7,    KC_8,    KC_9,       KC_0,              KC_MINS,
        KC_TRNS,      KC_Y,   KC_U,    KC_I,    KC_O,       KC_P,              KC_EQL,
                      KC_H,   KC_J,    KC_K,    KC_L,       LT(MDIA, KC_SCLN), KC_QUOT,
        MEH_T(KC_NO), KC_N,   KC_M,    KC_COMM, KC_DOT,     CTL_T(KC_SLSH),    RSFT_T(KC_BSLS),
                              KC_RALT, KC_RGUI, RGUI(KC_D), KC_TRNS,           KC_TRNS,
             KC_TRNS,       KC_PGDN,
             KC_INS,
             LT(I3,KC_END), KC_FN1, KC_ENT
    ),
/* Photoshop_Numbers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  6   |   7  |   8  |   9  |   0  |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[PSN] = LAYOUT_ergodox(
        // left hand
        KC_TRNS,       KC_6,            KC_7,        KC_8,       KC_9,        KC_0,       KC_TRNS,
        KC_TRNS,       KC_TRNS,         KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
        KC_TRNS,       KC_TRNS,         KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,
        KC_TRNS,       KC_TRNS,         KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
          KC_TRNS,     KC_TRNS,         KC_TRNS,     KC_TRNS,    KC_TRNS,
                                                                                 KC_TRNS, KC_TRNS,
                                                                                          KC_TRNS,
                                                                        KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_TRNS,      KC_TRNS,          KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
        KC_TRNS,      KC_TRNS,          KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
                      KC_TRNS,          KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
        KC_TRNS,      KC_TRNS,          KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
                                        KC_TRNS,     KC_TRNS,    KC_TRNS,     KC_TRNS,    KC_TRNS,
        KC_TRNS,       KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
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
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
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
