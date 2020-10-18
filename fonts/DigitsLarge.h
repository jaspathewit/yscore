
/*******************************************************************************
* Font for large digits, font contains "0123456789"
*******************************************************************************/

/*
 typedef struct {
     const uint8_t *data;
     uint16_t width;
     uint16_t height;
     uint8_t dataSize;
     } tImage;
 typedef struct {
     long int code;
     const tImage *image;
     } tChar;
 typedef struct {
     int length;
     const tChar *chars;
     } tFont;
*/

#ifndef DigitsLarge_h
#define DigitsLarge_h

#include <stdint.h>
#include "../TinyScreenExt.h"

#if (0x0 == 0x0)

static const uint8_t PROGMEM image_data_Digit_Large_0x30[165] = {
    // ∙∙░▓██▓░∙∙
    // ∙░██████░∙
    // ∙██▒∙∙▒██∙
    // ▒█▓∙∙∙∙▓█▒
    // ▓█░∙∙∙∙░█▓
    // ██∙∙∙∙∙∙██
    // ██∙∙∙∙∙∙██
    // ██∙∙∙∙∙∙██
    // ██∙∙∙∙∙∙██
    // ██∙∙∙∙∙∙██
    // ▓█░∙∙∙∙░█▓
    // ▒█▓∙∙∙∙▓█▒
    // ∙██▒∙∙▒██∙
    // ∙░██████░∙
    // ∙∙░▓██▓░∙∙

    0x00, 0x00, 0x49, 0xb6, 0xff, 0xff, 0xb6, 0x49, 0x00, 0x00, 0x00,
    0x00, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x49, 0x00, 0x00,
    0x00, 0xff, 0xff, 0x92, 0x00, 0x00, 0x92, 0xff, 0xff, 0x00, 0x00,
    0x6d, 0xff, 0xb6, 0x00, 0x00, 0x00, 0x00, 0xb6, 0xff, 0x6d, 0x00,
    0xb6, 0xff, 0x49, 0x00, 0x00, 0x00, 0x00, 0x49, 0xff, 0xb6, 0x00,
    0xdb, 0xff, 0x24, 0x00, 0x00, 0x00, 0x00, 0x24, 0xff, 0xdb, 0x00,
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00,
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00,
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00,
    0xdb, 0xff, 0x24, 0x00, 0x00, 0x00, 0x00, 0x24, 0xff, 0xdb, 0x00,
    0xb6, 0xff, 0x49, 0x00, 0x00, 0x00, 0x00, 0x49, 0xff, 0xb6, 0x00,
    0x6d, 0xff, 0xb6, 0x00, 0x00, 0x00, 0x00, 0xb6, 0xff, 0x6d, 0x00,
    0x00, 0xff, 0xff, 0x92, 0x00, 0x00, 0x92, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x49, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x49, 0x00, 0x00,
    0x00, 0x00, 0x49, 0xb6, 0xff, 0xff, 0xb6, 0x49, 0x00, 0x00, 0x00};

const tImage img_Digit_Large_0x30 = {image_data_Digit_Large_0x30, 11, 15,
                                     8};
#endif

#if (0x0 == 0x0)

static const uint8_t PROGMEM image_data_Digit_Large_0x31[165] = {
    // ∙∙░▓███∙∙∙∙
    // ∙██████∙∙∙∙
    // ∙█▓░∙██∙∙∙∙
    // ∙∙∙∙∙██∙∙∙∙
    // ∙∙∙∙∙██∙∙∙∙
    // ∙∙∙∙∙██∙∙∙∙
    // ∙∙∙∙∙██∙∙∙∙
    // ∙∙∙∙∙██∙∙∙∙
    // ∙∙∙∙∙██∙∙∙∙
    // ∙∙∙∙∙██∙∙∙∙
    // ∙∙∙∙∙██∙∙∙∙
    // ∙∙∙∙∙██∙∙∙∙
    // ∙∙∙∙∙██∙∙∙∙
    // ∙∙████████∙
    // ∙∙████████∙

    0x00, 0x24, 0x6d, 0xb6, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xdb, 0x92, 0x49, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
    0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00};

const tImage img_Digit_Large_0x31 = {image_data_Digit_Large_0x31, 11, 15,
                                     8};
#endif

