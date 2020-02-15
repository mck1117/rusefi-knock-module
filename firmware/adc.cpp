#include "adc.h"

static ADCConversionGroup grp = { FALSE, 1, nullptr, nullptr,
    0, // CFGR
    ADC_TR(0, 4095), // TR 1
    {   // SMPR[2]
        ADC_SMPR1_SMP_AN3(ADC_SMPR_SMP_61P5),
        0
    },
    {   // SQR[4]
        ADC_SQR1_SQ1_N(ADC_CHANNEL_IN5),
        0,
        0,
        0
    }
};

void collectSamples(size_t count, adcsample_t* buffer, adccallback_t callback)
{
    grp.end_cb = callback;

    // Synchronously convert samples
    adcConvert(&ADCD1, &grp, buffer, count);
}
