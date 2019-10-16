#include <stdio.h>

#include "absolute_value.h"
#include "bytes_required_for_bits.h"
#include "comparisons.h"
#include "is_power_of_2.h"
#include "shifts.h"
#include "sign.h"
#include "minmax.h"
#include "comparisons.h"
#include "difference.h"

int main(void)
{
    for(int i = -5; i < 17; i++)
    {
        // printf("asr %x = %x\n", i, asr_max(int, i));
        // printf("lsl %x = %x\n", i, lsl_max(i));
        // printf("lsr %x = %x\n", i, lsr_max(int, i));
        // printf("sign %d = %x\n", i, sign_n11(i));
        // printf("sign %d = %x\n", i, sign_n101(i));
        // printf("is ge 0 %d = %x\n", i, is_ge_0(i));
        // printf("is gt 0 %d = %x\n", i, is_gt_0(i));
        // printf("is zero %d = %x\n", i, is_zero(i));
        printf("is-power-of-2 %d = %d\n", i, is_power_of_2(i));
    }
}