#if (0x0 == 0x0)

static const uint8_t PROGMEM image_data_Digit_Large_0x32[165] = {
    // ∙▒████▒∙∙∙∙
    // ████████∙∙∙
    // █▒∙∙∙░██▓∙∙
    // ∙∙∙∙∙∙░██∙∙
    // ∙∙∙∙∙∙∙██∙∙
    // ∙∙∙∙∙∙░█▓∙∙
    // ∙∙∙∙∙∙▓█░∙∙
    // ∙∙∙∙∙▒█▓∙∙∙
    // ∙∙∙∙▒██∙∙∙∙
    // ∙∙∙▒██∙∙∙∙∙
    // ∙∙▒██░∙∙∙∙∙
    // ∙▒██░∙∙∙∙∙∙
    // ▒██░∙∙∙∙∙∙∙
    // █████████∙∙
    // █████████∙∙

    0x24, 0x92, 0xdb, 0xff, 0xff, 0xdb, 0x92, 0x00, 0x00, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
    0xdb, 0x6d, 0x24, 0x00, 0x00, 0x49, 0xff, 0xff, 0xb6, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0xff, 0xdb, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xdb, 0xff, 0x49, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x92, 0xff, 0xb6, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x92, 0xff, 0xdb, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x6d, 0xff, 0xff, 0x24, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x6d, 0xff, 0xff, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x92, 0xff, 0xff, 0x49, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x92, 0xff, 0xff, 0x49, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00};

const tImage img_Digit_Large_0x32 = {image_data_Digit_Large_0x32, 11, 15,
                                     8};
#endif

#if (0x0 == 0x0)

static const uint8_t PROGMEM image_data_Digit_Large_0x33[165] = {
    // ∙▒████▒∙∙∙∙
    // ████████∙∙∙
    // █▒░∙∙∙▓█▓∙∙
    // ∙∙∙∙∙∙∙██∙∙
    // ∙∙∙∙∙∙∙██∙∙
    // ∙∙∙∙∙∙▓█▒∙∙
    // ∙∙∙████▒∙∙∙
    // ∙∙∙████▓░∙∙
    // ∙∙∙∙∙∙▒██░∙
    // ∙∙∙∙∙∙∙░█▓∙
    // ∙∙∙∙∙∙∙∙██∙
    // ∙∙∙∙∙∙∙░██∙
    // ▓░∙∙∙∙▒██▒∙
    // ████████▓∙∙
    // ░▒████▓░∙∙∙

    0x24, 0x92, 0xdb, 0xff, 0xff, 0xdb, 0x92, 0x00, 0x00, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x24, 0x00, 0x00,
    0xdb, 0x6d, 0x24, 0x00, 0x00, 0x24, 0xb6, 0xff, 0xdb, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0xb6, 0xff, 0x6d, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x6d, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xb6, 0x24, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6d, 0xff, 0xff, 0x49, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xff, 0xdb, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xff, 0xdb, 0x00,
    0xdb, 0x49, 0x24, 0x00, 0x00, 0x24, 0x6d, 0xff, 0xff, 0x92, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb6, 0x00, 0x00,
    0x24, 0x92, 0xdb, 0xff, 0xff, 0xff, 0xb6, 0x49, 0x00, 0x00, 0x00};

const tImage img_Digit_Large_0x33 = {image_data_Digit_Large_0x33, 11, 15,
                                     8};
#endif

#if (0x0 == 0x0)

static const uint8_t PROGMEM image_data_Digit_Large_0x34[165] = {
    // ∙∙∙∙∙∙███∙∙
    // ∙∙∙∙∙▒███∙∙
    // ∙∙∙∙░█▒██∙∙
    // ∙∙∙∙██∙██∙∙
    // ∙∙∙▒█░∙██∙∙
    // ∙∙∙█▒∙∙██∙∙
    // ∙∙▓█∙∙∙██∙∙
    // ∙▒█░∙∙∙██∙∙
    // ∙█▓∙∙∙∙██∙∙
    // ▓█∙∙∙∙∙██∙∙
    // ███████████
    // ███████████
    // ∙∙∙∙∙∙∙██∙∙
    // ∙∙∙∙∙∙∙██∙∙
    // ∙∙∙∙∙∙∙██∙∙

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x92, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x24, 0xff, 0x6d, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xdb, 0xdb, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x6d, 0xff, 0x24, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x24, 0xff, 0x92, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0xdb, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x6d, 0xff, 0x49, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0xff, 0xb6, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0xb6, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00};

