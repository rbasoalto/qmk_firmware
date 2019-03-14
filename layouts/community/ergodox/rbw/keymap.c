#include QMK_KEYBOARD_H
#include QMK_KEYBOARD_CONFIG_H
#include "debug.h"
#include "action_layer.h"

#ifdef KEYBOARD_ergodox_infinity
#include "visualizer/lcd_backlight.h"
#endif

#include "rbw_defs.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | esc    |   1  |   2  |   3  |   4  |   5  |  `~  |           |  \|  |   6  |   7  |   8  |   9  |   0  |   =+   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   F  |   P  |   G  |(Ralt)|           |(Ralt)|   J  |   L  |   U  |   Y  |  ;:  |   -_   |
 * |--------+------+------+------+------+------| Caps |           | Del  |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   E  |   I  |   O  |   '"   |
 * |--------+------+------+------+------+------| LCmd |           | RCmd |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |  ,<  |  .>  |  /?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~SY  | Del  | Lalt | Left | Right|                                       |  Up  | Down |  [{  |  ]}  | ~MD  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Lalt | SY/PS|       |MD/ins| Ralt |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       | PgUp |      |      |
 *                                 | Space| Bksp |------|       |------| Tab  |Enter |
 *                                 |      |      | End  |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[QWER] = LAYOUT_ergodox(  // layer 0 : default (HW qwerty)
        // left hand
        KC_ESC,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_GRV,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       RALT_T(KC_CAPS),
        KC_LCTRL,   KC_A,       KC_S,       KC_D,       KC_F,       KC_G,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_LGUI,
        KC_FN1,     KC_DEL,     KC_LALT,    KC_LEFT,    KC_RIGHT,
                                                                    KC_LALT,    LT(SYMB,KC_PSCR),
                                                                                KC_HOME,
                                                        KC_SPC,     KC_BSPC,    KC_END,
        // right hand
        KC_BSLS,        KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_EQL,
        RALT_T(KC_DEL), KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_MINUS,
                        KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_RGUI,        KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                    KC_UP,      KC_DOWN,    KC_LBRC,    KC_RBRC,    KC_FN2,
        LT(MDIA,KC_INS),   KC_RALT,
        KC_PGUP,
        KC_PGDN,        KC_TAB,     KC_ENT
    ),
[COLE] = LAYOUT_ergodox(  // layer 1 : Colemak
        // left hand
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_Q,       KC_W,       KC_F,       KC_P,       KC_G,       KC_TRNS,
        KC_TRNS,    KC_A,       KC_R,       KC_S,       KC_T,       KC_D,
        KC_TRNS,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                    KC_TRNS,    KC_TRNS,
                                                                                KC_TRNS,
                                                        KC_TRNS,    KC_TRNS,    KC_TRNS,
        // right hand
        KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_TRNS,
                        KC_H,       KC_N,       KC_E,       KC_I,       KC_O,       KC_TRNS,
        KC_TRNS,        KC_K,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_TRNS,
                                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_TRNS,
        KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS
    ),
[RCOL] = LAYOUT_ergodox(  // layer 2 : HW REVERSE colemak
        // left hand
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_Q,       KC_W,       KC_K,       KC_S,       KC_F,       KC_TRNS,
        KC_TRNS,    KC_A,       KC_D,       KC_G,       KC_E,       KC_T,
        KC_TRNS,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                                    KC_TRNS,    KC_TRNS,
                                                                                KC_TRNS,
                                                        KC_TRNS,    KC_TRNS,    KC_TRNS,
        // right hand
        KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_O,       KC_I,       KC_L,       KC_SCLN,    KC_R,       KC_TRNS,
                        KC_H,       KC_Y,       KC_N,       KC_U,       KC_P,       KC_TRNS,
        KC_TRNS,        KC_J,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_TRNS,
                                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,        KC_TRNS,
        KC_TRNS,
        KC_TRNS,        KC_TRNS,    KC_TRNS
    ),
/* Keymap 1: Symbol Layer (layer 3)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |  p*  |  p7  |  p8  |  p9  |  p-  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------|  p/  |  p4  |  p5  |  p6  |  p+  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |  p0  |  p1  |  p2  |  p3  | pENT |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |  p.  |  p0  | pENT |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_PAST, KC_P7,  KC_P8,   KC_P9,   KC_PMNS, KC_F12,
                KC_PSLS, KC_P4,  KC_P5,   KC_P6,   KC_PPLS, KC_TRNS,
       KC_TRNS, KC_P0,   KC_P1,  KC_P2,   KC_P3,   KC_PENT, KC_TRNS,
                         KC_TRNS,KC_PDOT, KC_P0,   KC_PENT, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys (layer 4)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Eject | COLE | RCOL |      |      |      |      |           |      |      |      |      |      | RESET| POWER  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |  Up  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | Left | Down |Right |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       | Vol+ | Vol- | MUTE |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Lclk | Rclk |------|       |------|  <<  |  >>  |
 *                                 |      |      |      |       | Play |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_EJCT, KC_FN3,  KC_FN4,  KC_FN5,  KC_FN6,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_WH_U,
                                  KC_BTN1, KC_BTN2, KC_WH_D,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_PWR,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_MPLY, KC_MPRV, KC_MNXT
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),                // FN1 - Momentary Layer 5 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(MDIA),                // FN2 - Momentary Layer 6 (Media)
    [3] = ACTION_LAYER_TAP_TOGGLE(COLE),                // FN3 - Momentary Layer 1 (HW Colemak)
    [4] = ACTION_LAYER_TAP_TOGGLE(RCOL),                // FN4 - Momentary Layer 2 (HW REVERSE COLEMAK)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  print("matrix_init_user yay\n");
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case QWER:
	case COLE:
        case RCOL:
            break;
        case SYMB:
            ergodox_right_led_1_on();
            break;
        case MDIA:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
    if ((layer_state & COLE) || (layer_state & RCOL)) {
        // HW Colemak or Rcolemak is on
        ergodox_right_led_3_on();
    }
};
