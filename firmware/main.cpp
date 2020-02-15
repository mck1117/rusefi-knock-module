/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "ch.h"
#include "hal.h"

#include "opamp.h"

// these settings sample at 216.216 khz
static const ADCConversionGroup grp = { FALSE, 1, nullptr, nullptr,
    ADC_CFGR_CONT, //0, // CFGR
    ADC_TR(0, 4095), // TR 1
    {   // SMPR[2]
        ADC_SMPR1_SMP_AN3(ADC_SMPR_SMP_61P5),
        0
    },
    {   // SQR[4]
        ADC_SQR1_SQ1_N(ADC_CHANNEL_IN3),
        0,
        0,
        0
    }
};

adcsample_t sampleBuffer[2000];

int main(void)
{
    halInit();
    chSysInit();

    // Is this missing from halCommunityInit?
    opampInit();

    initOpamps();

    auto device = &ADCD1;

    adcStart(device, nullptr);

    while (true)
    {
        adcConvert(device, &grp, sampleBuffer, 400);
    }
}