const tImage img_Digit_Large_0x34 = {image_data_Digit_Large_0x34, 11, 15,
                                     8};
#endif

#if (0x0 == 0x0)

static const uint8_t PROGMEM image_data_Digit_Large_0x35[165] = {
    // ∙███████∙∙∙
    // ∙███████∙∙∙
    // ∙██∙∙∙∙∙∙∙∙
    // ∙██∙∙∙∙∙∙∙∙
    // ∙██∙∙∙∙∙∙∙∙
    // ∙█████▒∙∙∙∙
    // ∙███████∙∙∙
    // ∙▓░∙∙▒██▒∙∙
    // ∙∙∙∙∙∙▒██∙∙
    // ∙∙∙∙∙∙∙██∙∙
    // ∙∙∙∙∙∙∙██∙∙
    // ∙∙∙∙∙∙▒██∙∙
    // ▓░∙∙∙▒██▒∙∙
    // ███████▓∙∙∙
    // ░▓███▓▒∙∙∙∙

    0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
    0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00,
    0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xff, 0xff, 0xdb, 0xff, 0xff, 0x92, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x00, 0x00, 0x00,
    0x00, 0xb6, 0x24, 0x00, 0x00, 0x6d, 0xff, 0xff, 0x6d, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6d, 0xff, 0xdb, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6d, 0xff, 0xdb, 0x00, 0x00,
    0xb6, 0x49, 0x00, 0x00, 0x24, 0x6d, 0xff, 0xff, 0x6d, 0x00, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb6, 0x00, 0x00, 0x00,
    0x24, 0x92, 0xdb, 0xff, 0xff, 0xdb, 0x6d, 0x00, 0x00, 0x00, 0x00};

const tImage img_Digit_Large_0x35 = {image_data_Digit_Large_0x35, 11, 15,
                                     8};
#endif

#if (0x0 == 0x0)

static const uint8_t PROGMEM image_data_Digit_Large_0x36[165] = {
    // ∙∙∙▒███▓░∙∙
    // ∙∙▓██████∙∙
    // ∙▓██░∙∙░▓∙∙
    // ░██░∙∙∙∙∙∙∙
    // ▒█▓∙∙∙∙∙∙∙∙
    // ██░∙∙∙∙∙∙∙∙
    // ██∙▒███▒∙∙∙
    // ██▒██████∙∙
    // ███░∙∙░██▒∙
    // ██░∙∙∙∙░██∙
    // ▓█∙∙∙∙∙∙██∙
    // ▒█░∙∙∙∙░██∙
    // ░██░∙∙░██▒∙
    // ∙▒███████∙∙
    // ∙∙░▓███▒∙∙∙

    0x00, 0x00, 0x00, 0x6d, 0xdb, 0xff, 0xff, 0xb6, 0x49, 0x00, 0x00,
    0x00, 0x00, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0xb6, 0xff, 0xff, 0x49, 0x00, 0x00, 0x49, 0xb6, 0x00, 0x00,
    0x24, 0xff, 0xff, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x92, 0xff, 0xb6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xdb, 0xff, 0x49, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xff, 0xff, 0x24, 0x6d, 0xdb, 0xff, 0xdb, 0x92, 0x00, 0x00, 0x00,
    0xff, 0xff, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x00, 0x00,
    0xff, 0xff, 0xdb, 0x49, 0x00, 0x00, 0x49, 0xff, 0xff, 0x92, 0x00,
    0xff, 0xff, 0x24, 0x00, 0x00, 0x00, 0x00, 0x49, 0xff, 0xff, 0x00,
    0xdb, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00,
    0x92, 0xff, 0x24, 0x00, 0x00, 0x00, 0x00, 0x49, 0xff, 0xff, 0x00,
    0x24, 0xff, 0xff, 0x49, 0x00, 0x00, 0x49, 0xff, 0xff, 0x92, 0x00,
    0x00, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x00, 0x00,
    0x00, 0x00, 0x49, 0xdb, 0xff, 0xff, 0xdb, 0x92, 0x00, 0x00, 0x00};

