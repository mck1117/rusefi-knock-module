#include "ch.h"
#include "hal.h"

#include "opamp.h"

void initOpamps()
{
    const OPAMPConfig opamp1_conf = {
        OPAMP1_CSR_VPSEL_PA01 |
        OPAMP1_CSR_VMSEL_PA03
    };

    const OPAMPConfig opamp2_conf = {
        OPAMP2_CSR_VPSEL_PA07 |
        OPAMP2_CSR_VMSEL_PA05
    };

    const OPAMPConfig opamp3_conf = {
        OPAMP3_CSR_VPSEL_PB00 |
        OPAMP3_CSR_VMSEL_PB02
    };

    const OPAMPConfig opamp4_conf = {
        OPAMP4_CSR_VPSEL_PB13 |
        OPAMP4_CSR_VMSEL_PB10
    };

    // Configure opamps
    opampStart(&OPAMPD1, &opamp1_conf);
    opampStart(&OPAMPD2, &opamp2_conf);
    opampStart(&OPAMPD3, &opamp3_conf);
    opampStart(&OPAMPD4, &opamp4_conf);

    // opamp 1
    palSetPadMode(GPIOA, 1, PAL_MODE_INPUT_ANALOG);
    palSetPadMode(GPIOA, 2, PAL_MODE_INPUT_ANALOG);
    palSetPadMode(GPIOA, 3, PAL_MODE_INPUT_ANALOG);

    // opamp 2
    palSetPadMode(GPIOA, 5, PAL_MODE_INPUT_ANALOG);
    palSetPadMode(GPIOA, 6, PAL_MODE_INPUT_ANALOG);
    palSetPadMode(GPIOA, 7, PAL_MODE_INPUT_ANALOG);

    // opamp 3
    palSetPadMode(GPIOB, 0, PAL_MODE_INPUT_ANALOG);
    palSetPadMode(GPIOB, 1, PAL_MODE_INPUT_ANALOG);
    palSetPadMode(GPIOB, 2, PAL_MODE_INPUT_ANALOG);

    // opamp 4
    palSetPadMode(GPIOB, 10, PAL_MODE_INPUT_ANALOG);
    palSetPadMode(GPIOB, 12, PAL_MODE_INPUT_ANALOG);
    palSetPadMode(GPIOB, 13, PAL_MODE_INPUT_ANALOG);

    // Enable opamps
    opampEnable(&OPAMPD1);
    opampEnable(&OPAMPD2);
    opampEnable(&OPAMPD3);
    opampEnable(&OPAMPD4);
}
