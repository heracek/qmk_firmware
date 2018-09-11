#include QMK_KEYBOARD_H

#define TG_NKRO MAGIC_TOGGLE_NKRO

enum jj40_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNC
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
 * | Tab  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   :  |      |
 * | Esc  |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   <  |   >  |   ?  |      |
 * |Shift |   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |  Fn  | Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,   KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_GESC,   KC_A,    KC_S,    KC_D,    KC_F,       KC_G,   KC_H,   KC_J,       KC_K,    KC_L,    KC_SCLN, KC_ENT , \
  KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,   KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
  MO(_FUNC), KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_SPC, MO(_RAISE), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

 /* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   Ą  |   Č  |   Ę  |   Ė  |   Į  |   Š  |   Ų  |   "  |   _  |   +  |      |
 * |   `  |   ą  |   č  |   ę  |   ė  |   į  |   š  |   ų  |   '  |   -  |   =  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |   ~  |   "  |      |   {  |   }  |      |      |      |      |      |
 * |Shift |   |  |   `  |   '  |   "  |   [  |   ]  |   <  |   >  |   {  |   }  | Ins  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      ||||||||      |      |      |      |      |      |      |
 * |      | Ctrl | Alt  | GUI  |Lower||Space |Space |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_QUOT, KC_MINS, KC_EQL,  KC_BSPC, \
  KC_GESC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL , \
  KC_LSFT, KC_PIPE, KC_GRV,  KC_QUOT, KC_DQUO, KC_LBRC, KC_RBRC, KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, KC_INS , \
  _______, KC_LCTL, KC_LALT, KC_LGUI, _______,  KC_SPC,  KC_SPC, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
),

 /* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   $  |   %  |   ^  |      |      |      |      |   +  |      |   _  |      |
 * | Esc  |   4  |   5  |   6  |   +  |   -  |   *  |   /  |   =  |   _  |   -  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   &  |   *  |   (  |   )  |      |      |      |   <  |   >  |   |  |      |
 * |Shift |   7  |   8  |   9  |   0  |   (  |   )  |   .  |   ,  |   .  |   \  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      ||||||||      |      |      |      |
 * |      | Ctrl | Alt  | GUI  |      |Space |Space |Raise|| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_GESC, KC_4,    KC_5,    KC_6,    KC_PPLS, KC_PMNS, KC_PAST, KC_PSLS, KC_EQL,  KC_UNDS, KC_MINS, KC_ENT , \
  KC_LSFT, KC_7,    KC_8,    KC_9,    KC_0,    KC_LPRN, KC_RPRN, KC_PDOT, KC_COMM, KC_DOT,  KC_BSLS, KC_RSFT, \
  _______, KC_LCTL, KC_LALT, KC_LGUI, _______, KC_SPC,  KC_SPC,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

 /* Functions
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Mouse | RGB  | RGB  | RGB  | RGB  | Scrn |MouseW|Mouse |MouseW|Mouse |      |
 * | Caps | BTN2 | Hue+ | Sat+ | Brt+ | Togl | Brt+ | Left |  Up  |Right | Down | Vol+ |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Mouse | RGB  | RGB  | RGB  | RGB  | Scrn |Mouse |Mouse |Mouse |Mouse |      |
 * |Shift | BTN1 | Hue- | Sat- | Brt- | Mode | Brt- | Left | Down |Right |  Up  | Vol- |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * ||||||||      |      |      |      |      |      |      |      |      |      |      |
 * |||Fn||| Ctrl | Alt  | GUI  | NKRO |Space |Space |      |MPrev |MStop |MPlay |MNext |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNC] = LAYOUT_ortho_4x12( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 , \
  KC_CAPS, KC_BTN2, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, KC_PAUS, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_D, KC_VOLU, \
  KC_LSFT, KC_BTN1, RGB_HUD, RGB_SAD, RGB_VAD, RGB_MOD, KC_SLCK, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U, KC_VOLD, \
  _______, KC_LCTL, KC_LALT, KC_LGUI, TG_NKRO, KC_SPC,  KC_SPC,  _______, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT  \
)
};

// Loop
void matrix_scan_user(void) {
  // Empty
};