const tImage img_Digit_Large_0x36 = {image_data_Digit_Large_0x36, 11, 15,
                                     8};
#endif

#if (0x0 == 0x0)

static const uint8_t PROGMEM image_data_Digit_Large_0x37[165] = {
    // ██████████∙
    // █████████▓∙
    // ∙∙∙∙∙∙∙▓█▒∙
    // ∙∙∙∙∙∙∙██∙∙
    // ∙∙∙∙∙∙░█▓∙∙
    // ∙∙∙∙∙∙▓█▒∙∙
    // ∙∙∙∙∙∙██∙∙∙
    // ∙∙∙∙∙▒█▓∙∙∙
    // ∙∙∙∙∙▓█░∙∙∙
    // ∙∙∙∙∙██∙∙∙∙
    // ∙∙∙∙▒█▓∙∙∙∙
    // ∙∙∙∙▓█░∙∙∙∙
    // ∙∙∙∙██∙∙∙∙∙
    // ∙∙∙▒█▓∙∙∙∙∙
    // ∙∙∙██░∙∙∙∙∙

    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0xff, 0x6d, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6d, 0xff, 0xb6, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0xff, 0x6d, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x6d, 0xff, 0xb6, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xdb, 0xff, 0x49, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x6d, 0xff, 0xb6, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xdb, 0xff, 0x49, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x24, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x6d, 0xff, 0xb6, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xdb, 0xff, 0x49, 0x00, 0x00, 0x00, 0x00, 0x00};

const tImage img_Digit_Large_0x37 = {image_data_Digit_Large_0x37, 11, 15,
                                     8};
#endif

#if (0x0 == 0x0)

static const uint8_t PROGMEM image_data_Digit_Large_0x38[165] = {
    // ∙∙▒████▒∙∙∙
    // ░████████░∙
    // ▓█▓░∙∙░▓█▓∙
    // ██∙∙∙∙∙∙██∙
    // ██∙∙∙∙∙∙██∙
    // ▒█▓░∙∙░▓█░∙
    // ∙░██████░∙∙
    // ∙▒██████▒∙∙
    // ░██░∙∙░██░∙
    // ██░∙∙∙∙░██∙
    // ██∙∙∙∙∙∙██∙
    // ██░∙∙∙∙░██∙
    // ▓██░∙∙░██▓∙
    // ∙████████∙∙
    // ∙∙▒████▒∙∙∙

    0x00, 0x00, 0x92, 0xdb, 0xff, 0xff, 0xdb, 0x92, 0x24, 0x00, 0x00,
    0x24, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x24, 0x00,
    0xdb, 0xff, 0xdb, 0x24, 0x00, 0x00, 0x24, 0xdb, 0xff, 0xdb, 0x00,
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00,
    0xdb, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xdb, 0x00,
    0x6d, 0xff, 0xdb, 0x24, 0x00, 0x00, 0x24, 0xdb, 0xff, 0x6d, 0x00,
    0x00, 0x49, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x49, 0x00, 0x00,
    0x00, 0x6d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6d, 0x00, 0x00,
    0x6d, 0xff, 0xff, 0x49, 0x00, 0x00, 0x49, 0xff, 0xff, 0x6d, 0x00,
    0xdb, 0xff, 0x24, 0x00, 0x00, 0x00, 0x00, 0x24, 0xff, 0xdb, 0x00,
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00,
    0xff, 0xff, 0x24, 0x00, 0x00, 0x00, 0x00, 0x49, 0xff, 0xff, 0x00,
    0xb6, 0xff, 0xdb, 0x49, 0x00, 0x00, 0x49, 0xff, 0xff, 0xb6, 0x00,
    0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x92, 0xdb, 0xff, 0xff, 0xdb, 0x92, 0x00, 0x00, 0x00};

const tImage img_Digit_Large_0x38 = {image_data_Digit_Large_0x38, 11, 15,
                                     8};
#endif

#if (0x0 == 0x0)

