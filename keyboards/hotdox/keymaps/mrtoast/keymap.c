/*
 * Mr. Toastman
 */

#include QMK_KEYBOARD_H
#include "version.h"
/*
enum hotdox_layers {
    _BASE
    _FUNC
    _NUMPAD
};
*/

#define _BASE 0 // default layer
#define _FUNC 1 // function layer
#define _NUM  2 // numpad layer

#define LAY_0 TG(_BASE)
#define LAY_1 TG(_FUNC)
#define LAY_2  TG(_NUM)

enum hotdox_keycodes {
  VRSN = SAFE_RANGE,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |   1  |   2  |   3  |   4  |   5  |   6  |           |   6  |   7  |   8  |   9  |   0  |   -  |    =   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |   Q  |   W  |   E  |   R  |   T  |   [  |           |   ]  |   Y  |   U  |   I  |   O  |   P  |    '   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  | RShift |
 * |--------+------+------+------+------+------|   {  |           |   }  |------+------+------+------+------+--------|
 * |  Ctrl  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RCtrl  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   `  |  OS  | Alt  | Caps |PrtScn|                                       | Left |  Up  | Down | Right|   \  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | TG(1)| TG(2)|       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | PgUp |       | Home |      |      |
 *                                 | Back | DEL  |------|       |------| Enter| Space|
 *                                 | Space|      | PdDn |       | End  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_BASE] = LAYOUT_ergodox(
        // left hand
        KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_LBRC,
        KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,
        KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_LCBR,
        KC_GRV , KC_LGUI, KC_LALT, KC_CAPS, KC_PSCR, 
	                                                 LAY_1  , LAY_2  ,
                                                              KC_PGUP,
                                            KC_BSPC, KC_DEL , KC_PGDN,
	
        // right hand
        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, KC_EQL ,
        KC_RBRC, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_QUOT,
	             KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_RSFT,
        KC_RCBR, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
                          KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_BSLS,
        KC_NO  , KC_NO ,
        KC_HOME,
        KC_END , KC_ENT , KC_SPC
    ),
	
/* Keymap 1: Function layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  UP  |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | LEFT |      | RIGHT|      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | DOWN |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Function Layer
[_FUNC] = LAYOUT_ergodox(
        // left hand
        KC_TRNS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,
        KC_TRNS, KC_NO  , KC_UP  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_TRNS, KC_LEFT, KC_NO  , KC_RGHT, KC_NO  , KC_NO  ,
        KC_TRNS, KC_NO  , KC_DOWN, KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_TRNS, KC_TRNS, KC_NO  , KC_NO  ,
                                                     KC_TRNS, KC_TRNS,
                                                              KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                 KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  ,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),

/* Keymap 2: Numpad layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      | NUM  |  /   |  *   |  -   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  7   |  8   |  9   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |  4   |  5   |  6   |  ,   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  1   |  2   |  3   |  =   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   |  0   |  .   | ENT  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Numpad Layer
[_NUM] = LAYOUT_ergodox(
        // left hand
        KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_TRNS, KC_TRNS, KC_NO  , KC_NO  ,
                                                     KC_TRNS, KC_TRNS,
                                                              KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_NO  , KC_NO  , KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO  ,
        KC_NO  , KC_NO  , KC_P7  , KC_P8  , KC_P9  , KC_PPLS, KC_NO  ,
                 KC_NO  , KC_P4  , KC_P5  , KC_P6  , KC_NO  , KC_TRNS,
        KC_NO  , KC_NO  , KC_P1  , KC_P2  , KC_P3  , KC_NO  , KC_TRNS,
                          KC_P0  , KC_P0  , KC_PDOT, KC_PENT, KC_NO  ,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    )
};

/* Layer Templates : BLANK
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
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
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 *
// Blank layer
[_BLANK] = LAYOUT_ergodox(
        // left hand
        KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_TRNS, KC_TRNS, KC_NO  , KC_NO  ,
                                                     KC_TRNS, KC_TRNS,
                                                              KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                 KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS,
        KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  ,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
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

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};
