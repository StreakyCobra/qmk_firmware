#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define PROG 1 // programmation layer
#define PADS 2 // pads layer

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   =    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTRL |  [   |   ]  | Alt  | Alt  |                                       |Up/L1 |Dwn/L2|      |   \  | CTRL |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Del  |      |       | Home  | End |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       | PgUp |        |      |
 *                                 |Backsp| LGui |------|       |------| Enter  |Space |
 *                                 |ace   |      | Caps |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_GRV,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_NO,
  KC_TAB,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_NO,
  KC_ESC,          KC_A,        KC_S,          KC_D,    KC_F,    KC_G,
  KC_LSFT,         CTL_T(KC_Z), KC_X,          KC_C,    KC_V,    KC_B,    KC_NO,
  KC_LCTRL,        KC_LBRC,     KC_RBRC,       KC_LALT, KC_LALT,
                                                                 KC_NO,   KC_NO,
                                                                          KC_NO,
                               MT(MOD_LGUI, KC_BSPC), MT(MOD_LGUI, KC_DELT), KC_CAPS,
  // right hand
  KC_NO,        KC_6,    KC_7,    KC_8,    KC_9,              KC_0,           KC_MINS,
  KC_NO,        KC_Y,    KC_U,    KC_I,    KC_O,              KC_P,           KC_EQL,
                KC_H,    KC_J,    KC_K,    KC_L,           KC_SCLN,           KC_QUOT,
  KC_NO,        KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_T(KC_SLSH),           RSFT_T(KC_SLCK),
     LT(PROG, KC_UP),   LT(PADS, KC_DOWN), KC_NO,          KC_BSLS,           KC_RCTRL,
  KC_HOME, KC_END,
  KC_PGUP,
  KC_PGDN, KC_ENT, KC_SPC
),
/* Keymap 1: Programmation layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   [  |   ]  |   |  |  *   |           |      |      | HOME | END  |      |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Left | Down |  Up  |Right |      |        |
 * |---------+------+------+------+------+------|  &   |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   {  |   }  |   ~  |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[PROG] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,
  KC_NO,   KC_EXLM, KC_AT,   KC_LBRC, KC_RBRC, KC_PIPE, KC_ASTR,
  KC_NO,   KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
  KC_NO,   KC_PERC, KC_CIRC, KC_LCBR, KC_RCBR, KC_TILD, KC_AMPR,
  KC_TRNS,    KC_NO, KC_NO, KC_NO, KC_NO,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS,        KC_F6,      KC_F7,      KC_F8,      KC_F9,                KC_F10,            KC_F11,
  KC_TRNS,        KC_TRNS,    KC_HOME,    KC_END,     KC_TRNS,              KC_TRNS,           KC_F12,
                  KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,              KC_TRNS,           KC_TRNS,
  KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,              KC_TRNS,           KC_TRNS,
                              KC_TRNS,    KC_TRNS,    KC_TRNS,              KC_TRNS,           KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Pads layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           | Mute |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      | MsUp |      |      |      |           | Vol  |   -  |   7  |   8  |   9  |   *  |        |
 * |---------+------+------+------+------+------|      |           | Up   |------+------+------+------+------+--------|
 * |         |      |MsLeft|MsDown|MsRght|      |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           | Vol  |------+------+------+------+------+--------|
 * |         |      | Prev | Play | Next |      |      |           | Down |      |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      | Lclk | Lclk |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 |      |      |------|       |------|        |      |
 *                                 |      |      |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[PADS] = LAYOUT_ergodox(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_VOLU, KC_MINS, KC_7,    KC_8,    KC_9,    KC_ASTR, KC_TRNS,
           KC_NO,   KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_VOLD, KC_NO,   KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                    KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
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
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