static const uint8_t PROGMEM image_data_Digit_Large_0x39[165] = {
    // ∙∙▒███▓░∙∙∙
    // ∙███████▒∙∙
    // ▒██░∙∙░██∙∙
    // ██░∙∙∙∙░█▒∙
    // ██∙∙∙∙∙∙█▓∙
    // ██░∙∙∙∙░██∙
    // ▓██░∙∙░███∙
    // ∙██████▒██∙
    // ∙∙▒███▒∙██∙
    // ∙∙∙∙∙∙∙░██∙
    // ∙∙∙∙∙∙∙▓█▒∙
    // ∙∙∙∙∙∙░██░∙
    // ∙▓░∙∙░██▓∙∙
    // ∙██████▓∙∙∙
    // ∙░▓███▒∙∙∙∙

    0x00, 0x00, 0x92, 0xdb, 0xff, 0xff, 0xdb, 0x49, 0x00, 0x00, 0x00,
    0x00, 0xdb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0x00, 0x00,
    0x92, 0xff, 0xff, 0x49, 0x00, 0x00, 0x49, 0xff, 0xff, 0x24, 0x00,
    0xff, 0xff, 0x24, 0x00, 0x00, 0x00, 0x00, 0x49, 0xff, 0x92, 0x00,
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xdb, 0x00,
    0xff, 0xff, 0x24, 0x00, 0x00, 0x00, 0x00, 0x49, 0xff, 0xff, 0x00,
    0x92, 0xff, 0xff, 0x49, 0x00, 0x00, 0x49, 0xff, 0xff, 0xff, 0x00,
    0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0xff, 0x00,
    0x00, 0x00, 0x92, 0xdb, 0xff, 0xdb, 0x6d, 0x24, 0xff, 0xff, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xff, 0xdb, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb6, 0xff, 0x92, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0xff, 0xff, 0x24, 0x00,
    0x00, 0xb6, 0x49, 0x00, 0x00, 0x49, 0xff, 0xff, 0xb6, 0x00, 0x00,
    0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0x00, 0x00, 0x00,
    0x00, 0x49, 0xb6, 0xff, 0xff, 0xdb, 0x6d, 0x00, 0x00, 0x00, 0x00};

const tImage img_Digit_Large_0x39 = {image_data_Digit_Large_0x39, 11, 15,
                                     8};
#endif

static const tChar Digit_Large_array[] = {

#if (0x0 == 0x0)
    // character: '0'
    {0x30, &img_Digit_Large_0x30},
#else
    // character: '0' == ''
    {0x30, &img_Digit_Large_0x},
#endif

#if (0x0 == 0x0)
    // character: '1'
    {0x31, &img_Digit_Large_0x31},
#else
    // character: '1' == ''
    {0x31, &img_Digit_Large_0x},
#endif

#if (0x0 == 0x0)
    // character: '2'
    {0x32, &img_Digit_Large_0x32},
#else
    // character: '2' == ''
    {0x32, &img_Digit_Large_0x},
#endif

#if (0x0 == 0x0)
    // character: '3'
    {0x33, &img_Digit_Large_0x33},
#else
    // character: '3' == ''
    {0x33, &img_Digit_Large_0x},
#endif

#if (0x0 == 0x0)
    // character: '4'
    {0x34, &img_Digit_Large_0x34},
#else
    // character: '4' == ''
    {0x34, &img_Digit_Large_0x},
#endif

#if (0x0 == 0x0)
    // character: '5'
    {0x35, &img_Digit_Large_0x35},
#else
    // character: '5' == ''
    {0x35, &img_Digit_Large_0x},
#endif

#if (0x0 == 0x0)
    // character: '6'
    {0x36, &img_Digit_Large_0x36},
#else
    // character: '6' == ''
    {0x36, &img_Digit_Large_0x},
#endif

#if (0x0 == 0x0)
    // character: '7'
    {0x37, &img_Digit_Large_0x37},
#else
    // character: '7' == ''
    {0x37, &img_Digit_Large_0x},
#endif

#if (0x0 == 0x0)
    // character: '8'
    {0x38, &img_Digit_Large_0x38},
#else
    // character: '8' == ''
    {0x38, &img_Digit_Large_0x},
#endif

#if (0x0 == 0x0)
    // character: '9'
    {0x39, &img_Digit_Large_0x39},
#else
    // character: '9' == ''
    {0x39, &img_Digit_Large_0x},
#endif

};

const tFont Digits_Large = {10, Digit_Large_array};

#endif