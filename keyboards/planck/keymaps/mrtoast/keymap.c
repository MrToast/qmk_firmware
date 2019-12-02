/* 
 * Mr. Toastman
 */

#include QMK_KEYBOARD_H
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
  NUMPAD
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define NUMPAD MO(_NUMPAD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  -_  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  \|  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |  OS  | Alt  | MO-4 |Lower |    Space    |Raise | Left |  Up  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R  , KC_T  , KC_Y  , KC_U  , KC_I  ,  KC_O ,  KC_P   , KC_MINS,
    KC_LSFT, KC_A   , KC_S   , KC_D   , KC_F  , KC_G  , KC_H  , KC_J  , KC_K  ,  KC_L ,  KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z   , KC_X   , KC_C   , KC_V  , KC_B  , KC_N  , KC_M  , KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
    KC_ESC , KC_LGUI, KC_LALT, NUMPAD , LOWER , KC_SPC, KC_SPC, RAISE , KC_LEFT, KC_UP , KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -_  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  +=  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      |      |      |      |  BACKSPACE  |      | HOME | PG UP| PG DN| END  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TRNS, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
    KC_TRNS, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL ,
    KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_TRNS,
    KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_BSPC, KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   |  |      |   ~  |   (  |      |      |   )  |   |  |      |  -_  |  DEL |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  \|  |      |  `~  |   [  |      |      |   ]  |  \|  |      |  '"  |  '"  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |   -  |   {  |      |      |   }  |   _  |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CAPS |      |      |      |      |    ENTER    |      | HOME | PG UP| PG DN| END  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV , KC_PIPE, KC_NO  , KC_TILD, KC_LPRN, KC_NO  , KC_NO  , KC_RPRN, KC_PIPE, KC_NO  , KC_MINS, KC_DEL ,
    KC_TRNS, KC_BSLS, KC_NO  , KC_GRV , KC_LBRC, KC_NO  , KC_NO  , KC_RBRC, KC_BSLS, KC_NO  , KC_QUOT, KC_QUOT,
    KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_LCBR, KC_NO  , KC_NO  , KC_RCBR, KC_NO  , KC_NO  , KC_NO  , KC_TRNS,
    KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  , KC_ENT , KC_DEL , KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN, KC_END
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Reset| Debug| RGB+/| RGB+ | RGB- | HUE+ | HUE- | SAT+ | SAT- |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      | AUD+/|      |      | LIT+ | LIT- | EFX+ | EFX- |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 ,
    KC_TRNS, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_RMOD,RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, KC_NO  , KC_TRNS,
    KC_TRNS, KC_NO  , MU_MOD,  AU_TOG , KC_NO  , KC_NO  , RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, KC_NO  , KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* NUMPAD (MO(4))
 * ,-----------------------------------------------------------------------------------.
 * |      | NUM  |  /   |  *   |  -   |      |      |      |   7  |   8  |   9  |  +   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   4  |   5  |   6  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   1  |   2  |   3  | ENTER|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    DELETE   |      |   0  |   ,  |   .  | BKSP |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    KC_TRNS, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_NO  , KC_NO  , KC_NO  , KC_P7  , KC_P8  , KC_P9  , KC_PPLS,
    KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_P4  , KC_P5  , KC_P6  , KC_PEQL,
    KC_TRNS, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_P1  , KC_P2  , KC_P3  , KC_PENT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO  , KC_DEL , KC_ENT , KC_NO  , KC_P0  , KC_PCMM, KC_PDOT, KC_BSPC
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          PORTE &= ~(1<<6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          PORTE |= (1<<6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_DOWN);
        unregister_code(KC_MS_WH_DOWN);
      #else
        register_code(KC_PGDN);
        unregister_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        register_code(KC_MS_WH_UP);
        unregister_code(KC_MS_WH_UP);
      #else
        register_code(KC_PGUP);
        unregister_code(KC_PGUP);
      #endif
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
