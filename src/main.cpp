/**
 *  @file   main.cpp
 *  @brief  the main entry for this ESP32 program.
 *  Copyright (C) 2023-25 Leisquid Tianyi Li.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


#include "DEV_Config.h"

#include "EPD_7in5_V2.h"
#include "Debug.h"

#include "test.h"   /* 临时的 4 阶图像测试 */
#include "mono.h"   /* 临时的黑白图像测试 */

void setup() {

    DEV_Module_Init();
    printf("EPD_7IN5_V2_test Demo\n");

    printf("e-Paper Init and Clear...\r\n");

#if 1
    UBYTE *imageArray4Gr;
    UDOUBLE imageSize4Gr = EPD_7IN5_V2_WIDTH / 8 * EPD_7IN5_V2_HEIGHT * 2;
    if ( (imageArray4Gr = (UBYTE *) malloc(imageSize4Gr)) == NULL ) {
        printf("Failed to apply for imageArray4Gr memory...\n");
        while (1);
    }
    memcpy(imageArray4Gr, gImage_test, imageSize4Gr);

    printf("show image for array\r\n");
    printf("init 4gray\n");
    EPD_7IN5_V2_Init_4Gray();
    printf("clear\n");
    EPD_7IN5_V2_Clear();
    printf("display 4gray\n");
    EPD_7IN5_V2_Display_4Gray(imageArray4Gr);
    printf("Going to Sleep...\r\n");
    EPD_7IN5_V2_Sleep();
    /* 得需要封装一下，不然乱了。 */
    free(imageArray4Gr);
    imageArray4Gr = NULL;

    DEV_Delay_ms(4000);
#endif

#if 1
    UBYTE *imageArrayBW;
    UWORD imageSizeBW = EPD_7IN5_V2_WIDTH / 8 * EPD_7IN5_V2_HEIGHT;
    if ( (imageArrayBW = (UBYTE *) malloc(imageSizeBW)) == NULL ) {
        printf("Failed to apply for imageArrayBW memory...\n");
        while (1);
    }
    memcpy(imageArrayBW, gImage_mono, imageSizeBW);

    printf("show image for array2\r\n");
    printf("init bw\n");
    EPD_7IN5_V2_Init();
    printf("clear\n");
    EPD_7IN5_V2_Clear();
    printf("display bw\n");
    EPD_7IN5_V2_Display(imageArrayBW);

    // printf("init part\n");
    // EPD_7IN5_V2_Init_Part();
    // printf("display bw_part\n");
    // EPD_7IN5_V2_Display_Part(imageArrayBW, 0, 0, EPD_7IN5_V2_WIDTH, EPD_7IN5_V2_HEIGHT);

    free(imageArrayBW);
    imageArrayBW = NULL;
#endif

#if 1
    UBYTE *imageArrayPart;
    UWORD imageSizePart = 80 / 8 * 50;
    if ( (imageArrayPart = (UBYTE *) malloc(imageSizePart)) == NULL ) {
        printf("Failed to apply for imageArrayPart memory...\n");
        while (1);
    }
    memset(imageArrayPart, 0xc3, imageSizePart * sizeof(UBYTE));

    printf("part display test\r\n");
    printf("init part\n");
    EPD_7IN5_V2_Init_Part();
    printf("display part\n");
    EPD_7IN5_V2_Display_Part(imageArrayPart, 100, 300, 180, 350);

    free(imageArrayPart);
    imageArrayPart = NULL;
#endif

    printf("Going to Sleep...\r\n");
    EPD_7IN5_V2_Sleep();
}

void loop() {
}
