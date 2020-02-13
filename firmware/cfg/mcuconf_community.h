
/*
 * COMP driver system settings.
 */
#define STM32_COMP_USE_COMP1                  FALSE
#define STM32_COMP_USE_COMP2                  FALSE
#define STM32_COMP_USE_COMP3                  FALSE
#define STM32_COMP_USE_COMP4                  FALSE
#define STM32_COMP_USE_COMP5                  FALSE
#define STM32_COMP_USE_COMP6                  FALSE
#define STM32_COMP_USE_COMP7                  FALSE

#define STM32_COMP_USE_INTERRUPTS             FALSE
#define STM32_COMP_1_2_3_IRQ_PRIORITY         5
#define STM32_COMP_4_5_6_IRQ_PRIORITY         5
#define STM32_COMP_7_IRQ_PRIORITY             5

#if STM32_COMP_USE_INTERRUPTS
#define STM32_DISABLE_EXTI21_22_29_HANDLER
#define STM32_DISABLE_EXTI30_32_HANDLER
#define STM32_DISABLE_EXTI33_HANDLER
#endif

/*
 * OPAMP driver system settings.
 */

#define STM32_OPAMP_USE_OPAMP1                  TRUE
#define STM32_OPAMP_USE_OPAMP2                  TRUE
#define STM32_OPAMP_USE_OPAMP3                  TRUE
#define STM32_OPAMP_USE_OPAMP4                  TRUE
#define STM32_OPAMP_USER_TRIM_ENABLED           TRUE

