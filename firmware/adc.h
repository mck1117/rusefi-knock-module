#pragma once

#include "ch.h"
#include "hal.h"

void collectSamples(size_t count, adcsample_t* buffer, adccallback_t callback);
